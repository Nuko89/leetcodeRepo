#include <stdio.h>
#include <stdlib.h>

// 合併兩個已排序的子陣列
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // 左半部分長度
    int n2 = right - mid;      // 右半部分長度

    // 建立暫存陣列
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // 複製資料
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // 合併兩個暫存陣列到 arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // 如果 L 還有剩餘
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // 如果 R 還有剩餘
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

// 遞迴拆分
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // 避免溢位

        mergeSort(arr, left, mid);      // 排序左半部
        mergeSort(arr, mid + 1, right); // 排序右半部
        merge(arr, left, mid, right);   // 合併
    }
}

// 測試程式
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始陣列: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("排序後: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
