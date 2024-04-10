#include <iostream>
#include <string>

using namespace std;

string fizzBuzz(int f, int b, int t) {
    string result;
    string fizzStr = "Fizz";
    string buzzStr = "Buzz";
    bool fizzFlag = false;
    bool buzzFlag = false;
    int fizzCount = 0;
    int buzzCount = 0;

    for (int i = 1; i <= t; ++i) {
        fizzFlag = (i % f == 0);
        buzzFlag = (i % b == 0);

        if (fizzFlag && buzzFlag) {
            result += "FizzBuzz ";
            fizzCount = 0;
            buzzCount = 0;
        } else if (fizzFlag) {
            fizzCount++;
            result += (buzzCount > 0) ? "Fizz+" + to_string(fizzCount) + " " : fizzStr + " ";
            buzzCount = 0;
        } else if (buzzFlag) {
            buzzCount++;
            result += (fizzCount > 0) ? "Buzz+" + to_string(buzzCount) + " " : buzzStr + " ";
            fizzCount = 0;
        } else {
            result += to_string(i) + " ";
            fizzCount = 0;
            buzzCount = 0;
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <f> <b> <t>" << endl;
        return 1;
    }

    int f = stoi(argv[1]);
    int b = stoi(argv[2]);
    int t = stoi(argv[3]);

    cout << fizzBuzz(f, b, t) << endl;

    return 0;
}

