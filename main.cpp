#include <iostream>
#include "looper.h"


int main() {
    Looper::prepareMainLooper();
    Looper* lp = reinterpret_cast<Looper *>(Looper::myLooper);
    lp->loop();
    std::cout << "Thread : " << lp->isCurrentThread() << std::endl;
    return 0;
}
