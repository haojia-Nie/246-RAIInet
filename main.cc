
//
//  main.cpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "board.h"

#include "player.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "ability.h"

using namespace std;


class Link;
class Cell;


int main(int argc, const char * argv[]) {
    string cmd;
    string order;
    cin.exceptions(ios::eofbit|ios::failbit);

    Player p1(1);
    Player p2(2);
    bool graphics = false;
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++){
	   string argv_i(argv[i]);
	    if (argv_i == "-graphics"){
                graphics = true;
       	     }
   	}
    }
    Board b{p1, p2, graphics};

    if (argc > 1){
        for (int i = 1; i < argc; i ++){
	    string str(argv[i]);
            if (str == "-link1"){
                i++;
                p1.linkInit(argv[i]);
            }
            else if (str == "-link2"){
                i++;
                p2.linkInit(argv[i]);
            }
            else if (str == "-ability1"){
                i++;
                b.abilityinit(argv[i], 1);
            }
            else if (str == "-ability2"){
                i++;
                b.abilityinit(argv[i], 2);
            }
        }
    
    }
    if (b.gd) {
	    b.gd->graph();
    }
    // Add code here
    try {
        while (true) {
            int m = 0;
            int a = 0;
            cin >> cmd;
            if (cmd == "move"){
                 char link;
                 string dir;
		 cin >> link;
                 cin >> dir;
		if (b.activePlayer == &p1) {
			if (!(link <= 'h' && link >= 'a')) {
				cout << "You may only move your link" << endl;
			}
			else if(b.move(link, dir)){
                    	   if (b.activePlayer == &p1) {
                            	b.setActive(&p2);
                   	   }else {
                                b.setActive(&p1);
                           }
              		 }
               }
		else if (b.activePlayer == &p2) {
			if (!(link <= 'H' && link >= 'A')) {
				cout << "You may only move your link" << endl;
			}
			else if(b.move(link, dir)){
                            if (b.activePlayer == &p1) {
                              b.setActive(&p2);
                             }else {
                              b.setActive(&p1);
                             }
                        }
               }
	    }
            else if (cmd == "abilities"){
               int i = 1;
	       if (b.activePlayer == &p1) {
		       cout << "Player 1:" << endl;
	       }else {
		       cout << "Player 2:" << endl;
	       }
                for(auto ab: b.activePlayer->abilities) {

                    cout << "Ability "<< i << ": " << ab->getName() ;

                    if(ab->getUsed()){
                        cout << "  used" << endl;
                    }else {
                        cout << "  availiable" << endl;
                    }
                    i ++;
                }
		

            }
            else if (cmd == "ability"){
                int idNum;
                cin >> idNum;
                if (b.activePlayer->abilities[idNum]->getUsed()) {
                    cout << "This ability is used already" << endl;
                }

                else {
                    if (b.activePlayer->abilities[idNum]->getName() == 'F') {
                        int row, col;
                        cin >> row;
                        cin >> col;
                        if (b.addFirewall(b.activePlayer->getName(), row, col)){
                            b.activePlayer->abilities[idNum]->setUsed(true);
			    b.activePlayer->useAbility();
                            a++;
                        }
                    }
                    else{
                        char target;
                        cin >> target;
                        if (b.findLink(target)->getDownload()){
                            cout << "This target has been downloaded, please pick another one" << endl;
                        }
                        else if (b.activePlayer->abilities[idNum]->use(b.findLink(target))){
                            a++;
                            b.activePlayer->abilities[idNum]->setUsed(true);
			    b.activePlayer->useAbility();
                            if (b.activePlayer->abilities[idNum]->getName() == 'D') {
                                if (b.findLink(target)->getDownload()) {
                                b.download(b.findLink(target), b.activePlayer->getName());
                                }
                            }
                        }
                    }
                }
            }

            else if (cmd == "board") {
	    	    b.td.print(b.activePlayer->getName());
		    //b.print();
            }

            else if (cmd == "sequence"){
                string filename;
                cin >> filename;
                ifstream file;
                file.open(filename);
                string item;

                while (file >> item){
                    int m = 0;
                    int a = 0;
                    if (item == "move"){
                        char link;
                        string dir;
                        file >> link;
                        file >> dir;
			if (b.activePlayer == &p1) {
				if (!(link <= 'h' && link >= 'a')) {
					cout << "You may only move your link" << endl;
				}
			}else if (b.activePlayer == &p2) {
				if (!(link <= 'H' && link >= 'A')) {
					cout << "You may only move your link" << endl;
				}
			}

                        if(b.move(link, dir)){
                            if (b.activePlayer == &p1) {
                                b.setActive(&p2);
                            }else {
                                b.setActive(&p1);
                            }
                        }
                    }

                    else if (cmd == "abilities"){
			
	       if (b.activePlayer == &p1) {
		       cout << "Player 1:" << endl;
	       }else {
		       cout << "Player 2:" << endl;
	       }
               		int i = 1;
               		 for(auto ab: b.activePlayer->abilities) {

                    	cout << "Ability "<< i << ": " << ab->getName() ;

                    	if(ab->getUsed()){
                        	cout << "  used" << endl;
                   	 }else {
                        	cout << "  availiable" << endl;
                   	 }
                   	 i ++;
                  	 
			 }
		    }
                    else if (item == "ability"){
                        int idNum;
			string num;
			file >> num;
			istringstream ss (num);
                        ss  >> idNum;
                        if (b.activePlayer->abilities[idNum]->getUsed()) {
                            cout << "This ability is used already" << endl;
                        }

                        else {
                            if (b.activePlayer->abilities[idNum]->getName() == 'F') {
                                int row, col;
				string rowS, colS;
				file >> rowS ;
				file >> colS;
				istringstream ssR(rowS);
				istringstream ssC(colS);
				ssR >> row;
				ssC >> col;
                                if (b.addFirewall(b.activePlayer->getName(), row, col)){
                                    b.activePlayer->abilities[idNum]->setUsed(true);
                        b.activePlayer->useAbility();
                                    a++;
                                }
                            }
                            else{
                                char target;
                                file >> target;
                                if (b.findLink(target)->getDownload()){
                                    cout << "This target has been downloaded, please pick another one" << endl;
                                }
                                else if (b.activePlayer->abilities[idNum]->use(b.findLink(target))){
                                    a++;
                                    b.activePlayer->abilities[idNum]->setUsed(true);
                        b.activePlayer->useAbility();
                                    if (b.activePlayer->abilities[idNum]->getName() == 'D') {
                                        if (b.findLink(target)->getDownload()) {
                                        b.download(b.findLink(target), b.activePlayer->getName());
                                        }
                                    }
                                }
                            }
                        }
                    //b.td.print(b.activePlayer->getName());
                    }
                    else if (item == "quit"){
                        return 0;
                    }
            	    else if (item == "board") {
	    	    	b.td.print(b.activePlayer->getName());
		    //b.print();
            	    }
                }
//                return 0;
            }

            else if (cmd == "quit"){
                return 0;
            }

            else if (cmd == "swap") {
                b.swap();
            }
        }
    }
    catch (ios::failure &) {
        cout << "Invalid Input" << endl;
    }  // Any I/O failure quits


    return 0;
}


