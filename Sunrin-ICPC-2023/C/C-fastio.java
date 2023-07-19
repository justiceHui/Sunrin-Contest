import java.util.*;
import java.io.*;
import java.lang.*;

public class Main{

    public static void main(String[] args) throws IOException, NullPointerException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);
        int K = Integer.parseInt(line[2]);
        int Q = Integer.parseInt(line[3]);

        int[] A = new int[K];
        HashMap<Integer,Integer>[] T = new HashMap[N+1];
        ArrayList<Integer[]>[] G = new ArrayList[N+1];
        for(int i=1; i<=N; i++) T[i] = new HashMap<>();
        for(int i=1; i<=N; i++) G[i] = new ArrayList<>();

        for(int i=0; i<M; i++){
            line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]);
            int v = Integer.parseInt(line[1]);
            T[u].put(v, 0);
        }

        line = br.readLine().split(" ");
        for(int i=0; i<K; i++) A[i] = Integer.parseInt(line[i]);

        for(int i=0; i<Q; i++){
            line = br.readLine().split(" ");
            int t = Integer.parseInt(line[0]);
            int u = Integer.parseInt(line[1]);
            int v = Integer.parseInt(line[2]);
            if(T[u].containsKey(v)){
                int st = T[u].get(v), ed = t - 1;
                Integer[] gu = {v, st, ed}, gv = {u, st, ed};
                G[u].add(gu); G[v].add(gv);
                T[u].remove(v);
            }
            else T[u].put(v, t);
        }

        for(int u=1; u<=N; u++){
            for(var entry : T[u].entrySet()){
                int v = entry.getKey(), st = entry.getValue(), ed = 400000;
                Integer[] gu = {v, st, ed}, gv = {u, st, ed};
                G[u].add(gu); G[v].add(gv);
            }
        }

        int[] res = new int[N+1];
        for(int i=1; i<=N; i++) res[i] = 1000000000;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(int i=0; i<K; i++){
            res[A[i]] = 0;
            pq.add((long)A[i]);
        }

        while(!pq.isEmpty()){
            long now = pq.poll();
            int c = (int)(now / 202020), v = (int)(now % 202020);
            if(c != res[v]) continue;
            for(var entry : G[v]){
                int i = entry[0], s = entry[1], e = entry[2];
                int cst = Math.max(s, c) + 1;
                if(c <= e && res[i] > cst){
                    res[i] = cst; pq.add((long)cst * 202020 + i);
                }
            }
        }
        for(int i=1; i<=N; i++) bw.write(String.valueOf(res[i] < 1000000000 ? res[i] : -1) + " ");

        br.close();
        bw.close();
    }
}