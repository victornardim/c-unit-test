#include <stdio.h>
#include <stdlib.h>

#include "iExample.h"
#include "iTest.h"

void testCorrectAddition() {
    test_assertEquals(addition(1, 5), 6);
}

void testIncorrectAddition() {
    test_assertNotEquals(addition(2, 17), 10);
}

void testCorrectSubtraction() {
    test_assertEquals(subtraction(10, 2), 8);
}

void testIncorrectSubtraction() {
    test_assertNotEquals(subtraction(17, 8), 5);
}

void testCorrectMultiplication() {
    test_assertEquals(multiplication(5, 6), 30);
}

void testIncorrectMultiplication() {
    test_assertNotEquals(multiplication(2, 8), 14);
}

void testCorrectDivision() {
    test_assertEquals(division(20, 5), 4);
}

void testIncorrectDivision() {
    test_assertNotEquals(division(12, 6), 3);
}

void testIsEvenWithEvenNumber() {
    test_assertTrue(isEven(18));
}

void testIsEvenWithOddNumber() {
    test_assertFalse(isEven(29));
}

void testGetSupportedNumberName() {
    test_assertStringEquals(getNumberName(5), "five");
}

void testGetNotSupportedNumberName() {
    test_assertStringEquals(getNumberName(11), "not supported");
}

void testGetIncorrectNumberName() {
    test_assertStringNotEquals(getNumberName(7), "nine");
}

void executeExampleTests() {
    testSuite* suite = test_createSuite("Example test suite");
    test_addTestToSuite(suite, testGetIncorrectNumberName);
    test_addTestToSuite(suite, testGetNotSupportedNumberName);
    test_addTestToSuite(suite, testGetSupportedNumberName);
    test_addTestToSuite(suite, testIsEvenWithOddNumber);
    test_addTestToSuite(suite, testIsEvenWithEvenNumber);
    test_addTestToSuite(suite, testIncorrectDivision);
    test_addTestToSuite(suite, testCorrectDivision);
    test_addTestToSuite(suite, testIncorrectMultiplication);
    test_addTestToSuite(suite, testCorrectMultiplication);
    test_addTestToSuite(suite, testIncorrectSubtraction);
    test_addTestToSuite(suite, testCorrectSubtraction);
    test_addTestToSuite(suite, testIncorrectAddition);
    test_addTestToSuite(suite, testCorrectAddition);
    test_executeSuite(suite);
    test_destroySuite(suite);

    return (EXIT_SUCCESS);
}

int main(int argc, char** argv) {
    executeExampleTests();
}
