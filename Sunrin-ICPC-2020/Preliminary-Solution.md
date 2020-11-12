# 2020 천하제일 코딩대회 예선 풀이

### A번

> 선린인터넷고등학교의 한 학생은 프로그래밍 대회에 참가하여 거액의 상금을 수상하는 영광을 누리게 되었다.

전체 금액의 22%를 세금으로 납부하면 78%를 받게 됩니다.<br>전체 금액의 80%를 필요 경비를 인정하고, 나머지 부분에 대해서만 22%를 납부하면 95.6%를 받게 됩니다.

`N * 956 / 1000`처럼 계산하면 N이 `int`형일 때 overflow가 날 수도 있으니 `N / 1000 * 956`와 같이 계산하는 것을 권장합니다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    cout << n / 100 * 78 << " " << n / 1000 * 956;
}
```

### B번

조건문을 열심히 코딩해도 되지만, 저는 x, y축 방향 이동을 나타내는 배열 `dx, dy`를 잡아서 구현하는 것을 선호합니다.

`dx, dy`를 시계 방향 또는 반시계 방향으로 정한 뒤, 회전 방향에 따라 `dir + 1 mod 4`와 `dir - 1 mod 4`를 적용하면 됩니다. C/C++에서는  `-1 % 4 == -1`이기 때문에 `(dir - 1) % 4` 대신 `(dir + 3) % 4`를 써야 합니다.

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

ll n, t, x, y;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> t;
    ll lst = 0, dir = 0;
    for(int i=1; i<=n; i++){
        ll now; string s;
        cin >> now >> s;
        x += dx[dir] * (now - lst);
        y += dy[dir] * (now - lst);
        if(s == "left") dir = (dir + 3) % 4;
        else dir = (dir + 1) % 4;
        lst = now;
    }
    x += dx[dir] * (t - lst);
    y += dy[dir] * (t - lst);
    cout << x << " " << y;
}
```

### C번

잘 생각해보면, 문자열의 길이의 총합이 문제의 정답이 된다는 것을 알 수 있습니다.

C언어로 구현할 때는 `<string.h>`에 있는 `strlen`함수를 사용해 문자열의 길이를 구할 수 있습니다.

문자열의 길이가 최대 100이기 때문에 배열의 길이는 최소한 **101** 이상으로 잡아야 합니다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s;
        ans += s.size();
    }
    cout << ans;
}
```

### D번

어떤 원소가 최대한 앞에 나오기 위해서는 (1) 자기 자신은 최대한 작아지고, (2) 다른 모든 원소는 최대한 커져야 합니다.<br>마찬가지로, 어떤 원소가 최대한 뒤에 나오기 위해서는 (1) 자기 자신은 최대한 커지고, (2) 다른 모든 원소는 최대한 작아져야 합니다.

그러므로 어떤 원소 `a[x] ± b[x]`가 올 수 있는 가장 빠른 위치는, `a[i] + b[i]`의 값을 다 모았을 때 `a[x] - b[x]`보다 작은 수의 개수가 됩니다.<br>어떤 원소 `a[x] ± b[x]`가 올 수 있는 가장 뒤쪽 위치는, `a[i] - b[i]`의 값을 다 모았을 때 (`a[x] + b[x]`보다 작거나 같은 수의 개수) - 1입니다. (`a[x] - b[x]` 빼야함)

이분 탐색을 이용하면 문제에서 요구하는 답을 O(N log N)만에 구할 수 있습니다.

```cpp
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;

ll n, a[505050], b[505050];
vector<ll> mn, mx;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        ll x, y; cin >> x >> y;
        a[i] = x - y; mn.push_back(a[i]);
        b[i] = x + y; mx.push_back(b[i]);
    }
    sort(all(mn)); sort(all(mx));
    for(int i=1; i<=n; i++){
        int t1 = lower_bound(all(mx), a[i]) - mx.begin() + 1;
        int t2 = upper_bound(all(mn), b[i]) - mn.begin();
        cout << t1 << " " << t2 << "\n";
    }
}
```

