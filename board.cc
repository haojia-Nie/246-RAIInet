//
//  board.cpp
//  a555
//
//  Created by Stellar Pan on 2019-11-22.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#include "board.h"
#include <sstream>
using namespace std;
// get TextDisplay
TextDisplay& Board::getTd(){
    return td;
}
// get GraphicsDisplay
/*GraphicsDisplay& Board::getGd(){
    return gd;
}*/

// get the Grid
std::vector<std::vector<Cell*>> Board::getGrid(){
    return grid;
}
void Board::setActive(Player * active){
	activePlayer = active;
}

void Board::swap(){
    
    if(activePlayer->getName() == 1) {
        activePlayer = &p2;
        nonActivePlayer = &p1;
    }
    else {
        activePlayer = &p1;
        nonActivePlayer = &p2;
    }
}
// Initialize the abilities for the player
void Board::abilityinit(std::string order, int owner){
    
    //check if it for player 1 or player 2

    std::vector<Ability*>& a = a1;
    if(owner == 1){
        a = a1;;
    }
    else if (owner == 2){
        a = a2;;
    }
    a.clear();
    
    
    //read in all the abilities
    for (int i = 0; i < 5; i ++){
        char type = order[i];
        if (type == 'L'){
            LinkBoost* L = new LinkBoost{owner, 'L'};
            a.push_back(L);
        }
        else if (type == 'F'){
            FireWall* F = new FireWall{owner, 'F'};
            a.push_back(F);
        }
        else if (type == 'D'){
            Download* D = new Download{owner, 'D'};
            a.push_back(D);
        }
        else if (type == 'P'){
            Polarize* P = new Polarize{owner, 'P'};
            a.push_back(P);
        }
        else if (type == 'S'){
            Scan* S = new Scan{owner, 'S'};
            a.push_back(S);
        }
        else if (type == 'M'){
            Magicshield* M = new Magicshield{owner, 'M'};
            a.push_back(M);
        }
        
        else if (type == 'I'){
            Invisible* I = new Invisible{owner, 'I'};
            a.push_back(I);
        }
        else if (type == 'R'){
            Reinforce* R = new Reinforce{owner, 'R'};
            a.push_back(R);
        }
        else {
            cout << "This is a invalid ability, please re-enter the abilities you want" << endl;
            a.clear();
            owner = 3;
        }
    }
    if (owner == 1){
        p1.setAbs(a);
    }
    else if (owner == 2){
        p2.setAbs(a);
    }
     
}

