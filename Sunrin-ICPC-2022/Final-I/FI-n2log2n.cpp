#include <bits/stdc++.h>
using namespace std;
constexpr int S1 = 1 << 7, S2 = 1 << 14;

struct Tree1D{
    int T[S2<<1];
    Tree1D(){ memset(T, 0xc0, sizeof T); }
    void update(int x, int v){
        x |= S2; T[x] = max(T[x], v);
        while(x >>= 1) T[x] = max(T[x<<1], T[x<<1|1]);
    }
    int query(int l, int r){
        l |= S2; r |= S2; int ret = 0;
        while(l <= r){
            if(l & 1) ret = max(ret, T[l++]);
            if(~r & 1) ret = max(ret, T[r--]);
            l >>= 1; r >>= 1;
        }
        return ret;
    }
};

struct Tree2D{
    Tree1D T[S1<<1];
    void update(int x, int y, int v){
        x |= S1; T[x].update(y, v);
        while(x >>= 1){
            int t1 = T[x<<1].query(y, y), t2 = T[x<<1|1].query(y, y);
            T[x].update(y, max(t1, t2));
        }
    }
    int query(int l, int r, int L, int R){
        l |= S1; r |= S1; int ret = 0;
        while(l <= r){
            if(l & 1) ret = max(ret, T[l++].query(L, R));
            if(~r & 1) ret = max(ret, T[r--].query(L, R));
            l >>= 1; r >>= 1;
        }
        return ret;
    }
};

int N, A[111][111], D[111][111], R;
Tree2D T;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> A[i][j];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            D[i][j] = T.query(1, j, 1, A[i][j]-1) + 1;
            T.update(j, A[i][j], D[i][j]);
            R = max(R, D[i][j]);
        }
    }
    cout << R;
}