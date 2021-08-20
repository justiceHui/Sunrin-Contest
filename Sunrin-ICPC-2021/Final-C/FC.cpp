#include <bits/stdc++.h>
using namespace std;

int N, A[202020], C;

// Check sorted array
bool Check1(){
    for(int i=1; i<N; i++) if(A[i-1] > A[i]) return false;
    return true;
}

// Check cyclic shift of sorted array
bool Check2(){
    int st = min_element(A, A+N) - A;
    for(int i=1; i<N; i++) if(A[(i+st-1)%N] > A[(i+st)%N]) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    if(Check1()) cout << 1;
    else if(Check2()) cout << 2;
    else cout << 3;
}