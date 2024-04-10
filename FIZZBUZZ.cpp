#include <iostream>
#include <sstream>

std::string fizzBuzzPlus(int f, int b, int t) {
    std::ostringstream output;
    int fizzCount = 0;
    int buzzCount = 0;

    for (int num = 1; num <= t; ++num) {
        if (num % f == 0 && num % b == 0) {
            output << "FizzBuzz\n";
            fizzCount = 0;
            buzzCount = 0;
        } else if (num % f == 0) {
            fizzCount++;
            output << "Fizz";
            for (int i = 0; i < fizzCount - 1; ++i)
                output << "+";
            output << "\n";
            buzzCount = 0;
        } else if (num % b == 0) {
            buzzCount++;
            output << "Buzz";
            for (int i = 0; i < buzzCount - 1; ++i)
                output << "+";
            output << "\n";
            fizzCount = 0;
        } else {
            output << num << "\n";
        }
    }

    return output.str();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <f> <b> <t>\n";
        return 1;
    }

    int f, b, t;
    try {
        f = std::stoi(argv[1]);
        b = std::stoi(argv[2]);
        t = std::stoi(argv[3]);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Please enter valid integers for f, b, and t.\n";
        return 1;
    }

    if (f <= 0 || b <= 0 || t <= 0) {
        std::cerr << "Error: Please enter positive integers for f, b, and t.\n";
        return 1;
    }

    std::cout << fizzBuzzPlus(f, b, t);

    return 0;
}

//
// Created by Diana Gazenbiller on 10.04.24.
//
