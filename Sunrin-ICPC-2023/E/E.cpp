#include <bits/stdc++.h>
using namespace std;

int N, M, A[2][4] = {{1, 2, 3, 4}, {3, 4, 1, 2}};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    if(N == 1 && M == 1){ cout << "1\n1\n"; return 0; }
    if(N == 1 || M == 1){
        cout << "2\n";
        for(int i=0; i<N*M; i++) cout << i%2+1 << " \n"[M==1];
        return 0;
    }
    cout << "4\n";
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cout << A[i%2][j%4] << " \n"[j+1==M];
}