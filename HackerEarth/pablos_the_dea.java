import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class pablos_the_dea {

    public static long s(long n) {
        long sum = 0;
        while(n > 0){
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }

    public static long solve(long N, long M) {
        long lo = 1;
        long hi = N;
        long mid, sum, temp = -1;

        while(lo <= hi) {
            mid = (lo + (hi - lo)/2);
            sum = s(mid);
            if( mid - sum >= M ) {
                temp = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if(temp == -1) {
            return 0;
        } else {
            return (N - temp + 1);
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int t = Integer.parseInt(str);

        while(t > 0) {
            String[] s = br.readLine().split(" ");
            long[] ar = new long[s.length];

            for( int i=0; i < s.length; i++ ) {
                ar[i] = Long.parseLong(s[i]);
            }

            long N = ar[0];
            long M = ar[1];
            long ans = solve(N,M);

            System.out.println(ans);

            t-=1;
        }
    }
}
