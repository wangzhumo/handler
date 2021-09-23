//
// Created by 王诛魔 on 2021/9/23.
//

#ifndef HANDLER_MESSAGE_QUEUE_H
#define HANDLER_MESSAGE_QUEUE_H


#include "message.h"

class MessageQueue {
public:
    // 初始化自己，epoll
    MessageQueue(bool quitAllowed);

    ~MessageQueue() = default;

    void quit(bool safe);

    Message *next();

private:
    bool mQuitAllowed;
    bool mQuitting;
    Message* mMessages;
};


#endif //HANDLER_MESSAGE_QUEUE_H
