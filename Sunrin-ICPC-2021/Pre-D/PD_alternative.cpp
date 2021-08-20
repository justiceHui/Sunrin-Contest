#include <bits/stdc++.h>
using namespace std;

int N, A[1010101], C[11];

int getDiff(){
    int fst = -1, lst = -1;
    for(int i=1; i<=10; i++){
        if(!C[i]) continue;
        if(fst == -1) fst = i;
        lst = i;
    }
    return lst - fst;
}
void insert(int i){ C[A[i]]++; }
void erase(int i){ C[A[i]]--; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    int l = 1, r = 1, ans = 1;
    C[A[l]]++;
    while(true){
        int flag = getDiff() <= 2;
        if(flag) ans = max(ans, r-l+1);
        if(l == N) break;
        else if(r == N) erase(l++);
        else if(l == r) insert(++r);
        else if(flag) insert(++r);
        else erase(l++);
    }
    cout << ans;
}