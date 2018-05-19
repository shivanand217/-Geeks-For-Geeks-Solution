import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.InputMismatchException;

import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class problem_978B {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int n = Integer.parseInt(s);
        String str = br.readLine();

        int i=0,cnt=0,len;
        int ans=0;
        len = str.length();

        while(i < n) {
            if(i == n-1 || i == n-2) {
                break;
            }
            if(str.charAt(i)=='x' && str.charAt(i+1)=='x' && str.charAt(i+2)=='x') {
                cnt=0;
                while(str.charAt(i)=='x'){
                    cnt++;
                    i++;
                    if(i == n) {
                        break;
                    }
                }
                ans += (cnt-2);
                cnt = 0;
            } else {
                i++;
            }
        }

        System.out.println(ans);
    }
}
