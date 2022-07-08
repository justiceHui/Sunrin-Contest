import java.util.Scanner;

public class Main{
    static int gcd(int a, int b){ return b != 0 ? gcd(b, a % b) : a; }
    static int lcm(int a, int b){ return a / gcd(a, b) * b; }
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), res = 1;
        for(int i=0; i<n-2; i++){
            int t = sc.nextInt();
            res = lcm(res, t);
        }
        System.out.println(res);
    }
}