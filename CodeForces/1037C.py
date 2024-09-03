n = int(input())
a = input()
b = input()

costo = 0
i = 0
while i < n:
    if a[i] != b[i]:
        if i == n-1:
            costo += 1
            i += 1
        elif (a[i] == b[i+1]) and (a[i+1] == b[i]):
            costo += 1
            i += 2
        else:
            costo += 1
            i += 1
    else:
        i += 1

print(costo)