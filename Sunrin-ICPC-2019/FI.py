arr = [0] * 1010
sum = [0] * 1010
sex = [0] * 1010


def f(i, k):
    l = i
    r = i + k - 1
    if r > n:
        return -1
    pow1sum = sum[r] - sum[l - 1]
    pow2sum = sex[r] - sex[l - 1]
    m = pow1sum
    pow1sum *= k
    pow2sum *= k * k
    v = pow2sum - (2 * pow1sum * m) + (m * m * k)
    return v


n = int(input())
str = input().split()
for i in range(0, n):
    arr[i + 1] = int(str[i])

for i in range(1, n + 1):
    sum[i] = sum[i - 1] + arr[i]
    sex[i] = sex[i - 1] + arr[i] * arr[i]

for k in range(1, n + 1):
    ans = 1
    maxi = f(1, k)
    for i in range(2, n + 1):
        now = f(i, k)
        if maxi < now:
            maxi = now
            ans = i
    print(ans)
