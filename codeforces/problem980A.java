import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class problem980A {

    static int pearl=0,dash=0;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '-'){
                dash++;
            } else {
                pearl++;
            }
        }

        if(pearl == 0) {
            System.out.println("YES");
        } else {

            if(dash%pearl == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
