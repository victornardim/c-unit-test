#include <stdbool.h>

#ifndef IEXAMPLE_H
#define IEXAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
bool isEven(int number);
char* getNumberName(int number);

#ifdef __cplusplus
}
#endif

#endif /* IEXAMPLE_H */

