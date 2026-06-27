# 🧭 Esquerda, Volver! — Solução (Beecrowd 1437)

Este repositório contém soluções para o problema [Beecrowd 1437 - Esquerda, Volver!](https://www.beecrowd.com.br/judge/pt/problems/view/1437), proposto na **Maratona de Programação da SBC 2006**.

---

## 📜 Enunciado resumido

Um recruta inicia o treinamento voltado para o **Norte (N)**.

O sargento emite uma sequência de comandos:

* **E** → virar 90° para a **Esquerda**.
* **D** → virar 90° para a **Direita**.

Após executar todos os comandos, determine para qual direção o recruta estará voltado.

As possíveis direções são:

* **N** → Norte
* **L** → Leste
* **S** → Sul
* **O** → Oeste

A entrada possui vários casos de teste e termina quando `N = 0`.

---

## 🧠 Lógica da Solução

### ✅ Objetivo

Simular as rotações do recruta e determinar sua direção final.

Para isso, representamos as quatro direções em um vetor circular:

```text
N → L → S → O
↑           ↓
└───────────┘
```

Na implementação:

```python
r = ['N', 'L', 'S', 'O']
```

Cada direção corresponde a um índice:

| Índice | Direção |
| -----: | :-----: |
|      0 |    N    |
|      1 |    L    |
|      2 |    S    |
|      3 |    O    |

---

### 🔍 Etapas

1. Inicializar a posição em `0` (Norte).
2. Para cada comando:

   * `D` → somar `1`.
   * `E` → subtrair `1`.
3. Aplicar módulo `4` após cada movimento para manter o índice entre `0` e `3`.
4. Ao final, imprimir a direção correspondente.

Na solução, os comandos são representados por um dicionário:

```python
dir = {
    'D': 1,
    'E': -1
}
```

Assim, basta atualizar:

```python
p += dir[i]
p %= 4
```

---

## 🎯 Explicação Visual

Imagine a bússola como um círculo:

```text
        N (0)
         ↑
         |
O (3) ←     → L (1)
         |
         ↓
        S (2)
```

Cada comando apenas move uma posição nesse círculo.

---

### Exemplo 1

Entrada:

```text
D D E
```

Passo a passo:

| Comando | Índice | Direção |
| ------- | :----: | :-----: |
| Início  |    0   |    N    |
| D       |    1   |    L    |
| D       |    2   |    S    |
| E       |    1   |    L    |

Resposta:

```text
L
```

---

### Exemplo 2

Entrada:

```text
E E
```

Passo a passo:

| Comando | Índice | Direção |
| ------- | :----: | :-----: |
| Início  |    0   |    N    |
| E       |    3   |    O    |
| E       |    2   |    S    |

Resposta:

```text
S
```

Observe que o operador `% 4` faz a direção "dar a volta" quando ultrapassa os limites do vetor.

---

## ⏳ Complexidade

Para cada caso de teste, percorremos todos os comandos apenas uma vez.

* **Tempo:** `O(N)`
* **Espaço:** `O(1)`

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 1437.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada      | Saída              |
| ------------ | ------------------ |
| `3`<br>`DDE` | `L`                |
| `2`<br>`EE`  | `S`                |
| `0`          | *(fim da entrada)* |
