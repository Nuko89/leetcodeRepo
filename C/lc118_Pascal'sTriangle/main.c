#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    int **ans = (int**)malloc(sizeof(int*) * numRows);

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        ans[i] = (int*)malloc(sizeof(int) * (i + 1));
        
        ans[i][0] = 1;
        ans[i][i] = 1;

        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    return ans;
}