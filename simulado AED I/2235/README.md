# ⏳ Andando no Tempo — Solução (Beecrowd 2235)

Este repositório contém soluções para o problema [Beecrowd 2235 - Andando no Tempo](https://www.beecrowd.com.br/judge/pt/problems/view/2235), proposto na **Maratona de Programação SBC 2016**.

---

## 📜 Enunciado resumido

Uma máquina do tempo possui **três créditos**, cada um permitindo viajar uma quantidade fixa de anos para o **passado** ou para o **futuro**.

Cada crédito pode ser utilizado **no máximo uma vez**, e é possível realizar **uma, duas ou três viagens**.

O objetivo é determinar se existe alguma combinação de viagens que permita **voltar exatamente ao presente** (deslocamento total igual a zero).

---

## 🧠 Lógica da Solução

### ✅ Objetivo

Verificar se existe alguma combinação dos três créditos cujo deslocamento total seja zero.

Como há apenas três créditos, existem apenas **três situações** em que isso é possível:

1. Dois créditos possuem o mesmo valor.
2. Um crédito é igual à soma dos outros dois.
3. Algum crédito vale `0` (caso geral, embora pelas restrições do problema isso nunca aconteça).

Caso alguma dessas condições seja verdadeira, a resposta é **"S"**. Caso contrário, **"N"**.

---

## 🔍 Como a solução verifica isso

### 1️⃣ Dois créditos iguais

Se dois créditos possuem o mesmo valor, basta:

* usar um para o passado;
* usar o outro para o futuro.

Exemplo:

```
22 5 22
```

```
+22 −22 = 0
```

Na implementação isso é identificado verificando se existem apenas dois valores distintos:

```python
len(Counter(abc)) <= 2
```

---

### 2️⃣ Um crédito é igual à soma dos outros dois

Se um crédito for exatamente igual à soma dos outros dois, podemos fazer:

* usar o maior em uma direção;
* usar os outros dois na direção oposta.

Exemplo:

```
31 110 79
```

```
+110 −79 −31 = 0
```

Na implementação:

```python
max(abc) - (sum(abc) - max(abc)) == 0
```

ou seja,

```text
maior = soma dos outros dois
```

---

### 3️⃣ Crédito igual a zero

Caso exista um crédito igual a zero, basta utilizá-lo para realizar uma viagem que termina no mesmo instante.

```python
0 in abc
```

> **Observação:** pelas restrições do problema (`1 ≤ A, B, C ≤ 1000`), essa condição nunca ocorre. Ela foi mantida apenas por completude.

---

## 🎯 Explicação Visual

### Exemplo 1

Entrada:

```
22 5 22
```

Viagens:

```
+22
-22
```

Resultado:

```
0 anos
```

✅ Resposta:

```
S
```

---

### Exemplo 2

Entrada:

```
31 110 79
```

Viagens:

```
+110
-79
-31
```

```
110 - 79 - 31 = 0
```

✅ Resposta:

```
S
```

---

### Exemplo 3

Entrada:

```
45 8 7
```

Possibilidades:

```
45 ≠ 8
45 ≠ 7
8 ≠ 7

45 ≠ 8 + 7
```

Nenhuma combinação retorna ao presente.

❌ Resposta:

```
N
```

---

## ⏳ Complexidade

Como apenas três valores são analisados:

* **Tempo:** `O(1)`
* **Espaço:** `O(1)`

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 2235.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada     | Saída |
| ----------- | ----- |
| `22 5 22`   | `S`   |
| `31 110 79` | `S`   |
| `45 8 7`    | `N`   |
