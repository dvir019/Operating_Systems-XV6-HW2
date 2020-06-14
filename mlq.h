#ifndef C_QUEUE_MLQ_H
#define C_QUEUE_MLQ_H

#ifndef NPRIORITIES
#define NPRIORITIES 4
#endif //NPRIORITIES

#ifndef NULL
#define NULL ((void *)0)
#endif //NULL

#include "queue.h"

typedef struct {
    queue queues[NPRIORITIES];
    int runnableCounter[NPRIORITIES];
} mlq, *mlqPtr;


void initMlq(mlqPtr m);

void addToPriority(mlqPtr m, int priority, struct proc *p);

struct proc *removeFromPriority(mlqPtr m, int priority);

void increaseRunnableCounter(mlqPtr m, int priority);

void decreaseRunnableCounter(mlqPtr m, int priority);

#endif //C_QUEUE_MLQ_H