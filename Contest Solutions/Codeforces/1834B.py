import sys
input = sys.stdin.readline

def solve(a, b):
    r, c = 0, 0
    for i in range(len(a)):
        if not c:
            r += abs(int(a[i]) - int(b[i]))
            if a[i] != b[i]:
                c = 1
        else:
            r += 9
    print(r)

t = int(input())
for _ in range(t):
    a, b = input().split()
    if len(a) < len(b):
        a = '0' * (len(b) - len(a)) + a
    if len(b) < len(a):
        b = '0' * (len(a) - len(b)) + b
    if a < b:
        solve(a, b)
    else:
        solve(b, a)