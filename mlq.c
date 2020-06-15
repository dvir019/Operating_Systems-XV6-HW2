#include "mlq.h"

#define LEGAL_PRIORITY(priority) (((priority) >= 0) && ((priority) < NPRIORITIES))

void initMlq(mlqPtr m) {
    int i;
    for (i = 0; i < NPRIORITIES; ++i) {
        initQueue(&(m->queues[i]));
    }
}

void addToPriority(mlqPtr m, int priority, struct proc *p) {
    if (LEGAL_PRIORITY(priority))
        insertQueueTail((&((m->queues)[priority])), p);
}

struct proc *removeFromPriority(mlqPtr m, int priority) {
    if (LEGAL_PRIORITY(priority))
        return removeQueue(&((m->queues)[priority]));
    return NULL;
}

struct proc *getRunnableProcess(mlqPtr m) {
    struct proc *p;
    int prio;
    for (prio = NPRIORITIES; prio >= 0; prio--) {
        p = getFirstRunnableProcess(&(m->queues[prio]));
        if (p != NULL) {
            return p;
        }
    }
    return NULL;
}



