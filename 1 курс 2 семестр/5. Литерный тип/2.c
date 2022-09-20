#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[30];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    gets(word);
    int length = strlen(word);
    if (length == 4 && word[1] == 'A')
      printf("FITS");
    else {
      printf("DOES NOT FIT");
    }
    return 0;
}
