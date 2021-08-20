import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        if(n <= 25){
            System.out.println(s);
        }
        else{
            int exist = 0;
            for(int i=11; i+12<n; i++){
                if(s.charAt(i) == '.') exist = 1;
            }
            if(exist == 0){
                for(int i=0; i<11; i++) System.out.printf("%c", s.charAt(i));
                System.out.printf("...");
                for(int i=10; i>=0; i--) System.out.printf("%c", s.charAt(n-i-1));
            }
            else{
                for(int i=0; i<9; i++) System.out.printf("%c", s.charAt(i));
                System.out.printf("......");
                for(int i=9; i>=0; i--) System.out.printf("%c", s.charAt(n-i-1));
            }
        }
    }
}