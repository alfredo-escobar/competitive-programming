n = int(input())
m = int(input())

a = []
for i in range(n):
    a.append(int(input()))

resp2 = m + max(a)

for i in range(m):
    a[a.index(min(a))] += 1

resp1 = max(a)

print(resp1,resp2)
