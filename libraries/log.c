#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#include "iLog.h"
#include "iString.h"

#define STRING_SIZE 150

char* log_getTimestamp(){
    char* timestamp = string_allocateFromLength(50);

    time_t now = time(NULL);
    struct tm* timeStruct = localtime(&now);

    strftime(timestamp, 50, "%d/%m/%Y %T", timeStruct); //Format [dd/mm/yyyy hh:mm:ss]

    return timestamp;
}

char* log_getPatternedString(char* pattern, int argsCount, ...) {
    va_list args;
    va_start(args, argsCount);

    char* message = string_allocateFromLength(STRING_SIZE);
    vsnprintf(message, STRING_SIZE, pattern, args);

    va_end(args);

    return message;
}
