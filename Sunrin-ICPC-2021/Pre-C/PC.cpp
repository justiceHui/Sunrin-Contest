#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> S;
    if(S.size() <= 25){ cout << S; return 0; }

    bool one_sentence = true;
    for(int i=11; i+11+1<S.size(); i++){
        if(S[i] == '.') one_sentence = false;
    }
    if(one_sentence){
        for(int i=0; i<11; i++) cout << S[i];
        cout << "...";
        for(int i=10; i>=0; i--) cout << S[S.size()-i-1];
        return 0;
    }

    for(int i=0; i<9; i++) cout << S[i];
    cout << "......";
    for(int i=9; i>=0; i--) cout << S[S.size()-i-1];
}