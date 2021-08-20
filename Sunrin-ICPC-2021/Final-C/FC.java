import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), dec = 0, ans = 0;
        int[] a = new int[n+1];
        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        for(int i=1; i<n; i++) if(a[i] > a[i+1]) dec++;
        if(dec == 0) ans = 1;
        else if(dec == 1 && a[1] > a[n]) ans = 2;
        else ans = 3;
        System.out.println(ans);
    }
}