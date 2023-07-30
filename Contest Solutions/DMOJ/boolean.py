n = input().split()
bruh = n[-1] == "True"
for i in range(len(n) - 1):
    bruh = not bruh
print(bruh)
