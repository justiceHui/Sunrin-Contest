import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int res = 0;
        for(int i=0; i<q; i++){
            int t = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(t == 1) res ^= 1;
            else if((b - a + 1) / 2 % 2 == 1) res ^= 1;
            System.out.println(res);
        }
    }
}