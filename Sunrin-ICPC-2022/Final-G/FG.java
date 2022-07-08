import java.util.*;

public class Main{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int q = sc.nextInt();
        long[] a = new long[n+2], x = new long[n+2];
        long[][] w = new long[m+1][n+2];

        for(int i=1; i<=m; i++){
            int cnt = sc.nextInt();
            int[] idx = new int[cnt+1];
            for(int j=0; j<cnt; j++) idx[j] = sc.nextInt();
            idx[cnt] = n + 1;
            for(int j=0; j<cnt+1; j++) w[i][idx[j]] = sc.nextInt();
        }
        for(int i=1; i<=m; i++){
            int t = sc.nextInt();
            for(int j=1; j<=n+1; j++) a[j] += t * w[i][j];
        }
        int t = sc.nextInt(); a[n+1] += t;

        for(int iter=1; iter<=q; iter++){
            for(int i=1; i<=n; i++) x[i] = sc.nextInt();
            x[n+1] = 1;
            long res = 0;
            for(int i=1; i<=n+1; i++) res += a[i] * x[i];
            System.out.println(res);
        }
    }
}