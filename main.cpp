#include <iostream>
#include "message.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Message *message = Message::obtain();

    std::cout << "1 - Sise = " << Message::sPoolSize << std::endl;
    message->recycle();

    std::cout << "2 - Sise = " << Message::sPoolSize << std::endl;

    Message *message2 = Message::obtain();
    std::cout << "3 - Sise = " << Message::sPoolSize << std::endl;

    Message *message3 = Message::obtain();
    message2->recycle();
    std::cout << "4 - Sise = " << Message::sPoolSize << std::endl;

    Message *message4 = Message::obtain();
    std::cout << "5 - Sise = " << Message::sPoolSize << std::endl;

    message4->recycle();
    message3->recycle();
    std::cout << "6 - Sise = " << Message::sPoolSize << std::endl;
    return 0;
}
