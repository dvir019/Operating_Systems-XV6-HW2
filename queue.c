#include "types.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "queue.h"


void initQueue(queuePtr q) {
    q->front = q->rear = q->size = 0;
}

BOOLEAN isEmptyQueue(queuePtr q) {
    return (BOOLEAN) (!(q->size));
}

void insertQueueTail(queuePtr q, struct proc *process) {
    q->processes[q->rear] = process;
    q->rear = INCREASE_MODULO(q->rear);
    q->size++;
}

void insertQueueHead(queuePtr q, struct proc *process) {
    q->front = q->front == 0 ? NPROC - 1 : DECREASE_MODULO(q->front);
    q->processes[q->front] = process;
    q->size++;
}

struct proc *removeQueue(queuePtr q) {
    struct proc *process = q->processes[q->front];
    q->front = INCREASE_MODULO(q->front);
    q->size--;
    return process;
}

struct proc *getFirstRunnableProcess(queuePtr q) {
    int tempSize;
    struct proc *p = NULL;
    //struct proc *pReturn = NULL;
    for (tempSize = q->size; tempSize > 0; tempSize--) {
        p = removeQueue(q);
        if (p->state == RUNNABLE) {
            tempSize--;
            break;
        }
        insertQueueTail(q, p);
    }
    for (; tempSize > 0; tempSize--)
        insertQueueTail(q, removeQueue(q));

    return p;
}