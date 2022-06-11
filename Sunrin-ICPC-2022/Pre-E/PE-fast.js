const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const n = parseInt(input[0]);
let a = input[1].split(' ').map(s => parseInt(s));
a.unshift(0);

let count = new Array(101).fill(0);
let dp = new Array(101).fill(0).map(_ => new Array(101));
let mx = 0;

for(let i=1; i<=n; i++) count[a[i]] += 1;
for(let i=1; i<=100; i++) mx = Math.max(mx, count[i]);

for(let i=1; i<=100; i++) for(let j=1; j<=100; j++) dp[i][j] = 0;

for(let d=1; d<=100; d++){
    for(let i=1; i<=n; i++){
        if(a[i] - d >= 1) dp[d][a[i]] = Math.max(dp[d][a[i]], dp[d][a[i]-d] + 1);
        else dp[d][a[i]] = Math.max(dp[d][a[i]], 1);
        mx = Math.max(mx, dp[d][a[i]]);
    }
}


a.shift();
a.reverse();
a.unshift(0);
for(let i=1; i<=100; i++) for(let j=1; j<=100; j++) dp[i][j] = 0;

for(let d=1; d<=100; d++){
    for(let i=1; i<=n; i++){
        if(a[i] - d >= 1) dp[d][a[i]] = Math.max(dp[d][a[i]], dp[d][a[i]-d] + 1);
        else dp[d][a[i]] = Math.max(dp[d][a[i]], 1);
        mx = Math.max(mx, dp[d][a[i]]);
    }
}

console.log(mx);