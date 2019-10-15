#ifndef ITEST_H
#define ITEST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "iString.h"
#include "iArray.h"
#include "iLog.h"

#define SECURE_TEST_ATTEMPT_NUMBER 100

#ifdef __cplusplus
extern "C" {
#endif

#define test_log(status, testName, assertType) char* string = log_getPatternedString("%s (%s)", 2, testName, assertType); if(status){ log_success(string); } else { log_error(string); test_reportError();} free(string);
#define test_assertTrue(assert) test_log((assert == true), __func__, "test_assertTrue");
#define test_assertFalse(assert) test_log(assert == false, __func__, "test_assertFalse");
#define test_assertEquals(firstData, secondData) test_log((firstData == secondData), __func__, "test_assertEquals");
#define test_assertNotEquals(firstData, secondData) test_log((firstData != secondData), __func__, "test_assertNotEquals");
#define test_assertStringEquals(firstString, secondString) test_log(string_equals(firstString, secondString), __func__, "test_assertStringEquals");
#define test_assertStringNotEquals(firstString, secondString) test_log(!string_equals(firstString, secondString), __func__, "test_assertStringNotEquals");

typedef void (*testFunction)();

struct testSuite {
    char* name;
    array* tests;
} typedef testSuite;

testSuite* test_createSuite(char* name);
void test_destroySuite(testSuite* suite);
void test_addTestToSuite(testSuite* suite, testFunction test);
void test_executeSuite(testSuite* suite);
void test_reportError();

#ifdef __cplusplus
}
#endif

#endif /* ITEST_H */

