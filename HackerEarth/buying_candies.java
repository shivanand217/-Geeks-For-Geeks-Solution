import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class buying_candies {

    static long num_divisors(long x) {
        long sq = (long) Math.sqrt(x);
        long c=0;
        for(long i=1; i <= sq; i++) {
            if(x%i == 0) {
                c += 2;
                if(i == (x/i)) {
                    c -= 1;
                }
            }
        }
        return c;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int t = Integer.parseInt(str);

        while(t > 0) {
            str = br.readLine();
            int n = Integer.parseInt(str);
            long ans = Long.MAX_VALUE;
            while(true) {
                long p = num_divisors(n);
                ans = Long.min(ans, (long)n*p);
                if(p <= 2){
                    break;
                }
                n++;
            }
            System.out.println(ans);
            t-=1;
        }
    }

}
