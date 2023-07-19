import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) a[i] = sc.nextInt();
        Arrays.sort(a);
        int res = 0;
        for(int i=0, j=n-1; i<j; i++){
            while(i < j && a[i] + a[j] > k) j--;
            if(i < j && a[i] + a[j] <= k){ res++; j--; }
        }
        System.out.println(res);
        sc.close();
    }
}