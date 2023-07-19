import java.util.*;

public class Main{
    static boolean check(int[] a, int x){
        while(x > 0){
            if(a[x%10] == 1) return false;
            x /= 10;
        }
        return true;
    }
    static void solve(Scanner sc){
        int[] a = new int[10];
        int[] d = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=0; i<10; i++) a[i] = sc.nextInt();
        int res = 0;
        for(int i=1; i<=12; i++){
            for(int j=1; j<=d[i]; j++){
                if(check(a, i) && check(a, j)) res += 1;
            }
        }
        System.out.println(res);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i=0; i<t; i++) solve(sc);
        sc.close();
    }
}