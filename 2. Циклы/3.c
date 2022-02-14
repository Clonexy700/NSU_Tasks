#include <stdio.h>

int main()
{
    int i,j,n,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for(i=2; i<=n; i++) {
		k=0;
		for(j=2; j*j<=i; j++) {
			if (i%j==0){
				k = 1;
				break;
				}
			}
		if (k== 0){
			printf("%d ", i);
			}
		}
}
