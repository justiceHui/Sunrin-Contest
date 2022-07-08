import java.util.*;

public class Main {
    public static long gcd(long a, long b){
        while(b != 0){
            long ta = b, tb = a % b;
            a = ta; b = tb;
        }
        return a;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i=0; i<t; i++){
            long n = sc.nextLong(), res = -1;
            if(n % 2 == 1) res = n * (n-1) * (n-2);
            else if(gcd(n, n-3) == 1) res = n * (n-1) * (n-3);
            else res = (n-1) * (n-2) * (n-3);
            System.out.println(res);
        }
    }
}