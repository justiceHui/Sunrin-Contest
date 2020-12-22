#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

const int DI[] = {1, -1, 0, 0};
const int DJ[] = {0, 0, 1, -1};

struct Info{
    int di, dj;
    bool flag;
    Info() : Info(0, 0, true) {}
    Info(int di, int dj, bool flag) : di(di), dj(dj), flag(flag) {}
};

int N, si, sj, cnt;
char A[22][22];
bool chk[22][22];

queue<Info> q[22][22], nxt[22][22];

void Move(int i, int j, const Info &info){
    if(info.flag){
        int ii = i + info.di, jj = j + info.dj;
        if(ii < 1 || jj < 1 || ii > N || jj > N || A[ii][jj] != '.') return;
        nxt[ii][jj].push(info);
        chk[ii][jj] = true;
    }
    else{
        for(int k=0; k<4; k++){
            if(DI[k] == -info.di && DJ[k] == -info.dj) continue;
            int ii = i + DI[k], jj = j + DJ[k];
            if(ii < 1 || jj < 1 || ii > N || jj > N || A[ii][jj] != '.') continue;
            nxt[ii][jj].emplace(DI[k], DJ[k], false);
            chk[ii][jj] = true;
        }
    }
}

void Go(){
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        if(q[i][j].empty()) continue;
        if(q[i][j].size() == 1) Move(i, j, q[i][j].front());
        else{
            Info now(0, 0, true);
            while(q[i][j].size()){
                now.di += q[i][j].front().di;
                now.dj += q[i][j].front().dj;
                q[i][j].pop();
            }
            if(now.di != 0 || now.dj != 0) Move(i, j, now);
        }
    }
}

int End(){
    int sz = 0, now = 0;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        while(q[i][j].size()) q[i][j].pop();
        sz += nxt[i][j].size();
        swap(q[i][j], nxt[i][j]);
        if(!chk[i][j]) now++;
    }
    if(now == 0) return 1;
    if(sz == 0) return -1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        cin >> A[i][j];
        if(A[i][j] == 'S') si = i, sj = j;
        if(A[i][j] == '.') cnt++;
        else chk[i][j] = true;
    }
    if(cnt == 0){ cout << 0; return 0; }

    q[si][sj].emplace(0, 0, false);
    for(int i=1; ; i++){
        Go();
        int res = End();
        if(res == 1){ cout << i; return 0; }
        if(res == -1){ cout << -1; return 0; }
    }
}