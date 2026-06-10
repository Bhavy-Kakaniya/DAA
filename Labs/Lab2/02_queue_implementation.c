#include <stdio.h>
#include <stdbool.h>

void enque(int *head, int *tail, int queue[], int value)
{
    if (*head == -1)
    {
        *head = 0;
    }
    queue[++(*tail)] = value;
}

int deque(int *head, int *tail, int queue[])
{
    if (*head == -1 || *head > *tail)
    {
        printf("queue underflow");
        return -1;
    }
    return queue[(*head)++];
}

void display(int head, int tail, int queue[])
{
    if (head == -1 || head > tail)
    {
        printf("queue is empty");
        return;
    }
    for (int i = head; i <= tail; i++)
    {
        printf("%d, ", queue[i]);
    }
    printf("done");
}

int main()
{
    int head = -1;
    int tail = -1;
    int queue[100];

    bool stop = false;
    int choice;
    int value;

    while (!stop)
    {
        printf("\n===== QUEUE MENU =====");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);

            enque(&head, &tail, queue, value);

            printf("Value inserted successfully\n");
            break;

        case 2:
            value = deque(&head, &tail, queue);

            if (value != -1)
            {
                printf("Dequeued value: %d\n", value);
            }
            break;

        case 3:
            display(head, tail, queue);
            break;

        case 4:
            stop = true;
            printf("Program terminated\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}