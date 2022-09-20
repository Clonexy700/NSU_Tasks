#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct matrix{
    int** m;
    int k;
    int det;
}Matrix;
int** initiate(int n);
void free_mem(int** m, int n){
    for (int i=0;i<n;i++){
        free(m[i]);
    }
    free(m);
}
int** cross_lines(int** matrix,int n,int k){
    int** m_new = initiate(n-1);
    int count = 0;
    for (int i=1;i<n;i++){
        for (int j=0;j<n;j++){
            if (j!=k){
                m_new[i-1][count]=matrix[i][j];
                count++;
            }
        }
        count = 0;
    }
    return m_new;
}

int det(int** matrix,int k){
    if (k==1){
        return matrix[0][0];
    }
    if (k==2){
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    if (k>2){
        int s = 0;
        for (int i=0;i<k;i++){
            int** aNew = cross_lines(matrix, k, i);
            int det1 = det(aNew, k - 1);
            s+=pow(-1,i)*matrix[0][i]*det1;
            free_mem(aNew,k-1);
        }
        return s;
    }
}
void qSort(int nStart, int nEnd, Matrix *package){
    int L,R;
    Matrix c,X;
    if (nStart>=nEnd) return;
    L=nStart,R=nEnd;
    X = package[(L+R)/2];
    while (L<=R){
        while (package[L].det<X.det) L++;
        while (package[R].det>X.det) R--;
        if (L<=R){
            c=package[L]; package[L]=package[R]; package[R]=c;
            L++, R--;
        }
    }
    qSort(nStart,R,package);
    qSort(L,nEnd,package);
}
void output(int** m,int k){
    for (int i=0;i<k;i++){
        for (int j=0;j<k;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}





int main() {
    int n,k;
    scanf("%d",&n);
    Matrix *package = (Matrix*)malloc(sizeof (Matrix)*n);
    for (int i=0;i<n;i++){
        Matrix m;
        scanf("%d",&k);
        int** matrix = initiate(k);
        for (int j=0;j<k;j++){
            for(int l=0;l<k;l++){
                scanf("%d",&matrix[j][l]);
            }
        }
        int d = det(matrix,k);
        m.det = d, m.m = matrix,m.k=k;
        package[i]=m;
    }
    qSort(0,n-1,package);
    for (int i=0;i<n;i++){
        output(package[i].m,package[i].k);

    }
    for (int i=0;i<n;i++){
        free_mem(package[i].m,package[i].k);
    }
    return 0;
}

int** initiate(int n){
    int** m = (int**)malloc((n)*sizeof(int*));
    for (int i=0;i<n;i++){
        m[i]=(int*) malloc((n)*sizeof(int));
    }
    return m;
}
