c = 0
a = input()
b = input()

for i in range(len(a)):
    if a[i] != b[i]:
        c += 1

if c > 1 or c < 1:
    print('LARRY IS DEAD!')
else:
    print('LARRY IS SAVED!')
