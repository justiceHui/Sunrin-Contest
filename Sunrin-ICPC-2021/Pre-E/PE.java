import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int tc=1; tc<=t; tc++){
            long n = sc.nextLong(), res = 0, pw2 = 1, pw3 = 1;
            for(int i=0; i<40; i++, pw2*=2, pw3*=3){
                if((n & pw2) != 0) res += pw3;
            }
            System.out.println(res);
        }
    }
}