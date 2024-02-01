#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque *dq) {
    return dq->front == -1 && dq->rear == -1;
}

int isFull(Deque *dq) {
    return (dq->rear + 1) == dq->front;
}

void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 );
    }
    dq->data[dq->front] = value;
}

void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1);
    }
    dq->data[dq->rear] = value;
}

int deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from front.\n");
        return -1;
    }
    int value = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) ;
    }
    return value;
}

int deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return -1;
    }
    int value = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 );
    }
    return value;
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->data[i]);
        i = (i + 1) ;
    }
    printf("%d\n", dq->data[dq->rear]);
}

int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 30);
    insertFront(&dq, 40);

    display(&dq);

    printf("Deleted element from front: %d\n", deleteFront(&dq));
    printf("Deleted element from rear: %d\n", deleteRear(&dq));

    display(&dq);

    return 0;
}
