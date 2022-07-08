def valid(n, k, cnt):
    rem = n - sum(cnt)
    mx = 0
    for i in cnt: mx = max(mx, i)
    need = 0
    for i in range(10):
        if cnt[i] != 0: need += max(0, mx - cnt[i] - k)
    return need <= rem

def solve():
    s, k = input().split()
    k = int(k)
    n = len(s)
    cnt = [0] * 10
    for i in s: cnt[ord(i)-48] += 1
    if valid(n, k, cnt):
        print(s)
        return

    idx, val = -1, -1
    for i in range(n-1, -1, -1):
        cnt[ord(s[i])-48] -= 1
        for j in range(ord(s[i])-49, -1, -1):
            cnt[j] += 1
            if valid(n, k, cnt):
                idx = i
                val = j
                break
            cnt[j] -= 1
        if idx != -1: break

    if idx == 0 and val == 0:
        print('9' * (n-1))
        return

    print(s[:idx], end='')
    print(val, end='')

    idx += 1
    while idx < n:
        for i in range(9, -1, -1):
            cnt[i] += 1
            if valid(n, k, cnt):
                print(i, end='')
                break
            cnt[i] -= 1
        idx += 1
    print('')

t = int(input())
for tc in range(t):
    solve()