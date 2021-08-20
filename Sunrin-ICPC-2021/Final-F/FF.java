import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long[] D = new long[44];
        D[0] = 0; D[1] = 1; D[2] = 2;
        for(int i=3; i<44; i++) D[i] = D[i-1] + D[i-2] + 1;
        int T = sc.nextInt();
        for(int tc=1; tc<=T; tc++){
            int v = sc.nextInt(), res = 0;
            for(int i=1; i<44; i++) if(v >= D[i]) res = i;
            System.out.println(res);
        }
    }
}