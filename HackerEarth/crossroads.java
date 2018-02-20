import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class crossroads {

    static char[][] a = new char[20][20];
    static int n;
    static int[] dx = {1,0,-1,0,-1,1,-1,1};
    static int[] dy = {0,1,0,-1,-1,-1,1,1};

    static boolean _search(int x, int y, String s) {
        int len = s.length();
        int k;
        for( int d = 0; d < 8; d++ ) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            for( k = 1; k < len; k++ ) {
                if(xx < 0 || xx >= n || yy < 0 || yy >= n) {
                    break;
                }
                if( a[xx][yy] != s.charAt(k) )
                    break;
                xx = xx + dx[d];
                yy = yy + dy[d];
            }
            if(k == len) {
                return true;
            }
        }
        return false;
    }

    static boolean pat(String s) {
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                if(a[i][j] == s.charAt(0)) {
                    if(_search(i, j, s) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        n = Integer.parseInt(s);

        for(int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            for(int j=0; j<n; j++){
                a[i][j] = str[j].charAt(0);
            }
        }
        int q;
        s = br.readLine();
        q = Integer.parseInt(s);
        String tmp;
        boolean ans = true;

        while( q > 0 ) {
            tmp = br.readLine();
            if(pat(tmp) == false){
                ans=false;
            }
            q -= 1;
        }
        if(ans == false) {
            System.out.println("False");
        } else {
            System.out.println("True");
        }
        
    }
}
