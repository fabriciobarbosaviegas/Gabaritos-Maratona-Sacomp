# ☕ Máquina de Café — Solução (Beecrowd 2670)

Este repositório contém a solução para o problema [Beecrowd 2670 - Máquina de Café](https://www.beecrowd.com.br/judge/pt/problems/view/2670), proposto na **Maratona de Programação da SBC - ACM ICPC 2017**.

---

## 📜 Enunciado resumido

O prédio da SBC possui **3 andares**.

Em cada andar trabalham `A1`, `A2` e `A3` funcionários.

Uma máquina de café deve ser instalada em **um único andar**, e cada funcionário:

* vai até a máquina;
* toma café;
* retorna ao seu andar.

Cada deslocamento entre dois andares leva **1 minuto**.

O objetivo é encontrar o andar onde a máquina deve ser instalada para **minimizar o tempo total gasto por todos os funcionários**.

---

## 🧠 Lógica da Solução

### ✅ Observação principal

Existem apenas **três possibilidades** para instalar a máquina:

* Andar 1
* Andar 2
* Andar 3

Como são apenas três casos, basta calcular o tempo total para cada um e escolher o menor.

Além disso, cada funcionário precisa fazer o trajeto de **ida e volta**, logo:

* subir ou descer **1 andar** custa **2 minutos**;
* subir ou descer **2 andares** custa **4 minutos**.

---

## 🔍 Calculando cada possibilidade

### Máquina no 1º andar

Os funcionários do:

* 1º andar não se deslocam;
* 2º andar percorrem 1 andar (ida e volta = 2 minutos);
* 3º andar percorrem 2 andares (ida e volta = 4 minutos).

Tempo total:

```text
0 × A1 + 2 × A2 + 4 × A3
```

---

### Máquina no 2º andar

Agora:

* 1º andar percorre 1 andar;
* 2º andar permanece no mesmo local;
* 3º andar percorre 1 andar.

Tempo:

```text
2 × A1 + 0 × A2 + 2 × A3
```

---

### Máquina no 3º andar

Agora:

* 1º andar percorre 2 andares;
* 2º andar percorre 1 andar;
* 3º andar permanece no mesmo local.

Tempo:

```text
4 × A1 + 2 × A2 + 0 × A3
```

---

## 🎯 Explicação Visual

Considere:

```text
Andar 3 → 30 funcionários
Andar 2 → 20 funcionários
Andar 1 → 10 funcionários
```

### Máquina no 1º andar

```text
3º: ↓↓ ↑↑ = 4 min × 30 = 120

2º: ↓ ↑ = 2 min × 20 = 40

1º: 0 min × 10 = 0

Total = 160
```

---

### Máquina no 2º andar

```text
3º: ↓ ↑ = 2 min × 30 = 60

2º: 0 min × 20 = 0

1º: ↑ ↓ = 2 min × 10 = 20

Total = 80
```

---

### Máquina no 3º andar

```text
3º: 0 min × 30 = 0

2º: ↑ ↓ = 2 min × 20 = 40

1º: ↑↑ ↓↓ = 4 min × 10 = 40

Total = 80
```

Resposta:

```text
min(160, 80, 80) = 80
```

---

## 📊 Fluxo da solução

```text
          Ler A1, A2 e A3
                 │
      ┌──────────┼──────────┐
      ▼          ▼          ▼
 Máquina      Máquina    Máquina
 no 1º        no 2º      no 3º
      │          │          │
 Calcula      Calcula    Calcula
 tempo1       tempo2     tempo3
      └──────────┼──────────┘
                 ▼
        Escolhe o menor valor
                 │
                 ▼
            Imprime resposta
```
---

## ⏳ Complexidade

Como apenas três expressões são avaliadas:

* **Tempo:** `O(1)`
* **Espaço:** `O(1)`

---

## ▶️ Como Executar

### 🐍 Python

```bash
python3 2670.py
```

---

## 💡 Exemplos de Entrada e Saída

| Entrada              | Saída |
| -------------------- | ----- |
| `10`<br>`20`<br>`30` | `80`  |
| `10`<br>`30`<br>`20` | `60`  |
| `30`<br>`10`<br>`20` | `100` |
