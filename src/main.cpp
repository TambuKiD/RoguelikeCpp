//#include <stl>
#include <BearLibTerminal.h>
#include <iostream>
#include "GameObject.h"
#include "MovableObject.h"
#include "Character.h"
#include "Hero.h"
#include "ActionAnalyzer.h"

#include "LevelMap.h"


int main(){
    const int screen_x=81;
    const int screen_y=16;

    terminal_open();
    const string preSetup = "window.size="+std::to_string(screen_x)+"x"+std::to_string(screen_y);
    terminal_set(preSetup.c_str());
    //terminal_set("window.size=81x31");
    terminal_refresh();


    LevelMap testMap = LevelMap();
    ActionAnalyzer act = ActionAnalyzer(screen_x,screen_y, &testMap);//TODO Возможно правильнее передавать карту не через конструктор, а только ссылкой, при вызове метода

    Coordinates heroCoord={screen_x/2,screen_y/2};
    Hero hero = Hero(heroCoord);

    while(true){
        terminal_clear();
        if(terminal_has_input()){
            int event = terminal_read();
            //TODO main cycle
            //hero.Interact(event);
            act.Move(event,hero);

            /*if(event==TK_Q){
                terminal_clear();
                terminal_refresh();
                testMap.DrawMap();
                //hero.Draw();
                char a = getchar();
                //continue;
            }*/
            //TODO end of cycle
            if ((event==TK_ESCAPE)||(event==TK_CLOSE)){
                std::cout<<"Game end."<<std::endl;
                break;
            }//Переход к закрытию программы (escape, либо нажатие на крестик)
        }

        //Объекты отрисовываются здесь
        testMap.DrawMap();//Process finished with exit code -1073741819 (0xC0000005)
        hero.Draw();
        hero.DrawCounters(screen_x,screen_y);

        //Конец блока отрисовки
        terminal_refresh();
    }
    terminal_close();
    return 0;
}
