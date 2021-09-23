//
// Created by 王诛魔 on 2021/9/23.
//

#include "looper.h"
#include "message.h"

thread_local Looper *Looper::sThreadLocal = nullptr;
std::mutex Looper::sLooperSync;
Looper *Looper::sMainLooper;


Looper::Looper(bool quitAllowed) {
    mQueue = new MessageQueue(quitAllowed);
    // 记录用于对比执行的Thread,isCurrentThread
    mThread = std::this_thread::get_id();
}

void Looper::prepare() {
    prepare(true);
}

void Looper::prepare(bool quitAllowed) {
    if (Looper::sThreadLocal != nullptr) {
        throw "Only one Looper may be created per thread";
    }
    auto *looper = new Looper(quitAllowed);
    Looper::sThreadLocal = looper;
}

void Looper::prepareMainLooper() {
    // 主线程不允许退出
    prepare(false);
    // 获取
    std::lock_guard<std::mutex> lockGuard(Looper::sLooperSync);
    if (sMainLooper != nullptr) {
        throw "The main Looper has already been prepared.";
    }
    sMainLooper = myLooper();
}

void Looper::loop() {
    // get self
    Looper *loop = myLooper();
    if (loop == nullptr) {
        throw "No Looper; Looper.prepare()....";
    }

    // get
    loop->loopRun = false;
    MessageQueue *mq = loop->mQueue;
    for (;;) {
        Message *msg = mq->next();
        if (msg == nullptr) {
            // quit -> exit
            return;
        }

        // 执行消息
        msg->target->dispatchMessage(msg);

        // recycle
        msg->recycle();
    }
}