// set up the board at the begining of the game;
Board::Board(Player& p1, Player& p2, bool graphics): p1{p1}, p2{p2}, activePlayer{&p1},
	nonActivePlayer{&p2}, td{&p1, &p2}{
    
    
    // set up a 8x8 grid
    grid.clear();
    grid = std::vector<std::vector<Cell*>> (8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Cell* n = new Cell{i, j};
            grid[i].push_back(n);
        }
    }
    
    // set up two vectors of links that are stored in the board
    for(int i = 0; i < 8; i++) {
        if ((i == 3) || (i == 4)) {
            Link a{1, i};
            Link b{6, i};
            links1.push_back(a);
            links2.push_back(b);
        }
        else {
            Link a{0, i};
            Link b{7, i};
            links1.push_back(a);
            links2.push_back(b);
        }
    }
    
    // put links into grid;
    for (auto &lk : links1) {
        grid[lk.getRow()][lk.getCol()]->setContain(&lk);
    }
    for (auto &lk : links2) {
        grid[lk.getRow()][lk.getCol()]->setContain(&lk);
    }
    
    // put server ports as links into grid;
    Link s1{0, 3};
    Link s2{0, 4};
    Link s3{7, 3};
    Link s4{7, 4};
    servers.push_back(s1);
    servers.push_back(s2);
    servers.push_back(s3);
    servers.push_back(s4);
    
    for(int i = 0; i < 4; i ++) {
        if (i < 2) {
            servers[i].init(1, 'S', 100, 'S');
        }
        else {
            servers[i].init(2, 'S', 100, 'S');
        }
    }
    grid[0][3]->setContain(&servers[0]);
    grid[0][4]->setContain(&servers[1]);
    grid[7][3]->setContain(&servers[2]);
    grid[7][4]->setContain(&servers[3]);

    // default links initialize
    char name1[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char name2[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i ++){
        if (i < 4) {
            links1[i].init(1, 'V', i + 1, name1[i]);
            links2[i].init(2, 'V', i + 1, name2[i]);
            
        }else {
            links1[i].init(1, 'D', i - 3, name1[i]);
            links2[i].init(2, 'D', i - 3, name2[i]);
        }
    }
    
    
    // default ability initialize
    LinkBoost* p1L = new LinkBoost{1, 'L'};
    FireWall* p1F = new FireWall{1, 'F'};
    Download* p1D = new Download{1, 'D'};
    Scan* p1S = new Scan{1, 'S'};
    Polarize* p1P = new Polarize{1, 'P'};
    Magicshield* p1M = new Magicshield{1, 'M'};
    Invisible* p1I = new Invisible{1, 'I'};
    a1.push_back(p1L);
    a1.push_back(p1F);
    a1.push_back(p1D);
    a1.push_back(p1S);
    a1.push_back(p1P);
    //a1.push_back(p1M);
    //a1.push_back(p1I);
    
    
    LinkBoost* p2L = new LinkBoost{2, 'L'};
    FireWall* p2F = new FireWall{2, 'F'};
    Download* p2D = new Download{2, 'D'};
    Scan* p2S = new Scan{2, 'S'};
    Polarize* p2P = new Polarize{2, 'P'};
    a2.push_back(p2L);
    a2.push_back(p2F);
    a2.push_back(p2D);
    a2.push_back(p2S);
    a2.push_back(p2P);
    
    // connect links to their player
    for(int i = 0; i < 8; i++){
        p1.links.push_back(&links1[i]);
    }
    for(int i = 0; i < 8; i++){
        p2.links.push_back(&links2[i]);
    }
    
    // connect abilities to their player
    p1.setAbs(a1);
    p2.setAbs(a2);
     
    if (graphics) {
	gd = new GraphicsDisplay{&p1, &p2};
    }
    
    // let the board and textdisplay observe all the links
    for (auto &lk : links1) {
        lk.attach(this);
        lk.attach(&td);
	if (graphics){
		lk.attach(gd);
	}
    }
    for (auto &lk : links2) {
        lk.attach(this);
        lk.attach(&td);
	if (graphics){
		lk.attach(gd);
	}
    }
}

// the board will respond when they get notified
void Board:: notify(Subject<Info>& whofrom){
    
    int newRow = -1;
    int newCol = -1;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            if(grid[i][j]->getContain() == &whofrom){
                
                // if the link is downloaded and no longer on the grid;
                if (grid[i][j]->getContain()->getDownload() == true) {
                    grid[i][i]->setContain(nullptr);
                }
                // if the link move to another cell, the location changes
                else {
                    newRow = grid[i][j]->getContain()->getRow();
                    newCol = grid[i][j]->getContain()->getCol();
                    Link* l = grid[i][j]->getContain();
                    grid[i][j]->setContain(nullptr);
                    grid[newRow][newCol]->setContain(l);
                }
            }
        }
    }
}

// destructor
Board:: ~Board(){
    
     links1.clear();
     links2.clear();
     a1.clear();
     a2.clear();
     servers.clear();
     grid.clear();
     
}

// find the address of a Link that has a specific name
Link* Board:: findLink(char name){
    for (auto &lk : links1) {
        if(lk.getName() == name) {
            return &lk;
        }
    }
    for (auto &lk : links2) {
        if(lk.getName() == name) {
            return &lk;
        }
    }
    return nullptr;
}

