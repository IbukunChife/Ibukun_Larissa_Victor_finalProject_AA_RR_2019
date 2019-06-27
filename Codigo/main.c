#include "Ford-Fulkerson.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int vertice, aresta, tarefa, funcionario; //declaração dos itens a serem lidos na primeira linha.
    printf("\n\t\t-----------------GRAFO BIPARTIDO-----------------\n\n");
    printf("Entre Com a Quantidade De Vertice, De Aresta, De Tarefas, De Funcionario \n");
    scanf("%d %d %d %d", &vertice, &aresta, &tarefa, &funcionario);

    int **grafo; //criação do grafo em memória dinâmica.
    grafo = (int**)calloc(vertice+2, sizeof(int*));

    int i = 0;

    for (i = 0; i < vertice+2; i++){
        grafo[i] = (int*)calloc(vertice+2, sizeof(int)); //alocação de uma coluna completa para o grafo. sendo assim, no final, teremos também as linhas alocadas.
//o tamanho é vértive+2 e a criação da A-origem e B-destino no grafo, que serão os dois ultimos elementos.
    }

    for (i = 0; i < aresta; i++){
        int num1, num2, peso;
        printf("Entre com a Vertice De Origem, Vertice de Destino e o Fluxo Maximo da Aresta: ");
        scanf ("%d %d %d", &num1, &num2, &peso); //leitura e atribuição de valores diretamente no grafo.
        grafo[num1][num2] = peso;
    }

    for (i = 0; i < tarefa; i++){
        int indice_vertice;
        printf("Identifique Uma Vertice Que Sera a Tarefas: ");
        scanf("%d", &indice_vertice); //identificando um vertice que será uma tarefa

        grafo[vertice][indice_vertice] = 99999999; //ligando a A-origem a ela
    }

    for (i = 0; i < funcionario; i++){
        int indice_aresta;
        printf("Identifique Uma Vertice Que Sera o Funcionarios: ");
        scanf("%d", &indice_aresta); //identificando um vertice que será um funcionario

        grafo[indice_aresta][vertice+1] = 99999999; //ligando ele ao B-destino
    }
     printf("\n---Resultados---\n\n");

    int resposta;

    resposta = fordFulkerson(vertice, grafo); //chamada do algoritmo de ford fulkerson.
    printf("-Ford Fulkerson: %d\n", resposta);




    for (i = 0; i < vertice+2; i++){
        free(grafo[i]);
    }
    free(grafo);

    return 0;
}
