#include <stdarg.h>

#ifndef ILOG_H
#define ILOG_H

#ifdef __cplusplus
extern "C" {
#endif

#define log_success(message) char* timestamp = log_getTimestamp(); printf("\n[%s] {SUCCESS}: %s", timestamp, message); free(timestamp);
#define log_error(message) char* timestamp = log_getTimestamp(); printf("\n[%s] {ERROR}: %s", timestamp, message); free(timestamp);
#define log_message(message) char* timestamp = log_getTimestamp(); printf("\n[%s]: %s", timestamp, message); free(timestamp);

char* log_getTimestamp();
char* log_getPatternedString(char* pattern, int argsCount, ...);

#ifdef __cplusplus
}
#endif

#endif /* ILOG_H */

