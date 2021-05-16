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

void BubbleSort(RecordType a[], int n) {
    int i, j;
    for(i = 0; i<=n-2; i++)
        for(j = n-1; j>i; j--) 
            if(a[j].Key < a[j-1].Key)
                Swap(&a[j], &a[j-1]);
}

int main(){
    freopen("danhSachChuaSX.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    RecordType a[n+1];
    for(int i = 0; i<n; i++) {
        scanf("%d ", &a[i].Key);
    }
    printf("Truoc SX\n");
    for(int i =0; i<n; i++) {
        printf("%d ", a[i].Key);
    }
    printf("\nSau SX\n");
    BubbleSort(a,n);
    for(int i =0; i<n; i++) {
        printf("%d ", a[i].Key);
    }


}