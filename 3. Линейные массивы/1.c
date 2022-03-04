#include<stdio.h>

int main()
{
    int size, index;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d", &size, &index);
    if ((index<size) && (index >= 0)){ printf("legal");
    } else {
    printf("out of bounds");
    }
    return 0;
}
