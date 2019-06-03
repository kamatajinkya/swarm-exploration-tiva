/*
 * logging.c
 *
 *  Created on: May 26, 2019
 *      Author: Ajinkya Kamat
 */

#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include "logging.h"

#define LOG_FIFO_SIZE 500

typedef struct{
    char buffer[LOG_FIFO_SIZE];
    unsigned long end;
    unsigned start;
}LogCircularFifo;

static struct{
    LogCircularFifo fifo;
}module;

static void log_logFifoInitialize()
{
    module.fifo.end = 0;
    module.fifo.start = 0;
}

static void log_logFifoEnqueue(const char c)
{
    module.fifo.buffer[module.fifo.end] = c;

    module.fifo.end++;
    module.fifo.end %= LOG_FIFO_SIZE;

    if(module.fifo.start == module.fifo.end)
        module.fifo.start++;
}

static bool log_logFifoDequeue(char *c)
{
    if(module.fifo.end == module.fifo.start)
        return false;

    *c = module.fifo.buffer[module.fifo.start];
    module.fifo.start++;
    module.fifo.start %= LOG_FIFO_SIZE;
    return true;
}

/// Converts log level to string for human readable output
/// \param[in] level Level of log use enums defined
static char* log_convert_log_level_to_string(log_level level)
{
  if(level == LOG_LEVEL_ERROR) return "ERROR";
  if(level == LOG_LEVEL_INFO) return "INFO";

  return "LOG_ERROR";
}

void log_printfString(const char* string)
{
    unsigned long index  = 0;
    while(string[index] != '\0')
    {
        log_logFifoEnqueue(string[index]);
        index++;
    }
}

void log_printfInt(int number)
{
    long base = 1;
    if(number < 0)
    {
        log_logFifoEnqueue('-');
        number *= -1;
    }

    if(number == 0)
    {
        log_logFifoEnqueue('0');
    }

    while((number/base) != 0)
    {
        log_logFifoEnqueue('0' + (char)(number%base));
        base++;
    }
}

void log_initialize()
{
    log_logFifoInitialize();
}

void log_debug(log_level level,
                        const char* file,
                        int line,
                        const char* format, ...)
{
  log_printfString(file);
  log_printfString(":");
  log_printfInt(line);
  log_printfString("[");
  log_printfString(log_convert_log_level_to_string(level));
  log_printfString("]: ");

  va_list args;
  va_start(args, format);

  unsigned long index = 0;

  while(format[index] != '\0')
  {
      if(format[index] == '%')
      {
          index++;
          switch (format[index]) {
              case 's':
                  log_printfString(va_arg(args, char*));
                  break;
              case 'd':
                  log_printfInt(va_arg(args, int));
                  break;
              default:
                  log_printfString("unsupported-type");
                  break;
          }
      }
  }
  va_end(args);
}

void log_dump(log_DumpWriter writer)
{
    char character;
    while(log_logFifoDequeue(&character));
        writer(character);
}
