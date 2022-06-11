import java.util.Scanner;

public class Main{
    public static boolean isLeaf(int y){
        return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
    }
    public static int getMaxDate(int y, int m){
        if(m == 2) return 28 + (isLeaf(y) ? 1 : 0);
        else if(m <= 7 && m % 2 == 1 || m >= 8 && m % 2 == 0) return 31;
        else return 30;
    }
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int tc=1; tc<=T; tc++){
            int y = sc.nextInt();
            int m = sc.nextInt();
            int d = m;
            if(m > 1){
                m -= 1;
                d = getMaxDate(y, m);
            }
            else{
                y -= 1;
                m = 12;
                d = 31;
            }
            System.out.println(y + " " + m + " " + d);
        }
    }
}