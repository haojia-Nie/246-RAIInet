

#include "player.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


std::vector<Link*> Player:: getLinks(){
    return links;
}

void Player::useAbility() {
	ability --;
}

int Player::getAbility(){
	return ability;
}

int Player::getVirus(){
	return virus;
}

int Player::getData(){
	return data;
}


vector<char> Player::graphAbility(){
   vector<char> ability1;
   for (int i = 0; i < 5; i++){
        ability1.push_back(abilities.at(i)->getName());
    }
   return ability1;
}

vector<bool> Player::graphReveal(){
   vector<bool> reveal1;
   for (int i = 0; i < 8; i++){
        reveal1.push_back(links.at(i)->getReveal());
    }
   return reveal1;
}
vector<char> Player::graphType(){
   vector<char> type1;
   for (int i = 0; i < 8; i++){
        type1.push_back(links.at(i)->getType());
    }
   return type1;
}
vector<int> Player::graphAttack(){
    vector<int> attack1;
    for (int i = 0; i < 8; i++){
        attack1.push_back(links.at(i)->getAttack());
    }
    return attack1;
}

void Player:: myPrint(){
    cout << "Player " << name << endl;
    cout << "Downloaded: " << data << "D" << ", " << virus << "V" << endl;
    cout << "Abilities: " << ability << endl;
    
    for (int i = 0; i < 4 ; i++) {
        Link* lk = links[i];
        cout << lk->getName() << ": " << lk->getType() << lk->getAttack() << "  ";
    }
    cout << endl;
    
    for (int i = 4; i < 8 ; i++) {
        Link* lk = links[i];
        cout << lk->getName() << ": " << lk->getType() << lk->getAttack() << "  ";
    }
    cout << endl;
}


void Player:: otherPrint() {
    cout << "Player " << name << endl;
    cout << "Downloaded: " << data << "D" << ", " << virus << "V" << endl;
    cout << "Abilities: " << ability << endl;
    for (int i = 0; i < 4 ; i++) {
        Link* lk = links[i];
        cout << lk->getName() << ": " ;
        if (lk->getDownload() || lk->getReveal()) {
            cout << lk->getType() << lk->getAttack() << "  ";
        }else {
            cout << "?  " ;
        }
    }
    cout << endl;
    
    for (int i = 4; i < 8 ; i++) {
        Link* lk = links[i];
             cout << lk->getName() << ": " ;
             if (lk->getDownload() || lk->getReveal()) {
                 cout << lk->getType() << lk->getAttack() << "  ";
             }else {
                 cout << "?  " ;
             }
    }
    cout << endl;
    
}


void Player:: linkInit(std::string order){
   for (int i = 0; i < 8; i ++){
       char type = order[i*2];
       char Attack = order[i * 2 + 1];
       links[i]->setType(type);
       links[i]->setAttack(Attack - '0');
   }
}

void Player::setAbs(std::vector<Ability*> abs){
    abilities.clear();
    
    for (int i = 0; i < 5; i++){
           abilities.push_back(abs[i]);
       }
}

void Player:: setLinks(std::vector<Link> lks){
    
    for(int i = 0; i < 8; i++){
        links.push_back(&lks[i]);
    }
    
    for (auto &lk : links) {
        std::cout << lk->getRow() << " " << lk->getCol() << ", " ;
    }
    std::cout << "here" << std::endl;
}


Player::Player(int name): name{name}{
};


Player:: ~Player(){
    
};


void Player:: addVirus(int i){
    virus += i;
}
void Player:: addData(int i){
    data += i;
}
int Player:: getName(){
    return name;
}
