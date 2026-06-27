# 🔐 Enigma — Solução (Beecrowd 2880)

Este repositório contém a solução para o problema [Beecrowd 2880 - Enigma](https://www.beecrowd.com.br/judge/pt/problems/view/2880), proposto na **Maratona de Programação da SBC 2018**.

---

## 📜 Enunciado resumido

A máquina **Enigma** possuía uma característica importante:

> **Uma letra nunca era criptografada para ela mesma.**

Dada:

* uma **mensagem cifrada**;
* uma palavra conhecida (**crib**);

devemos determinar **em quantas posições** essa palavra poderia aparecer na mensagem.

Uma posição é considerada válida se, ao alinhar o crib com aquele trecho da mensagem, **nenhuma letra ocupar a mesma posição com o mesmo caractere**.

---

## 🧠 Lógica da Solução

### ✅ Ideia principal

Percorremos todas as posições possíveis onde o crib pode ser alinhado com a mensagem.

Para cada posição:

1. extraímos o trecho da mensagem com o mesmo tamanho do crib;
2. comparamos letra por letra;
3. se existir alguma posição onde as letras sejam iguais, essa posição é inválida;
4. caso contrário, contamos essa posição como possível.

---

## 🔍 Etapas

1. Ler a mensagem cifrada.
2. Ler o crib.
3. Para cada posição possível:

   * extrair a substring correspondente;
   * comparar os dois textos;
   * verificar se existe alguma letra igual na mesma posição.
4. Contabilizar todas as posições válidas.

---

## 🎯 Explicação Visual

Considere:

```text
Mensagem:
FDMLCRDMRALF

Crib:
ARMADA
```

Vamos deslizar o crib pela mensagem.

```text
Posição 1

FDMLCR
ARMADA
 ^

F ≠ A
D ≠ R
M ≠ M ❌
```

Existe uma letra igual (`M`).

Essa posição é descartada.

---

```text
Posição 2

 DMLCRD
 ARMADA
```

Comparando:

```text
D ≠ A
M ≠ R
L ≠ M
C ≠ A
R ≠ D
D ≠ A
```

Nenhuma letra coincide.

✔ Esta posição é válida.

---

```text
Posição 3

MLCRDM
ARMADA
```

Existe uma coincidência.

❌ Inválida.

O processo continua até o final da mensagem.

No exemplo do problema existem exatamente:

```text
2 posições válidas
```

---

## 📊 Funcionamento do algoritmo

```text
Mensagem

FDMLCRDMRALF
│
├── FDMLCR
├── DMLCRD ✔
├── MLCRDM
├── LCRDMR
├── CRDMRA ✔
├── RDMRAL
└── DMRALF

Total = 2
```

Cada janela possui exatamente o tamanho do crib.

---

## ⏳ Complexidade

Sejam:

* `N` = tamanho da mensagem;
* `M` = tamanho do crib.

Existem `N - M + 1` posições possíveis.

Cada posição realiza até `M` comparações.

Assim:

* **Tempo:** `O((N - M + 1) × M)` ≈ `O(N × M)`
* **Espaço:** `O(1)` (desconsiderando a substring criada pela linguagem).

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 2880.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada                          | Saída |
| -------------------------------- | ----- |
| `FDMLCRDMRALF`<br>`ARMADA`       | `2`   |
| `AAAAABABABABABABABABA`<br>`ABA` | `7`   |
