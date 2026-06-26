# 🏆 Copa do Mundo — Solução (Beecrowd 1414)

Este repositório contém soluções para o problema [Beecrowd 1414 - Copa do Mundo](https://www.beecrowd.com.br/judge/pt/problems/view/1414), proposto na **Maratona de Programação da SBC 2006**.

---

## 📜 Enunciado resumido

Em uma Copa do Mundo de futebol de botões, cada partida distribui pontos da seguinte forma:

* ✅ Vitória: vencedor recebe **3 pontos**.
* 🤝 Empate: cada time recebe **1 ponto**.
* ❌ Derrota: perdedor recebe **0 pontos**.

Dado o número de partidas já disputadas e a pontuação atual de cada equipe, determine **quantos jogos terminaram empatados**.

---

## 🧠 Lógica da Solução

### ✅ Objetivo

Descobrir quantas partidas terminaram empatadas utilizando apenas:

* o número total de partidas `N`;
* a soma dos pontos de todas as equipes.

### 🔍 Observação importante

Cada partida distribui uma quantidade fixa de pontos:

* **Vitória:** distribui **3 pontos** no total.
* **Empate:** distribui apenas **2 pontos** (1 para cada equipe).

Logo, **cada empate "faz desaparecer" exatamente 1 ponto** em relação ao caso de uma vitória.

Se todas as partidas tivessem vencedor, seriam distribuídos:

```
3 × N pontos
```

Entretanto, a soma real dos pontos das equipes é:

```
S = soma de todos os pontos
```

Assim, o número de empates é simplesmente:

```
empates = 3 × N − S
```

---

## 🎯 Explicação Visual

Considere o seguinte campeonato:

| Partida | Resultado | Pontos distribuídos |
| ------- | --------- | ------------------- |
| A × B   | A vence   | 3                   |
| C × D   | Empate    | 2                   |
| E × F   | Empate    | 2                   |

Temos:

```
N = 3 partidas
```

Se todas fossem vitórias:

```
3 × N = 9 pontos
```

Mas foram distribuídos apenas:

```
3 + 2 + 2 = 7 pontos
```

Logo:

```
Empates = 9 − 7 = 2
```

Exatamente duas partidas terminaram empatadas.

---

## ⏳ Complexidade

Como basta somar os pontos das equipes:

* **Tempo:** `O(T)`
* **Espaço:** `O(1)`

Onde `T` é o número de times.

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 1414.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada                                             | Saída              |
| --------------------------------------------------- | ------------------ |
| `3 3`<br>`Brasil 3`<br>`Australia 3`<br>`Croacia 3` | `0`                |
| `3 3`<br>`Brasil 5`<br>`Japao 1`<br>`Australia 1`   | `2`                |
| `0 0`                                               | *(fim da entrada)* |
