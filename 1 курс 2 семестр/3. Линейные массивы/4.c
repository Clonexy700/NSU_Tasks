#include <stdio.h>
int binarySearch(int array[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (array[m] == x)
            return m;
        if (array[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, x;
    scanf("%d %d\n", &n, &x);
    int array[n+1];
    int index;
    for (int i = 0; i<n; i++) {
      scanf("%d ", &index);
      array[i] = index;
    }
    int result = binarySearch(array, 0, n - 1, x);
    (result == -1) ? printf("error:no element"): printf("%d", result);
    return 0;
}
