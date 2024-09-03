n = int(input())

a = [int(i) for i in input().split()]
max_a = max(a)

freq = [0] * (max_a + 1)
for i in a:
    freq[i] += 1

sumaMax = [0,freq[1]]
for i in range(2,(max_a+1)):
    sumaMax.append(max(sumaMax[i-1], (freq[i]*i) + sumaMax[i-2]))

print(sumaMax[max_a])