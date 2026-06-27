from math import gcd
res = []

for i in range(int(input())):
    S1 = int(input(), 2)
    S2 = int(input(), 2)

    res.append(True if gcd(S1, S2) > 1 else False)

for i, j in enumerate(res):
    print(f"Pair #{i+1}: {'All you need is love!' if j else 'Love is not all you need!'}")