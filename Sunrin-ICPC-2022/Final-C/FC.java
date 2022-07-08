import java.util.*;

public class Main{
    static int[] s, e, c, p, deg;
    static long[] a, b, group, vertex;
    static int[][][] g;
    static void init(int n){
        s = new int[n-1]; e = new int[n-1]; c = new int[n-1];
        p = new int[n-1]; deg = new int[n+1];
        a = new long[n+1]; b = new long[n+1];
        group = new long[n+1]; vertex = new long[n+1];
        g = new int[n+1][][];
        for(int i=0; i+1<n; i++) p[i] = i;
    }
    static int find(int v){
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    static void merge(int u, int v){
        if(find(u) != find(v)) p[p[u]] = p[v];
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); init(n);
        for(int i=0; i+1<n; i++){
            s[i] = sc.nextInt(); deg[s[i]]++;
            e[i] = sc.nextInt(); deg[e[i]]++;
            c[i] = sc.nextInt();
        }
        for(int i=1; i<=n; i++){
            g[i] = new int[deg[i]][];
            deg[i] = 0;
        }
        for(int i=0; i+1<n; i++){
            g[s[i]][deg[s[i]]++] = new int[]{e[i], i};
            g[e[i]][deg[e[i]]++] = new int[]{s[i], i};
        }
        for(int i=1; i<=n; i++) a[i] = sc.nextLong();
        for(int i=1; i<=n; i++) b[i] = sc.nextLong();

        for(int i=1; i<=n; i++){
            Arrays.sort(g[i], new Comparator<int[]>(){
                @Override
                public int compare(int[] a, int[] b){ return c[a[1]] - c[b[1]]; }
            });
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<g[i].length; j++){
                if(c[g[i][j-1][1]] == c[g[i][j][1]]) merge(g[i][j-1][1], g[i][j][1]);
            }
        }
        for(int i=1; i<=n; i++){
            Arrays.sort(g[i], new Comparator<int[]>(){
                @Override
                public int compare(int[] a, int[] b){ return find(a[1]) - find(b[1]); }
            });
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<g[i].length; j++){
                if(j == 0 || find(g[i][j-1][1]) != find(g[i][j][1])) group[find(g[i][j][1])] += a[i];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<g[i].length; j++){
                if(j == 0 || find(g[i][j-1][1]) != find(g[i][j][1])) vertex[i] += group[find(g[i][j][1])];
            }
        }

        long mn = 0, mx = 0;
        Arrays.sort(vertex, 1, n+1);
        Arrays.sort(b, 1, n+1);
        for(int i=1; i<=n; i++){
            mn += vertex[i] * b[n-i+1];
            mx += vertex[i] * b[i];
        }
        System.out.println(mn + "\n" + mx);
    }
}