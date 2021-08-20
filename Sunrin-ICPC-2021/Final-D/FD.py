N = int(input())
mn = 4
res = ""
for i in range(N):
    inp = input().split()
    if mn > int(inp[1]):
        mn = int(inp[1])
        res = inp[0]
print(res)