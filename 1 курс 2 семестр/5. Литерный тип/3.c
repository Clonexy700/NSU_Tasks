#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    gets(str);
    int size = strlen(str);
    str[size-1] = '\0';
    int x = atoi(str);
    if (x%15==0) {
      printf("YES");
    }
    else if (x%15 != 0) {
      printf("NO");
    }
    return 0;
}
