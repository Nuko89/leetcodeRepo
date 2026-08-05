import java.util.ArrayList;
import java.util.List;

public class lc3731 {
    public List<Integer> findMissingElements(int[] nums) {
        int n = nums.length;
        int numlst[] = new int[101];//Java 的基本型別陣列在建立時預設就會全部初始化為 0
        
        int begin = nums[0], end = nums[0];
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            numlst[x] = 1;
            begin   = Math.min(begin, x);
            end     = Math.max(end, x);
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = begin; i <= end; i++) {
            if (numlst[i] == 0) ans.add(i);
        }
        return ans;
    }
}

