const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let line = 0;
const temp = input[line++].split(' ');
const n = +temp[0], m = +temp[1];
let cnt = [0, 0, 0];
line += n;
for(let i=0; i<m; i++){
    const c = input[line++].split(' ')[2];
    if(c == 'R') cnt[0]++;
    else if(c == 'B') cnt[1]++;
    else cnt[2]++;
}
for(let i=0; ; i++){
    if(cnt[2] > 0) cnt[2]--;
    else if(cnt[i%2] > 0) cnt[i%2]--;
    else{
        if(i % 2 == 0) console.log('jhnan917');
        else console.log('jhnah917');
        break;
    }
}