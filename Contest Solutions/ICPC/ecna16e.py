s = input()
ans = len(s)
for i in range(len(s)):
    for j in range(i, len(s)):
        temp = 0
        k = j + 1
        while k < len(s) - j + i:
            if s[i:j + 1] == s[k:k + j - i + 1]:
                temp += 1
                k += j - i
            k += 1
        ans = min(ans, len(s) - temp * (j - i) + 1)
print(ans)
