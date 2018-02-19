import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class triangle_formation {

    public static boolean check(long a, long b, long c) {
        if( a <= 0 || b <= 0 || c <= 0 ) {
            return false;
        }

        if( a+c <= b || a+b <= c || b+c <= a ) {
            return false;
        }

        BigInteger f1 = BigInteger.valueOf(1);
        BigInteger f2 = BigInteger.valueOf(1);
        BigInteger f3 = BigInteger.valueOf(1);

        f1 = f1.multiply(BigInteger.valueOf(a));
        f1 = f1.multiply(BigInteger.valueOf(a));
        f2 = f2.multiply(BigInteger.valueOf(b));
        f2 = f2.multiply(BigInteger.valueOf(b));
        f3 = f3.multiply(BigInteger.valueOf(c));
        f3 = f3.multiply(BigInteger.valueOf(c));

        //System.out.println(f1 + " " + f2 + " " + f3);

        if( (f1.add(f2)).equals(f3) || (f1.add(f3)).equals(f2) || (f2.add(f3)).equals(f1)) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int t = Integer.parseInt(str);

        for( int i = 0; i < t; i++ ) {
            String[] s = br.readLine().split(" ");
            long[] a = new long[s.length];

            for(int j = 0; j < s.length; j++ ) {
                a[j] = Long.parseLong(s[j]);
            }

            long a1 = a[0];
            long b = a[1];
            long c = a[2];
            long x = a[3];

            if( (check(a1+x,b+x,c) == true) || (check(a1+x, b, c+x) == true) || (check(a1, b+x, c+x) == true) ){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

}
