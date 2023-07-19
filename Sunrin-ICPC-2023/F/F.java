import java.util.*;

public class Main{
    static boolean check(long[] a, long k, long x){
        long res = 0;
        for(int i=0; i<a.length; i++) if(a[i] > x) res += a[i] - x;
        return res <= k;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[] a = new long[n];
        for(int i=0; i<n; i++) a[i] = sc.nextLong();
        long l = 0, r = 1000000000000l;
        while(l < r){
            long m = (l + r) / 2;
            if(check(a, k, m)) r = m;
            else l = m + 1;
        }
        System.out.println(r);
        sc.close();
    }
}