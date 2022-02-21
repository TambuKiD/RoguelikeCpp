#ifndef ROGUELIKE_CHARACTER_H
#define ROGUELIKE_CHARACTER_H

#include <utility>

#include "MovableObject.h"

struct Statline{
    char symbol; //определяет то, как оно отображается в консоли графике
    int action_points; //определяет кол-во очков действия на ход
    int meleeSkill; //шанс(в процентах) на попадание оружием ближнего боя
    int ballisticSkill;
    int intelligence;
    int brave;
    int hp;
};

class Character: public MovableObject {
protected:
    Statline profile_;
    string name;
    //Coordinates coord_;
public:
    Character(){
        Statline profile_ =  {};
        profile_.symbol = '@';
        profile_.action_points = 10;
        profile_.meleeSkill = 60;
        profile_.ballisticSkill = 60;
        profile_.intelligence = 70;
        profile_.brave = 10;
        profile_.hp = 7;
        Coordinates coord_ = {};
        coord_.x = 1;
        coord_.y = 1;
    }
    Character(Coordinates coord){
        coord_=coord;
        Statline profile_ = {};
        profile_.symbol = '@';
        profile_.action_points = 10;
        profile_.meleeSkill = 60;
        profile_.ballisticSkill = 60;
        profile_.intelligence = 70;
        profile_.brave = 10;
        profile_.hp = 7;
    }
    Character(string newName,Statline newProfile, Coordinates coord){
        name=std::move(newName);
        profile_=newProfile;
        coord_=coord;
    }
    //virtual ~Character()=0;//Не нужен ли здесь обычный деструктор, и если нужен, то как быть с деструкторами в классах-наследниках?
    //virtual void Move(int key)=0;
};


#endif //ROGUELIKE_CHARACTER_H
