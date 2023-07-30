n = int(input())
m = int(input())
adj = []
noun = []
for i in range (n):
    adj.append(input())
for i in range (m):
    noun.append(input())
for i in adj:
    for j in noun:
        print(i + " as " + j)
