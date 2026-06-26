while True:
    N, K = [int(i) for i in input().split()]
    if N == K == 0:
        break

    events = []
    for i in range(N):
        c, s = [int(i) for i in input().split()]
        events.append((c, 1, i))
        events.append((s, 0, i))

    events.sort()

    stack = []
    ok = True

    for i, tipo, carro in events:
        if tipo == 1:
            if len(stack) == K:
                ok = False
                break
            stack.append(carro)
        else:
            if not stack or stack[-1] != carro:
                ok = False
                break
            stack.pop()

    print("Sim" if ok else "Nao")
