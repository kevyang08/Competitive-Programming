a = list(map(int, input().split()))
print(max(a[0]*a[1]*a[2],a[0]*a[1]+a[2],a[0]+a[1]*a[2],(a[0]+a[1])*a[2],a[0]*(a[1]+a[2]),a[0]+a[1]+a[2],a[0]*a[2]+a[1],a[1]*(a[2]+a[0])))
