public class lc1406 {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;
        int dp[] = new int[n + 1];
        int suffixSum[] = new int[n + 1];

        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + stoneValue[i];
        }
        
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = Integer.MIN_VALUE;
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                int take = suffixSum[i] - suffixSum[i + k];
                dp[i] = Math.max(dp[i], take - dp[i + k]);
            }
        }

        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
}
