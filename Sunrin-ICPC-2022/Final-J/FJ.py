def gcd(a, b):
    return gcd(b, a % b) if b != 0 else a

def lcm(a, b):
    return a // gcd(a, b) * b

n = int(input())
a = list(map(int, input().split()))
res = 1
for i in a:
    res = lcm(res, i)
print(res)