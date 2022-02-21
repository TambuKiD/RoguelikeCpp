//
// Created by 1 on 21.08.2021.
//

#ifndef ROGUELIKE_LEVELMAP_H
#define ROGUELIKE_LEVELMAP_H
#include "MovableObject.h"
//#include <string>
#include "BearLibTerminal.h"

/*
 *  '#' - wall
 *  '.' - floor
 *  '$' - money_
 *  '~' - water?
 */

class LevelMap {
protected:
    unsigned int x_size_=8;
    unsigned int y_size_=6;
    char lMap[6][8]= {
            { '.', '.', '#', '.', '#', '.', '.', '$' },
            { '#', '#', '#', '.', '#', '#', '#', '.' },
            { '#', '.', '.', '.', '.', '$', '#', '.' },
            { '#', '.', '.', '~', '.', '.', '.', '.' },
            { '#', '.', '.', '.', '.', '.', '#', '.' },
            { '#', '#', '#', '#', '#', '#', '#', '.' }
    };//Как привязать 6 и 7 к x_size_ (выдаёт: "Invalid use of non-static data member 'y_size_'")



public:
    LevelMap(){}//Должен будет принимать как минимум x_size_ и y_size_

/*
 * '.' - Есть проход
 * '1' - Нет прохода
 * '2' - Монета
 *
    string CheckMap(Coordinates coord){
        char smb = GetSymb(coord);
        if(smb!='.'){
            //return 1;
        }
    }
*/

    char GetSymb(Coordinates coord){
        if((coord.x<x_size_)&&(coord.y<y_size_)) {
            return lMap[coord.y][coord.x];
        }
        else{return '!';}
    }

    void DrawMap (){
        for(int i = 0; i<y_size_;i++){
            for(int j=0;j<x_size_;j++){
                switch (lMap[i][j]) {
                    case '#':
                        terminal_color(color_from_name("grey"));
                        break;
                    case '~':
                        terminal_color(color_from_name("blue"));
                        break;
                    default:
                        terminal_color(color_from_name("white"));
                }
                terminal_put(j,i,lMap[i][j]);
                terminal_color(color_from_name("white"));
            }
        }
    }

    void DeleteMoney(Coordinates coord){
        if(lMap[coord.y][coord.x]=='$'){
            lMap[coord.y][coord.x]='.';
        }
        cout<<"$ deleted"<<endl;
        DrawMap();
    }
};


#endif //ROGUELIKE_LEVELMAP_H
