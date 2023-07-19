n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

i, j, res = 0, n - 1, 0
while i < j:
    while i < j and a[i] + a[j] > k: j -= 1
    if i < j and a[i] + a[j] <= k:
        res += 1
        j -= 1
    i += 1

print(res)