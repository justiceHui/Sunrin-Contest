#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 202020;
constexpr int MAX_Q = 404040;
constexpr int BUCKET = 500;
constexpr int INS = +1;
constexpr int DEL = -1;

template<size_t _Sz>
struct FenwickTree{
    int T[_Sz][_Sz];
    void add(int x, int y, int v){
        for(x+=3; x<_Sz; x+=x&-x) for(int yy=y+3; yy<_Sz; yy+=yy&-yy) T[x][yy] += v;
    }
    int get(int x, int y){
        int ret = 0;
        for(x+=3; x; x-=x&-x) for(int yy=y+3; yy; yy-=yy&-yy) ret += T[x][yy];
        return ret;
    }
};

struct Query{
    int s, e, x, buc;
    Query() = default;
    Query(int s, int e, int x) : s(s), e(e), x(x), buc(s / BUCKET) {}
    bool operator < (const Query &t) const {
        if(buc != t.buc) return buc < t.buc;
        if(buc & 1) return e < t.e;
        return e > t.e;
    }
};

int N, M, K, Q;
int Type[MAX_Q], X[MAX_Q], Y[MAX_Q], R[MAX_Q], Idx[MAX_Q], InsTime[MAX_N], DelTime[MAX_N], Counter;
int L1[MAX_Q], R1[MAX_Q], L2[MAX_Q], R2[MAX_Q];
vector<Query> Queries;
FenwickTree<1024> Tree;

void Update(int r1, int c1, int r2, int c2, int v){
    Tree.add(r1, c1, v);
    Tree.add(r1, c2+1, -v);
    Tree.add(r2+1, c1, -v);
    Tree.add(r2+1, c2+1, v);
}
int Query(int r, int c){
    return Tree.get(r, c);
}
void Mo(int op, int ti){
    if(Type[ti] == 1) Update(L1[ti], R1[ti], L2[ti], R2[ti], op);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K; Q = M + K;
    for(int i=1; i<=Q; i++){
        cin >> Type[i];
        if(Type[i] == 1) cin >> X[i] >> Y[i] >> R[i];
        if(Type[i] == 2) cin >> X[i] >> Y[i], Idx[i] = ++Counter, InsTime[Idx[i]] = i;
        if(Type[i] == 3) cin >> Idx[i], DelTime[Idx[i]] = i;

        int x = X[i], y = Y[i];
        X[i] = x + y;
        Y[i] = x - y + 500;
        if(Type[i] == 1){
            L1[i] = max(1, X[i] - R[i]); L2[i] = min(1000, X[i] + R[i]);
            R1[i] = max(1, Y[i] - R[i]); R2[i] = min(1000, Y[i] + R[i]);
        }
    }
    for(int i=1; i<=N; i++){
        if(!InsTime[i]) continue;
        if(!DelTime[i]) DelTime[i] = Q + 1;
        Queries.emplace_back(InsTime[i], DelTime[i], i);
    }
    sort(Queries.begin(), Queries.end());

    int s = Queries[0].s, e = Queries[0].e, res = 0;
    for(int i=s; i<=e; i++) Mo(+1, i);
    if(Query(X[s], Y[s])) res++;

    for(int i=1; i<Queries.size(); i++){
        while(Queries[i].s < s) Mo(INS, --s);
        while(e < Queries[i].e) Mo(INS, ++e);
        while(s < Queries[i].s) Mo(DEL, s++);
        while(Queries[i].e < e) Mo(DEL, e--);
        if(Query(X[s], Y[s])) res++;
    }
    cout << res;
}