
#ifndef textdisplay_h
#define textdisplay_h


#include "observer.h"
#include "player.h"

class TextDisplay: public Observer<Info>{
  std::vector<std::vector<char>> Display;
    std::vector<std::vector<char>> d1;
    std::vector<std::vector<char>> d2;

    Player* p1;
    Player* p2;
    public:
const int gridSize = 8;
    
    TextDisplay(Player* p1, Player* p2);
    void notify(Subject<Info>& whofrom) override;
    void print(int activeplayer);
    Player* getP1();
    Player* getP2();
};


#endif /* display_h */
