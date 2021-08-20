N = int(input())
A = list(map(int, input().split()))
A.insert(0, 0)
mx = 1
for i in range(1, N+1):
    l, r = i, i
    while l > 1 and A[l] > A[l-1]: l -= 1
    while r < N and A[r] > A[r+1]: r += 1
    if mx < r-l+1: mx = r-l+1
print(mx)