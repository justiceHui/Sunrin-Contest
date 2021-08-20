import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), res = 5;
        String name = "";
        for(int i=0; i<n; i++){
            String s = sc.next();
            int d = sc.nextInt();
            if(d < res){
                res = d;
                name = s;
            }
        }
        System.out.println(name);
    }
}