# Linked Lists
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

<p>Este repositório contém exemplos e implementações de diferentes tipos de listas encadeadas em C. As listas encadeadas são uma estrutura de dados fundamental que permitem armazenar e manipular uma coleção de elementos de forma eficiente. Este projeto abrange listas encadeadas simples, duplamente encadeadas e circularmente encadeadas.</p>
<h2>Sumário</h2>
<ol>
  <li><a href="#desc">Descrição</li>
  <li><a href="#tipos">Tipos de Listas Encadeadas</li>
  <li><a href="#node">Estruturas de Nó</li>
  <li><a href="#inst">Instalação</li>
</ol>

<h2 id="desc">Descrição</h2>
<p>Uma lista encadeada é uma coleção de nós onde cada nó contém um valor e um ponteiro para o próximo nó na sequência. Este projeto inclui implementações básicas e avançadas de listas encadeadas, demonstrando como inserir, remover e buscar elementos.</p>

<h2 id="tipos">Tipos de Listas Encadeadas</h2>
<ul>
  <li>Lista Encadeada Simples: Cada nó aponta para o próximo nó na lista.</li>
  <li>Lista Duplamente Encadeada: Cada nó aponta para o próximo e para o nó anterior.</li>
  <li>Lista Circularmente Encadeada: O último nó aponta para o primeiro, formando um círculo.</li>
</ul>

<h2 id="node">Estruturas de Nó</h2>
<ol>
  <li>Lista Encadeada Simples</li>
  <p>Na lista encadeada simples, cada nó contém um valor e um ponteiro para o próximo nó. O último nó aponta para NULL.</p>

    typedef struct Node {
    int data;
    struct Node* next;
    } Node;

<li>Listas com Cabeça</li>
  <p>Na lista com cabeça, há uma estrutura adicional que armazena informações sobre a quantidade de elementos e ponteiros para o primeiro e o último nós.</p>
  
          typedef struct no
      {
          int chave;
          struct no *prox;
      } TNo;
      
      typedef struct cabeca
      {
          int qtde;
          TNo *prox, *ult;
      } TCabeca;

  <h3>Características:</h3>
<ul>
  <li>Inserção: Pode ser feita no início, meio ou fim da lista.</li>
  <li>Remoção: Mais eficiente que a lista encadeada simples, pois não precisa percorrer a lista para ajustar o nó anterior.</li>
  <li>Busca: Pode ser feita em ambas as direções.</li>
</ul>



</ol>
<h2 id="inst">Instalação</h2>
<ol>
  <l1>Clonar o Repositório</l1>
  
    git clone https://github.com/sthevenalves/linked-lists.git
  <li>Compilar e Executar</li>

    cd linked_list
    gcc main.c -o main
    ./main
</ol>


