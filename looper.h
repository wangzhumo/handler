//
// Created by 王诛魔 on 2021/9/23.
//

#ifndef HANDLER_LOOPER_H
#define HANDLER_LOOPER_H

#include <thread>
#include "message_queue.h"
#include <exception>

class Looper {
public:
    // 自己所在线程的副本
    static thread_local Looper* sThreadLocal;
    // 主进程
    static Looper *sMainLooper;
    // lock
    static std::mutex sLooperSync;
private:
    // 当前持有的MessageQueue
    MessageQueue *mQueue;
    // 当前所在的Thread
    std::__thread_id mThread;
    // run?
    bool loopRun;

public:
    void prepare();
    void prepareMainLooper();
    void prepare(bool quitAllowed);

    // 获取当前线程的自己
    static Looper* myLooper() {
        return sThreadLocal;
    }

    void quit(){
        mQueue->quit(false);
    }

    void quitSafely(){
        mQueue->quit(true);
    }

    static void loop();

private:
    Looper(bool quitAllowed);

    ~Looper() = default;
};


#endif //HANDLER_LOOPER_H
