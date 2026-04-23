n, c = map(int, input().split())
a = list(map(int, input().split()))

if (c == 2 and n % 2 == 1):
    print(-1)
    exit()

for i in range(n):
    a[i] -= 1

copy_a = a.copy()

def solve(a):
    ans = 0

    for i in range(n):
        prev = a[i - 1]
        cur = a[i]
        next = a[(i + 1) % n]
    
        if a[i] == prev:
            ans += 1
            while (a[i] == prev or a[i] == next) and (((a[i] + 1) % c) != cur):
                a[i] = (a[i] + 1) % c

    return ans

ans = min(solve(a), solve(copy_a[::-1]))

if ans != 9999999:
    print(ans)
else:
    print(-1)