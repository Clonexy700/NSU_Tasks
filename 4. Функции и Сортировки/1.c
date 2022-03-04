#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d\n", &n);
    int arr[n];
    int temp;
    int length = sizeof(arr)/ sizeof(arr[0]);
    for (int i = 0;i < length; i++) {
        int monke;
        scanf("%d ", &monke);
        arr[i] = monke;
    }
    for (int i = 0;i < length; i++) {
        for (int j = i+1; j < length; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
