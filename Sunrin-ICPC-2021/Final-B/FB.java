import java.util.Scanner;

public class Main{
    public static long pow(long a, long b, long mod){
        long res = 1;
        while(b != 0){
            if(b % 2 == 1) res = res * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return res;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        long x = sc.nextLong();
        long mod = 998244353;

        long sum = (x * (x + 1) / 2) % mod;
        long res = pow(x, n+k-2, mod) * sum % mod * sum % mod * k % mod;
        for(int i=0; i<n-k+1; i++) System.out.printf("%d ", res);
    }
}