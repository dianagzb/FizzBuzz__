#include <iostream>
#include <string>

void fizzBuzz(int f, int b, int t) {
    int fizzCount = 0;
    int buzzCount = 0;

    for (int i = 1; i <= t; ++i) {
        std::string output = "";
        if (i % f == 0) {
            fizzCount++;
            if (i > 1 && i - 1 % f == 0) {
                output += "+";
            } else {
                output += "Fizz";
            }
        }
        if (i % b == 0) {
            buzzCount++;
            if (i > 1 && i - 1 % b == 0) {
                output += "+";
            } else {
                output += "Buzz";
            }
        }
        if (output.empty()) {
            output = std::to_string(i);
            fizzCount = 0;
            buzzCount = 0;
        }
        std::cout << output << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " f b t" << std::endl;
    } else {
        int f = std::stoi(argv[1]);
        int b = std::stoi(argv[2]);
        int t = std::stoi(argv[3]);
        fizzBuzz(f, b, t);
    }
    return 0;
}

//
// Created by Diana Gazenbiller on 06.04.24.
//
