#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void output_assert(InStream &in, bool flag, string result){
    if(!flag) in.quit(_wa, result.c_str());
}

int N;
string S;

void Check(InStream &in){
    string res = in.readWord();
    output_assert(in, res.size() == N * S.size(), "length wrong");
    for(int i=0; i<res.size(); i+=S.size()){
        string now;
        for(int j=0; j<S.size(); j++) now += res[i+j];
        sort(now.begin(), now.end());
        output_assert(in, now == S, "not valid word");
    }
    while(!in.seekEof()){
        string s = in.readWord();
        output_assert(in, s.empty(), "trash print");
    }
}

int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    N = inf.readInt(); inf.readEoln();
    S = inf.readWord(); inf.readEoln();
    sort(S.begin(), S.end());
    Check(ans);
    Check(ouf);
    quit(_ok, "ok");
    return 0;
}
