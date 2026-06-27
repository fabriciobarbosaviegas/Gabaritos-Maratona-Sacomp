# ❤️ Tudo o que Você Precisa é Amor — Solução (Beecrowd 1307)

Este repositório contém soluções para o problema [Beecrowd 1307 - Tudo o que Você Precisa é Amor](https://www.beecrowd.com.br/judge/pt/problems/view/1307), proposto na **Maratona de Programação da SBC 2001**.

---

## 📜 Enunciado resumido

São dadas duas strings binárias válidas `S1` e `S2`.

Uma string binária `L` é considerada **amor** se ambas as strings puderem ser obtidas por sucessivas subtrações de `L` até restar exatamente `L`.

O objetivo é determinar se **existe ao menos uma string binária válida `L`** que satisfaça essa condição para as duas entradas.

Para cada caso de teste deve ser impressa uma das mensagens:

* `All you need is love!`
* `Love is not all you need!`

---

## 🧠 Lógica da Solução

### ✅ Ideia principal

Subtrair repetidamente um número até restar ele próprio é equivalente a dizer que o número inicial é um **múltiplo** dele.

Logo, queremos encontrar um valor `L` que seja divisor de ambos os números.

Em teoria:

```text
S1 % L = 0
S2 % L = 0
```

O maior número que divide ambos é o **Máximo Divisor Comum (MDC)**.

Assim:

* Se o `MDC > 1`, existe um valor válido para `L`.
* Se o `MDC = 1`, o único divisor comum é `1`, que corresponde à string binária `"1"`, considerada inválida pelo enunciado (strings de apenas um dígito não são permitidas).

Portanto, basta verificar:

```python
gcd(S1, S2) > 1
```

---

## 🔍 Etapas

1. Ler o número de casos de teste.
2. Para cada caso:

   * converter as strings binárias para inteiros;
   * calcular o MDC entre os dois valores;
   * verificar se o resultado é maior que `1`;
   * imprimir a mensagem correspondente.

A conversão é feita diretamente pela linguagem:

```python
S1 = int(input(), 2)
S2 = int(input(), 2)
```

O cálculo do MDC utiliza a função da biblioteca padrão:

```python
from math import gcd

gcd(S1, S2)
```

---

## 🎯 Explicação Visual

### Exemplo 1

Entrada:

```text
S1 = 11011
S2 = 11000
```

Convertendo para decimal:

```text
11011₂ = 27
11000₂ = 24
```

Calculando:

```text
MDC(27,24) = 3
```

Como:

```text
3 > 1
```

Existe uma string válida representando esse valor:

```text
3 = 11₂
```

Resposta:

```text
All you need is love!
```

---

### Exemplo 2

Entrada:

```text
S1 = 11011
S2 = 11001
```

Convertendo:

```text
27 e 25
```

Calculando:

```text
MDC(27,25) = 1
```

O único divisor comum é:

```text
1 = 1₂
```

Essa string possui apenas um caractere e, segundo o problema, **não é válida**.

Resposta:

```text
Love is not all you need!
```

---

## 📚 Algoritmo Utilizado

A solução utiliza o **Algoritmo de Euclides**, implementado pela função `gcd()` da biblioteca `math`.

Esse algoritmo encontra o MDC de dois números de forma extremamente eficiente.

---

## ⏳ Complexidade

Sejam `a` e `b` os números obtidos das strings.

* Conversão das strings: **O(L)**, onde `L ≤ 30`.
* Cálculo do MDC: **O(log(min(a,b)))**.

Complexidade total por caso:

* **Tempo:** `O(log N)`
* **Espaço:** `O(1)`

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 1307.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada               | Saída                       |
| --------------------- | --------------------------- |
| `11011`<br>`11000`    | `All you need is love!`     |
| `11011`<br>`11001`    | `Love is not all you need!` |
| `111111`<br>`100`     | `Love is not all you need!` |
| `1000000000`<br>`110` | `All you need is love!`     |
| `1010`<br>`100`       | `All you need is love!`     |
