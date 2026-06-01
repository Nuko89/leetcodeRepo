#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    //printf("%d\n", n);
    if (n < 2) return s;
    
    bool dp[n][n];
    memset(dp, 0, sizeof(dp)); //全填 0
    for (int i = 0; i < n; i++) dp[i][i] = true; //對角(自己)填1
    
    int i, j, l;
    int maxLen = 1;
    int start = 0;
    for (l = 2; l <= n; l++){//l = i跟j的長度
        for (i = 0; i <= n - l; i++){
            j = i + l - 1;

            if (s[i] == s[j]){//檢查頭尾相同
                if (l == 2){//長度等於2就是回文
                    dp[i][j] = true;
                }
                else{//看中間是不是回文
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            else{
                dp[i][j] = false;
            }

            if (dp[i][j] && maxLen < l){//更新最長
                maxLen = l;
                start = i;
            }
        }
    }
    
    //printf("%d\n", start);
    //printf("%d\n", maxLen);
    //printf("%s\n", s);
    //printf("%c\n", s[0]);
    //for (int i = 0; i < n; i++) {
        //for (int j = 0; j < n; j++) {
            //printf("%d ", dp[i][j]);  // bool 轉成 int 印
        //}
        //printf("\n");
    //}
    //製作輸出字串
    //int* arr = (int*)malloc(arrSize * sizeof(int));//不知道為什麼報錯
    //char* ans = (char*)malloc(maxLen * sizeof(char));
    //for (i = 0; i < maxLen; i++){
        //ans[i] = s[start + i];
    //}

    static char res[1001];  // 題目限制 ≤ 1000
    //strncpy(res, s + start, maxLen);//等效下面
    for (i = 0; i < maxLen; i++){
        res[i] = s[start + i];
    }
    res[maxLen] = '\0';
    return res;
}