n = int(input())
r = []
c = 0
for i in range(n):
    r.append(input())

for i in range(n):
    if (input() == r[i]):
        c += 1

print(c)
