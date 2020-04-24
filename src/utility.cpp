#include "utility.h"
#include <iostream>
#include <climits>
#include <thread>
#include <math.h>
#include <random>

namespace utility {

    int integer_input () {
        int input = 0;

        std::cin >> input;
        while (!std::cin) {
            std::cout << "Bad value!";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input;
        }

        return input;
    }

    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    int random_bounded (int minimum, int maximum) {
        std::uniform_int_distribution<int> distribution{minimum, maximum};
        return distribution(mersenne);
    }
}
