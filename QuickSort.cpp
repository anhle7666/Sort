#include <stdio.h>
typedef int KeyType;
typedef struct {
    KeyType Key;
}RecordType;

void Swap(RecordType &x, RecordType &y) {
    RecordType temp = x;
    x = y;
    y = temp;
}

int FindPivot(RecordType List[], int i, int j) {
    KeyType FirstKey;
    int k;
    k = i + 1;
    FirstKey = List[i].Key;
    while((k <= j) && (List[k].Key == FirstKey)) k++;
    if(k>j) return -1;
    if(List[k].Key > FirstKey) return k;
    return i;
}

int Partition(RecordType List[], int i, int j, KeyType Pivot) {
    int L, R;
    L = i;
    R = j;
    while ( L <= R) {
        while(List[L].Key < Pivot) L++;
        while(List[R].Key >= Pivot) R--;
        if( L < R) Swap(List[L], List[R]);
    }
    return L;
}

void QuickSort(RecordType a[], int i, int j) {
    KeyType Pivot;
    int PivotIndex, k;
    PivotIndex = FindPivot(a,i,j);
    if(PivotIndex != -1) {
        Pivot = a[PivotIndex].Key;
        k = Partition(a,i,j,Pivot);
        QuickSort(a,i,k-1);
        QuickSort(a,k,j);
    }
}

int main() {
    freopen("danhSachChuaSX.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    RecordType a[n];
    for(int i = 0;i<n; i++) {
        scanf("%d ", &a[i].Key );
    }
    printf("QuickSort Truoc Sap Xep\n");
    for(int i =0; i<n; i++) {
        printf("%d ", a[i].Key);
    }
    QuickSort(a,0,n-1);
    printf("\nSau Sap Xep\n");
    for(int i = 0; i<n ;i++) {
        printf("%d ", a[i].Key);
    }
}