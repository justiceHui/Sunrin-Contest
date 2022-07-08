const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let line = 0;

function solve(){
    let tmp = input[line++].split(' ');
    const n = +tmp[0], t = +tmp[1];
    let a = new Array(n+1).fill(0);
    let b = new Array(n+1).fill(0);
    let c = new Array(n+1).fill(0);
    let d = new Array(n+1).fill(0);
    let e = new Array(n+1).fill(0);
    for(let i=1; i<=n; i++){
        tmp = input[line++].split(' ');
        a[i] = +tmp[0]; b[i] = +tmp[1]; c[i] = +tmp[2]; d[i] = +tmp[3];
    }
    e = input[line++].split(' ');
    for(let i=0; i<=n; i++) e[i] = +e[i];

    let l = 0, r = t;
    while(l < r){
        let m = Math.floor((l + r) / 2), now = m + e[0];
        for(let i=1; i<=n; i++){
            now = Math.max(c[i], now);
            let x = Math.floor((now - c[i]) / a[i]);
            if(c[i]+a[i]*x <= now && now+d[i] <= c[i]+a[i]*x+b[i]) now += d[i] + e[i];
            else now = c[i] + a[i]*(x+1) + d[i] + e[i];
        }
        if(now == t){ console.log("YES"); return; }
        if(now > t) r = m; else l = m + 1;
    }
    console.log("NO");
}

const TC = +input[line++];
for(let tc=1; tc<=TC; tc++) solve();