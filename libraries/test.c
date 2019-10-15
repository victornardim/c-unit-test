#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "iTest.h"
#include "iString.h"
#include "iArray.h"

#define ADDRESS_SIZE 8

static int errors = 0;

testSuite* test_createSuite(char* name) {
    testSuite* newSuite = malloc(sizeof(testSuite));
    newSuite->name = string_allocateFromBuffer(name);
    newSuite->tests = array_create(ADDRESS_SIZE);

    return newSuite;
}

void test_destroySuite(testSuite* suite) {
    free(suite->name);
    array_destroy(suite->tests);
    free(suite);
}

void test_addTestToSuite(testSuite* suite, testFunction test) {
    array_push(suite->tests, &test);
}

static void logSuiteStart(char* suiteName) {
    printf("\nExecuting suite '%s'...", suiteName);
}

static void logSuiteEnd(char* suiteName, float duration, int passedTests, int testQuantity) {
    printf("\nSuite '%s' finished in %.2fs!", suiteName, duration);
    printf("\n%d/%d (%d%%) of the tests have passed.\n", passedTests, testQuantity, (passedTests * 100 / testQuantity));
}

void test_executeSuite(testSuite* suite) {
    time_t start, end;
    time(&start);

    logSuiteStart(suite->name);

    int testQuantity = array_size(suite->tests);
    while(array_size(suite->tests) > 0) {
        void* functionPointer = array_pop(suite->tests);
        testFunction function = *(testFunction*)functionPointer;
        function();
        free(functionPointer);
    }

    int passedTests = (testQuantity - errors);

    time(&end);

    logSuiteEnd(suite->name, (float)(end - start), passedTests, testQuantity);

    errors = 0;
}

void test_reportError() {
    errors++;
}
