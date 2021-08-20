n = int(input())
a = list(map(int, input().split()))
idx = a.index(max(a))

res = True
for i in range(0, idx):
    if a[i] >= a[i+1]:
        res = False

for i in range(idx+1, n-1):
    if a[i] <= a[i+1]:
        res = False

print("YES" if res else "NO")