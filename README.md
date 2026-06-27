# 🏆 Gabaritos – Maratona SACOMP de Programação

Repositório contendo os **gabaritos oficiais** da **1ª Maratona SACOMP de Programação**, realizada em **26 de junho de 2026**, além dos materiais utilizados nos simulados de preparação para as disciplinas de **Algoritmos e Estruturas de Dados I e II**.

Cada problema possui sua implementação (em **Python** ou **C99**) acompanhada de um **README explicativo**, contendo:

* 📜 Resumo do enunciado;
* 🧠 Explicação detalhada da lógica utilizada;
* 🎯 Ilustrações e exemplos visuais;
* 📊 Análise de complexidade;
* ▶️ Instruções de compilação e execução;
* 💡 Exemplos de entrada e saída.

## Consulte também:
(Curso de programação competitiva SACOMP 2025)[https://github.com/fabriciobarbosaviegas/Curso-de-programa-o-competitiva-SACOMP-2025]

---

## 📂 Organização do Repositório

```text
.
├── LICENSE
├── README.md
├── prova/
│   ├── 1307/
│   ├── 1414/
│   ├── 1933/
│   ├── 2666/
│   ├── 2670/
│   ├── 2880/
│   ├── 2972/
│   └── 2973/
├── simulado AED I/
│   ├── 1414/
│   ├── 1523/
│   ├── 2235/
│   ├── 3416/
│   └── 3428/
└── simulado AED II/
    ├── 1127/
    ├── 1414/
    ├── 1437/
    └── 2234/
```

---

## 📁 Estrutura dos Problemas

Cada diretório corresponde a um problema do **Beecrowd** e contém:

```text
<id do problema>/
├── <id>.py        # Solução em Python
├── <id>.c         # Solução em C (quando disponível)
└── README.md      # Explicação detalhada da solução
```

Alguns problemas possuem múltiplas implementações para ilustrar abordagens diferentes (por exemplo, utilizando e não utilizando operações **bitwise**).

---

## 📚 Conteúdo

### 🏁 Prova

| Problema | Linguagem                   |
| -------- | --------------------------- |
| 1307     | Python                      |
| 1414     | Python                      |
| 1933     | Python                      |
| 2666     | C99                         |
| 2670     | Python                      |
| 2880     | Python                      |
| 2972     | Python + C99 (duas versões) |
| 2973     | README                      |

### 📘 Simulado AED I

| Problema | Linguagem |
| -------- | --------- |
| 1414     | Python    |
| 1523     | Python    |
| 2235     | Python    |
| 3416     | Python    |
| 3428     | README    |

### 📗 Simulado AED II

| Problema | Linguagem |
| -------- | --------- |
| 1127     | C99       |
| 1414     | Python    |
| 1437     | Python    |
| 2234     | README    |

---

## 🎯 Objetivo

Este repositório foi desenvolvido para servir como material de apoio aos participantes da Maratona SACOMP e aos estudantes que desejam aprender técnicas de programação competitiva.

As soluções procuram não apenas resolver os problemas, mas também explicar o raciocínio utilizado, apresentando conceitos importantes como:

* Programação Dinâmica;
* Algoritmos Gulosos;
* Pilhas;
* Busca em Grafos;
* Árvores;
* Matemática Discreta;
* Manipulação de Bits (Bitwise);
* Janelas Deslizantes;
* Teoria dos Números.

---

## ⚙️ Compilação

### Python

```bash
python3 arquivo.py
```

### C99

```bash
gcc -std=c99 arquivo.c -o programa
./programa
```

---

## 📖 Licença

Este projeto está disponível sob a licença presente no arquivo **LICENSE**.
