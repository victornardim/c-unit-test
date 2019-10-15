#include <stdio.h>
#include <stdbool.h>

#ifndef ISTRING_H
#define ISTRING_H

#ifdef __cplusplus
extern "C" {
#endif

    char* string_allocateFromBuffer(const char *buffer);
    char* string_allocateFromLength(size_t size);
    void string_clear(char *string);

    bool string_contains(const char *source, const char *content);
    bool string_equals(const char *source, const char *comparation);
    bool string_isEmpty(const char *string);
    void string_remove(char* source, const char *toRemove);
    bool string_isValidInteger(const char *string);

#ifdef __cplusplus
}
#endif

#endif /* ISTRING_H */

