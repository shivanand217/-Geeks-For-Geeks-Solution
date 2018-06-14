import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class problem989A {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int i=0;
        boolean ans=false;

        if(s.length() < 3) {
            System.out.println("No");
            System.exit(0);
        }

        while(i < s.length()-2) {
            if(s.charAt(i) != s.charAt(i+1) && s.charAt(i+1) != s.charAt(i+2) && s.charAt(i) != s.charAt(i+2)
                    && s.charAt(i)!='.' && s.charAt(i+1)!='.' && s.charAt(i+2)!='.'){
                ans=true;
                break;
            }
            i++;
        }

        if(ans == false) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }

}
