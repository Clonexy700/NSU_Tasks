#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, t;

	scanf("%d", &n);

	int l = n-1;

	int *a=(int*)malloc(l*sizeof(int));

	for(int i = 0; i < l; i++)
	{
		a[i] = i + 2;
	}
	for(int i = 0; i < l; i++)
	{
		t = a[i];
		if(t == 0)
			continue;
		for(int j = i+t; j < l; j+=t)
		{
			a[j] = 0;
		}
		printf("%d ", t);
	}
}
