import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class pablo_photography {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int t = Integer.parseInt(str);

        while (t > 0) {

            long one = 0;
            long two = 0;
            str = br.readLine();
            int n = Integer.parseInt(str);
            String[] line = br.readLine().split(" ");

            int a[] = new int[line.length];

            for(int i = 0; i < line.length; i++) {
                a[i] = Integer.parseInt(line[i]);
            }

            for (int i = 0; i < line.length ; i++) {
                if (i % 2 == 0) {
                    one += a[i];
                } else {
                    two += a[i];
                }
            }

            long ans = Math.abs(one - two);
            System.out.println(ans);

            t -= 1;
        }
    }
}
