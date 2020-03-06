//
//  display.cpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#include "textdisplay.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

TextDisplay::TextDisplay(Player* p1, Player* p2):p1{p1}, p2{p2}{
    Display.clear();
    Display = std::vector<std::vector<char>> (8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char a = '.';
            Display[i].push_back(a);
        }
    }
    
    Display[0][0] = 'a';
    Display[0][1] = 'b';
    Display[0][2] = 'c';
    Display[0][3] = 'S';
    Display[0][4] = 'S';
    Display[0][5] = 'f';
    Display[0][6] = 'g';
    Display[0][7] = 'h';
    Display[1][3] = 'd';
    Display[1][4] = 'e';
    
    
    Display[7][0] = 'A';
    Display[7][1] = 'B';
    Display[7][2] = 'C';
    Display[7][3] = 'S';
    Display[7][4] = 'S';
    Display[7][5] = 'F';
    Display[7][6] = 'G';
    Display[7][7] = 'H';
    Display[6][3] = 'D';
    Display[6][4] = 'E';
    
    d1 = std::vector<std::vector<char>> (8);
    d2 = std::vector<std::vector<char>> (8);

    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c = Display[i][j];
            d1[i].push_back(c);
        }
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c = Display[i][j];
            d2[i].push_back(c);
        }
    }
}




void TextDisplay:: notify(Subject<Info>& whofrom) {
    Info its = whofrom.getInfo();
    int row = its.row;
    int col = its.col;
    char name = its.name;
    if ((name == 'm') || (name == 'w')) {
         Display[row][col] = name;
        d1[row][col] = name;
       d2[row][col] = name;
    }
    else {
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++){
            if (Display[i][j] == name){
                Display[i][j] = '.';
                d1[i][j] = '.';
                d2[i][j] = '.';
            }
        }
    }
        if (!its.downloaded){
            Display[row][col] = name;
            d1[row][col] = name;
            d2[row][col] = name;
        }
        if(its.invisible) {
            if (its.owner == 1){
                d2[row][col] = '.';
            }
            if (its.owner == 2){
                d1[row][col] = '.';
            }
        }
    }
}

Player* TextDisplay:: getP1(){
    return p1;
}
Player* TextDisplay:: getP2(){
    return p2;
}


void TextDisplay:: print(int activeplayer){
    if (activeplayer == 1) {
        getP1()->myPrint();
        cout << "========" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << d1[i][j];
            }
            cout << endl;
        }
        cout << "========" << endl;
    }
    else {
        getP1()->otherPrint();
        cout << "========" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << d2[i][j];
            }
            cout << endl;
        }
        cout << "========" << endl;
    }

    if (activeplayer == 1) {
        getP2()->otherPrint();
    }
    else {
        getP2()->myPrint();
    }
}
