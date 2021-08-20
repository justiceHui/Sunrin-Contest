import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n+1];
        int[] D = new int[n+1];
        for(int i=1; i<=n; i++) A[i] = sc.nextInt();
        for(int i=1; i<=n; i++){
            D[i] = 1;
            for(int j=i-1; j>=1; j--) if(A[j] < A[i]) D[i] = (D[i] + D[j]) % 998244353;
        }
        for(int i=1; i<=n; i++) System.out.printf("%d ", D[i]);
    }
}