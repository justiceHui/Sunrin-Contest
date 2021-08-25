#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[1000][1000];

bool Test1(int step){
    for(int i=0; i<N; i+=step){
        for(int j=0; j<M; j++){
            for(int k=1; k<step; k++){
                if(A[i][j] != A[i+k][j]) return false;
            }
        }
    }
    return true;
}

bool Test2(int step){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j+=step){
            for(int k=1; k<step; k++){
                if(A[i][j] != A[i][j+k]) return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> A[i][j];

    int n_step = -1, m_step = -1;
    for(int i=N; i>=1; i--) if(N % i == 0 && Test1(i)) { n_step = i; break; }
    for(int j=M; j>=1; j--) if(M % j == 0 && Test2(j)) { m_step = j; break; }

    cout << N / n_step << " " << M / m_step << "\n";
    for(int i=0; i<N; i+=n_step){
        for(int j=0; j<M; j+=m_step) cout << A[i][j];
        cout << "\n";
    }
}