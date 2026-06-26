# ☕ Eu Quero Cafééé — Solução (Beecrowd 3416)

Este repositório contém soluções para o problema [Beecrowd 3416 - Eu Quero Cafééé](https://www.beecrowd.com.br/judge/pt/problems/view/3416).

---

## 📜 Enunciado resumido

O Professor Zak Galou prometeu servir café durante todas as aulas de Programação Competitiva.

Sabendo que:

* existem `N` estudantes;
* cada estudante consome `D` mililitros de café;
* o café só pode ser preparado em **lotes de `L` litros**;

determine a **menor quantidade de litros** que deve ser preparada para que nenhum estudante fique sem café.

Caso sobre café, não há problema.

---

## 🧠 Lógica da Solução

### ✅ Objetivo

Calcular a menor quantidade de café (em litros) que seja suficiente para atender todos os estudantes e que seja um **múltiplo de `L` litros**, já que cada preparo produz exatamente `L` litros.

### 🔍 Etapas

1. Ler `N`, `L` e `D`.
2. Calcular o consumo total em mililitros:

```text
consumo = N × D
```

3. Converter o consumo para litros:

```text
consumo_litros = consumo / 1000
```

4. Se `consumo_litros ≤ L`, basta preparar um único lote (`L` litros).

5. Caso contrário:

   * calcular quantos lotes são necessários;
   * arredondar para cima utilizando `ceil`;
   * multiplicar pela capacidade de cada lote (`L`).

---

## 🎯 Explicação Visual

### Exemplo 1

Entrada:

```
15 3 200
```

Cada estudante bebe:

```
200 mL
```

Consumo total:

```
15 × 200 = 3000 mL = 3 L
```

Como um preparo produz exatamente **3 litros**:

Resposta:

```
3 litros
```

---

### Exemplo 2

Entrada:

```
15 3 250
```

Consumo total:

```
15 × 250 = 3750 mL
          = 3,75 L
```

Um preparo produz apenas:

```
3 L
```

Não é suficiente.

São necessários dois preparos:

```
3 L + 3 L = 6 L
```

Visualmente:

```
Necessário: 3,75 L

Preparado:
Total = 6 L
```

Resposta:

```
6 litros
```

---

## ⏳ Complexidade

Como realizamos apenas algumas operações aritméticas:

* **Tempo:** `O(1)`
* **Espaço:** `O(1)`

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 3416.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada    | Saída |
| ---------- | ----- |
| `15 3 200` | `3`   |
| `15 3 250` | `6`   |
