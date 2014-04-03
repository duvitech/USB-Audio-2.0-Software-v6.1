#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <xccompat.h>

typedef struct queue {
   uintptr_t data;
   int rdptr; // Using absolute indices which count reads and writes so this needs to be considered when accessing.
   int wrptr;
   int size;
   int element_size;
   int mask;
} queue;

void init_queue(REFERENCE_PARAM(queue, q), unsigned char arr[], int size, int element_size);
void enqueue(REFERENCE_PARAM(queue, q), unsigned value);
unsigned dequeue(REFERENCE_PARAM(queue, q));
int isempty(REFERENCE_PARAM(queue, q));
int isfull(REFERENCE_PARAM(queue, q));
int items(REFERENCE_PARAM(queue, q));
int space(REFERENCE_PARAM(queue, q));
void dump(REFERENCE_PARAM(queue, q));

#endif // QUEUE_H
