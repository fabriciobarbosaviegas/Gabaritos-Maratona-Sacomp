while True:
    T, N = [int(i) for i in input().split()]

    if T == N == 0:
        break

    s = 0

    for i in range(T):
        s += int(input().split()[1])

    print(3*N-s)