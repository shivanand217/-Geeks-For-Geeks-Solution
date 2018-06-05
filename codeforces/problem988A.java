import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class problem988A {

    static long sum, new_sum;
    static int k,n,tmp,tmp1;
    //static ArrayList<Pair<Integer, Pair<Integer,Long> > > l = new ArrayList<Pair<Integer,Pair<Integer,Long> > >();
    static ArrayList<Integer> arr;
    //static Pair<Integer, Pair<Integer,Long> > P = new Pair<Integer, Pair<Integer, Long> >();

    private static class Pair implements Comparable<Pair> {
        public Integer v1;
        public Integer v2;
        public Long v3;

        Pair(Integer v1, Integer v2, Long v3){
            this.v1 = v1;
            this.v2 = v2;
            this.v3 = v3;
        }

        public int compareTo(Pair that) {
            return this.v3.compareTo(that.v3);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        k = Integer.parseInt(s);

        ArrayList<Pair> pairList = new ArrayList<>();
        Pair p;

        for(int i=1; i<=k; i++) {
            sum = 0;
            s = br.readLine();
            n = Integer.parseInt(s);
           // arr.clear();

            String[] a = br.readLine().split(" ");

            for(int j=0; j < a.length; j++) {
                tmp1 = Integer.parseInt(a[j]);
                sum += tmp1;
                arr.add(tmp1);
            }

            for(int j=0; j<arr.size(); j++) {
                new_sum = sum - arr.get(j);

                p = new Pair(i, j+1, new_sum);
                pairList.add(p);
                //l.add(new Pair<Integer, Pair<Integer,Long> > (i, (j+1, new_sum)));
            }
        }

        System.out.println(pairList.size());

        int x,y;
        int I,J;
        boolean ans= false;

        //arr.sort();
    }
}
