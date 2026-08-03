public class lc877 {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int dp[][] = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = Math.max(
                    piles[i] - dp[i + 1][j],   // 拿左邊，剩下的 [i+1, j] 換對手當「先手」
                    piles[j] - dp[i][j - 1]    // 拿右邊，剩下的 [i, j-1] 換對手當「先手」
                );
            }
        }

        return dp[0][n-1] >= 0;
    }
}
