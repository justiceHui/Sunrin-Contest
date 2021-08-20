import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] g = new int[n+1][n+1];
        int[] a = new int[n+1];
        int[] b = new int[n+1];
        int pv = 0;
        for(int i=1; i<n; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            g[u][v] = g[v][u] = 1;
        }
        if(n <= 4){
            for(int i=1; i<=n; i++){
                for(int j=i+1; j<=n; j++){
                    if(g[i][j] == 0){
                        pv++; a[pv] = i; b[pv] = j;
                    }
                }
            }
        }
        else{
            for(int i=2; i<=n; i++){
                if(g[1][i] == 0){
                    pv++; a[pv] = 1; b[pv] = i;
                }
            }
        }
        System.out.println(pv);
        System.out.println(n <= 4 ? 1 : 2);
        for(int i=1; i<=pv; i++) System.out.printf("%d %d\n", a[i], b[i]);
    }
}