#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node *getMiddle(struct Node *start, struct Node *end)
{
    if (start == NULL)
        return NULL;

    struct Node *slow = start;
    struct Node *fast = start->next;

    while (fast != end)
    {
        fast = fast->next;
        if (fast != end)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

struct Node *binarySearch(struct Node *start, struct Node *end, int key)
{
    if (start == end)
        return NULL;

    struct Node *mid = getMiddle(start, end);

    if (mid == NULL)
        return NULL;

    if (mid->data == key)
        return mid;

    if (key < mid->data)
        return binarySearch(start, mid, key);

    return binarySearch(mid->next, end, key);
}

void main()
{
    struct Node *head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    struct Node *result = binarySearch(head, NULL, key);

    if (result != NULL)
        printf("Element %d found in the linked list.\n", key);
    else
        printf("Element %d not found in the linked list.\n", key);
}