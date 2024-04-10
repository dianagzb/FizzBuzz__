#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Verwendung: " << argv[0] << " <f> <b> <t>\n";
        return 1;
    }

    int f = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);
    int t = std::stoi(argv[3]);
    int fizzCount = 0;
    int buzzCount = 0;

    for (int i = 1; i <= t; ++i) {
        bool fizz = (i % f == 0);
        bool buzz = (i % b == 0);
        std::string output = "";

        if (fizz && buzz) {
            output = "FizzBuzz";
            fizzCount = buzzCount = 0;
        } else if (fizz) {
            fizzCount++;
            output = "Fizz";
            if (fizzCount > 1) {
                output += std::string(fizzCount - 1, '+');
            }
            buzzCount = 0;
        } else if (buzz) {
            buzzCount++;
            output = "Buzz";
            if (buzzCount > 1) {
                output += std::string(buzzCount - 1, '+');
            }
            fizzCount = 0;
        } else {
            output = std::to_string(i);
            fizzCount = buzzCount = 0;
        }

        std::cout << output << std::endl;
    }

    return 0;
}


//
// Created by Diana Gazenbiller on 09.04.24.
//
