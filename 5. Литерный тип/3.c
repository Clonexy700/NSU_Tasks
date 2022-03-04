#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findSum(char str[100000])
{
    char temp[100000] = "";

    int sum = 0;
    for (char ch : str) {t
        if (isdigit(ch))
            temp += ch;

        else {
            sum += atoi(temp.c_str());
            temp = "";
        }
    }
    return sum + atoi(temp.c_str());
}

int main()
{
    char str[100000];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    gets(str);
    printf("%d", findSum(str));

    return 0;
}
