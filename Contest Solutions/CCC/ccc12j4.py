k = int(input())
s = input()
bruh = ''

for p in range(len(s)):
    bruh += chr(ord(s[p]) - (3 * (p + 1) + k)%26) if ord(s[p]) - (3 * (p + 1) + k)%26 >= 65 else chr(ord(s[p]) - (3 * (p + 1) + k)%26 + 26)
    
print(bruh)
