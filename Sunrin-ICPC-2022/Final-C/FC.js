const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let line = 0;
const n = +input[line++];

let s = new Array(n-1).fill(0);
let e = new Array(n-1).fill(0);
let c = new Array(n-1).fill(0);
let p = new Array(n-1).fill(0);
let rnk = new Array(n-1).fill(0);

let group = new Array(n+1).fill(0);
let vertex = new Array(n+1).fill(0);
let g = [];
for(let i=0; i<=n; i++) g.push([]);
for(let i=0; i+1<n; i++) p[i] = i;

function find(v){ return v == p[v] ? v : p[v] = find(p[v]); }
function merge(u, v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(rnk[u] > rnk[v]){
        let t = u; u = v; v = t;
    }
    p[u] = v;
    if(rnk[u] == rnk[v]) rnk[v]++;
}

for(let i=0; i+1<n; i++){
    const tmp = input[line++].split(' ');
    s[i] = +tmp[0]; e[i] = +tmp[1]; c[i] = +tmp[2];
    g[s[i]].push([e[i], i]);
    g[e[i]].push([s[i], i]);
}

let a = input[line++].split(' ');
let b = input[line++].split(' ');
a.unshift(0); b.unshift(0);
for(let i=1; i<=n; i++){
    a[i] = +a[i]; b[i] = +b[i];
}

for(let i=1; i<=n; i++) g[i].sort((a, b) => { return c[a[1]] - c[b[1]]; });
for(let i=1; i<=n; i++){
    for(let j=1; j<g[i].length; j++){
        if(c[g[i][j-1][1]] == c[g[i][j][1]]) merge(g[i][j-1][1], g[i][j][1]);
    }
}

for(let i=1; i<=n; i++) g[i].sort((a, b) => { return find(a[1]) - find(b[1]); });
for(let i=1; i<=n; i++){
    for(let j=0; j<g[i].length; j++){
        if(j == 0 || find(g[i][j-1][1]) != find(g[i][j][1])) group[find(g[i][j][1])] += a[i];
    }
}
for(let i=1; i<=n; i++){
    for(let j=0; j<g[i].length; j++){
        if(j == 0 || find(g[i][j-1][1]) != find(g[i][j][1])) vertex[i] += group[find(g[i][j][1])];
    }
}

let mn = 0, mx = 0;
vertex.shift(); b.shift();
vertex.sort((a, b) => { return a - b; });
b.sort((a, b) => { return a - b; });

for(let i=0; i<n; i++){
    mn += vertex[i] * b[n-i-1];
    mx += vertex[i] * b[i];
}

console.log(mn);
console.log(mx);