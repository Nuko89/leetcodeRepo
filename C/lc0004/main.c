#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int medianIndex = (nums1Size + nums2Size) / 2;
    //printf("medianIndex=%d\n", medianIndex);
    size_t arrSize = nums1Size + nums2Size;
    double ans;
    int i1 = 0;
    int i2 = 0;
    int j = 0;
    int* arr = (int*)malloc(arrSize * sizeof(int));
    for (; j < medianIndex && i1 < nums1Size && i2 < nums2Size; j++){
        if (nums1[i1] < nums2[i2]){
            arr[j] = nums1[i1];
            //printf("arr[j]=%d\n", arr[j]);
            i1++;
        }
        else{
            arr[j] = nums2[i2];
            //printf("arr[j]=%d\n", arr[j]);
            i2++;
        }
        //printf("j=%d\n", j);
    }
    //printf("1j=%d\n", j);

    if (i1 >= nums1Size){
        for (; j <= medianIndex; j++){
            arr[j] = nums2[i2];
            //printf("arr[j]=%d\n", arr[j]);
            i2++;
            //printf("i1j=%d\n", j);
        }
        ans = arr[medianIndex];
        j--;
    }
    else if (i2 >= nums2Size){
        for (; j <= medianIndex; j++){
            arr[j] = nums1[i1];
            //printf("arr[j]=%d\n", arr[j]);
            i1++;
            //printf("i2j=%d\n", j);
        }
        ans = arr[medianIndex];
        j--;
    }
    else{
        if (nums1[i1] < nums2[i2]){
        ans = nums1[i1];
        }
        else{
            ans = nums2[i2];
        }
    }
    //printf("2j=%d\n", j);

    //printf("ans=%f\n", ans);
    //printf("arr[j - 1]=%f\n", arr[j - 1]);
    double tmp = arr[medianIndex - 1];
    //printf("arr[j - 1]=%f\n", tmp);

    if ((nums1Size + nums2Size) % 2 == 0){
        ans = (ans + tmp) / 2;
    }
    
    return ans;
}