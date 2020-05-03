#ifndef graphicsdisplay_h
#define graphicsdisplay_h


#include <iostream>
#include <vector>
#include "observer.h"
#include "info.h"
#include "window.h"
#include "player.h"

class Cell;
class Xwindow;


class GraphicsDisplay:public Observer<Info>{
    std::vector<std::vector<char>> Display;
    std::vector<std::vector<char>> d1;
    std::vector<std::vector<char>> d2;
    std::vector<char> type1;
    std::vector<char> type2;
    std::vector<int> attack1;
    std::vector<int> attack2;
    std::vector<char> ability1;
    std::vector<char> ability2;
    std::vector<bool> reveal1;
    std::vector<bool> reveal2;
    Player * active;
    
    Player *p1;
    Player *p2;
    Xwindow myWin;
    public:
    void changeActive();
    ~GraphicsDisplay();
    void graph();
    GraphicsDisplay(Player * p1, Player * p2);

    void notify(Subject<Info> &whoFrom) override;
    
};


#endif /* graphicsdisplay_h */

