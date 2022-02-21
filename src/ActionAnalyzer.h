//
// Created by 1 on 20.08.2021.
//

#ifndef ROGUELIKE_ACTIONANALYZER_H
#define ROGUELIKE_ACTIONANALYZER_H

#include <BearLibTerminal.h>
#include "Hero.h"
#include "LevelMap.h"
//#include <iostream> //TODO delete this later

class ActionAnalyzer {
private:
    int screen_Size_x_;
    int screen_Size_y_;
    LevelMap* lmap_;
public:
    ActionAnalyzer(int screen_x, int screen_y, LevelMap* levelMap): screen_Size_x_(screen_x), screen_Size_y_(screen_y), lmap_(levelMap){}

    void Move(const int event, /*const*/Hero& hero){
        if ((event == TK_LEFT) || (event == TK_RIGHT) || (event == TK_UP) || (event == TK_DOWN)) {
            switch (event) {
                case TK_LEFT:
                    if(CheckCoord(hero.GetCoord(),{-1,0})) {
                        hero.SetDeltaCoord({-1, 0});
                        SymbAnalyze(hero);
                        hero.SetDeltaSteps(1);
                    }
                    break;
                case TK_RIGHT:
                    if(CheckCoord(hero.GetCoord(),{+1,0})) {
                        hero.SetDeltaCoord({+1, 0});
                        SymbAnalyze(hero);
                        hero.SetDeltaSteps(1);
                    }
                    break;
                case TK_UP:
                    if(CheckCoord(hero.GetCoord(),{0, -1})) {
                        hero.SetDeltaCoord({0, -1});
                        SymbAnalyze(hero);
                        hero.SetDeltaSteps(1);
                    }
                    break;
                case TK_DOWN:
                    if(CheckCoord(hero.GetCoord(),{0, +1})) {
                        hero.SetDeltaCoord({0, +1});
                        SymbAnalyze(hero);
                        hero.SetDeltaSteps(1);
                    }
                    break;
            }
            //TODO Столкновения со стенами
        }//TODO другие опции взаимодействия
        /*else{

        }*/
    }

    bool CheckCoord(/*Map& map,*/ Coordinates coord, Coordinates deltaCoord){
        //coord.x+=deltaCoord.x;
        //coord.y+=deltaCoord.y;
        coord=coord+deltaCoord;
        if((coord.x>=0)&&(coord.x<screen_Size_x_) && (coord.y>=0)&&(coord.y<screen_Size_y_)){
            char smb = lmap_->GetSymb(coord);
            if((smb != '#')&&(smb !='~')) {
                return true;
            }
            else{return false;}
        }
        else{
            //std::cout<<"Wrong movement"<<std::endl;
            return false;
        }
    }

    void SymbAnalyze(Hero& hero){
        char smb = lmap_->GetSymb(hero.GetCoord());
        switch(smb){
            case '#':
                break;
            case '.':
                break;
            case '$':
                hero.SetDeltaMoney(1);
                lmap_->DeleteMoney(hero.GetCoord());
                break;
            case '~':
                break;
        }
    }

};


#endif //ROGUELIKE_ACTIONANALYZER_H
