#include <bits/stdc++.h>
using namespace std;

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int N, ans;
char A[22][22];
bool chk[22][22];

void DFS(int i, int j){
    chk[i][j] = true;
    for(int k=0; k<4; k++){
        int ii = i + di[k], jj = j + dj[k];
        if(ii < 1 || jj < 1 || ii > N || jj > N) continue;
        if(A[ii][jj] != '.' || chk[ii][jj]) continue;
        DFS(ii, jj);
    }
}

int Get(){
    memset(chk, 0, sizeof chk);
    int ret = 0;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
            if(A[i][j] == '.' && !chk[i][j]) ret++, DFS(i, j);
        }
    return ret;
}

bool One(int i, int j){
    for(int k=0; k<4; k++){
        int ii = i + di[k], jj = j + dj[k];
        if(ii < 1 || jj < 1 || ii > N || jj > N) continue;
        if(A[ii][jj] == '.') return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
            cin >> A[i][j];
            if(A[i][j] == 'S') A[i][j] = '@';
        }

    int cnt = Get();

    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
            if(A[i][j] != '.') continue;
            A[i][j] = '@';
            if(cnt != Get() + One(i, j)) ans++;
            A[i][j] = '.';
        }
    cout << ans;
}