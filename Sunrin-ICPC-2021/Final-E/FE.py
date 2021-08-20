N = int(input())
ans = []
st = set()
for i in range(1, N):
    u, v = map(int, input().split())
    if u > v:
        (u, v) = (v, u)
    st.add((u,v))

if N <= 4:
    for i in range(1, N+1):
        for j in range(i+1, N+1):
            if (i,j) not in st:
                ans.append((i,j))
else:
    for i in range(2, N+1):
        if (1,i) not in st:
            ans.append((1,i))

print(len(ans))
if N <= 4:
    print(1)
else:
    print(2)
for i in ans:
    print(i[0], i[1])