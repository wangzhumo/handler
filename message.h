//
// Created by 王诛魔 on 2021/9/22.
//

#ifndef HANDLER_MESSAGE_H
#define HANDLER_MESSAGE_H


#include "handler.h"

class Message {
public:
    Message();
    ~Message();

    Message obtain();

    Message recycle();

public:
    int what;
    long when;
    Handler target;
    Message* next;
    static Message *sPools;

};


#endif //HANDLER_MESSAGE_H
