import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Holi_And_Colorful_houses {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int t = Integer.parseInt(s);
        int N = 0, Q = 0;
        String p = "";
        int cost1 = 0, cost2 = 0;
        int st =0, m =0, n =0, len =0;

        while(t-- > 0) {
            String[] str = br.readLine().split(" ");
            N = Integer.parseInt(str[0]);
            Q = Integer.parseInt(str[1]);

            p = br.readLine();
            len = p.length();

            for(int i = 0; i < Q; i++) {
                cost1 = 0;
                cost2 = 0;
                str = br.readLine().split(" ");
                m = Integer.parseInt(str[0]);
                n = Integer.parseInt(str[1]);

                m -= 1;
                n -= 1;

                /** traverse anti-clock-wise **/
                /** here we will get the cost1 due to traversing in anti-clock-wise **/
                st = m;
                while(st != n) {
                    if(st == n)
                        break;
                    if(st == 0) {
                        st = len-1;
                        if(p.charAt(st) != p.charAt(0)) {
                            cost1++;
                        }
                    } else {
                        st--;
                        if(p.charAt(st) != p.charAt(st+1)){
                            cost1++;
                        }
                    }
                }

                st = m;
                while(st != n) {
                    if(st == n)
                        break;
                    if(st == len-1){
                        st = 0;
                        if(p.charAt(len-1) != p.charAt(0)){
                            cost2++;
                        }
                    } else {
                        st++;
                        if(p.charAt(st) != p.charAt(st-1)){
                            cost2++;
                        }
                    }
                }

                System.out.println(Math.min(cost1,cost2));
            }
        }
    }
}
