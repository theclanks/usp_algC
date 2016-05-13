#include <stdlib.h>
#include <stdio.h>

int main()
{

    int t = 4; // tamanho 4x4
    //int cidades[][4] = { {1,1,1,0}, {0,1,1,0}, {1,0,1,1}, {0,0,1,1} }; // original
    //int cidades[][4] = { {1,0,1,0}, {0,1,1,0}, {1,0,1,1}, {0,0,1,1} };  // caso nao chegam (entrada)
    //int cidades[][4] = { {1,1,1,0}, {0,1,0,0}, {1,0,1,1}, {0,0,1,1} };  // caso nao saem (saida)
    int cidades[][4] = { {1,0,1,0}, {0,1,0,0}, {1,0,1,1}, {0,0,1,1} };  // caso nao chegam e nao saem (isolada)
    int i, j, k, chegam, saem;
    int maior, cmaior, ok;

    printf("Matriz cidades \n");
    // Impressao matriz cidades
    for (i=0;i<t;i++)
    {
        for (j=0;j<t;j++) {
            printf("%d", cidades[i][j]);
        }
        printf("\n");
    }

    // Caso a
    // Dado k, determinar quantas estradas saem e quantas chegam a cidade k.
    chegam = 0;
    saem = 0;
    printf("\n\na) Informe a cidade : ");
    scanf("%d", &k);
    // quantas saem (fixar linha)
    for (j=0;j<t;j++) {
        if (cidades[k][j] == 1 && k != j){
            saem++;
        }
    }
    // quantas chegam (fixar colunas)
    for (i=0;i<t;i++) {
        if (cidades[i][k] == 1 && k != i){
            chegam++;
        }
    }
    printf("Na cidade %d \n", k);
    printf("Saem: %d \n", saem);

    printf("Chegam: %d \n", chegam);

    // Caso b
    // Qual das cidades chega o maior numero de estradas?
    printf("\n\nCaso b\n");
    chegam = 0;
    maior = 0;
    for (i=0;i<t;i++)
    {
        chegam = 0;
        // Neste caso temos que analisar por colunas
        for (j=0;j<t;j++) {
            if (cidades[j][i] == 1 && j != i) {
                chegam++;
            }
        }
        if (chegam > maior) {
            cmaior = i;
            maior = chegam;
        }
    }
    printf("b) A cidade que possui mais entradas eh %d \n", cmaior);

    // Caso c
    // Dado k, verificar se todas as ligacoes diretas entre a 
    // cidade k e outras sao de mao dupla.
    printf("\n\nCaso c \n");
    printf("c) Informe a cidade : ");
    scanf("%d", &k);

    ok = 0;
    for (i=0;i<t;i++)
    {
        // Neste caso temos que analisar por colunas e linhas
        for (j=0;j<t;j++) {
            if ( cidades[k][i] == 1 && cidades[j][k] == 1
                && k != i
                && k != j
                && i == j)
            {
                printf("Sim a cidade %d possui mao dupla com %d \n", k, i);
                ok = 1;
            }
        }

    }
    if (ok == 0) {
        printf("A cidade %d nao possui mao dupla \n",k);
    }


    //////////////////////////////////////////////////////////////////////////////
    // Caso d relacionar, se existirem:
    // 1 As cidades isoladas, isto eh, as que nao tem ligacao com nenhuma outra;
    // ///////////////////////////////////////////////////////////////////////////
    printf("\n\nCaso d) I\n");
    for (i=0; i<t; i++) {
        ok = 0;
        for (j=0;j<t;j++)
        {
                if ( cidades[i][j] == 0
                    && cidades[j][i] == 0
                    && j != i)
                {
                    //printf("A cidade nao %d possui saida com nenhuma \n", j);
                    ok++;
                }

        }
        if (ok == t-1) {
            printf("A cidade %d esta isolada \n",i);
        }
    }
    /////////////////////////////////////////////////////////////////////
    // 2 As cidades das quais nao ha saida, apesar de haver entradas;
    // //////////////////////////////////////////////////////////////////
    printf("\n\nCaso d II\n");
    for (i=0; i<t; i++) {
        ok = 0;
        for (j=0;j<t;j++)
        {
                if ( cidades[i][j] == 1 && j != i)
                {
                    ok++;
                }
        }
        if (ok == 0) {
            printf("A cidade %d nao possui saida \n",i);
        }
    }

    ////////////////////////////////////////////////////////////////////
    // 3 As cidades das quais ha saida sem haver entrada;
    ////////////////////////////////////////////////////////////////////
    printf("\n\nCaso d III\n");
    for (i=0; i<t; i++) {
        ok = 0;
        for (j=0;j<t;j++)
        {
                if ( cidades[j][i] == 1 && j != i)
                {
                    ok++;
                }
        }
        if (ok == 0) {
            printf("A cidade %d nao possui entrada \n",i);
        }
    }


    return(0);

}
