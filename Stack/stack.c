#include<stdio.h>
#include<stdlib.h>


struct Stack{
    int items[5];
    int top;
};


void initialize(struct Stack *stack){
    stack->top=-1;
}

int is_empty(struct Stack *stack){
    return (stack->top==-1);
}

int is_full(struct Stack *stack){
    int N=5;
    if(stack->top==N-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack *stack,int element){
    if(!is_full(stack)){
        stack->top++;
        stack->items[stack->top]=element;
    }
    else{
        printf("No Push, Stack is Full\n");
    }
}


void pop(struct Stack *stack){
    if(!is_empty(stack)){
        int popped_element=stack->items[stack->top];
        stack->top--;
    }
    else{
        printf("Stack is Empty\n");
    }
}


void peek(struct Stack *stack){
    if(!is_empty(stack)){
        printf("Top element is : %d\n",stack->items[stack->top]);
    }
    else{
        printf("Stack is Empty\n");
    }
}

void display(struct Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d\t", stack->items[i]);
    }
    printf("\n");
}


void main(){
    struct Stack stack;
    initialize(&stack);
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);

    display(&stack);


    pop(&stack);

    display(&stack);

    peek(&stack);


}


