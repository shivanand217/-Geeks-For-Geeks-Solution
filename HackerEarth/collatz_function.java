import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class collatz_function {

    public static long[] a = new long[33000];
    public static PrintWriter out = new PrintWriter(System.out);

    private static long solve(int num) {
        long steps = 0;
        while(num > 1) {
            if(num % 2 == 1){
                num = 3 * num + 1;
            } else {
                num /= 2;
            }
            steps++;
        }
        return steps;
    }

    private static void pre() {
        a[1] = 0;
        a[2] = 1;
        for(int i = 0; i < 33000; i++) {
            a[i] = solve(i);
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int t = Integer.parseInt(s);
        pre();

        while(t > 0) {
            s = br.readLine();
            int n = Integer.parseInt(s);
            System.out.println(a[n]);
            t -= 1;
        }
    }
}
