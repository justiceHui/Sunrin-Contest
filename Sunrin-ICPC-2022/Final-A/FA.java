import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] cnt = new int[3];
        for(int i=0; i<n; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
        }
        for(int i=0; i<m; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            char c = sc.next().charAt(0);
            if(c == 'R') cnt[0]++;
            else if(c == 'B') cnt[1]++;
            else cnt[2]++;
        }
        for(int i=0; ; i++){
            if(cnt[2] > 0) cnt[2]--;
            else if(cnt[i%2] > 0) cnt[i%2]--;
            else{
                if(i % 2 == 0) System.out.println("jhnan917");
                else System.out.println("jhnah917");
                break;
            }
        }
    }
}