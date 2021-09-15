#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
void linkedListTraversal(struct Node* ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node*insertatbeginning(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return ptr;
};

struct Node* insertinbetween(struct Node* head, int data, int index)
{
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p = head;
    int i= 0;

    while(i< index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

struct Node* insertatend (struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p = head;
    ptr->data = data;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

struct Node* insertafteranode (struct Node*head, struct Node*prev, int data)
{
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prev->next;
    prev->next = ptr;
    return head;
};

int main()
{
    struct Node*head;
    struct Node*first;
    struct Node*second;
    struct Node*third;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 14;
    second->next = third;

    third->data = 19;
    third->next = NULL;
    printf("Linked List before Insertion: %d \n");
    linkedListTraversal(head);

    printf("Linked List after Insertion: %d \n");
    printf("Case 1: Insert a node at the beginning: %d \n");
    head = insertatbeginning(head, 47);
    linkedListTraversal(head);
    printf("Case 2: Insert a node in between: %d \n");
    head = insertinbetween(head, 23, 3);
    linkedListTraversal(head);
    printf("Case 3: Insert a node at the end: %d \n");
    head = insertatend(head, 32);
    linkedListTraversal(head);
    printf("Case 4: Insert a node after a node: %d \n");
    head = insertafteranode(head, second, 42);
    linkedListTraversal(head);
    return 0;
}
