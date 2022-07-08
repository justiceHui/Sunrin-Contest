const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

function valid(n, k, cnt){
    let rem = n, mx = 0, need = 0;
    for(let i=0; i<10; i++){
        rem -= cnt[i]; mx = Math.max(mx, cnt[i]);
    }
    for(let i=0; i<10; i++) if(cnt[i] != 0) need += Math.max(0, mx-cnt[i]-k);
    return need <= rem;
}

function ord(c){ return c.charCodeAt(0); }
function chr(c){ return String.fromCharCode(c); }

function solve(n, k, s){
    let cnt = new Array(10).fill(0);
    for(let i=0; i<n; i++) cnt[ord(s[i])-48] += 1;
    if(valid(n, k, cnt)) return s;

    let idx = -1, val = -1;
    for(let i=n-1; i>=0; i--){
        cnt[ord(s[i])-48] -= 1;
        for(let j=ord(s[i])-49; j>=0; j--){
            cnt[j] += 1;
            if(valid(n, k, cnt)){
                idx = i; val = j; break;
            }
            cnt[j] -= 1;
        }
        if(idx != -1) break;
    }
    let z = 0;
    if(idx == 0 && val == 0){
        cnt[0] -= 1; idx -= 1; n--; z = 1;
    }

    let res = "";
    for(let i=z; i<idx+z; i++) res += s[i];
    if(idx != -1) res += chr(48+val);

    for(idx++; idx<n; idx++){
        for(let i=9; i>=0; i--){
            cnt[i] += 1;
            if(valid(n, k, cnt)){
                res += chr(48+i);
                break;
            }
            cnt[i] -= 1;
        }
    }
    return res;
}

const t = +input[0];
for(let i=1; i<=t; i++){
    const temp = input[i].split(' ');
    console.log(solve(temp[0].length, +temp[1], temp[0]));
}