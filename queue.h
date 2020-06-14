#ifndef OPERATING_SYSTEMS_XV6_HW2_QUEUE_H
#define OPERATING_SYSTEMS_XV6_HW2_QUEUE_H

#ifndef C_QUEUE_QUEUE_H
#define C_QUEUE_QUEUE_H

#ifndef NPROC
#define NPROC 64
#endif // NPROC

#ifndef BOOLEAN
typedef enum {
    FALSE, TRUE
} BOOLEAN;
#endif // BOOLEAN

#define INCREASE_MODULO(num) (((num) + 1) % NPROC)

typedef struct {
    struct proc *processes[NPROC];
    int front;
    int rear;
    int size;

} queue, *queuePtr;

void initQueue(queuePtr q);

BOOLEAN isEmptyQueue(queuePtr q);

void insertQueue(queuePtr q, struct proc *precess);

struct proc *removeQueue(queuePtr q);

#endif //C_QUEUE_QUEUE_H


#endif //OPERATING_SYSTEMS_XV6_HW2_QUEUE_H
