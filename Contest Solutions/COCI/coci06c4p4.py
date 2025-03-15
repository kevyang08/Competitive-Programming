M=1000000007
n,c=map(int,input().split())
dp=[1]+[0]*c
for i in range(2,n+1):
    s=(dp[c]+dp[c-1])%M
    l=c-1
    for j in range(c,0,-1):
        while l>0 and j-l+1<i:
            l-=1
            s=(s+dp[l])%M
        dp[j],s=s,(s-dp[j]+M)%M
print(dp[c])