l,r = [int(i) for i in input().split()]

print("YES")

while l<r:
    print(str(l)+" "+str(l+1))
    l += 2