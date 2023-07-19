import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int res = 6;
        for(int i=11; i<=n; i++) res *= i;
        System.out.println(res);
        sc.close();
    }
}
