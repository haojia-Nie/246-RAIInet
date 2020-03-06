//
//  board.hpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#ifndef board_h
#define board_h

#include <iostream>
#include <vector>
#include <string>

#include "link.h"
#include "player.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "cell.h"
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "info.h"

class Board : public Observer<Info> {
public:
    std::vector<std::vector<Cell*>> grid;
    Player& p1;
    Player& p2;
    Player* activePlayer;
    Player* nonActivePlayer;
    
    int p1A = 5;
    int p2A = 5;
    
    std::vector<Ability*> a1;
    std::vector<Ability*> a2;
    std::vector<Link> links1;
    std::vector<Link> links2;
    std::vector<Link> servers;
    TextDisplay td;
    GraphicsDisplay * gd = nullptr;
    
public:
    void abilityinit(std::string, int owner);
    bool move(char name, std::string direc);
    std::vector<std::vector<Cell*>> getGrid();
    Board(Player& p1, Player& p2, bool graphics);
    TextDisplay& getTd();
    void setActive(Player * active);
//    GraphicsDisplay& getGd();
    void notify(Subject<Info>& whofrom) override;
    ~Board();
    void swap();
    Link* findLink(char name);
    void print();
    void download(Link* link, int player);
    bool addFirewall(int player, int row, int col);
};




#endif /* board_h */
