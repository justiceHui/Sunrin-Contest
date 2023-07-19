import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] a = { {1, 2, 3, 4}, {3, 4, 1, 2} };
        if(n == 1 && m == 1){ System.out.print("1\n1\n"); return; }
        if(n == 1 || m == 1){
            System.out.println(2);
            for(int i=0; i<n*m; i++) System.out.printf("%d%c", i%2+1, n == 1 ? ' ' : '\n');
            return;
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        System.out.println(4);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bw.write(String.valueOf(a[i%2][j%4]) + (j + 1 < m ? ' ' : '\n'));
            }
        }
        sc.close();
        bw.close();
    }
}