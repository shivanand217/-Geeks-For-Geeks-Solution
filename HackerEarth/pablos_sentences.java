import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class pablos_sentences {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int t = Integer.parseInt(str);

        while(t > 0) {
            String s;
            s = br.readLine();

            int len = s.length() - 1;

            int[] vow = new int[len+1];
            int[] con = new int[len+1];

            for(int i=0; i<len+1; i++) {
                vow[i] = 0; con[i] = 0;
            }

            for(int i=len; i >= 0; i--) {
                if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'){
                    if(i != len) {
                        vow[i] = vow[i+1]+1;
                        con[i] = con[i+1];
                    } else {
                        vow[i] = 1;
                    }
                } else {
                    if(i != len){
                        con[i] = con[i+1]+1;
                        vow[i] = vow[i+1];
                    } else {
                        con[i] = 1;
                    }
                }
            }

            long ans = 0;
            for( int i=0; i <= len; i++ ) {
                if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'){
                    ans += con[i];
                } else {
                    ans += vow[i];
                }
            }
            System.out.println(ans);

            t-=1;
        }
    }
}
