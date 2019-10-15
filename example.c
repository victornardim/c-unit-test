#include <stdio.h>
#include <stdbool.h>

#include "iExample.h"
#include "iString.h"

int addition(int a, int b) {
    return a + b;
}

int subtraction(int a, int b) {
    return a - b;
}

int multiplication(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if(b == 0) fprintf(stderr, "ERROR! Divide by zero!");
    return a / b;
}

bool isEven(int number) {
    return (number % 2 == 0);
}

char* getNumberName(int number) {
    char* name[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if(number < 0 || number > 9)
        return "not supported";

    return name[number];
}
