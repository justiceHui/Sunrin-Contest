import java.util.Scanner;

public class Main{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1];
        int[] c = new int[101];
        int[][] idx = new int[n+1][101];
        int[] lst = new int[101];
        int mx = 0;

        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        for(int i=1; i<=n; i++) c[a[i]] += 1;
        for(int i=1; i<=100; i++) if(c[i] > mx) mx = c[i];

        for(int i=1; i<=100; i++) lst[i] = -1;
        for(int i=n; i>=1; i--){
            for(int j=1; j<=100; j++) idx[i][j] = lst[j];
            lst[a[i]] = i;
        }

        for(int d=-100; d<=100; d++){
            if(d == 0) continue;
            for(int i=1; i<=n; i++){
                int len = 0;
                for(int j=i; j!=-1; ){
                    int nxt = a[j] + d; len += 1;
                    if(1 <= nxt && nxt <= 100) j = idx[j][nxt];
                    else break;
                }
                if(len > mx) mx = len;
            }
        }
        System.out.println(mx);
    }
}