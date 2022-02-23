#include <stdio.h>
int main(){
  int N;
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d", &N);
  int a[N+1];
   for(int i=0; i<=N; i++){
       a[i] = i;
   }
   a[1]=0;
   for(int step=2; step<=N; step++){
       if(a[step]!=0){
           for(int j=step*2; j<N; j+=step){
               a[j]=0;
           }
       }
   }
   for(int i=0; i<=N; i++){
       if(a[i]!=0){
            printf("%d ", a[i]);
       }
   }
   return 0;
}
