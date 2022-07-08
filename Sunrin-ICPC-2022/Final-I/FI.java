import java.util.Scanner;

public class Main {
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), res = 0;
        int[][] a = new int[n+1][n+1];
        int[][] d = new int[n+1][n+1];
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) a[i][j] = sc.nextInt();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int mx = 0;
                for(int r=1; r<=i; r++){
                    for(int c=1; c<=j; c++){
                        if(a[r][c] < a[i][j] && mx < d[r][c]) mx = d[r][c];
                    }
                }
                d[i][j] = mx + 1;
                if(d[i][j] > res) res = d[i][j];
            }
        }
        System.out.println(res);
    }
}