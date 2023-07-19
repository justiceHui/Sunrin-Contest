import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        double[] d = new double[n+1];
        int[][] g = new int[n+1][n+1];
        int[] cnt = new int[n+1];
        for(int i=0; i<m; i++){
            int s = sc.nextInt();
            int e = sc.nextInt();
            g[s][e] = 1; cnt[s]++;
        }
        d[1] = 100;
        for(int i=1; i<=n; i++){
            if(cnt[i] == 0) continue;
            double nxt = d[i] / cnt[i];
            for(int j=1; j<=n; j++) if(g[i][j] == 1) d[j] += nxt;
            d[i] = 0;
        }
        double mx = 0;
        for(int i=1; i<=n; i++) if(d[i] > mx) mx = d[i];
        System.out.println(mx);
        sc.close();
    }
}