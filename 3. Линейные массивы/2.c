#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main ()
{
    int n, p, *array, flag;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &n);
    n = n - 1;
    array = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        array[i] = i + 2;
    for (int i = 0; i < sqrt(n); i++)
    {
        p = array[i];
        flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (!(array[j] % p))
            {
                for (int k = j; k < n - 1; k++)
                    array[k] = array[k+1];
                flag = 1;
                n--;
                j--;
            }
        }
        if (flag == 0) break;
    }
    for (int i = 0; i < n; i++)
      printf("%d ", array[i]);
    free(array);
    return 0;
}
