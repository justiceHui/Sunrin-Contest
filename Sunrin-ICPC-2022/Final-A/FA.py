n, m = map(int, input().split())
cnt = [0] * 3
for i in range(n): input()
for i in range(m):
    c = input().split()[2]
    if c == 'R': cnt[0] += 1
    elif c == 'B': cnt[1] += 1
    else: cnt[2] += 1

i = 0
while True:
    if cnt[2] > 0: cnt[2] -= 1
    elif cnt[i%2] > 0: cnt[i%2] -= 1
    else:
        if i % 2 == 0: print('jhnan917')
        else: print('jhnah917')
        break
    i += 1