#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, s, p;

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &n, &s);

    int *array = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        array[i] = p;
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        int d = 0;

        for (int j = i; j < n; j++) {
            d += array[j];
            if (d == s) c += 1;
        }
    }

    printf("%d", c);

	return 0;
}
