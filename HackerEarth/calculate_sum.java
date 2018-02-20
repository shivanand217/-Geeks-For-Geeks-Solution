import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class calculate_sum {

    static String mod = "1000000007";

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int t = Integer.parseInt(str);

        while(t > 0) {
            str = br.readLine();
            long n = Long.parseLong(str);

            BigInteger ans = BigInteger.ONE;
            BigInteger N = BigInteger.valueOf(n);
            BigInteger three = BigInteger.valueOf(Integer.parseInt(String.valueOf('3')));
            BigInteger seven = BigInteger.valueOf(Integer.parseInt(String.valueOf('7')));
            BigInteger one = BigInteger.ONE;
            BigInteger two = BigInteger.valueOf(Integer.parseInt(String.valueOf('2')));

            ans = ans.multiply(N).multiply(N.add(one)).multiply((three.multiply(N).multiply(N)).add(seven.multiply(N)).add(two));

            ans = ans.divide(BigInteger.valueOf(Long.parseLong(String.valueOf("24"))));
            ans = ans.mod(BigInteger.valueOf(Long.parseLong(String.valueOf(mod))));

            System.out.println(ans);

            t -= 1;
        }

    }
}
