#include "graphicsdisplay.h"
#include "observer.h"
#include "player.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

using namespace std;


GraphicsDisplay::GraphicsDisplay(Player *p1, Player *p2): p1{p1}, p2{p2}, active{p1}{
    Display.clear();
    myWin.fillRectangle(0,0,500,600, 9);
    myWin.drawStringFont(220,280,"RAIInet",
                         "lucidasans-bolditalic-24", 0);

    // sleep
    sleep_for(20ns);
    sleep_until(system_clock::now() + 1s);
    
    
    myWin.fillRectangle(0,0,500,600, 0);
    // prints the neccessary information  strings
    myWin.drawStringFont(30,30, "Player1 ",
                         "lucidasans-bold-14",Xwindow::DarkGreen);
    myWin.drawStringFont(30,50, "Downloaded: ",
                         "lucidasans-bold-14",Xwindow::DarkGreen);

    myWin.drawStringFont(400,30, "Player2 ",
                         "lucidasans-bold-14",Xwindow::DarkGreen);
    myWin.drawStringFont(400,50, "Downloaded: ",
                         "lucidasans-bold-14",Xwindow::DarkGreen);

    // draws the virus and data it downloaded
    int dVirus1 = p1->getVirus();;
    int dData1 = p1->getData();
    int dVirus2 = p2->getVirus();
    int dData2 = p2->getData();

    for (int i = 0; i < dVirus1; i++) {
        myWin.fillRectangle(30 + 30 * i, 60, 15, 15, 9);
    }

    for (int i = 0; i < dData1; i++) {
        myWin.fillRectangle(30 + 30 * i, 80, 15, 15, 10);
    }
    // for player 2
    for (int i = 0; i < dVirus2; i++) {
        myWin.fillRectangle(400 + 30 * i, 60, 15, 15, 9);
    }

    for (int i = 0; i < dData2; i++) {
        myWin.fillRectangle(400 + 30 * i, 80, 15, 15, 10);
    }

    myWin.drawStringFont(30,115, "Ability: ",
                         "lucidasans-bold-14",Xwindow::DarkGreen);
    for (int i = 1; i < 6; i++) {
        myWin.fillRectangle(70 + 30 * i, 102, 17, 17, 3);
    }

    myWin.drawStringFont(400,115, "Ability: ",
                         "lucidasans-bold-14",Xwindow::DarkGreen);
    for (int i = 1; i < 6; i++) {
        myWin.fillRectangle(440 + 30 * i, 102, 17, 17, 3);
    }

    Display =vector<std::vector<char>> (8);
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


}

void GraphicsDisplay::graph() {

// ability name 	
    ability1 = p1->graphAbility();
    ability2 = p1->graphAbility();
    for (int i = 0; i < 5; i ++) {
	    stringstream ss;
	    string ab1;
	    ss << ability1.at(i);
	    ss >> ab1;

	    stringstream ss2;
	    string ab2;
	    ss2 << ability2.at(i);
	    ss2 >> ab2;
    	myWin.drawStringFont(100 + 30 * i, 113, ab1, 
			"lucidasans-bold-14", 0);
    	myWin.drawStringFont(470 + 30 * i, 113, ab2, 
			"lucidasans-bold-14", 0);

    }


    type1 = p1->graphType();
    type2 = p2->graphType();
    attack1 = p1->graphAttack();
    attack2 = p2->graphAttack();
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
 // the panel   
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            stringstream ss;
            string target;
            ss << Display[i][j];
            ss >> target;
            if (Display[i][j] == '.'){
                myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 5);

            }
            else if (Display[i][j] == 'S') {
                myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 6);
            }
            else if (Display[i][j] <= 'h' && Display[i][j] >= 'a') {
                myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 2);

                int index = Display[i][j] - 'a';

                if (type1.at(index) == 'V') {
                    myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 9);
                }else {
                    myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 10);
                }
                myWin.drawStringFont(120 + 50 * j, 162 + i * 50, target,
                                     "lucidasans-bold-14",Xwindow::White);

                stringstream attackNum;
                attackNum << attack1.at(index);
                string str = attackNum.str();
                myWin.drawStringFont(120 + 50 * j, 182 + i * 50, str,
                                     "lucidasans-bold-14",Xwindow::White);

                }
                else if (Display[i][j] <= 'H' && Display[i][j] >= 'A') {
                myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 8);
                myWin.drawStringFont(120 + 50 * j, 162 + i * 50, target,
                                     "lucidasans-bold-14",Xwindow::White);
                }
        }
    }
}

