A = [int(input()), int(input()), int(input())]

tempo1 = 0 * A[0] + 2 * A[1] + 4 * A[2]
tempo2 = 2 * A[0] + 0 * A[1] + 2 * A[2]
tempo3 = 4 * A[0] + 2 * A[1] + 0 * A[2]

print(min(tempo1, tempo2, tempo3))