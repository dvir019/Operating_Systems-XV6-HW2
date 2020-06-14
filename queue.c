#include "queue.h"


void initQueue(queuePtr q) {
    q->front = q->rear = q->size = 0;
}

BOOLEAN isEmptyQueue(queuePtr q) {
    return (BOOLEAN) (!(q->size));
}

void insertQueue(queuePtr q, struct proc *process) {
    q->processes[q->rear] = process;
    q->rear = INCREASE_MODULO(q->rear);
    q->size++;
}

struct proc *removeQueue(queuePtr q) {
    struct proc *process = q->processes[q->front];
    q->front = INCREASE_MODULO(q->front);
    q->size--;
    return process;
}

struct proc *getFirstRunnableProcess(queuePtr q){
//    int tempSize;
//    struct proc *p;
//    for (tempSize = q->size; tempSize > 0; tempSize--){
//        p =
//    }
    return NULL;
}