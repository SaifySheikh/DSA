#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_at_beginning(struct node **head, int element) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
    } else {
        struct node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newnode->next = *head;
        last->next = newnode;
        *head = newnode;
    }
}

void insert_at_end(struct node **head, int element) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
    } else {
        struct node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newnode;
        newnode->next = *head;
    }
}

void deletenode(struct node **head, int element) {
    if (*head == NULL) {
        printf("No element in list\n");
        return;
    }

    struct node *current = *head, *prev = NULL;

    while (current->next != *head && current->data != element) {
        prev = current;
        current = current->next;
    }

    if (current->data != element) {
        printf("Element not found in the list\n");
        return;
    }

    if (current == *head && current->next == *head) {
        *head = NULL;
        free(current);
        return;
    }

    if (current == *head) {
        while (current->next != *head) {
            current = current->next;
        }
        *head = (*head)->next;
        current->next = *head;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void display(struct node *head) {
    printf("The list is:\n");
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("NULL\n");
        return;
    }
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main() {
    struct node *head = NULL;
    int ele, c, r;

    do {
        printf("\n1.Insertion at Beginning\n2.Insertion at end\n3.Deletion\n4.Display\nEnter: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &ele);
                insert_at_beginning(&head, ele);
                break;
            case 2:
                printf("Enter Element: ");
                scanf("%d", &ele);
                insert_at_end(&head, ele);
                break;
            case 3:
                printf("Enter Element: ");
                scanf("%d", &ele);
                deletenode(&head, ele);
                break;
            case 4:
                display(head);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Enter 1 to repeat else enter 0: ");
        scanf("%d", &r);

    } while (r == 1);

    printf("*Program Finished*\n");
    return 0;
}
