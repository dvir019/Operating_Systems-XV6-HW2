#ifndef C_QUEUE_MLQ_H
#define C_QUEUE_MLQ_H

#ifndef NPRIORITIES
#define NPRIORITIES 4
#endif //NPRIORITIES

#include "queue.h"

typedef struct {
    queue queues[NPRIORITIES];
} mlq, *mlqPtr;


void initMlq(mlqPtr m);

void addToPriority(mlqPtr m, int priority, struct proc *p);

struct proc *removeFromPriority(mlqPtr m, int priority);

struct proc *getRunnableProcess(mlqPtr m);

#endif //C_QUEUE_MLQ_H