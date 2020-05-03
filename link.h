#ifndef link_h
#define link_h

#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "subject.h"
#include "info.h"
class Link : public Subject<Info> {
public:
    char type = 'x';
    char name = 'x';
    int attack = 0;
    int speed = 1;
    int owner = 0;
    int row;
    int col;
    bool onFire = false;
    bool downloaded = false;
    bool invisible = false;
    bool shield = false;
    bool revealed =  false;
    
public:
    void setFire(bool fire);
    bool getFire();

    void init(int owner, char type, int attack, char name);
    void init2(int row, int col, int owner, char type, int attack, char name);
    int getSpeed();
    int getAttack();
    char getType();
    char getName();
    void setAttack(int attack);
    void setType(char newType);
    void addSpeed(int i);
    void addAttack(int i);
        
    int getOwner();
    
    bool getDownload();
    void setDownload(bool d);
    
    bool getShield();
    void setShield(bool set);
    
    bool getReveal();
    void setReveal(bool set);
    
    bool getInvi();
    void setInvi(bool set);
    
    void move(char direc);
    Link(int row, int col);
    int getRow();
    int getCol();
    void setRow(int r);
    void setCol(int c);
    
    Info getInfo() const override;
    
};


#endif /* link_h */
