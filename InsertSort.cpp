#include <stdio.h>

typedef int KeyType;
typedef struct {
    KeyType Key;
}RecordType;

void Swap(RecordType *x, RecordType *y) {
    RecordType temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSort(RecordType x[], int n) {
    int i, j;
    for(int i=0 ; i<n; i++) {
        j = i;
        while ((j>0) && (x[j].Key < x[j-1].Key)) 
        {
            Swap(&x[j], &x[j-1]);
            j--;
        }
    }
}

int main() {
    freopen("danhSachChuaSX.txt", "r", stdin);
    int n;
    scanf("%d ", &n);
    RecordType a[n+1];
    for(int i = 0; i<n; i++) {
        scanf("%d", &a[i].Key);
    }
    printf("DS chua SX\n");
    for(int i = 0; i<n ; i++) {
        printf("%d ", a[i].Key);
    }
    printf("\nDS sau SX\n");
    InsertSort(a,n);
    for(int i = 0; i<n; i++) {
        printf("%d ", a[i].Key);
    }



}