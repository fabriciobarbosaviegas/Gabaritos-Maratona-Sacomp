# 🪙 Lançando Moedas — Solução (Beecrowd 2972)

Este repositório contém a solução para o problema **Beecrowd 2972 - Lançando Moedas**, proposto na **Maratona de Programação da SBC 2019**.

---

## 📜 Enunciado resumido

Carla e Daniel irão lançar uma moeda **N vezes**, formando uma cadeia binária de comprimento `N`.

Cada cadeia pode ser atribuída:

* à Carla;
* ao Daniel;
* ou a ninguém.

Como a moeda pode ser desbalanceada, a divisão deve ser **justa para qualquer probabilidade** de cara ou coroa.

Além disso, deseja-se **minimizar a quantidade de cadeias não utilizadas**.

O objetivo é determinar o **menor número possível de cadeias que ficarão sem dono**.

---

# 🧠 Lógica da Solução

## ✅ Observação matemática

Uma cadeia de tamanho `N` possui exatamente `k` bits iguais a `1`.

Sua probabilidade de ocorrer é:

```text
P = p^k · (1-p)^(N-k)
```

onde:

* `p` é a probabilidade de sair coroa;
* `(1-p)` é a probabilidade de sair cara.

Todas as cadeias com a mesma quantidade de bits `1` possuem exatamente a mesma probabilidade.

---

## 📊 Quantas cadeias existem em cada grupo?

Para cada quantidade de bits `1`, existem

```text
C(N, k)
```

cadeias.

Exemplo para `N = 3`:

| Bits 1 | Cadeias     | Quantidade |
| ------ | ----------- | ---------: |
| 0      | 000         |          1 |
| 1      | 001 010 100 |          3 |
| 2      | 011 101 110 |          3 |
| 3      | 111         |          1 |

---

## 🔍 Como tornar a divisão justa?

Como todas as cadeias de um mesmo grupo têm a mesma probabilidade, podemos dividir apenas grupos cuja quantidade seja **par**.

Por exemplo:

```text
6 cadeias

3 → Carla
3 → Daniel
```

Já um grupo com quantidade ímpar:

```text
5 cadeias
```

não pode ser dividido igualmente.

Uma cadeia obrigatoriamente ficará sem dono.

---

## ✨ O Teorema utilizado

Um resultado clássico da teoria dos coeficientes binomiais afirma que:

> O número de coeficientes binomiais ímpares da linha `N` do Triângulo de Pascal é

```text
2^(número de bits 1 de N)
```

Esses coeficientes ímpares correspondem exatamente aos grupos que deixam uma cadeia "sobrando".

Logo, o número mínimo de cadeias não utilizadas é

```text
2^(popcount(N))
```

onde

```text
popcount(N)
```

é a quantidade de bits iguais a `1` na representação binária de `N`.

---

# 🎯 Explicação Visual

### Exemplo 1

```text
N = 3

3 = 11₂
```

Possui

```text
2 bits iguais a 1
```

Então

```text
Resposta = 2² = 4
```

---

### Exemplo 2

```text
N = 5

5 = 101₂
```

Possui

```text
2 bits 1
```

Logo

```text
Resposta = 2² = 4
```

---

### Exemplo 3

```text
N = 8

8 = 1000₂
```

Possui apenas

```text
1 bit igual a 1
```

Então

```text
Resposta = 2¹ = 2
```

---

## 📊 Funcionamento do algoritmo

```text
Entrada
      │
      ▼
Converter N para binário
      │
      ▼
Contar quantos bits são 1
      │
      ▼
Calcular

2^(quantidade de bits 1)

      │
      ▼
Imprimir resultado
```

---

# 💻 Duas Implementações

Este repositório apresenta **duas formas diferentes** de resolver o problema.

## 🥇 Solução 1 — Utilizando operações bitwise

A primeira solução utiliza operações de bits para tornar o algoritmo mais eficiente.

Para contar os bits iguais a `1`:

**Python**

```python
bits = bin(N).count('1')
```

**C**

```c
while (n) {
    bits += n & 1;
    n >>= 1;
}
```

Depois basta calcular:

```text
2^bits
```

No C isso é feito com deslocamento:

```c
1LL << bits
```

---

## 🥈 Solução 2 — Sem utilizar bitwise

A segunda implementação utiliza apenas operações aritméticas.

### Contagem dos bits

Em vez de deslocamentos:

```text
bit atual = n % 2
```

Depois:

```text
n = n / 2
```

até que `n` seja zero.

---

### Potência de dois

Em vez de usar deslocamentos:

```text
resultado = 1

repete bits vezes:
    resultado *= 2
```

obtendo o mesmo valor de

```text
2^bits
```

Essa implementação é útil para quem ainda não estudou operações bit a bit.

---

## ⏳ Complexidade

Seja `B` o número de bits necessários para representar `N`.

* **Tempo:** `O(B)`
* **Espaço:** `O(1)`

Como `N ≤ 10¹⁸`, temos no máximo cerca de 60 bits, tornando a solução extremamente eficiente.

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 2972.py
```

### 📘 C99

```bash
gcc -std=c99 -o 2972 2972.c
./2972
```

### 📘 C99

```bash
gcc -std=c99 -o 2972 2972noBit.c
./2972
```


---

## 💡 Exemplos de Entrada e Saída

| Entrada | Saída |
| ------- | ----: |
| `3`     |   `4` |
| `5`     |   `4` |
| `8`     |   `2` |