void GraphicsDisplay::changeActive(){
    if (active == p1){
        active = p2;
    }else {
        active = p1;
    }
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            stringstream ss;
            string target;
            ss << Display[i][j];
            ss >> target;
            if (active == p1){
                if (Display[i][j] <= 'h' && Display[i][j] >= 'a') {
                    int index = Display[i][j] - 'a';
                    if (type1.at(index) == 'V') {
                        myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 9);
                    }else {
                        myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 10);
                    }

                    myWin.drawStringFont(120 + 50 * j, 162 + i * 50, target,
                                     "lucidasans-bold-14",Xwindow::White);
                    stringstream attackNum;
                    attackNum << attack1.at(index);
                    string str = attackNum.str();
                    myWin.drawStringFont(120 + 50 * j, 182 + i * 50, str,
                                     "lucidasans-bold-14",Xwindow::White);
                }

                else if (Display[i][j] <= 'H' && Display[i][j] >= 'A') {
                    myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 8);
                    myWin.drawStringFont(120 + 50 * j, 162 + i * 50, target,
                                     "lucidasans-bold-14",Xwindow::White);
                }
            }
            else if (active == p2){
                if (Display[i][j] <= 'H' && Display[i][j] >= 'A') {
                    int index = Display[i][j] - 'A';
                    if (type2.at(index) == 'V') {
                        myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 9);
                    }else {
                        myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 10);
                    }

                    myWin.drawStringFont(120 + 50 * j, 162 + i * 50, target,
                                     "lucidasans-bold-14",Xwindow::White);
                    stringstream attackNum;
                    attackNum << attack2.at(index);
                    string str = attackNum.str();
                    myWin.drawStringFont(120 + 50 * j, 182 + i * 50, str,
                                     "lucidasans-bold-14",Xwindow::White);
                }
                else if (Display[i][j] <= 'h' && Display[i][j] >= 'a') {
                    myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 8);
                    myWin.drawStringFont(120 + 50 * j, 162 + i * 50, target,
                                     "lucidasans-bold-14",Xwindow::White);
                }

            }
        }
    }
}


GraphicsDisplay::~GraphicsDisplay() {}

void GraphicsDisplay::notify(Subject<Info> & whofrom){
    
    // update downloaded 	    
    int dVirus1 = p1->getVirus();;
    int dData1 = p1->getData();
    int dVirus2 = p2->getVirus();
    int dData2 = p2->getData();
    // for player 1

    for (int i = 0; i < dVirus1; i++) {
        myWin.fillRectangle(30 + 30 * i, 60, 15, 15, 9);
    }

    for (int i = 0; i < dData1; i++) {
        myWin.fillRectangle(30 + 30 * i, 80, 15, 15, 10);
    }
    // for player 2
    for (int i = 0; i < dVirus2; i++) {
        myWin.fillRectangle(400 + 30 * i, 60, 15, 15, 9);
    }

    for (int i = 0; i < dData2; i++) {
        myWin.fillRectangle(400 + 30 * i, 80, 15, 15, 10);
    }


        Info its = whofrom.getInfo();
        int row = its.row;
        int col = its.col;
        char name = its.name;

        stringstream ss;
        string target;
        ss << name;
        ss >> target;

        if ((name == 'm') || (name == 'w')) {

        Display[row][col] = name;
            d1[row][col] = name;
            d2[row][col] = name;
            myWin.fillRectangle(120 + 50 * col, 150 + row * 50, 45, 45, 5);
            myWin.drawStringFont(120 + 50 * col, 162 + row * 50, target,
                                 "lucidasans-bold-14",Xwindow::Brown);
        }
        else {
            if (its.owner == 1 && active != p1){
                changeActive();
            }else if (its.owner == 2 && active != p2){
                changeActive();
            }


            for (int i = 0; i < 8; i ++) {
                for (int j = 0; j < 8; j++){
                    if (Display[i][j] == name){
                        Display[i][j] = '.';
                        d1[i][j] = '.';
                        d2[i][j] = '.';
                        myWin.fillRectangle(120 + 50 * j, 150 + i * 50, 45, 45, 5);
                    }
                }
            }
            if (!its.downloaded){
                Display[row][col] = name;
                d1[row][col] = name;
                d2[row][col] = name;
                int index = (active == p1) ? (name - 'a'): (name - 'A');
                string str;
                stringstream attackNum;
                
		// get the attack value
		if (its.owner == 1) {
           		 attackNum << attack1.at(index);
       		 }else {
            		attackNum << attack2.at(index);
       		 }
                 str = attackNum.str();
		
		 // print type rectangle
                if (type1.at(index) == 'V'){
                    myWin.fillRectangle(120 + 50 * col, 150 + row * 50, 45, 45, 9);
                }else if (type1.at(index == 'D')){
                    myWin.fillRectangle(120 + 50 * col, 150 + row * 50, 45, 45, 10);
                }

/*                if (its.reveal) {
                    if(its.owner() == 1){
                        reveal1.at(index) = true;
                    }else {
                        reveal2.at(index) = true;
                    }
                }

*/
                
                myWin.drawStringFont(120 + 50 * col, 162 + row * 50, target,
                                     "lucidasans-bold-14",Xwindow::White);
                myWin.drawStringFont(120 + 50 * col, 182 + row * 50, str,
                                 "lucidasans-bold-14",Xwindow::White);
       		 if (!its.invisible) {
           		 sleep_for(20ns);
           		 sleep_until(system_clock::now() + 1s);
            		changeActive();
       		 }
            }
            if(its.invisible) {
                if (its.owner == 1){
                    d2[row][col] = '.';
                    myWin.fillRectangle(120 + 50 * row, 150 + col * 50, 45, 45, 5);
                }
                if (its.owner == 2){
                    d1[row][col] = '.';
                    myWin.fillRectangle(120 + 50 * row, 150 + col * 50, 45, 45, 5);
                }
                changeActive();
            }
        
        int ability1 = 5 - p1->getAbility();
        int ability2 = 5 - p2->getAbility();
         for (int i = 0; i < ability1; i++) {
              myWin.fillRectangle(70 + 30 * (5 - i), 102, 15, 15, 0);
         }
         for (int i = 0; i < ability2; i++) {
              myWin.fillRectangle(440 + 30 * (5 - i), 102, 15, 15, 0);
            }
    }
    
}



