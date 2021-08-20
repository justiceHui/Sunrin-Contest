#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void output_assert(bool flag, string result){
    if(!flag) quit(_wa, result);
}

int G[333][333];

int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    memset(G, 0x3f, sizeof G);
    for(int i=0; i<333; i++) G[i][i] = 0;

    int N = inf.readInt();
    for(int i=1; i<N; i++){
        int u = inf.readInt();
        int v = inf.readInt();
        G[u][v] = G[v][u] = 1;
    }
    int opt = N <= 4 ? 1 : 2;

    int user_cnt = ouf.readInt();
    int user_opt = ouf.readInt();
    output_assert(opt == user_opt, "optimal value : optimal " + to_string(opt) + " output " + to_string(user_opt));
    output_assert(user_cnt <= N-1, "bridge < N : " + to_string(user_cnt));

    for(int i=1; i<=user_cnt; i++){
        int u = ouf.readInt();
        int v = ouf.readInt();
        output_assert(1 <= u && u <= N, "U[" + to_string(i) + "] range : " + to_string(u));
        output_assert(1 <= v && v <= N, "V[" + to_string(i) + "] range : " + to_string(v));
        output_assert(u != v, "self loop : Edge[" + to_string(i) + "] " + to_string(u));
        output_assert(G[u][v] == 0x3f3f3f3f, "multi edge : Edge[" + to_string(i) + "] " + to_string(u) + " " + to_string(v));
        G[u][v] = G[v][u] = 1;
    }

    int extraOufCount = 0;
    while(!ouf.seekEof()) ouf.readLong(), extraOufCount++;
    output_assert(extraOufCount == 0, "trash output");

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    int mx = 0;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) mx = max(mx, G[i][j]);
    output_assert(mx == user_opt, "construct answer : mx " + to_string(mx) + " output " + to_string(user_opt));

    quit(_ok, "ok");
    return 0;
}