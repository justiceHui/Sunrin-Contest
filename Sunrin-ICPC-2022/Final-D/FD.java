import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int n = sc.nextInt();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            if(a * (v-b) * (v-b) + c == u) cnt++;
        }
        System.out.println(cnt);
    }
}