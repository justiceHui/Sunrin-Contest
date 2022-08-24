#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename Container>
pair<vector<int>, vector<int>> SuffixArray(const Container &s){
    int n = s.size();
    vector<int> sa(n), lcp(n), pos(n), tmp(n);
    for(int i=0; i<n; i++) sa[i] = i, pos[i] = s[i];
    for(int k=1; ; k<<=1){
        auto cmp = [&](int a, int b){
            if(pos[a] != pos[b]) return pos[a] < pos[b];
            if((a+=k) < n && (b+=k) < n) return pos[a] < pos[b];
            return a > b;
        };
        sort(sa.begin(), sa.end(), cmp);
        for(int i=1; i<n; i++) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
        for(int i=0; i<n; i++) pos[sa[i]] = tmp[i];
        if(tmp.back() + 1 == n) break;
    }
    for(int i=0, j=0; i<n; i++, j=max(j-1, 0)){
        if(!pos[i]) continue;
        while(sa[pos[i]-1]+j < n && sa[pos[i]]+j < n && s[sa[pos[i]-1]+j] == s[sa[pos[i]]+j]) j++;
        lcp[pos[i]] = j;
    }
    return { sa, lcp };
}

template<typename T> struct RMQ {
    vector<vector<T>> st;
    vector<int> lg;
    RMQ() = default;
    RMQ(const vector<T> &a){
        int n = a.size();
        st = vector<vector<T>>(__lg(n)+1, vector<T>(n));
        for(int i=0; i<n; i++) st[0][i] = a[i];
        for(int i=1; i<st.size(); i++) for(int j=0; j<n; j++) if(j + (1<<i) - 1 < n) st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        lg.resize(n);
        for(int i=0; i<st.size(); i++) lg[1<<i] = i;
        for(int i=1; i<n; i++) if(!lg[i]) lg[i] = lg[i-1];
    }
    T query(int l, int r){
        if(l > r) return 0x3f3f3f3f;
        int k = lg[r-l+1];
        return min(st[k][l], st[k][r-(1<<k)+1]);
    }
};

struct Solver{
    static const int sq = 400;
    vector<int> l, r, s, sa, lcp, pos;
    vector<string> v;
    vector<vector<int>> idx;
    RMQ<int> rmq;
    vector<ll> sum;
    vector<int> large, lcp_fr, lcp_bk; int lst;
    map<pair<int,int>, ll> cache;
    Solver(const vector<string> &a){
        v = a; lst = -1;
        for(int i=0; i<v.size(); i++){
            l.push_back(s.size());
            for(auto j : v[i]) s.push_back(j);
            r.push_back(s.size()-1);
            s.push_back(-i-1);
        }
        tie(sa,lcp) = SuffixArray(s);
        rmq = RMQ<int>(lcp);
        pos.resize(s.size());
        for(int i=0; i<s.size(); i++) pos[sa[i]] = i;
        idx.resize(v.size()); sum.resize(v.size());
        for(int i=0; i<v.size(); i++){
            for(int j=l[i]; j<=r[i]; j++) idx[i].push_back(pos[j]);
            sort(idx[i].begin(), idx[i].end());
            for(int j=1; j<idx[i].size(); j++) sum[i] += rmq.query(idx[i][j-1]+1, idx[i][j]);
            sum[i] = 1LL * idx[i].size() * (idx[i].size()+1) / 2 - sum[i];
        }
        large.resize(s.size());
        lcp_fr.resize(s.size());
        lcp_bk.resize(s.size());
    }
    int get_lcp(int a, int b){
        int p1 = pos[a], p2 = pos[b];
        if(p1 > p2) swap(p1, p2);
        return rmq.query(p1+1, p2);
    }
    void prepare(int a){
        fill(large.begin(), large.end(), -1);
        large.back() = idx[a].size();
        for(int i=0; i<idx[a].size(); i++) large[idx[a][i]] = i;
        for(int i=s.size()-2; i>=0; i--) if(large[i] == -1) large[i] = large[i+1];
    }
    ll get(int a, int b){
        if(a == b) return sum[a];
        if(v[a].size() > v[b].size()) swap(a, b);
        else if(v[a].size() == v[b].size() && a > b) swap(a, b);
        if(auto it=cache.find(make_pair(a,b)); it != cache.end()) return it->second;
        if(lst != b && idx[b].size() >= sq) prepare(b), lst = b;

        const vector<int> &now = idx[a];
        vector<pair<int,int>> can;
        for(int i=0, it=0; i<now.size(); i++){
            if(idx[b].size() >= sq) it = large[now[i]];
            else while(it < idx[b].size() && idx[b][it] < idx[a][i]) it++;

            int prv = it != 0 ? idx[b][it-1] : -1, f1 = 1;
            if(i > 0 && prv < now[i-1]) prv = now[i-1], f1 = 0;
            int nxt = it < idx[b].size() ? idx[b][it] : 1e9, f2 = 1;
            if(i+1 < now.size() && nxt > now[i+1]) nxt = now[i+1], f2 = 0;

            if(prv != -1 && f1) can.emplace_back(sa[now[i]], rmq.query(prv+1, now[i]));
            if(nxt != 1e9 && f2) can.emplace_back(sa[now[i]], rmq.query(now[i]+1, nxt));
        }

        ll res = 0;
        for(int i=0; i<can.size(); i++){
            int skip = i > 0 ? min(can[i-1].second, get_lcp(can[i-1].first, can[i].first)) : 0, len = can[i].second;
            if(skip < len) res += len - skip;
        }
        return cache[{a,b}] = res;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<string> V(N);
    for(auto &i : V) cin >> i;
    Solver S(V);

    int Q; cin >> Q;
    vector<tuple<int,int,int>> Qry;
    vector<ll> R(Q);
    for(int i=0; i<Q; i++){
        int a, b; cin >> a >> b; a--; b--;
        if(V[a].size() > V[b].size()) swap(a, b);
        else if(V[a].size() == V[b].size() && a > b) swap(a, b);
        Qry.emplace_back(b, a, i);
    }
    sort(Qry.begin(), Qry.end());
    for(auto [a,b,idx] : Qry) R[idx] = S.get(a, b);
    for(auto i : R) cout << i << "\n";
}