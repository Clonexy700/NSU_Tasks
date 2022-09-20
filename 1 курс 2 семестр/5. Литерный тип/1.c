#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(const char *src, int m, int n)
{
    int len = n - m;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';
    return dest - len;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char word[30];
    gets(word);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int m = strlen(word)-3;
    int n = strlen(word)-2;
    int k = strlen(word)-1;
    if (word[m] == 'e' && word[n] == 'r' && word[k] == '.') {
      printf("%sest", substr(word, 0, m));
    } else if (word[m] != 'e' && word[n] == 'e' && word[k] == '.') {
      printf("%sr", substr(word, 0, k));
    } else if (word[m] != 'e' && word[n] != 'r' && word[n] != 'e' && word[k] == '.') {
      printf("%ser", substr(word, 0, k));
    }
    return 0;
}
