#include<stdio.h>

int power(int x, int y) {
    if(y == 0) {
        return 1;
    }
    return x * power(x, y - 1);
}

void main() {
    int x = 3, y = 6;
    printf("%d", power(x, y)); 
}