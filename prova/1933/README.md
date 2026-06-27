# 🃏 Tri-du — Solução (Beecrowd 1933)

Este repositório contém soluções para o problema [Beecrowd 1933 - Tri-du](https://www.beecrowd.com.br/judge/pt/problems/view/1933), proposto na **XX Maratona de Programação da SBC (2015)**.

---

## 📜 Enunciado resumido

No jogo **Tri-du**, cada jogador recebe três cartas.

As combinações possíveis são:

* **Trio** (três cartas iguais);
* **Dupla** (duas cartas iguais).

As regras são:

* Um **trio** sempre vence uma **dupla**.
* Entre dois trios, vence o de maior valor.
* Entre duas duplas, vence a de maior valor.

Dadas as duas primeiras cartas de um jogador (`A` e `B`), determine qual deve ser o valor da terceira carta para **maximizar a probabilidade de vitória**.

---

## 🧠 Lógica da Solução

### ✅ Ideia principal

Existem apenas dois casos possíveis.

### Caso 1 — As duas cartas são iguais

Se:

```text
A = B
```

Já existe uma dupla.

A melhor escolha é completar um trio utilizando outra carta de mesmo valor.

Exemplo:

```text
7 7
```

Melhor terceira carta:

```text
7
```

Resultado:

```text
7 7 7
```

Um trio sempre vence qualquer dupla.

---

### Caso 2 — As cartas são diferentes

Se:

```text
A ≠ B
```

Não é possível formar um trio.

As únicas opções são formar uma dupla com uma das cartas.

Exemplo:

```text
10 7
```

Podemos escolher:

```text
10 → (10,10,7)
```

ou

```text
7 → (10,7,7)
```

Como uma dupla de maior valor sempre vence uma dupla de menor valor, devemos escolher a carta de maior valor.

Logo:

```text
Resposta = max(A,B)
```

---

## 🔍 Etapas

1. Ler `A` e `B`.
2. Como:

   * se `A == B`, então `max(A,B) = A`;
   * se `A != B`, queremos a maior das duas cartas;
3. Basta imprimir:

```python
print(max(A,B))
```

Na implementação apresentada:

```python
if A > B:
    print(A)
else:
    print(B)
```

---

## 🎯 Explicação Visual

### Exemplo 1

Entrada:

```text
10 7
```

Possibilidades:

| Terceira carta | Mão formada |
| -------------: | ----------- |
|             10 | **10,10,7** |
|              7 | 10,7,7      |

Comparando:

```text
Dupla de 10
>
Dupla de 7
```

Resposta:

```text
10
```

---

### Exemplo 2

Entrada:

```text
2 2
```

Já existe uma dupla.

Adicionar:

```text
2
```

Forma:

```text
2 2 2
```

Resultado:

```text
Trio
```

Resposta:

```text
2
```

---

## ⏳ Complexidade

Como apenas uma comparação é realizada:

* **Tempo:** `O(1)`
* **Espaço:** `O(1)`

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 1933.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada | Saída |
| ------- | ----- |
| `10 7`  | `10`  |
| `2 2`   | `2`   |
