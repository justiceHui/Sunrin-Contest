import java.util.*;
import java.io.*;

public class Main{
    static boolean check(long[] a, long k, long x){
        long res = 0;
        for(int i=0; i<a.length; i++) if(a[i] > x) res += a[i] - x;
        return res <= k;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        long k = Long.parseLong(line[1]);
        long[] a = new long[n];
        line = br.readLine().split(" ");
        for(int i=0; i<n; i++) a[i] = Long.parseLong(line[i]);
        long l = 0, r = 1000000000000l;
        while(l < r){
            long m = (l + r) / 2;
            if(check(a, k, m)) r = m;
            else l = m + 1;
        }
        System.out.println(r);
        br.close();
    }
}