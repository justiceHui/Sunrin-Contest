import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        for(int tc=1; tc<=tt; tc++){
            int n = sc.nextInt();
            long t = sc.nextLong();
            long[] a = new long[n+1];
            long[] b = new long[n+1];
            long[] c = new long[n+1];
            long[] d = new long[n+1];
            long[] e = new long[n+1];
            for(int i=1; i<=n; i++){
                a[i] = sc.nextLong();
                b[i] = sc.nextLong();
                c[i] = sc.nextLong();
                d[i] = sc.nextLong();
            }
            for(int i=0; i<=n; i++) e[i] = sc.nextLong();

            long l = 0, r = t, res = 0;
            while(l < r){
                long m = (l + r) / 2, now = m + e[0];
                for(int i=1; i<=n; i++){
                    if(c[i] > now) now = c[i];
                    long x = (now - c[i]) / a[i];
                    if(c[i]+a[i]*x <= now && now+d[i] <= c[i]+a[i]*x+b[i]) now += d[i] + e[i];
                    else now = c[i] + a[i]*(x+1) + d[i] + e[i];
                }
                if(now == t){ res = 1; break; }
                if(now > t) r = m; else l = m + 1;
            }
            if(res == 1) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}