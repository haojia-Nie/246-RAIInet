
#ifndef ability_h
#define ability_h

#include <vector>
#include <string>
//#include "cell.h"
//#include "board.h"
//#include "link.h"
class Link;


class Ability{
    bool used = false;
    int owner;
    char name;
    

public:
    virtual bool use(Link * target) = 0;
    Ability(int owner, char name);
    bool getUsed();
    void setUsed(bool set);
    int getOwner();
    char getName();
};

class ExtraRound: public Ability {
public:
    ExtraRound(int owner, char name): Ability{owner, name}{}
    bool use(Link * target);
};

class FireWall: public Ability {
public:
    FireWall(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};

class LinkBoost : public Ability{
public:
    LinkBoost(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};

class Polarize : public Ability{
public:
    Polarize(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};

class Scan : public Ability{
public:
    Scan(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};

class Download : public Ability{
public:
    Download(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};

class Reinforce : public Ability{
public:
    Reinforce(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};

class Magicshield : public Ability{
public:
    Magicshield(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};

class Invisible : public Ability{
public:
    Invisible(int owner, char name): Ability{owner, name} {}
    bool use(Link * target);
};


#endif /* ability_h */
