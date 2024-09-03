t = int(input())
for i in range(t):
    x,y = [int(i) for i in input().split()]
    dif = x-y
    if dif == 1:
        print("NO")
    else:
        print("YES")