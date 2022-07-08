const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const n = +input[0];
let a = [];
for(let i=1; i<=n; i++) a.push(new Array(n));
for(let i=1; i<=n; i++){
    const tmp = input[i].split(' ');
    for(let j=0; j<n; j++) a[i-1][j] = +tmp[j];
}
let d = [], res = 0;
for(let i=0; i<n; i++) d.push(new Array(n));
for(let i=0; i<n; i++){
    for(let j=0; j<n; j++){
        let mx = 0; d[i][j] = 0;
        for(let r=0; r<=i; r++) for(let c=0; c<=j; c++) if(a[r][c] < a[i][j]) mx = Math.max(mx, d[r][c]);
        d[i][j] = mx + 1;
        res = Math.max(res, d[i][j]);
    }
}
console.log(res);