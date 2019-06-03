/*
 * logging.h
 *
 *  Created on: May 26, 2019
 *      Author: Ajinkya Kamat
 */

#ifndef MODULES_LOGGING_H_
#define MODULES_LOGGING_H_

void log_initialize();

typedef enum{
  LOG_LEVEL_ERROR = 1,
  LOG_LEVEL_INFO = 2,
}log_level;

/// Logs debug statement. Do not use this function use the macros LOG_ERROR()
/// or LOG_INFO()
/// \param[in] format message to be printed in printf like format
void log_debug(log_level level,
                        const char* file,
                        int line,
                        const char* format, ...);
#define LOG_ERROR(...) log_debug(DEVICE_LOG_LEVEL_ERROR,   \
                                               FILENAME,__LINE__,          \
                                               __VA_ARGS__);
#define LOG_INFO(...) log_debug(DEVICE_LOG_LEVEL_INFO,      \
                                                FILENAME,__LINE__,           \
                                               __VA_ARGS__);

/// Dumps log to the correct interface using the writer function
/// \param[in] writer function pointer to function used to dump log. Use a blocking function
///            that send output via serial or saves to SDCard etc
typedef void (*log_DumpWriter) (char);
void log_dump(log_DumpWriter writer);

#endif /* MODULES_LOGGING_H_ */
