n, k = map(int, input().split())
a = list(map(int, input().split()))

def check(x):
    global a, k
    res = 0
    for i in a: res += max(0, i - x)
    return res <= k

l, r = 0, 10**12
while l < r:
    m = (l + r) // 2
    if check(m): r = m
    else: l = m + 1

print(r)