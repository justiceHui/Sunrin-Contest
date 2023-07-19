import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = sc.nextInt();
        int[] a = new int[n+10]; a[1] = 1;
        if(n % 3 == 0) for(int i=1; i<=n; i+=3){ a[i] = -1; a[i+1] = 2; a[i+2] = 2; }
        if(n % 3 == 1) for(int i=1; i<=n; i+=3){ a[i] = 2; a[i+1] = -1; a[i+2] = 2; }
        if(n % 3 == 2) for(int i=2; i<=n; i+=3){ a[i] = 2; a[i+1] = -1; a[i+2] = 2; }
        for(int i=1; i<=n; i++) a[i] += a[i-1];
        bw.write(String.valueOf(n) + "\n");
        for(int i=0; i<n; i++) bw.write(String.valueOf((a[i]+n)%n+1) + " ");
        bw.write("1");

        sc.close();
        bw.close();
    }
}