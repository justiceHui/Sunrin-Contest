const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const n = parseInt(input[0]);
let a = input[1].split(' ').map(s => parseInt(s));
a.unshift(0);

let count = new Array(101).fill(0);
let idx = new Array(n+1).fill(0).map(_ => new Array(101).fill(0));
let lst = new Array(101).fill(0);
let mx = 0;

for(let i=1; i<=n; i++) count[a[i]] += 1;
for(let i=1; i<=100; i++) mx = Math.max(mx, count[i]);

for(let i=1; i<=100; i++) lst[i] = -1;
for(let i=n; i>=1; i--){
    for(let j=1; j<=100; j++) idx[i][j] = lst[j];
    lst[a[i]] = i;
}

for(let d=-100; d<=100; d++){
    if(d == 0) continue;
    for(let i=1; i<=n; i++){
        let len = 0;
        for(let j=i; j!=-1; ){
            let nxt = a[j] + d; len += 1;
            if(1 <= nxt && nxt <= 100) j = idx[j][nxt];
            else break;
        }
        mx = Math.max(mx, len);
    }
}

console.log(mx);