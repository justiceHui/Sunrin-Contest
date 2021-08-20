import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), inf = 1000000000;
        int[] a = new int[n+1];
        int[][] dp = new int[n+1][4];
        int[][] prv = new int[n+1][4];

        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        for(int i=1; i<=n; i++) for(int j=0; j<=3; j++) dp[i][j] = inf;

        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=3; j++){
                if(dp[i-1][j] <= a[i] && dp[i][j] > a[i]){
                    dp[i][j] = a[i];
                    prv[i][j] = j;
                }
                if(j > 0 && dp[i][j] > dp[i-1][j-1]){
                    dp[i][j] = dp[i-1][j-1];
                    prv[i][j] = j-1;
                }
            }
        }

        int isFinished = 0;
        for(int ti=0; ti<=3; ti++){
            if(isFinished == 0 && dp[n][ti] != inf){
                System.out.printf("YES\n%d\n", ti);
                for(int i=n, j=ti; i>=1; j=prv[i][j], i--){
                    if(prv[i][j] == j-1){
                        System.out.printf("%d %d\n", i, dp[i][j]);
                    }
                }
                isFinished = 1;
            }
        }

        if(isFinished == 0){
            System.out.println("NO");
        }
    }
}