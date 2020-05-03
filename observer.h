
#ifndef observer_h
#define observer_h
#include <iostream>
#include <vector>
#include <string>

template <typename InfoType> class Subject;

template <typename InfoType> class Observer {
 public:
  virtual void notify(Subject<InfoType> &whoFrom) = 0; // pass the Subject that called the notify method
  virtual ~Observer() = default;
};







#endif /* observer_h */
