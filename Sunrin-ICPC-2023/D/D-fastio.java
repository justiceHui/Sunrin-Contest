import java.util.*;
import java.io.*;

public class Main{
    static long f(long x){ return x * (x + 1) / 2; }
    static long[] get(long[] a){
        int n = a.length;
        long mx = 0, le = 0, ri = 0;
        long vm = 0, vl = 0, vr = 0;
        long[] res = new long[3];
        for(int i=0; i<n; i++){
            vm = (vm >= 0 ? vm : 0) + a[i];
            mx = vm > mx ? vm : mx;
        }
        for(int i=0; i<n; i++){
            vl += a[i];
            le = vl > le ? vl : le;
        }
        for(int i=n-1; i>=0; i--){
            vr += a[i];
            ri = vr > ri ? vr : ri;
        }
        res[0] = mx; res[1] = le; res[2] = ri;
        return res;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] a = new long[n];
        String[] line = br.readLine().split(" ");
        for(int i=0; i<n; i++) a[i] = Integer.parseInt(line[i]);
        long s = 0;
        for(int i=0; i<n; i++) s += a[i];

        long[] a4 = new long[n*4];
        for(int i=0; i<n*4; i++) a4[i] = a[i%n] - i - 1;
        long res = get(a4)[0];
        if(res < 0) res = 0;

        long k = (2 * s + (long)n * n - n) / (2 * (long)n * n);
        if(k <= 4){ System.out.println(res); return; }

        long[] le = new long[n*2], ri = new long[n*2];
        for(int i=0; i<n+n; i++) le[i] = a[i%n] - i - 1;
        for(int i=0; i<n+n; i++) ri[i] = a[i%n] - (k-1) * n - i - 1;
        long sum = s * (k - 3) - f((k-1)*n) + f(2*n);
        long tmp = get(le)[2] + sum + get(ri)[1];
        if(tmp > res) res = tmp;

        System.out.println(res);
        br.close();
    }
}