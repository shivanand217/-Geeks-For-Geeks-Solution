import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class problem989B {

    public static void main(String args[]) throws IOException {

        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int m,n;
        String[] str = br.readLine().split(" ");

        n=Integer.parseInt(str[0]);
        m=Integer.parseInt(str[1]);

        String s;
        s = br.readLine();

        StringBuilder st = new StringBuilder(s);

        int i=0, j=m;
        if(st.length() == 1 || (n == m)) {
            System.out.println("No");
            System.exit(0);
        }

        if(j >= n) {
            for(int k=0; k < st.length(); k++){
                if(st.charAt(k)=='.') {
                    st.setCharAt(k, '0');
                }
            }
            System.out.println(st);
            System.exit(0);
        }

        boolean ans = true;
        int old = j;

        while(i < st.length()-m) {
            if(j >= n) {
                if(ans == true) {
                    System.out.println("No");
                    System.exit(0);
                } else {
                    break;
                }
            }
            if(st.charAt(i) != st.charAt(j)) {
                ans=false;
                if(st.charAt(j)=='.'){
                    if(st.charAt(i)=='1'){
                        st.setCharAt(j, '0');
                    } else {
                        st.setCharAt(j, '1');
                    }
                }
                if(st.charAt(i)=='.') {
                    if(st.charAt(j)=='1'){
                        st.setCharAt(i, '0');
                    } else if(st.charAt(j)=='0'){
                        st.setCharAt(i, '1');
                    }
                }
            } else {
                if(st.charAt(i)=='.' && st.charAt(j)=='.') {
                    st.setCharAt(i, '0');
                    st.setCharAt(j, '1');
                    ans=false;
                }
            }
            i++; j++;
            if(j >= n) {
                if(ans == true) {
                    System.out.println("No");
                    System.exit(0);
                } else {
                    break;
                }
            }
        }

        while(i < st.length()){
            if(st.charAt(i)=='.') {
                st.setCharAt(i, '1');
            }
            i++;
        }
        System.out.println(st);
    }

}
