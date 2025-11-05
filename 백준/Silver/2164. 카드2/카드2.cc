#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 500000
#include <stdio.h>

typedef int element;

typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];

}QueueType;

void init_queue (QueueType *q){
    q->front = 0;
    q->rear = 0;
}

void enqueue(QueueType* q, element item) {
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main() {
    QueueType q;
    QueueType* p = &q;
    init_queue(&q);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        enqueue(&q, i + 1);
    }
    for (int i = 0; i < N-1; i++) {
        dequeue(&q);
        enqueue(&q, dequeue(&q));
    }

    printf("%d", p->data[p->rear]);

    return 0;

}