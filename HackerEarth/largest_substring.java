import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class largest_substring {

    static int[] count = new int[26];
    static int[][] prefix = new int[26][100005];

    static boolean validate(int x,int y) {
        int cnt;
        for(int i = 0; i < 26; i++) {
            if(x != 0) {
                cnt = prefix[i][y] - prefix[i][x-1];
            } else {
                cnt = prefix[i][y];
            }
            if(cnt > count[i])
                return false;
        }
        return true;
    }

    static int solve(int x,int l,int r) {
        if(l > r) return -1;
        int mid = (l + (r - l)/2);
        if(validate(x, mid) == true) {
            if(validate(x, mid+1) == false) {
                return mid;
            } else {
                return solve(x, mid+1, r);
            }
        } else {
            return solve(x, l, mid-1);
        }
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int n = Integer.parseInt(str);

        for(int i=0; i<26; i++) {
            for(int j=0; j<n; j++) {
                prefix[i][j]=0;
            }
        }

        String s = br.readLine();
        String[] s1 = br.readLine().split(" ");

        for(int i=0; i < 26; i++) {
            count[i] = Integer.parseInt(s1[i]);
        }

        int p;
        for(int i=0; i < n; i++) {
            p = s.codePointAt(i);
            prefix[p - 97][i]=1;
        }

        for( int i=0; i < 26; i++ ) {
            for( int j=1; j<n; j++ ) {
                prefix[i][j] = prefix[i][j] + prefix[i][j-1];
            }
        }

        int mx = 0;
        int l=-1, r=-1, res=-1;

        for(int i = 0; i < n; i++) {
            if(validate(i, n-1) == true) {
                res = n-1;
            } else {
                res = solve(i, i, n-1 );
            }
            if(res != -1 && res - i + 1 > mx) {
                mx = res-i+1;
                l = i+1;
                r = res+1;
            }
        }
        if(mx > 0) {
            System.out.println(l+" "+r);
        } else {
            System.out.println("No Solution");
        }
    }
}
