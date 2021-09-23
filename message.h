//
// Created by 王诛魔 on 2021/9/22.
//

#ifndef HANDLER_MESSAGE_H
#define HANDLER_MESSAGE_H


#include <mutex>
#include "handler.h"


class Message {
public:
    Message();

    ~Message() = default;

    static Message *obtain();

    void recycle();

    void setAsynchronous(bool async) {
        if (async) {
            flag |= FLAG_ASYNCHRONOUS;
        } else {
            flag &= ~FLAG_ASYNCHRONOUS;
        }
    }

    bool isInUse() {
        return ((flag & FLAG_IN_USE) == FLAG_IN_USE);
    }

    void markInUse() {
        flag |= FLAG_IN_USE;
    }

public:
    int what;
    int flag;
    long when;
    Handler *target;
    Message *next;
    static Message *sPools;
    static int sPoolSize;
    static std::mutex sPoolSync;

private:
    // Max pool size
    const static int MAX_POOL_SIZE = 50;
    // If set message is in use.
    const static int FLAG_IN_USE = 1 << 0;
    // If set message is asynchronous
    const static int FLAG_ASYNCHRONOUS = 1 << 1;

};

#endif //HANDLER_MESSAGE_H
