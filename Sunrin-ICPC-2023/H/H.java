import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) a[i] = sc.nextInt();
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                if(a[j-1] > a[j]){ int t = a[j-1]; a[j-1] = a[j]; a[j] = t; }
            }
        }
        int[] x = new int[n], y = new int[n];
        int xx = 0, yy = 0;
        for(int i=0; i<n; i++){
            x[i] = a[i]; y[i] = a[i];
            for(int j=0; j<i; j++){
                if(a[j] <= a[i] && x[j] + a[i] > x[i]) x[i] = x[j] + a[i];
                if(a[j] >= a[i] && y[j] + a[i] > y[i]) y[i] = y[j] + a[i];
            }
            if(x[i] > xx) xx = x[i];
            if(y[i] > yy) yy = y[i];
        }
        System.out.println(xx + yy);
        for(int i=0; i<n; i++) System.out.printf("%d ", a[i]);
        sc.close();
    }
}