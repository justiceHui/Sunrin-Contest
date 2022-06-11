import java.util.Scanner;

public class Main{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1];
        int[] c = new int[101];
        int[][] dp = new int[101][101];
        int mx = 0;

        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        for(int i=1; i<=n; i++) c[a[i]] += 1;
        for(int i=1; i<=100; i++) if(c[i] > mx) mx = c[i];

        for(int d=1; d<=100; d++){
            for(int i=1; i<=n; i++){
                if(a[i] - d >= 1 && dp[d][a[i]] < dp[d][a[i]-d] + 1) dp[d][a[i]] = dp[d][a[i]-d] + 1;
                else if(dp[d][a[i]] < 1) dp[d][a[i]] = 1;
                if(mx < dp[d][a[i]]) mx = dp[d][a[i]];
            }
        }

        for(int i=1, j=n, t; i<=j; i++, j--){
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
        for(int i=1; i<=100; i++) for(int j=1; j<=100; j++) dp[i][j] = 0;

        for(int d=1; d<=100; d++){
            for(int i=1; i<=n; i++){
                if(a[i] - d >= 1 && dp[d][a[i]] < dp[d][a[i]-d] + 1) dp[d][a[i]] = dp[d][a[i]-d] + 1;
                else if(dp[d][a[i]] < 1) dp[d][a[i]] = 1;
                if(mx < dp[d][a[i]]) mx = dp[d][a[i]];
            }
        }

        System.out.println(mx);
    }
}