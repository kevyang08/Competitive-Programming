n, m = input().split()
n = int(n)
m = int(m)
low = m
index = 1
for i in range(n):
    count = 0
    line = input().split()
    for j in line:
        if j == "1" or j == "10":
            count+=1
    if count < low:
        low = count
        index = i + 1
print(index)
