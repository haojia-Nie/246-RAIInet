//
//  subject.hpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#ifndef subject_h
#define subject_h

#include <iostream>
#include <vector>
#include <string>

template <typename InfoType> class Observer;

template <typename InfoType> class Subject {
  std::vector<Observer<InfoType>*> observers;

 public:
    void attach(Observer<InfoType> *o);
    virtual InfoType getInfo() const = 0;
    void notifyObservers();
 
};

template <typename InfoType>
void Subject<InfoType>:: notifyObservers() {
    for (auto &ob : observers) {
        ob->notify(*this);
    }
}

template <typename InfoType>
void Subject<InfoType>:: attach(Observer<InfoType> *o){
    observers.push_back(o);
}



#endif /* subject_h */
