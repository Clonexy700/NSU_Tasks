#include <stdio.h>

int main()
{
    int number,i,j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&number);
    int array[number+1];
    for(i = 2; i<=number; i++)
        array[i] = i;

    i = 2;
    while ((i*i) <= number)
    {
        if (array[i] != 0)
        {
            for(j=2; j<number; j++)
            {
                if (array[i]*j > number)
                    break;
                else
                    array[array[i]*j]=0;
            }
        }
        i++;
    }

    for(i = 2; i<=number; i++)
    {
        if (array[i]!=0)
            printf("%d ", array[i]);
    }

    return 0;
}
