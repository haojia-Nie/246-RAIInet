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
