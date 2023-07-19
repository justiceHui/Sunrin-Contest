d = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def check(a, x):
    while x > 0:
        if a[x%10] == 1: return False
        x //= 10
    return True

def solve():
    global d
    res = 0
    a = list(map(int, input().split()))
    for i in range(1, 13):
        for j in range(1, d[i]+1):
            if check(a, i) and check(a, j): res += 1
    print(res)

t = int(input())
for _ in range(t): solve()