//
// Created by 1 on 24.07.2021.
//

#ifndef ROGUELIKE_MOVABLEOBJECT_H
#define ROGUELIKE_MOVABLEOBJECT_H
#include "GameObject.h"
#include <iostream>


struct Coordinates{
    int x;
    int y;
    friend Coordinates operator+(const Coordinates& l,const Coordinates& r){
        return {l.x+r.x,l.y+r.y};
    }
    Coordinates operator+=(const Coordinates& rhs){
        //const Coordinates lhs = *this;
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};




class MovableObject: GameObject { //Возможно, имеет смысл заменить public на protected
protected:
    Coordinates coord_;
public:
    virtual void Move(const int& way)=0;
    Coordinates GetCoord(){
        return coord_;
    }
    void SetDeltaCoord(Coordinates deltaCoord){
        //if(coord_.x + deltaCoord.x>0) {
            coord_.x += deltaCoord.x;
        //}
        //if(coord_.y + deltaCoord.y>0) {
            coord_.y += deltaCoord.y;
        //std::cout<<"Current pos is: ("<<coord_.x<<"x"<<coord_.y<<')'<<std::endl;
        //}
    }
    void SetCoord(Coordinates newCoord){
        if((newCoord.x>0)&&(newCoord.y>0)){
            coord_=newCoord;
        }
    }
};


#endif //ROGUELIKE_MOVABLEOBJECT_H
