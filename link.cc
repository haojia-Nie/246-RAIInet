//
//  link.cpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#include "link.h"

void Link::setFire(bool fire){
    onFire = fire;
}

bool Link::getFire(){
    return onFire;
}

void Link:: init(int owner, char type, int attack, char name){
    this->owner = owner;
    this->type = type;
    this->attack = attack;
    this->name = name;
}
int Link:: getSpeed(){
    return speed;
}

int Link:: getAttack(){
    return attack;
}
char Link:: getType(){
    return type;
}
char Link:: getName(){
    return name;
}

int Link:: getOwner() {
    return owner;
}

void Link:: setAttack(int attack){
    this->attack = attack;
}
void Link:: setType(char newType) {
    this->type = newType;
}

void Link:: addSpeed(int i){
    speed += i;
}
void Link:: addAttack(int i){
    attack += i;
}

bool Link:: getDownload() {
    return downloaded;
}

void Link:: setDownload(bool d) {
    downloaded = d;
}

bool Link:: getShield() {
    return shield;
}

void Link:: setShield(bool set) {
    shield = set;
}

bool Link::getReveal() {
    return revealed;
}

void Link:: setReveal(bool set){
    revealed = set;
}


bool Link:: getInvi() {
    return invisible;
}

void Link:: setInvi(bool set) {
    invisible = set;
}

Info Link:: getInfo() const{
    Info in;
    in.owner = owner;
    in.row = row;
    in.col = col;
    in.name = name;
    in.downloaded = downloaded;
    in.invisible = invisible;
    in.reveal = revealed;
    in.firewall= (type == 'F');
    return in;
}

Link::Link(int row, int col): row{row}, col{col}{}


int Link:: getRow(){
    return row;
}
int Link:: getCol(){
    return col;
}

void Link:: setRow(int r){
    row = r;
}
void Link:: setCol(int c){
    col = c;
}
