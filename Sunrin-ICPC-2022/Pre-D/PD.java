import java.util.Scanner;

public class Main{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        for(int i=0; i<n; i++) System.out.print(s);
    }
}