# 🚗 Estacionamento Linear — Solução (Beecrowd 1523)

Este repositório contém soluções para o problema [Beecrowd 1523 - Estacionamento Linear](https://www.beecrowd.com.br/judge/pt/problems/view/1523), proposto por **Cristhian Bonilha (UTFPR)**.

---

## 📜 Enunciado resumido

Um estacionamento possui apenas **um corredor**, onde os carros ficam estacionados em fila.

As regras são:

* Os carros entram pelo único portão disponível.
* O primeiro carro estaciona no fundo.
* Os demais estacionam atrás dele.
* **Somente o último carro da fila pode sair.**
* O estacionamento comporta no máximo `K` carros simultaneamente.

Dado o horário de chegada e saída de `N` motoristas, determine se é possível que todos utilizem o estacionamento respeitando essas regras.

---

## 🧠 Lógica da Solução

### ✅ Objetivo

Simular a entrada e saída dos carros e verificar se a ordem das operações é compatível com um estacionamento linear.

A estrutura ideal para representar esse comportamento é uma **pilha (Stack)**, pois:

* quem entra por último é o primeiro que pode sair (**LIFO – Last In, First Out**).

---

### 🔍 Etapas

1. Ler `N` e `K`.
2. Para cada motorista:

   * criar um evento de **chegada**;
   * criar um evento de **saída**.
3. Ordenar todos os eventos por horário.

   * Em caso de empate, as **saídas acontecem antes das chegadas**, permitindo que um carro saia exatamente quando outro chega.
4. Percorrer os eventos:

   * **Chegada**

     * se a pilha já possui `K` carros → impossível;
     * caso contrário, empilha o carro.
   * **Saída**

     * o carro deve estar obrigatoriamente no topo da pilha;
     * caso contrário, algum carro estaria bloqueando sua saída → impossível.
5. Caso todos os eventos sejam processados corretamente, imprimir `"Sim"`.

---

## 🎯 Explicação Visual

Considere o primeiro exemplo:

```
K = 2

Carro 0: chega 1, sai 10
Carro 1: chega 2, sai 5
Carro 2: chega 6, sai 9
```

Após ordenar os eventos:

| Horário | Evento        |
| ------- | ------------- |
| 1       | Chega carro 0 |
| 2       | Chega carro 1 |
| 5       | Sai carro 1   |
| 6       | Chega carro 2 |
| 9       | Sai carro 2   |
| 10      | Sai carro 0   |

### Simulação

```
Início

Pilha:
[]
```

Chega carro 0

```
[0]
```

Chega carro 1

```
[0, 1]
```

Sai carro 1

```
[0]
```

Chega carro 2

```
[0, 2]
```

Sai carro 2

```
[0]
```

Sai carro 0

```
[]
```

Todos conseguiram entrar e sair corretamente.

✅ Resposta:

```
Sim
```

---

### Exemplo em que falha

```
K = 2

Carro 0: chega 1, sai 10
Carro 1: chega 2, sai 5
Carro 2: chega 6, sai 12
```

Eventos:

```
1  -> chega 0
2  -> chega 1

Pilha:
[0,1]
```

Sai carro 1

```
[0]
```

Chega carro 2

```
[0,2]
```

Agora ocorre:

```
10 -> carro 0 quer sair
```

Mas o topo da pilha é:

```
[0,2]
    ↑
```

O carro 2 bloqueia a saída do carro 0.

Logo:

```
Nao
```

---

## ⏳ Complexidade

* Ordenação dos eventos: **O(N log N)**
* Simulação da pilha: **O(N)**

Complexidade total:

* **Tempo:** `O(N log N)`
* **Espaço:** `O(N)`

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 1523.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada                            | Saída              |
| ---------------------------------- | ------------------ |
| `3 2`<br>`1 10`<br>`2 5`<br>`6 9`  | `Sim`              |
| `3 2`<br>`1 10`<br>`2 5`<br>`6 12` | `Nao`              |
| `0 0`                              | *(fim da entrada)* |
