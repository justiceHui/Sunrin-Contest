#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, mn = 5;
    string res;
    cin >> N;
    for(int i=1; i<=N; i++){
        string name;
        int difficulty;
        cin >> name >> difficulty;
        if(mn > difficulty){
            mn = difficulty;
            res = name;
        }
    }
    cout << res;
}