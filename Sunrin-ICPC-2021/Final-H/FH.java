import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int res = 0;
        int n = sc.nextInt();
        int[] a = new int[n+1];
        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        for(int i=1; i<=n; i++){
            int l = i, r = i;
            while(l > 1 && a[l] > a[l-1]) l--;
            while(r < n && a[r] > a[r+1]) r++;
            if(r-l+1 > res) res = r-l+1;
        }
        System.out.println(res);
    }
}