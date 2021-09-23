//
// Created by 王诛魔 on 2021/9/23.
//

#include <thread>
#include "message_queue.h"

std::mutex MessageQueue::sQueueSync;

MessageQueue::MessageQueue(bool quitAllowed) {
    mQuitAllowed = quitAllowed;
    // 创建epoll

}

void MessageQueue::quit(bool safe) {
    if (!mQuitAllowed) {
        throw "Main thread not allowed to quit.";
    }
    std::lock_guard<std::mutex> lockGuard(MessageQueue::sQueueSync);
    if (mQuitting){
        return;
    }
    // 否则，退出即可
}

Message *MessageQueue::next() {
    // 这里我们要实现各种阻塞效果.
    int nextPollTimeoutMillis = 0;
    for (;;){

        // 提供一个阻塞的功能
        pollOnce(nextPollTimeoutMillis);

        std::lock_guard<std::mutex> lockGuard(MessageQueue::sQueueSync);
        const std::time_t now = std::time(NULL);
        Message *msg = mMessages;
        if (msg != nullptr){
            if (now < msg->when){
                nextPollTimeoutMillis = std::max((msg->when - now),LONG_MAX);
            }else{
                mMessages = msg->next;
                msg->next = nullptr;
                msg->markInUse();
                return msg;
            }
        }else{
            nextPollTimeoutMillis = -1;
        }

        // 终止
        if (mQuitting){
            dispose();
            return nullptr;
        }
    }
}

void MessageQueue::dispose() {

}

void MessageQueue::pollOnce(long millis) {
    std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* ptm = std::localtime(&tt);

    ptm->tm_sec++;
    std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(mktime(ptm)));
}
