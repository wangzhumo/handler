//
// Created by 王诛魔 on 2021/9/29.
//

#ifndef HANDLER_EVENT_THREAD_H
#define HANDLER_EVENT_THREAD_H
#include <event2/util.h>

class EventThread {
public:
    EventThread();
    ~EventThread() = default;

    // 处理消息
    void eventPollOnce();

    // wake
    void eventWake();

private:
    struct event_base *base;
};


#endif //HANDLER_EVENT_THREAD_H
