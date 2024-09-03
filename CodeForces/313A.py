def ultimoDigito(x):
    if x<0:
        mod = -1
        x = abs(x)
    else:
        mod = 1
    return int(x//10) * mod

def penultimoDigito(x):
    if x<0:
        mod = -1
        x = abs(x)
    else:
        mod = 1        
    ult = int((x*0.1 - x//10 + 0.001) * 10)
    return (int(x//100)*10 + ult) * mod

x = int(input())
best = max(x, ultimoDigito(x), penultimoDigito(x))
print(best)