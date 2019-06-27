#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int buscaLargura(int vertice, int *caminho, int **grafo, int **fluxo){
    int A_origem = vertice+1; //determino que a A-origem e B-destino s�o o penultimo e ultimo elementos
    int B_destino = vertice+2;
    fila *f = criaFila(); //uso a fun��o de criar fila que me retorna uma fila do tipo fila.

    int *visitado; // 0 � n�o-visitado, 1 � visitado, por�m n�o todos os vizinhos, 2 � visitado todos os vizinhos.
    visitado = (int*)calloc((vertice+2), sizeof(int)); //aloco espa�o para o vetor visitado (que guarda vertices visitados)

    int i,j;

    for (i = 0; i < vertice+2; i++){
        visitado[i] = 0; // colocando todos como n�o-visitados, ou seja, 0.
    }

    enfileirar(A_origem-1, f, visitado); //enfileiro o v�rtice origem na fila, no caso a A-origem,e ele torna visitado (1) no vetor visitado.
    caminho[A_origem-1] = -1;

    while (f->primeiro != NULL){ //enquanto ainda existir elemento na fila, ainda tem lugar pra visitar

        i = desenfileirar(f, visitado); //desenfileira e ainda torna o visitado (2), ou seja, n�o h� mais v�rtices a serem analisados.

        for (j = 0; j < vertice+2; j++){

            if (visitado[j] == 0 && (grafo[i][j] - fluxo[i][j] > 0)){ //enquanto o vertice ainda n�o for visitado e se existe um caminho ali, ou seja, a conta > 0

                enfileirar(j, f, visitado); //enfileira ele para analis�-lo.
                caminho[j] = i; //cheguei no j a partir de i
            }
        }

    }

    int check = visitado[B_destino-1]; //recebe o valor visitado, variando de 0,1 e 2.

    free(visitado);
    free(f);

    return (check == 2); //retorna 2 se achar um caminho at� B-destino, ou seja, chegou no B-destino.
}

