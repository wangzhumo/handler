//
// Created by 王诛魔 on 2021/9/22.
//

#include "message.h"

Message *Message::sPools = nullptr;
int  Message::sPoolSize = 0;
std::mutex Message::sPoolSync;

Message::Message() {
    flag = 0;
    when = 0;
    when = 0;
    target = nullptr;
    next = nullptr;
}

Message *Message::obtain() {
    std::lock_guard<std::mutex> lockGuard(Message::sPoolSync);
    if (Message::sPools != nullptr) {
        Message *message = Message::sPools;
        Message::sPools = message->next;
        message->next = nullptr;
        message->flag = 0;
        Message::sPoolSize--;
        return message;
    }
    auto *message = new Message();
    return message;
}

void Message::recycle() {
    flag = 0;
    what = 0;
    when = 0;
    target = nullptr;

    std::lock_guard<std::mutex> lockGuard(Message::sPoolSync);
    if (Message::sPoolSize < MAX_POOL_SIZE) {
        next = Message::sPools;
        Message::sPools = this;
        Message::sPoolSize++;
    }
}
