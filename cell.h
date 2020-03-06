//
//  cell.hpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#ifndef cell_h
#define cell_h

class Link;
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"


class Cell{
    int r;
    int c;
    Link* contain = nullptr;
    
public:
    Cell(int r, int c);
    Link* getContain();
    void setContain(Link* lk);
    
};




#endif /* cell_h */
