//
//  player.hpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#ifndef player_h
#define player_h
#include <iostream>
#include <vector>
#include <string>
#include "link.h"
#include "ability.h"

class Player{
public:
    
    int name = 0;
    int virus = 0;
    int data = 0;
    int ability = 5;
    std::vector<Link *> links;
    std::vector<Ability *> abilities;

public:
    int getVirus();
    int getData();
    int getAbility();

    std::vector<char> graphType();
    std::vector<char> graphAbility();
    std::vector<int> graphAttack();
    std::vector<bool> graphReveal();
    void myPrint();
    void otherPrint();
    Player(int name);
    void linkInit(std::string order);
    void useAbility();
    void setAbs(std::vector<Ability*> abs);
    void setLinks(std::vector<Link> lks);
    std::vector<Link *> getLinks();
    void addVirus(int i);
    void addData(int i);
    int getName();
    ~Player();
};





#endif /* player_h */
