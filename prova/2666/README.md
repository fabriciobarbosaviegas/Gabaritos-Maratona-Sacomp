# 👑 Imposto Real — Solução (Beecrowd 2666)

Este repositório contém a solução para o problema [Beecrowd 2666 - Imposto Real](https://www.beecrowd.com.br/judge/pt/problems/view/2666), proposto na **Maratona de Programação da SBC - ACM ICPC 2017**.

---

## 📜 Enunciado resumido

O reino de Nlogônia possui **N cidades** ligadas por estradas formando uma **árvore** (existe exatamente um caminho entre quaisquer duas cidades).

Cada cidade possui uma determinada quantidade de ouro que deve ser transportada até a **capital (cidade 1)**.

A carruagem real possui capacidade máxima de **C kg** por viagem, podendo utilizar os cofres das cidades para armazenar ouro temporariamente.

O objetivo é determinar a **menor distância total** que a carruagem precisa percorrer para transportar todo o ouro até a capital.

---

## 🧠 Lógica da Solução

### ✅ Observação principal

Como o grafo é uma **árvore**, todo ouro presente em uma cidade obrigatoriamente passa pela única estrada que liga sua subárvore ao restante do reino.

Assim, podemos calcular independentemente quantas viagens cada estrada precisará suportar.

A ideia consiste em realizar uma **DFS (Depth-First Search)** a partir da capital.

Durante a volta da recursão, cada subárvore informa:

* quanto ouro ela possui;
* quantas viagens são necessárias para transportar esse ouro até seu pai.

---

## 🔍 Etapa 1 — Somar o ouro das subárvores

A DFS retorna para o pai a quantidade total de ouro existente na subárvore.

Para um vértice `u`:

```text
ouro(u) = ouro da própria cidade + ouro de todas as subárvores
```

Ou seja,

```text
sub(u) = E[u] + sum(sub(filhos))
```

---

## 🔍 Etapa 2 — Quantas viagens cada estrada precisa?

Suponha que uma subárvore possua:

```text
25 kg
```

e a carruagem transporte apenas

```text
10 kg
```

Serão necessárias:

```text
ceil(25 / 10) = 3 viagens
```

Cada viagem precisa:

* ir até a subárvore;
* voltar para continuar coletando ouro.

Logo cada viagem percorre a estrada duas vezes.

Assim, para uma estrada de comprimento `d`:

```text
custo = 2 * ceil(ouro_subárvore / capacidade) * d
```

Esse valor é somado à resposta.

---

## 🎯 Explicação Visual

Considere a árvore abaixo.

```text
          (1)
         /   \
      4km     3km
       /       \
     (2)       (3)
               /
            2km
             /
           (4)
```

Quantidade de ouro:

```text
Cidade 1 → 0 kg
Cidade 2 → 12 kg
Cidade 3 → 5 kg
Cidade 4 → 18 kg

Capacidade = 10 kg
```

### Passo 1 — Cidade 4

Possui:

```text
18 kg
```

Viagens:

```text
ceil(18/10)=2
```

Custo da estrada:

```text
2 × 2 × 2 = 8 km
```

Cidade 3 recebe:

```text
18 + 5 = 23 kg
```

---

### Passo 2 — Cidade 3

Agora a subárvore possui:

```text
23 kg
```

Viagens:

```text
ceil(23/10)=3
```

Estrada até a capital:

```text
2 × 3 × 3 = 18 km
```

---

### Passo 3 — Cidade 2

Possui:

```text
12 kg
```

Viagens:

```text
ceil(12/10)=2
```

Custo:

```text
2 × 2 × 4 = 16 km
```

---

### Distância total

```text
8 + 18 + 16 = 42 km
```

---

## 📊 Fluxo da DFS

```text
                 DFS(1)
                    │
      ┌─────────────┴─────────────┐
      ▼                           ▼
   DFS(filho)                 DFS(filho)
      │                           │
      ▼                           ▼
 Calcula ouro               Calcula ouro
 da subárvore               da subárvore
      │                           │
      └─────────────┬─────────────┘
                    ▼
      ceil(ouro/CAP)
                    │
                    ▼
      Soma custo da estrada
                    │
                    ▼
      Retorna ouro ao pai
```

---

## 📚 Algoritmos utilizados

A solução utiliza:

* **Lista de adjacência** para representar a árvore;
* **DFS (Depth-First Search)** para percorrer todas as cidades;
* Cálculo matemático do número mínimo de viagens utilizando:

```text
ceil(ouro / capacidade)
```

Na implementação inteira, o teto é calculado sem ponto flutuante:

```c
(sv + CAP - 1) / CAP
```

---

## ⏳ Complexidade

Cada cidade e cada estrada são visitadas exatamente uma vez.

Assim:

* **Tempo:** `O(N)`
* **Espaço:** `O(N)`

---

## ▶️ Como Executar

### 📘 C99

```bash
gcc -std=c99 -O2 -o 2666 2666.c
./2666
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada                                                                             | Saída |
| ----------------------------------------------------------------------------------- | ----- |
| `6 10`<br>`0 10 10 10 10 10`<br>`1 4 7`<br>`5 1 2`<br>`3 5 3`<br>`2 5 2`<br>`6 5 2` | `44`  |
| `3 10`<br>`10 10 12`<br>`1 2 5`<br>`2 3 7`                                          | `58`  |
| `5 9`<br>`5 2 6 3 6`<br>`1 2 1`<br>`2 3 1`<br>`2 4 1`<br>`2 5 1`                    | `10`  |
