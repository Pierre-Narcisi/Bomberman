#include <iostream>
#include "Event/Event.hpp"

int main()
{
    evt::Event  evt;

    auto &a = evt.addHandler<void, int>([] (int a) {
        std::cout << "Ah." << std::endl;
        return (a);
    });

    auto &b = evt.addHandler<int, int>([] (int a) -> int {
        std::cout << "Bh." << std::endl;
        return (a);
    });

    a();
    (void) b;

    
    evt.fire(32);
    auto res = evt.fire<int, int>(32);
    std::cout << (*res)[0] << std::endl;
    return (0);
}
