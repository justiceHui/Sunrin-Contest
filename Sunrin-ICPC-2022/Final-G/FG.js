const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let temp = input[0].split(' '), line = 1;
const n = +temp[0], m = +temp[1], q = +temp[2];

let a = new Array(n+2).fill(0);
let x = new Array(n+2).fill(0);
let w = [];
for(let i=0; i<=m; i++) w.push(new Array(n+2).fill(0));

for(let i=1; i<=m; i++){
    const tmp = input[line++].split(' ');
    const cnt = +tmp[0];
    let idx = [];
    for(let j=0; j<cnt; j++) idx.push(+tmp[j+1]);
    idx.push(n+1);
    for(let j=0; j<idx.length; j++) w[i][idx[j]] = +tmp[cnt+j+1];
}

temp = input[line++].split(' ');
for(let i=1; i<=m; i++){
    let t = +temp[i-1];
    for(let j=1; j<=n+1; j++) a[j] += t * w[i][j];
}
a[n+1] += +temp[m];

for(let iter=0; iter<q; iter++){
    const tmp = input[line++].split(' ');
    for(let i=1; i<=n; i++) x[i] = +tmp[i-1];
    x[n+1] = 1;
    res = 0;
    for(let i=1; i<=n+1; i++) res += a[i] * x[i];
    console.log(res);
}