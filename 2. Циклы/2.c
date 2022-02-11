#include<stdio.h>

int main()
    {
    int number, reverse=0, remaining;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &number);
    while (number != 0) {
        remaining = number % 10;
        reverse = reverse*10+remaining;
        number /= 10;
        }
    printf("%d", reverse);
    return 0;
    }
