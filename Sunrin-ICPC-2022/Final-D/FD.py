import math

a, b, c, d = map(int, input().split())
n = int(input())
cnt = 0

for i in range(n):
    u, v = map(int, input().split())
    if a * (v-b) * (v-b) + c == u: cnt += 1
print(cnt)