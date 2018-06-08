import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class problem965A {

    static int k=0,n=0,s=0,p=0;
    static int sheets,packs,total_sheets;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        k = Integer.parseInt(str[0]);
        n = Integer.parseInt(str[1]);
        s = Integer.parseInt(str[2]);
        p = Integer.parseInt(str[3]);

        if(n%s == 0) {
            sheets = n/s;
        } else {
            sheets = n/s + 1;
        }

        total_sheets = k*sheets;

        if(total_sheets%p == 0){
            packs=total_sheets/p;
        } else {
            packs=total_sheets/p+1;
        }

        System.out.println(packs);
    }
}
