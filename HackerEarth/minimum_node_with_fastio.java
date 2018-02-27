import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.InputMismatchException;

public class minimum_node_with_fastio {

    static InputReader in = new InputReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
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

    public static void main(String args[]) {
        int n = in.readInt();
        int q = in.readInt();
        String s = "";
        // initialize the graph with nodes
        graph = new ArrayList[n+1];

        for(int i=1;i<=n; i++) {
            val[i] = in.readLong();
            // initialize each node with an Arraylist<>
            graph[i] = new ArrayList<Integer>();
        }
        for(int i=1;i<=n-1; i++) {
            int u = in.readInt();
            int v = in.readInt();
            graph[u].add(v);
            graph[v].add(u);
        }
        for(int i=1;i<=q;i++) {
            int x = in.readInt();
            long k = in.readLong();
            ans = Integer.MAX_VALUE;
            dfs(x,0,0,0,k);
            if(ans == Integer.MAX_VALUE) {
                ans = -1;
            }
            out.println(ans);
        }

        out.flush();
        out.close();
    }

    /**
     * ignore from here its just some Fast I/O
     * and other useful Stuff's
     */
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, readInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }

    }

    public static ArrayList<Long> sieve(long n) {

        int i, j;
        ArrayList<Long> list = new ArrayList<Long>();
        int n_n = (int) Math.sqrt(n);
        boolean tp[] = new boolean[100000001];
        tp[0] = tp[1] = true;
        for (i = 2; i <= n_n; i++) {
            if (!tp[i])
                for (j = 2 * i; j <= n; j += i) {
                    tp[j] = true;
                }
        }
        for (j = 2; j <= n; j++)
            if (!tp[j])
                list.add((long) j);
        return list;
    }

    public static ArrayList<Integer> sieve(int n) {

        int i, j;
        ArrayList<Integer> list = new ArrayList<Integer>();
        int n_n = (int) Math.sqrt(n);
        boolean tp[] = new boolean[n + 1];
        tp[0] = tp[1] = true;
        for (i = 2; i <= n_n; i++) {
            if (!tp[i])
                for (j = 2 * i; j <= n; j += i) {
                    tp[j] = true;
                }
        }
        for (j = 2; j <= n; j++)
            if (!tp[j])
                list.add(j);
        return list;

    }

    public static boolean[] sieve1(int n) {
        int i, j;
        int n_n = (int) Math.sqrt(n);
        boolean tp[] = new boolean[n + 1];
        tp[0] = tp[1] = true;
        for (i = 2; i <= n_n; i++) {
            if (!tp[i])
                for (j = 2 * i; j <= n; j += i) {
                    tp[j] = true;
                }
        }
        return tp;
    }

    public static ArrayList<Long> segmented_sieve(long m, long n) {
        long tp, lb, ub, j;
        long n_n = (long) Math.sqrt(n);
        ArrayList<Long> ans = sieve(n_n);
        if (n_n < m)
            lb = m;
        else
            lb = n_n + 1;
        ub = lb + n_n;

        ArrayList<Long> ans1 = new ArrayList<Long>();

        while (ub <= n) {
            boolean mark[] = new boolean[(int) (ub - lb + 2)];
            for (long i : ans) {
                tp = (long) Math.ceil((double) lb / i) * i;
                for (j = tp; j <= ub; j += i)
                    mark[(int) (j - lb)] = true;
            }
            for (j = lb; j <= ub; j++)
                if (!mark[(int) (j - lb)])
                    ans.add(j);
            lb = ub + 1;
            ub = lb + n_n;
            if (lb > n)
                break;
            if (ub >= n)
                ub = n;
        }
        for (long i : ans)
            if (i >= m && i <= n)
                ans1.add(i);
        return ans1;
    }

    public static long[] divisors(long m, long n) {
        ArrayList<Integer> ans = sieve((int) Math.sqrt(n));
        boolean check[] = sieve1(10000);
        long mark[] = new long[(int) (n - m + 1)];
        for (long i = m; i <= n; i++)
            mark[(int) (i - m)] = i;
        long div[] = new long[(int) (n - m + 1)];
        set(div, 1);
        for (long i : ans) {
            for (long j = (long) Math.ceil((double) m / i) * i; j <= n; j += i) {
                long tp = mark[(int) (j - m)];
                int ct = 0;
                while (tp % i == 0) {
                    ct++;
                    tp /= i;
                }
                div[(int) (j - m)] *= ct + 1;
                mark[(int) (j - m)] = tp;
            }
        }
        return div;
    }

    public static void set(long a[], long val) {
        for (int i = 0; i < a.length; i++)
            a[i] = val;
    }

    public static void set(int a[], int val) {
        for (int i = 0; i < a.length; i++)
            a[i] = val;
    }

    public static int lowerBound(int a[], int x, int n) {
        int l = 0;
        int h = n;
        while (l < h) {
            int mid = (l + h) / 2;
            if (x <= a[mid]) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    public static int upperBound(int a[], int x, int n) {
        int l = 0;
        int h = n;
        while (l < h) {
            int mid = (l + h) / 2;
            if (x >= a[mid]) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return l;
    }
}

