//
// Created by 1 on 22.02.2022.
//

#ifndef ROGUELIKE_ICOMMAND_H
#define ROGUELIKE_ICOMMAND_H

class ICommand{
public:
    virtual void Execute()=0;
    virtual ~ICommand()=0;
};

#endif //ROGUELIKE_ICOMMAND_H
