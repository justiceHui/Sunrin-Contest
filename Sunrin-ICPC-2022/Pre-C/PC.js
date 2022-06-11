const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const T = parseInt(input[0]);
for(let i=1; i<=T; i++){
    const n = parseInt(input[i*2-1]);
    const a = input[i*2].split(' ').map(s => parseInt(s));
    if(a.length != n) break;
    let flag = true;
    for(let j=0; j<n; j++){
        a[j] = Math.min(a[j], n - a[j] + 1);
        if(j > 0 && a[j-1] > a[j]) a[j] = n - a[j] + 1;
        if(j > 0 && a[j-1] > a[j]) flag = false;
    }
    if(flag) console.log("YES");
    else console.log("NO");
}