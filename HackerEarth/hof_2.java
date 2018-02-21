import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class hof_2 {
    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int t = Integer.parseInt(str);
        long bag,hi,sum;

        while(t > 0) {
            str = br.readLine();
            int n = Integer.parseInt(str);
            if(n < 7) {
                System.out.println("0");
                continue;
            }
            bag=(n/7);
            hi=(bag*7);
            sum=(bag*(7+hi))/2;
            System.out.println(sum);
            t -= 1;
        }

    }

}
