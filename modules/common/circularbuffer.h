/*
 * circularbuffer.h
 *
 *  Created on: Jun 3, 2019
 *      Author: kamat
 */

#ifndef MODULES_COMMON_CIRCULARBUFFER_H_
#define MODULES_COMMON_CIRCULARBUFFER_H_

typedef struct {
    long start;
    long end;
    long size;
}CircularBufferPtr;

void circularBuffer_Init(long size);

void circularBuffer_Push(CircularBufferPtr* bufferPtr);

long circularBuffer_Pop(CircularBufferPtr* bufferPtr);

long circularBuffer_Peek(CircularBufferPtr* bufferPtr);

#endif /* MODULES_COMMON_CIRCULARBUFFER_H_ */
