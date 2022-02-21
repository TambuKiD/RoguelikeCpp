//
// Created by 1 on 27.07.2021.
//

#ifndef ROGUELIKE_HERO_H
#define ROGUELIKE_HERO_H
#include <string>
#include "Character.h"
#include <BearLibTerminal.h>

using namespace std;

    class Hero : public Character {
    private:
        unsigned int money_;
        unsigned int steps_;
        unsigned int lvl_;
        //Statline profile_;
        //Coordinates coord_;
        //string name= "Hero";
    public:
        explicit Hero() {
            Statline profile_ =  {};
            profile_.symbol = '@';
            profile_.action_points = 10;
            profile_.meleeSkill = 60;
            profile_.ballisticSkill = 60;
            profile_.intelligence = 70;
            profile_.brave = 10;
            profile_.hp = 7;

            lvl_ = 1;
            money_=0;
            steps_ = 0;
            Coordinates coord_ = {};
            coord_.x = 1;
            coord_.y = 1;

            Draw();
        }//default characteristics

        explicit Hero(Coordinates coord) {
            coord_=coord;
            Statline profile_ = {};
            profile_.symbol = '@';
            profile_.action_points = 10;
            profile_.meleeSkill = 60;
            profile_.ballisticSkill = 60;
            profile_.intelligence = 70;
            profile_.brave = 10;
            profile_.hp = 7;

            lvl_=1;
            money_=0;
            steps_ = 0;

            Draw();
        }

        explicit Hero(Statline profile, Coordinates coord){
            profile_=profile;
            coord_=coord;
            lvl_ = 1;
            money_=0;steps_ = 0;


            Draw();
        }

        explicit Hero(Coordinates coord, Statline profile) {
            coord_=coord;
            profile_=profile;

            lvl_=1;
            money_=0;
            steps_ = 0;

            Draw();
        }

        /*~Hero() override {
            //TODO ?
        }*/

        void Move(const int& way) override {
            switch (way) {
                case 1://LEFT
                    coord_.x--;
                    break;
                case 2://RIGHT
                    coord_.x++;
                    break;
                case 3://UP
                    coord_.y--;
                    break;
                case 4://DOWN
                    coord_.y++;
                    break;
            }

            //Draw();
        }//Заглушка, чтобы не было претензий к наследованию

        void SetLevel(unsigned int lvl) {
            lvl_=lvl;
        }

        void Draw(){
            //terminal_color(color_from_argb(1,0,200,74));
            terminal_color(color_from_name("green"));
            terminal_put(coord_.x,coord_.y,'@'/*profile_.symbol*/);
            terminal_color(color_from_name("white"));
        }//отрисовывает
        void DrawCounters(int screen_x, int screen_y){
            Coordinates coord = {screen_x-3,1};
            //string str = to_string(money_);
            terminal_print(coord.x,coord.y,to_string(money_).c_str());
            //str = to_string(steps_).c_str();
            terminal_print(coord.x,coord.y+1,to_string(steps_).c_str());
        }

        std::string GetName() override{
            return name;
        }

        bool SetDeltaMoney(int deltaM){
            if(money_ + deltaM > 0){
                money_ += deltaM;
                return true;
            }
            else{return false;}
        }
        void SetMoney(unsigned int m){
            money_ = m;
        }
        unsigned int GetMoney(){
            return money_;
        }

        bool SetDeltaSteps(int deltaS){
            if(steps_ + deltaS > 0){
                steps_ += deltaS;
                return true;
            }
            else{return false;}
        }
        void SetSteps(unsigned int s){
            steps_ = s;
        }
        unsigned int GetSteps(){
            return steps_;
        }

    };


#endif //ROGUELIKE_HERO_H
