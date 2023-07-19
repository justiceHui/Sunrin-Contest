def f(x):
    return x * (x + 1) // 2

def get(a):
    n = len(a)
    mx, le, ri, vm, vl, vr = 0, 0, 0, 0, 0, 0
    for i in range(n):
        vm = max(vm, 0) + a[i]
        mx = max(mx, vm)
    for i in range(n):
        vl += a[i]
        le = max(le, vl)
    for i in range(n-1, -1, -1):
        vr += a[i]
        ri = max(ri, vr)
    return (mx, le, ri)

n = int(input())
a = list(map(int, input().split()))
s = sum(a)

a4 = [a[i%n] - i - 1 for i in range(n*4)]
res = max(0, get(a4)[0])

k = max(5, (2 * s + n * n - n) // (2 * n * n))

le = [a[i%n] - i - 1 for i in range(n*2)]
ri = [a[i%n] - (k-1) * n - i - 1 for i in range(n*2)]
sum = s * (k - 3) - f((k-1)*n) + f(2*n)
res = max(res, get(le)[2] + sum + get(ri)[1])

print(res)