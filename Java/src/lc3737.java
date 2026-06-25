public class lc3737 {
    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) cnt++;

                int gap = j - i + 1;
                if (cnt > gap / 2) ans++;
            }
        }
        return ans;
    }
}
