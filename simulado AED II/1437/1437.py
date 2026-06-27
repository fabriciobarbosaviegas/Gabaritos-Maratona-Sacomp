r = ['N', 'L', 'S', 'O']
dir = {'D':1, 'E':-1}

while True:
        N = int(input())
        if N == 0:
                break
        d = input()

        p = 0

        for i in d:
                p += dir[i]
                p %= 4
        print(r[p])

