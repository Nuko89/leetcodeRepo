import java.util.ArrayList;
import java.util.List;
import java.util.ArrayDeque;
import java.util.Queue;

public class lc3310 {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        int m = invocations.length;
        
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {//set n nodes
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {//add adj
            adj.get(invocations[i][0]).add(invocations[i][1]);
        }

        //Step 1 : from k to mark suspicious nodes
        boolean sus[] = new boolean[n];//inital value == false
        sus[k] = true;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(k);
        while(!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj.get(u)) {
                if (sus[v] == false) {
                    sus[v] = true;
                    q.add(u);
                }
            }
        }

        //Step 2 : check any external calls the sus collection
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {//add adj
            int a = invocations[i][0];
            int b = invocations[i][1];
            if (sus[b] && !sus[a]) {
                for (int j = 0; j < n; j++) {
                    res.add(j);
                }
                return res;
            }
        }

        for(int i = 0; i < n; i++) {
            if (!sus[i]) res.add(i);
        }
        return res;
    }
}
