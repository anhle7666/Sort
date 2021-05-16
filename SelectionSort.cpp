#include <stdio.h>

typedef int otherType;

typedef struct {
	int key;
	otherType OtherFields;
}RecordType;

void swap(RecordType *x, RecordType *y) {
	RecordType temp = *x;
	*x = *y;
	*y = temp;
}

void SelectionSort(RecordType List[], int n){
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n-1; j++) {
			if(List[i].key > List[j].key) 
				swap(&List[i],&List[j]);
		}
	}
}

int main() {
	freopen("danhSachChuaSX.txt", "r", stdin);
	RecordType List[50];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &List[i].key);
	}
	printf("Truoc Sap xep: \n");
	for(int i = 0; i < n; i++) {
		printf("%d ", List[i].key);
	}
	SelectionSort(List, n);
	printf("\n-----------\nSau Sap xep: \n");
	for(int i = 0; i < n; i++) {
		printf("%d ", List[i].key);
	}
}


