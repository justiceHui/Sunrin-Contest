import java.util.Scanner;

public class Main{
    static boolean valid(int n, int k, int[] cnt){
        int rem = n, mx = 0, need = 0;
        for(int i=0; i<10; i++){
            rem -= cnt[i];
            if(cnt[i] > mx) mx = cnt[i];
        }
        for(int i=0; i<10; i++){
            if(cnt[i] != 0 && mx - cnt[i] - k > 0) need += mx - cnt[i] - k;
        }
        return need <= rem;
    }
    static void solve(int n, int k, String _s){
        int[] cnt = new int[10];
        char[] s = _s.toCharArray();
        for(int i=0; i<n; i++) cnt[(int)s[i]-48]++;
        if(valid(n, k, cnt)){
            System.out.println(_s); return;
        }

        int idx = -1, val = -1;
        for(int i=n-1; i>=0; i--){
            cnt[(int)s[i]-48]--;
            for(int j=(int)s[i]-49; j>=0; j--){
                cnt[j]++;
                if(valid(n, k, cnt)){ idx = i; val = j; break; }
                cnt[j]--;
            }
            if(idx != -1) break;
        }
        s[idx] = (char)(48+val);
        if(s[0] == '0'){
            cnt[0]--; idx--; n--;
            for(int i=0; i<n; i++) s[i] = s[i+1];
        }
        for(int i=0; i<idx; i++) System.out.print(s[i]);
        if(idx != -1) System.out.print((char)(48+val));

        for(idx++; idx<n; idx++){
            for(int i=9; i>=0; i--){
                cnt[i]++;
                if(valid(n, k, cnt)){ System.out.print((char)(48+i)); break; }
                cnt[i]--;
            }
        }
        System.out.println("");
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int tc=1; tc<=T; tc++){
            String s = sc.next();
            int k = sc.nextInt();
            int n = s.length();
            solve(n, k, s);
        }
    }
}