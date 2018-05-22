#include <iostream>
#include "Manager/Manager.hpp"
#include "HdlCollector/HdlCollector.hpp"

class A
{
public:
    A()
    {
        auto &manager = evt::Manager::get();

        collector << manager["Salut"]->addHandler<>([] {
            std::cout << "Je suis dans A" << std::endl;
        });
    }
private:
    evt::HdlCollector   collector;
};

void    testTemplateManager()
{
    auto &a = evt::BasicManager<int>::get();

    a[12]->addHandler<>([] {
        std::cout << "héhé" << std::endl;
    });

    a[12]->fire();
}

int main()
{
    auto &manager = evt::Manager::get();

    manager["Salut"]->addHandler<>([] {
        std::cout << "Je suis dans main()" << std::endl;
    });

    auto a = new A();
    manager["Salut"]->fire();

    std::cout << std::endl;
    delete a;
    manager["Salut"]->fire();

    testTemplateManager();
    return (0);
}
