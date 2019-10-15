#ifndef IARRAY_H
#define IARRAY_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct array {
    void* data;
    int dataSize;
    size_t length;
    int maxLength;
} typedef array;

array* array_create(int dataSize);
void array_destroy(array* array);
void array_push(array* array, void* data);
void* array_pop(array* array);
void* array_get(array* array, int index);
size_t array_size(array* array);
int array_find(array* array, void* data, size_t dataSize);

#ifdef __cplusplus
}
#endif

#endif /* IARRAY_H */

