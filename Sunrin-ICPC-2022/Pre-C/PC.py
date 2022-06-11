T = int(input())

for tc in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    flag = True
    for i in range(n):
        a[i] = a[i] if a[i] < n-a[i]+1 else n-a[i]+1
        if i > 0 and a[i-1] > a[i]: a[i] = n-a[i]+1
        if i > 0 and a[i-1] > a[i]: flag = False
    print('YES' if flag else 'NO')