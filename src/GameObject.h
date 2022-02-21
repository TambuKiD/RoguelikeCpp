#include <string>
//#include <iostream>
#ifndef ROGUELIKE_GAMEOBJECT_H
#define ROGUELIKE_GAMEOBJECT_H

using namespace std;

class GameObject {
private:
    string name;
    //int id;
public:
    virtual string GetName()=0;
    //virtual ~GameObject()=0;

};


#endif //ROGUELIKE_GAMEOBJECT_H
