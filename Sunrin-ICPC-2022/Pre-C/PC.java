import java.util.Scanner;

public class Main{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int tc=1; tc<=T; tc++){
            int n = sc.nextInt();
            int[] a = new int[n];
            boolean flag = true;
            for(int i=0; i<n; i++) a[i] = sc.nextInt();
            for(int i=0; i<n; i++){
                if(a[i] > n-a[i]+1) a[i] = n-a[i]+1;
                if(i > 0 && a[i-1] > a[i]) a[i] = n-a[i]+1;
                if(i > 0 && a[i-1] > a[i]) flag = false;
            }
            System.out.println(flag ? "YES" : "NO");
        }
    }
}