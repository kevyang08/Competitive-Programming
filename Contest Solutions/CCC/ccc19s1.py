grid = [[1, 2], [3, 4]]
h = v = 0
s = input()

for i in range(len(s)):
    if s[i] == 'H':
        h += 1
    elif s[i] == 'V':
        v += 1

if h%2 == 1:
    temp = grid[0]
    grid[0] = grid[1]
    grid[1] = temp
if v%2 == 1:
    grid[0].reverse()
    grid[1].reverse()

for i in range(2):
    print(str(grid[i][0]) + ' ' + str(grid[i][1]))
