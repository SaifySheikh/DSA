#include<stdio.h>
#include<stdlib.h>
#define size 5

struct Queue{
    int front;
    int rear;
    int arr[size];
};


void init(struct Queue *queue){
    queue->front=-1;
    queue->rear=-1;
}


int is_full(struct Queue *queue){
    if(queue->front==size-1){
        return 1;
    }
    else{
        return 0;
    }
}


int is_empty(struct Queue *queue){
    if(queue->front==-1 && queue->rear==-1){
        return 1;

    }
    return 0;
}


void enqueue(struct Queue *queue,int element){
    if(is_full(queue)){
        printf("Queue already fulled!!!");
    }
    if(is_empty(queue)){
        queue->front=0;
        queue->rear=0;

        queue->arr[queue->rear]=element;

    }
    else{
        queue->rear++;
        queue->arr[queue->rear]=element;
    }

}


int dequeue(struct Queue *queue){
    if(is_empty(queue)){
        printf("Queue is already Empty!!!\n");
    }
    else{
        int value=queue->arr[queue->front];
        queue->front++;
        if(queue->front>queue->rear){
            queue->front=-1;
            queue->rear=-1;
        }
        return value;
    }
}


void display(struct Queue *queue){
    if(is_empty(queue)){
        printf("empty hai\n");
    }
    else{
        for(int i=queue->front;i<queue->rear+1;i++){
            printf("%d\t",queue->arr[i]);
        }
    }
}



int main() {
    struct Queue queue;
    init(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    display(&queue);

    printf("\nDequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}