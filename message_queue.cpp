//
// Created by 王诛魔 on 2021/9/23.
//

#include "message_queue.h"

MessageQueue::MessageQueue(bool quitAllowed) {
    mQuitAllowed = quitAllowed;
    // 创建epoll

}

void MessageQueue::quit(bool safe) {

}

Message *MessageQueue::next() {
    return nullptr;
}
