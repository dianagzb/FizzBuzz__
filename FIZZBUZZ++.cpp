#include <cstdio>
#include <cstdlib>
#include <cstring>

// Funktion zur Generierung der FizzBuzz++-Reihe
char* fizzBuzzPlus(int f, int b, int t) {
    char* output = (char*)malloc(t * 10); // Speicher für die Ausgabe reservieren
    int fizzCount = 0;
    int buzzCount = 0;
    char buffer[10];

    output[0] = '\0'; // Ausgabe-String initialisieren

    for (int num = 1; num <= t; ++num) {
        if (num % f == 0 && num % b == 0) {
            snprintf(buffer, sizeof(buffer), "FizzBuzz\n");
            strcat(output, buffer);
            fizzCount = 0;
            buzzCount = 0;
        } else if (num % f == 0) {
            fizzCount++;
            snprintf(buffer, sizeof(buffer), "Fizz");
            for (int i = 0; i < fizzCount - 1; ++i)
                strcat(buffer, "+");
            strcat(buffer, "\n");
            strcat(output, buffer);
            buzzCount = 0;
        } else if (num % b == 0) {
            buzzCount++;
            snprintf(buffer, sizeof(buffer), "Buzz");
            for (int i = 0; i < buzzCount - 1; ++i)
                strcat(buffer, "+");
            strcat(buffer, "\n");
            strcat(output, buffer);
            fizzCount = 0;
        } else {
            snprintf(buffer, sizeof(buffer), "%d\n", num);
            strcat(output, buffer);
        }
    }

    return output;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <f> <b> <t>\n", argv[0]);
        return 1;
    }

    int f, b, t;
    try {
        f = atoi(argv[1]);
        b = atoi(argv[2]);
        t = atoi(argv[3]);
    } catch (...) {
        fprintf(stderr, "Error: Please enter valid integers for f, b, and t.\n");
        return 1;
    }

    if (f <= 0 || b <= 0 || t <= 0) {
        fprintf(stderr, "Error: Please enter positive integers for f, b, and t.\n");
        return 1;
    }

    char* output = fizzBuzzPlus(f, b, t);
    printf("%s", output);
    free(output);

    return 0;
}


//
// Created by Diana Gazenbiller on 10.04.24.
//
