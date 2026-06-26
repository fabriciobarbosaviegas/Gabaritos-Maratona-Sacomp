import math
N, L, D = [int(i) for i in input().split()]

consumo = N*D/1000

if consumo <= L:
    print(L)
else:
    quantidade = consumo / L
    print(math.ceil(quantidade) * L)