
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

#include <stdio.h>

//jogo batalha naval
int main (){
    int i,j;

    char linha [10] = {'A','B','C','D','E','F','G','H','I','J'};
    //inicia o tabuleiro {10x10}
    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    //declara navios
    int navio1[3] = {3,3,3};
    int navio2[3] = {3,3,3};
    int linhanavio1 = 3;
    int colnavio2 = 5;
    //posiciona os navios
    //navio 1
    for ( i = 0; i < 3; i++)
    {
        int pos = linhanavio1+i;
        if (pos >= 0 && pos < 10 && tabuleiro[linhanavio1][pos] == 0){
            tabuleiro[linhanavio1][pos] = navio1[i];
        } else {
            printf("Falha posição navio 1 (i: %d,pos: %d, tabuleiro: %d)",i,pos,tabuleiro[linhanavio1][pos]);
            return -1;
        }

    }
    //navio 2
    for ( i = 0; i < 3; i++)
    {
        int pos = colnavio2+i;
        if (pos >= 0 && pos < 10 && tabuleiro[pos][colnavio2] == 0){
            tabuleiro[pos][colnavio2] = navio2[i];
        } else {
            printf("Falha posição navio 2 (i: %d,pos: %d, tabuleiro: %d)",i,pos,tabuleiro[pos][colnavio2]);
            return -1;
        }
        
    }

    //exibe o tabuleiro
    printf("Tabuleiro da Batalha Naval \n    ");

    for ( i = 0; i < 10; i++) //for para exibir o cabeçalho
    {

        printf(" %c",linha[i]);
    }

    printf("\n     _ _ _ _ _ _ _ _ _ _");

    
    for ( i = 0; i < 10; i++)
    {
        i < 9 ? printf("\n  %d|",i + 1):printf("\n %d|",i + 1); //caso i < 9 imprimir um espasso a mais na frente

        
        for ( j = 0; j < 10; j++)
        {
            printf(" %d",tabuleiro[i][j]);
        }
        
    }
    printf ("\n");

    return 0;
}