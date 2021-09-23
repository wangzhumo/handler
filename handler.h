//
// Created by 王诛魔 on 2021/9/22.
//

#ifndef HANDLER_HANDLER_H
#define HANDLER_HANDLER_H


#include "message.h"

class Handler {

public:
    void dispatchMessage(Message *pMessage);
};


#endif //HANDLER_HANDLER_H
