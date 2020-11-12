#include <bits/stdc++.h>
using namespace std;

int x;
string a, b, c;

void solve(const string &s){
    string aa = "Messi ";
    string bb = "Gimossi ";
    
    for(int k=0; k<s.size(); k++){
        char i = c[k];
        if(i == '0'){
            if(x == 5) { cout << "Messi Messi Gimossi"; exit(0); }
            if(x < 5)  { cout << aa[x]; exit(0); }
            if(x > 5)  { x -= aa.size(); }
        }
        else{
            if(x == 7) { cout << "Messi Messi Gimossi"; exit(0); }
            if(x < 7)  { cout << bb[x]; exit(0); }
            if(x > 7)  { x -= bb.size(); }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    a = "0"; b = "01";
    for(int i=3; i<=39; i++){
        c = b + a;
        if(i != 40) a = b, b = c;
    }
    cin >> x; x--;
    solve(c);
    solve(b);
}