#include <bits/stdc++.h>
using namespace std;

template< size_t _Sz>
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

int N, M, K, Q, X[202020], Y[202020], V[202020], Dead[202020], ID, Res;
FenwickTree<1010> T;

void Update(int sx, int sy, int ex, int ey, int v){
    T.add(sx, sy, v);
    T.add(sx, ey+1, -v);
    T.add(ex+1, sy, -v);
    T.add(ex+1, ey+1, v);
}
int Query(int x, int y){
    return T.get(x, y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K; Q = M + K;
    for(int i=1; i<=Q; i++){
        int op; cin >> op;
        if(op == 1){
            int _x, _y, x, y, r;
            cin >> _x >> _y >> r;
            x = _x + _y;
            y = _x - _y + 500;
            Update(max(1, x-r), max(1, y-r), min(1000, x+r), min(1000, y+r), 1);
        }
        else if(op == 2){
            int _x, _y, x, y;
            cin >> _x >> _y;
            x = _x + _y;
            y = _x - _y + 500;
            ID++;
            X[ID] = x;
            Y[ID] = y;
            V[ID] = Query(x, y);
        }
        else{
            int k; cin >> k;
            if(Query(X[k], Y[k]) > V[k]) Res++;
            Dead[k] = 1;
        }
    }

    for(int i=1; i<=ID; i++){
        if(!Dead[i] && Query(X[i], Y[i]) > V[i]) Res++;
    }

    cout << Res;
}