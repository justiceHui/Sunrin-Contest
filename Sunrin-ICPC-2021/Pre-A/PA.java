import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        for(int i=n-5; i<n; i++) System.out.printf("%c", s.charAt(i));
    }
}