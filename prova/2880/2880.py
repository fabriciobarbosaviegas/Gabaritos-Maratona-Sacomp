def compare(str1, str2, len):
    for i in range(len):
        if str1[i] == str2[i]:
            return 0    
    return 1

def main():
    alfabeto = input()
    palavra = input()

    palavraLen = len(palavra)
    alfabetoLen = len(alfabeto)
    c = 0

    for i in range(alfabetoLen):
        passo = i+palavraLen

        if passo > alfabetoLen:
            break
        
        cifra = alfabeto[i:passo]
        c += compare(palavra, cifra, palavraLen)

    print(c)

if __name__ == "__main__":
    main()