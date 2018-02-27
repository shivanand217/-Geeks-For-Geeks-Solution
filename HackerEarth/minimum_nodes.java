import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class minimum_nodes {
    static int max_node = 100005;
    static ArrayList<Integer> graph[];
    static long[] val = new long[max_node];
    static int ans = Integer.MAX_VALUE;

    static void dfs(int node,int cnt,int par,long sum,long k) {
        sum += val[node];
        cnt += 1;
        if(sum >= k) {
            ans = Integer.min(ans, cnt);
        }
        for(int it: graph[node]) {
            if(it == par) {
                continue;
            }
            dfs(it,cnt,node,sum,k);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int q = Integer.parseInt(str[1]);

        // initialize the graph with nodes
        graph = new ArrayList[n+1];

        String[] str1 = br.readLine().split(" ");
        for(int i=0; i < str1.length; i++) {
            val[i+1] = Long.parseLong(str1[i]);
            // initialize each node with an Arraylist<>
            graph[i+1] = new ArrayList<Integer>();
        }

        for(int i=1; i<=n-1; i++) {
            str = br.readLine().split(" ");
            int u = Integer.parseInt(str[0]);
            int v = Integer.parseInt(str[1]);
            graph[u].add(v);
            graph[v].add(u);
        }

        for(int i=1; i<=q; i++) {
            str = br.readLine().split(" ");
            int x = Integer.parseInt(str[0]);
            long k = Long.parseLong(str[1]);
            ans = Integer.MAX_VALUE;
            dfs(x,0,0,0,k);
            if(ans == Integer.MAX_VALUE) {
                ans = -1;
            }
            System.out.println(ans);
        }

    }
}
