#include <stdio.h>
#include <stdlib.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main(void){
    int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
    int L_size = sizeof(L) / sizeof(L[0]);

    printf("Given list \n");
    printList(L, L_size);

    MergeSort(L, 0, L_size - 1);

    printf("The sorted list \n");
    printList(L, L_size);
    return 0;
}

void Merge(int L[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary arrays
    int L1[n1], L2[n2];

    // Copy data to temporary arrays L1 and L2
    for (int i = 0; i < n1; i++)
        L1[i] = L[l + i];
    for (int j = 0; j < n2; j++)
        L2[j] = L[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge the temporary arrays back into L[l..r]
    while (i < n1 && j < n2) {
        if (L1[i] <= L2[j]) {
            L[k] = L1[i];
            i++;
        } else {
            L[k] = L2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L1, if any
    while (i < n1) {
        L[k] = L1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of L2, if any
    while (j < n2) {
        L[k] = L2[j];
        j++;
        k++;
    }
}

void MergeSort(int L[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;
        MergeSort(L, l, m);
        MergeSort(L, m + 1, r);
        Merge(L, l, m, r);
    }
}

void printList(int L[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", L[i]);
    printf("\n");
}