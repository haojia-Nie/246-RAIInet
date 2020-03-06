//
//  ability.cpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#include "ability.h"
#include "link.h"
using namespace std;
Ability:: Ability(int owner, char name): owner{owner}, name{name} {}


// get the owner
int Ability:: getOwner(){
    return owner;
}
// label the ability to "used"
void Ability::setUsed(bool set) {
    used = set;
}
// check if this ability is used
bool Ability:: getUsed() {
    return used;
}
// get the name of the ability
char Ability:: getName(){
    return name;
}



//
// Subclasses of Ability


bool FireWall:: use(Link * target){
    return true;
}


bool ExtraRound:: use(Link * target){
    return true;
}


// increase the speed of the link by 1
bool LinkBoost:: use(Link * target){
    //cout << "LinkBoost: " << endl;
    if (target->getOwner() == getOwner()) {
        target->addSpeed(1);
        return true;
    }
    else {
        cout << "You can only linkboost your link" << endl;
        return false;
    }
}

// reverse the type of the target
bool Polarize:: use(Link * target){
//    cout << "Polarize: " << endl;
    if (target->getOwner() == getOwner()) {
        if (target->getType() == 'V'){
            target->setType('D');
        }
        else {
            target->setType('V');
        }
    }
    // polarize the other user's link
    else {
        if (target->getShield()){
            target->setShield(false);
  //          cout << "Shield is triggered" << endl;
        }
        else {
            if (target->getType() == 'V'){
                target->setType('D');
            }
            else {
                target->setType('V');
            }
        }
    }
    return true;
}

// scan the info of the link
bool Scan:: use(Link * target){
    //cout << "Scan: " << endl;
    if (target->getOwner() == getOwner()) {
        cout << "You can only Scan the other player's link" << endl;
    }
    else if  (target -> getReveal()) {
        cout << "You have already scanned this link" << endl;
    }
    else if (target->getShield()){
        target->setShield(false);
        cout << "Shield is triggered" << endl;
        return true;
    }
    else {
        target->setReveal(true);
        return true;
    }
    return false;
}

// download a opponent link

bool Download:: use(Link * target){
    //cout << "Download: " << endl;
    if (target->getOwner() == getOwner()) {
        cout << "You can only Download the other player's link" << endl;
    }
    else {
        if (target->getShield()){
            target->setShield(false);
            cout << "Shield is triggered" << endl;
        }
        else {
            target->setDownload(true);
            target->notifyObservers();
        }
        return true;
    }
    return false;
}

// add 1 attack/strength to the link
bool Reinforce:: use(Link * target){
 //   cout << "Reinforce: " << endl;
    if (target->getOwner() != getOwner()) {
        cout << "You can only Reinforce your link" << endl;
    }
    else {
        target->addAttack(1);
        return true;
    }
    return false;
}

// add a magicshield to the link which can block one ability to it from the other player
bool Magicshield:: use(Link * target){
   // cout << "Magicshield: " << endl;
    if (target->getOwner() != getOwner()) {
        cout << "You can only Shield your link" << endl;
    }
    else {
        if(target->getShield()){
            cout << "This link already has shield" << endl;
        }
        else {
            target->setShield(true);
            return true;
        }
    }
    return false;
}

// add a magicshield to the link which can block one ability to it from the other player
bool Invisible:: use(Link * target){
   // cout << "Invisible: " << endl;
    if (target->getOwner() != getOwner()) {
        cout << "You can only make your link invisible" << endl;
    }
    else {
        if(target->getInvi()){
            cout << "This link is already invisible" << endl;
        }
        else {
            target->setInvi(true);
            target->notifyObservers();
            return true;
        }
    }
    return false;
}
