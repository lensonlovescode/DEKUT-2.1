#include <iostream>
void zakine() {
    int k;

    auto ravine = [&]() {
        std::cout << "Value of k in ravine: " << k << std::endl;
    };

    auto zarine = [&]() {
        int k;
        k = 5;
        auto kanene = [&](auto kanana) {
            int k;
            k = 7;
            kanana();
        };

        kanene(ravine);
    };

    k = 9;
    zarine();
}
int main() {
    zakine();
    return 0;
}

