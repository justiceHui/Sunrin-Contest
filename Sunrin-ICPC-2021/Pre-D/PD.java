import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1];
        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        int mx = 0;
        for(int i=1; i+2<=10; i++){
            int now = 0;
            for(int j=1; j<=n; j++){
                if(i <= a[j] && a[j] <= i+2) now++;
                else now = 0;
                if(mx < now) mx = now;
            }
        }
        System.out.println(mx);
    }
}