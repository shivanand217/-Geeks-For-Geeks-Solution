import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class points_in_rectangle {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int t = Integer.parseInt(s);
        int x1,y1,x2,y2,ans,n;
        int X1,Y1,X2,Y2,X,Y;

        while(t-- > 0) {
            ans = 0;
            String[] str = br.readLine().split(" ");

            x1 = Integer.parseInt(str[0]);
            y1 = Integer.parseInt(str[1]);
            x2 = Integer.parseInt(str[2]);
            y2 = Integer.parseInt(str[3]);

            if(x1 > x2) {
                X1=x1;
                X2=x2;
            } else {
                X1=x2;
                X2=x1;
            }
            if(y1 > y2) {
                Y1=y1;
                Y2=y2;
            } else {
                Y1=y2;
                Y2=y1;
            }

            s = br.readLine();
            n = Integer.parseInt(s);
            for(int i=0; i<n; i++) {
                String[] s1 = br.readLine().split(" ");
                X = Integer.parseInt(s1[0]);
                Y = Integer.parseInt(s1[1]);
                if( (X < X1 && X > X2) && (Y < Y1 && Y > Y2) )
                    ans++;
            }

            System.out.println(ans);
        }
    }
}
