#include <bits/stdc++.h>
#include "Car.h"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Car *c = new Car();
    c->setName("BMW");
    std::cout << c->getName() << "\n";

    return 0;
}
