import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class tidy_number {

    public static boolean check( int num ) {
        String s = "";
        int p;

        while( num > 0 ) {
            p = num%10;
            s += Integer.toString(p);
            num /= 10;
        }

        StringBuilder inp1 = new StringBuilder();
        inp1.append(s);
        inp1 = inp1.reverse();
        int i = 1;

        while( i < inp1.length() ) {
            char p1 = s.charAt(i);
            if( Character.getNumericValue(s.charAt(i)) > Character.getNumericValue(s.charAt(i-1)) ) {
                return false;
            }
            i++;
        }

        return true;
    }

    public static int solve(int num) {
        while(num > 0) {
            if(check(num) == true) {
                return num;
            }
            num -= 1;
        }
        return 1;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int t = Integer.parseInt(s);
        int ans,n;

        while(t > 0) {
            s = br.readLine();
            n = Integer.parseInt(s);
            ans = solve(n);
            System.out.println(ans);
            t -= 1;
        }
    }
}
