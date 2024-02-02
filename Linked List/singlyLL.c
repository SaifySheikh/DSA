#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void insert_at_beginning(struct node **head,int element){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
    }
    else{
        newnode->next = *head;
        *head = newnode;
    }
}


void insert_at_end(struct node **head,int element){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
        return;
    }
    else{
        struct node *ptr=*head;
        while(ptr->next!= NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}


void display(struct node *head){
    printf("The list is:\n");
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}


int main(){
    struct node *head=NULL;
    int ele, c, r;
    
    do {
        printf("\n1.Insertion at Beginning\n2.Insertion at end\n3.Deletion\n4.Display\nEnter: ");
        scanf("%d",&c);
    
        switch(c){
            case 1: printf("Enter Element: ");
                    scanf("%d",&ele);
                    insert_at_beginning(&head,ele);
                    break;
            case 2: printf("Enter Element: ");
                    scanf("%d",&ele);
                    insert_at_end(&head,ele);
                    break;
            case 3: printf("Enter Element: ");
                    scanf("%d",&ele);
                    /*del(&head,ele);*/
                    break;
            case 4: display(head);
                    break;
            default: printf("Invalid choice\n");
        }   

        printf("Enter 1 to repeat else enter 0: ");
        scanf("%d",&r);

    } while(r == 1);
    
    printf("*Program Finished*\n");
    return 0;
    
}