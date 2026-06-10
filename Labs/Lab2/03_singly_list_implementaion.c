#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *link;
};

struct node *first = NULL;

void insert(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    newnode->value = val;
    newnode->link = first;
    first = newnode;
    printf("node inserted");
}

void delete()
{
    if(first == NULL){
        printf("List is empty");
        return;
    }
    struct node *temp = first;
    first = first->link;
    free(temp);
    printf("First node deleted\n");
}

void display()
{
    struct node *temp = first;
    if (first == NULL)
    {
        printf("list is empty");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    int value;
    int stop = 0;

    while (!stop)
    {
        printf("\n===== LINKED LIST MENU =====");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);

            insert(value);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            stop = 1;
            break;

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}