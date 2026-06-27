# 🚚 Desvio de Rota — Solução (Beecrowd 1123)

Este repositório contém soluções para o problema [Beecrowd 1123 - Desvio de Rota](https://www.beecrowd.com.br/judge/pt/problems/view/1123), proposto na **Maratona de Programação da SBC 2010**.

---

## 📜 Enunciado resumido

Um veículo da transportadora seguia uma **rota de serviço fixa**, formada pelas cidades:

```text
0 → 1 → 2 → ... → C-1
```

Após quebrar na cidade `K`, o veículo precisa continuar a entrega até o destino (`C-1`).

Entretanto existe uma regra importante:

> Assim que o veículo entrar em qualquer cidade pertencente à rota de serviço, ele é obrigado a seguir o restante da rota original, sem realizar novos desvios.

O objetivo é encontrar o **menor custo de pedágio** necessário para chegar ao destino.

---

## 🧠 Lógica da Solução

O problema pode ser dividido em duas partes:

1. **Chegar até alguma cidade da rota de serviço** com o menor custo possível.
2. **Seguir obrigatoriamente a rota** até o destino.

A solução combina **pré-processamento** com o algoritmo de **Dijkstra**.

---

## 🔍 Etapa 1 — Custo restante da rota

Como a rota é fixa:

```text
0 → 1 → 2 → ... → C-1
```

Podemos calcular, para cada cidade da rota, quanto custa chegar ao destino.

Criamos o vetor:

```text
route_cost[i]
```

onde

```text
route_cost[i] = custo de seguir a rota de i até C-1
```

Esse vetor é preenchido de trás para frente.

### Exemplo

Suponha:

```text
0 --10-- 1 --5-- 2 --7-- 3
```

O destino é a cidade **3**.

Calculando:

| Cidade | route_cost |
| ------ | ---------: |
| 3      |          0 |
| 2      |          7 |
| 1      |         12 |
| 0      |         22 |

Assim, se conseguirmos chegar à cidade 1, já sabemos que ainda faltará pagar **12** de pedágio.

---

## 🔍 Etapa 2 — Dijkstra com restrição

Agora executamos **Dijkstra** a partir da cidade `K`.

Entretanto existe uma modificação importante.

Quando o algoritmo alcança uma cidade da rota (`0 ≤ cidade < C`), ele **não continua explorando seus vizinhos**.

No código:

```c
if (u < C)
    continue;
```

Isso acontece porque, segundo o enunciado, ao entrar na rota não é mais permitido fazer desvios.

Portanto, essas cidades tornam-se **nós terminais** da busca.

---

## 🔍 Etapa 3 — Escolher o melhor ponto de entrada

Após o Dijkstra conhecemos:

```text
dist[i]
```

que representa o menor custo para chegar até cada cidade.

Para cada cidade da rota calculamos:

```text
custo total = dist[i] + route_cost[i]
```

e escolhemos o menor valor.

---

## 🎯 Explicação Visual

Considere a seguinte rota de serviço:

```text
0 ----5---- 1 ----4---- 2
```

Destino:

```text
2
```

O veículo está na cidade:

```text
5
```

Suponha que existam estradas:

```text
5 ----2---- 1
5 ----8---- 0
```

### Pré-processamento

```text
route_cost

Cidade 2 → 0
Cidade 1 → 4
Cidade 0 → 9
```

### Dijkstra

Menores custos encontrados:

```text
dist[0] = 8
dist[1] = 2
```

Agora calculamos:

| Entrada  | Distância | Rota restante | Total |
| -------- | --------: | ------------: | ----: |
| Cidade 0 |         8 |             9 |    17 |
| Cidade 1 |         2 |             4 | **6** |

A melhor escolha é entrar na rota pela cidade **1**.

Resposta:

```text
6
```

---

## 📊 Fluxo da solução

```text
             Cidade K
                 │
                 ▼
        Dijkstra modificado
                 │
      ┌──────────┴──────────┐
      ▼                     ▼
Entrou na rota?          Ainda fora?
      │                     │
     Sim                   Continua
      │
      ▼
Para de expandir
      │
      ▼
 Soma route_cost
      │
      ▼
 Menor resposta
```

---

## 📚 Algoritmos utilizados

A solução combina duas ideias:

* **Programação dinâmica simples** para calcular o custo restante da rota (`route_cost`);
* **Dijkstra** para encontrar o menor custo até qualquer ponto da rota.

A restrição do problema é tratada modificando levemente o Dijkstra, impedindo que cidades da rota expandam novos caminhos.

---

## ⏳ Complexidade

Considerando a implementação com matriz de adjacência:

* Construção de `route_cost`: **O(C)**
* Dijkstra: **O(N²)**
* Escolha da resposta: **O(C)**

Complexidade total:

* **Tempo:** `O(N²)`
* **Espaço:** `O(N²)` (matriz de adjacência)

---

## ▶️ Como Executar

### 📘 C99

```bash
gcc -std=c99 -O2 -o 1127 1127.c
./1127
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada                                                                                 | Saída |
| --------------------------------------------------------------------------------------- | ----- |
| `4 6 3 3`<br>`0 1 10`<br>`1 2 10`<br>`0 2 1`<br>`3 0 1`<br>`3 1 10`<br>`3 2 10`         | `10`  |
| `6 7 2 5`<br>`5 2 1`<br>`2 1 10`<br>`1 0 1`<br>`3 0 2`<br>`3 4 2`<br>`3 5 3`<br>`5 4 2` | `6`   |
| `5 5 2 4`<br>`0 1 1`<br>`1 2 2`<br>`2 3 3`<br>`3 4 4`<br>`4 0 5`                        | `6`   |