// move a link to {direc}
bool Board:: move(char name, string direc) {
    
    Link* link = findLink(name);
    if (!link){
        cout << "Please enter a valid link id" << endl;
        return false;
    }
    int col = link->getCol();
    int row = link->getRow();

    int originCol = link->getCol();
    int originRow = link->getRow();

    if (direc == "up") {
        row -= link->getSpeed();
    }
    else if (direc == "down") {
        row += link->getSpeed();
    }
    else if (direc == "left") {
        col -= link->getSpeed();
    }
    else if (direc == "right") {
        col += link->getSpeed();
    }
    else {
        cout << "Please enter a valid direction (any of up, down, left, right)" << endl;
        return false;
    }
    
    if ((col < 0)||(col > 7)) {
        cout << "You cannot go outside the board!" << endl;
        return false;
    }
    
    if (row <= 7 && row >= 0 && grid[row][col]->getContain()) {
        Link* other = grid[row][col]->getContain();
        
        // check if the user move their link onto his own link;
        if (other->getOwner() == link->getOwner()) {
            if (other->getName() == 'S') {
                cout << "You can not move a link on top of your own server port" << endl;
            	return false;
	        }
            else if (other->getName() == 'm' || other->getName() == 'w'){
                link->setFire(true);
                link->setRow(row);
                link->setCol(col);
                link->notifyObservers();
                return true;                //return true;
            }
            else {
                cout << "You can not move a link on top of your own link" << endl;
		        return false;
            }
        }
        
        // if the user move their link onto the opponent link;
        else {
            if (other->getAttack() > link->getAttack() ||
		other->getFire()) {
                other->setReveal(true);
                link->setReveal(true);
		download(link, other->getOwner());
            }
            else  {
                download(other, link->getOwner());
                link->setRow(row);
                link->setCol(col);
		other->setReveal(true);
                link->setReveal(true);
            }
        }
    }
// if it reaches opponent's edges
    else if ((row < 0)||(row > 7)) {
        if (link->getOwner() == 1 && row > 7){
            download(link, link->getOwner());
        }else if (link->getOwner() == 2 && row < 0){
            download(link, link->getOwner());
        }else{
            cout << "You cannot go outside the board!" << endl;
            return false;
        }
    }
    // if there is no link in the target cell
    else {
        link->setRow(row);
        link->setCol(col);
    }

    link->notifyObservers();
    
    if (link->getFire()){
        addFirewall(link->getOwner(), originRow, originCol);
        link->setFire(false);
    }

    return true;
}

// print the board
void Board:: print(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            if(grid[i][j]->getContain()){
                cout << grid[i][j]->getContain()->getName();
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

// download a link and remove it from the board
void Board:: download(Link* link, int player){
    link->setDownload(true);
    int row = link->getRow();
    int col = link->getCol();
    
    grid[row][col]->setContain(nullptr);
    
    if (link->getType() == 'V') {
        if (player == 1) {
            p1.addVirus(1);
        }
        else {
            p2.addVirus(1);
        }
    }
    else {
        if (player == 1) {
            p1.addData(1);
        }
        else {
            p2.addData(1);
        }
    }
}

// Add a firewall to the grid at [row, col]
bool Board:: addFirewall(int player, int row, int col){
    
    
    if ((row > 7) || (row < 0) || (col > 7) || (col < 0)) {
        cout << "You can not put a firewall outside the board" << endl;
    }
    else if (grid[row][col]->getContain()) {
        cout << "You can not put a firewall here" << endl;
    }
    else {
        Link* firewall = new Link{row, col};
        char name;
        if (player == 1) {
            name = 'm';
        }
        else {
            name = 'w';
        }
        firewall->init(player, 'F', 100, name);
        
        grid[row][col]->setContain(firewall);
	    firewall->attach(gd);
	    firewall->attach(&td);
        firewall->notifyObservers();
        return true;
    }
    return false;
}

