# 천하제일 코딩대회 예선 풀이

### A. 선린인터넷고등학교 교가

> Problem Idea: 나정휘(jhnah917)
>
> Preparation: 나정휘(jhnah917)

문자열을 입력받은 다음, 마지막 5글자를 출력하면 됩니다.

```cpp
// C++
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; string S;
    cin >> N >> S;
    for(int i=N-5; i<N; i++) cout << S[i];
}
```

```python
# python
N = int(input())
S = input()
print(S[-5:])
```

### B. 드높은 남산 위에 우뚝 선

> Problem Idea: 나정휘(jhnah917)
>
> Preparation: 나정휘(jhnah917)

배열의 최댓값을 기준으로, 왼쪽은 "올라가는 상태"가 되어야 하고 오른쪽은 "내려가는 상태"가 되어야 합니다.

```cpp
// C++
#include <bits/stdc++.h>
using namespace std;

int N, A[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    int idx = max_element(A+1, A+N+1) - A;
    for(int i=1; i<idx; i++){
        if(A[i] >= A[i+1]){ cout << "NO"; return 0; }
    }
    for(int i=idx; i<N; i++){
        if(A[i] <= A[i+1]){ cout << "NO"; return 0; }
    }
    cout << "YES";
}
```

```python
# python
n = int(input())
A = list(map(int, input().split()))
idx = A.index(max(A))
res = True
for i in range(idx):
    res = res and A[i] < A[i+1]
for i in range(idx+1, n-1):
    res = res and A[i] > A[i+1]

if res: print ("YES")
else: print ("NO")
```

### C. (중략)

> Problem Idea: 나정휘(jhnah917)
>
> Preparation: 나정휘(jhnah917)

0-based로 생각합시다. 설명의 편의를 위해 `S[l:r]`를 `S[l]S[l+1]S[l+2] ... S[r-1]`이라고 정의하겠습니다. 파이썬의 slice라고 생각하면 됩니다.

1. 만약 N이 25 이하라면 S를 그대로 출력하면 됩니다.
2. 만약 S[11:N-11]이 한 문장 안에 속한다면 `S[0:11] + "..." + S[N-11:N]`을 출력하면 됩니다. 어떤 문자열 `T`가 한 문장 안에 속한다는 것은, `T`의 마지막 글자를 제외한 모든 문자가 `.`이 아닌 것과 동치입니다.
3. 1, 2에 모두 해당하지 않는다면 `S[0:9] + "......" + S[N-10:N]`을 출력하면 됩니다.

```cpp
// C++
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; string S;
    cin >> N >> S;
    if(S.size() <= 25){ cout << S; return 0; }

    bool one_sentence = true;
    for(int i=11; i+11+1<S.size(); i++){
        if(S[i] == '.') one_sentence = false;
    }
    if(one_sentence){
        for(int i=0; i<11; i++) cout << S[i];
        cout << "...";
        for(int i=10; i>=0; i--) cout << S[S.size()-i-1];
        return 0;
    }

    for(int i=0; i<9; i++) cout << S[i];
    cout << "......";
    for(int i=9; i>=0; i--) cout << S[S.size()-i-1];
}
```

```python
// python
N = int(input())
S = input()
Ans = ""

if len(S) <= 25:
    Ans = S
elif '.' not in S[11:-12]:
    Ans = S[:11] + "..." + S[-11:]
else:
    Ans = S[:9] + "......" + S[-10:]

print(Ans)
```

### D. 세워라 반석 위에

> Problem Idea: 나정휘(jhnah917)
>
> Preparation: 나정휘(jhnah917)

수열의 길이를 `N`, `A[i]`의 범위를 `X`라고 합시다.

가장 먼저 생각해볼 수 있는 풀이는 `O(N^3)` 풀이입니다. 가능한 `O(N^2)`개의 모든 구간을 보면서, 구간의 최솟값과 최댓값을 `O(N)`에 구하면 `O(N^3)`에 답을 구할 수 있지만 **시간 초과**가 발생합니다.

구간의 최댓값과 최솟값의 차이가 2 이하인 가장 긴 구간을 구해야 합니다. `X`가 매우 작은 것에 주목합시다. 만약 구간의 최솟값 `l`을 미리 고정시켰을 때의 답, 다시 말해 `l ≤ A[i] ≤ l+2`인 `A[i]`로만 이루어진 구간의 최대 길이를 `T(N)` 시간에 계산할 수 있다면 정답을 `O((X-2)T(N))` 시간에 구할 수 있습니다. 그리고 이러한 문제는 `O(N)`에 쉽게 해결할 수 있습니다.

`T(N) = O(N)`이므로 전체 문제를 `O(NX)`에 해결할 수 있습니다.

```cpp
// C++
#include <bits/stdc++.h>
using namespace std;

int N, A[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    int mx = 0;
    for(int i=1; i+2<=10; i++){
        int now = 0;
        for(int j=1; j<=N; j++){
            if(i <= A[j] && A[j] <= i+2) mx = max(mx, ++now);
            else now = 0;
        }
    }
    cout << mx;
}
```

```python
# Python
N = int(input())
A = list(map(int, input().split()))

mx = 0
for i in range(1, 9):
    now = 0
    for j in A:
        if i <= j <= i+2:
            now += 1
            if now > mx:
                mx = now
        else:
            now = 0

print(mx)
```

##### Challenge

* `O(N log N)`에 해결할 수 있습니다.

### E. 선린의 터를

> Problem Idea: 권욱제(wookje)
>
> Preparation: 나정휘(jhnah917)

`3^k > 3^(k-1) + 3^(k-2) + 3^(k-3) + ...`이라는 것은 자명합니다. 그러므로 가장 작은 수 8개는 다음과 같습니다.

* 1 = 3^0
* 3 = 3^1
* 4 = 3^0 + 3^1
* 9 = 3^2
* 10 = 3^0 + 3^2
* 12 = 3^1 + 3^2
* 13 = 3^0 + 3^1 + 3^2
* 27 = 3^3

`3^k`를 사용했다면 `k`번째 자리를 1, 사용하지 않았다면 0이라고 표시하면 아래와 같이 이진법을 뒤집은 형태가 나온다는 것을 알 수 있습니다.

* 1000 : 1 = 3^0
* 0100 : 3 = 3^1
* 1100 : 4 = 3^0 + 3^1
* 0010 : 9 = 3^2
* 1010 : 10 = 3^0 + 3^2
* 0110 : 12 = 3^1 + 3^2
* 1110 : 13 = 3^0 + 3^1 + 3^2
* 0001 : 27 = 3^3

그러므로 `N`을 2진법으로 나타낸 결과를 3진법으로 해석하면 된다는 것을 알 수 있습니다.

```cpp
// C++
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll pw3[40] = {1};

void Solve(){
    ll N; cin >> N;
    ll R = 0;
    for(int i=0; i<40; i++) if(N & (1LL << i)) R += pw3[i];
    cout << R << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=1; i<40; i++) pw3[i] = pw3[i-1] * 3;
    int T; cin >> T;
    while(T--) Solve();
}
```

```python
# python
T = int(input())
pw3 = [0] * 40

pw3[0] = 1
for i in range(1, 40):
    pw3[i] = pw3[i-1] * 3

for tc in range(T):
    N = int(input())
    ans = 0
    for i in range(0, 40):
        if (N & (1 << i)) != 0:
            ans += pw3[i]
    print(ans)
```

