#include <stdio.h>

typedef int KeyType;
typedef struct
{
    KeyType Key;
} RecordType;

void Swap(RecordType &x, RecordType &y)
{
    RecordType temp = x;
    x = y;
    y = temp;
}

void PushDown(RecordType a[], int First, int Last)
{
    int r = First;
    while (r <= (Last - 1) / 2)
    {
        if (Last == 2 * r + 1)
        {
            if (a[r].Key > a[Last].Key)
                Swap(a[r], a[Last]);
            r = Last;
        }
        else if ((a[r].Key > a[2 * r + 1].Key) && a[2 * r + 1].Key <= a[2 * r + 2].Key)
        {
            Swap(a[r], a[2 * r + 1]);
            r = 2 * r + 1;
        }
        else if ((a[r].Key > a[2 * r + 2].Key) && a[2 * r + 2].Key < a[2 * r + 1].Key)
        {
            Swap(a[r], a[2 * r + 2]);
            r = 2 * r + 2;
        }
        else
            r = Last;
    }
}

void HeapSort(RecordType a[], int n)
{
    int i;
    for (i = (n - 2) / 2; i >= 0; i--)
    {
        PushDown(a, i, n - 1);
    }
    for (i = n - 1; i >= 2; i--)
    {
        Swap(a[0], a[i]);
        PushDown(a, 0, i - 1);
    }
    Swap(a[0], a[1]);
}

int main()
{
    freopen("danhSachChuaSX.txt", "r", stdin);
    int n, i;
    scanf("%d", &n);
    RecordType a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i].Key);
    }
    printf("HeapSort.\nChua Sap Xep: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i].Key);
    }
    HeapSort(a,n);
    printf("\nSau Sap xep (giam dan): ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i].Key);
    }
}