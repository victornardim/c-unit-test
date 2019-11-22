# C Unit Test Library

This is a simple library to make unit tests on your C code.

If you are upset trying to figure out how to setup and code your tests using some framework, this lib is for you! :)

## Getting started

You don't need nothing more than the files located on the 'libraries' folder to start testing.

So, just import these files to your project and let the test-off begin!

## Step-by-step

1. Create a suite
    ```c
    testSuite* suite = test_createSuite("Example test suite");
    ```

2. Code your tests
    ```c
    void testCorrectAddition() {
        test_assertEquals(addition(1, 5), 6);
    }

    void testIncorrectAddition() {
        test_assertNotEquals(addition(2, 17), 10);
    }
    ```

3. Add your tests to the suite
    ```c
    test_addTestToSuite(suite, testIncorrectAddition);
    test_addTestToSuite(suite, testCorrectAddition);
    ```

4. Execute the suite
    ```c
    test_executeSuite(suite);
    ```

5. Destroy the suite
    ```c
    test_destroySuite(suite);
    ```

## Assertions
```c
test_assertTrue(assert);
test_assertFalse(assert);
test_assertEquals(firstData, seccondData);
test_assertNotEquals(firstData, secondData);
test_assertStringEquals(firstString, secondString);
test_assertStringNotEquals(firstString, secondString);
```
