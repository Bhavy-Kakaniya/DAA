#include <stdio.h>
#include <stdbool.h>

void push(int value, int *top, int stack[])
{
    stack[++(*top)] = value;
}

int pop(int *top, int stack[])
{
    if (*top >= 0)
        return stack[(*top)--];
    else
    {
        printf("Stack underflow");
        return -1;
    }
}

int peep(int top, int stack[])
{
    if (top >= 0)
        return stack[top];
    printf("Stack is empty\n");
    return -1;
}

void display(int top, int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    printf("Stack: ");
    for (int i = top; i > -1; i--)
    {
        printf("%d, ", stack[i]);
    }
    printf("done");
}

void change(int index, int new_value, int stack[], int top)
{
    if (index >= 0 && index <= top)
    {
        stack[index] = new_value;
        printf("value changed");
    }
    else
        printf("Invalid index");
}

int main()
{
    int top = -1;
    int stack[100];
    bool stop = false;
    int choice;

    while (!stop)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Change");
        printf("\n4. Peep");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        int value;
        int new_value, index;

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value, &top, stack);
            break;

        case 2:
            printf("Popped value: %d\n", pop(&top, stack));
            break;

        case 3:
            printf("Enter index of value to change: ");
            scanf("%d", &index);

            printf("Enter new value: ");
            scanf("%d", &new_value);

            change(index, new_value, stack, top);
            break;

        case 4:
            printf("Peeped value: %d\n", peep(top, stack));
            break;

        case 5:
            display(top, stack);
            break;

        case 6:
            stop = true;
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}