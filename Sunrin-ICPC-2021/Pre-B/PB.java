import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1];
        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        int idx = 1;
        for(int i=2; i<=n; i++){
            if(a[idx] < a[i]) idx = i;
        }

        int isMountain = 1;
        for(int i=1; i<idx; i++){
            if(a[i] >= a[i+1]) isMountain = 0;
        }
        for(int i=idx; i<n; i++){
            if(a[i] <= a[i+1]) isMountain = 0;
        }
        if(isMountain == 1) System.out.println("YES");
        else System.out.println("NO");
    }
}