#include <iostream>
#include "binaerer_suchbaum.h"
using namespace suchbaum;
int main() {
    BaumKnoten *test = new BaumKnoten;
    test = nullptr;
    einfuegen(test, 12);
    std::cout<<"Das ist ein Test: "<<test->data<<std::endl;
    return 0;
}