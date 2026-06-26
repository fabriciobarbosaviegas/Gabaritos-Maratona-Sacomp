from collections import Counter

abc = [int(i) for i in input().split()]

if 0 in abc: print("S")
elif len(Counter(abc)) <= 2: print("S")
elif max(abc) - (sum(abc)-max(abc)) == 0: print("S")
else: print("N")