#include <stdio.h>

struct navio
{
    int area[3];
    int colIni;
    int linIni;
};


//jogo batalha naval
int main (){
    int i,j;

    char linha [10] = {'A','B','C','D','E','F','G','H','I','J'};
    //inicia o tabuleiro {10x10}
    int tabuleiro[10][10] = {0};  // inicializa tudo com 0

    // Inicialização de navios {area},colIni,linIni
    struct navio navio1 = { {3, 3, 3}, 3, 2 };//horizontal
    struct navio navio2 = { {3, 3, 3}, 3, 4 };//vertical
    struct navio navio3 = { {3, 3, 3}, 6, 0 };//diagonal
    struct navio navio4 = { {3, 3, 3}, 5, 7 };//diagonal


    //posiciona os navios
    //navio 1
    for ( i = 0; i < 3; i++)
    {
        int pos = navio1.colIni+i;
        if (pos >= 0 && pos < 10 && tabuleiro[navio1.linIni][pos] == 0){
            tabuleiro[navio1.linIni][pos] = navio1.area[i];
        } else {
            printf("Falha posição navio 1 (i: %d,pos: %d, tabuleiro: %d)",i,pos,tabuleiro[navio1.linIni][pos]);
            return -1;
        }
    }

    //navio 2
    for ( i = 0; i < 3; i++)
    {
        int pos = navio2.linIni+i;
        if (pos >= 0 && pos < 10 && tabuleiro[pos][navio2.colIni] == 0){
            tabuleiro[pos][navio2.colIni] = navio2.area[i];
        } else {
            printf("Falha posição navio 2 (i: %d,pos: %d, tabuleiro: %d)",i,pos,tabuleiro[pos][navio2.colIni]);
            return -1;
        }
        
    }

    //navio 3
    for ( i = 0; i < 3; i++)
    {
        int coluna = navio3.colIni+i;
        int linha = navio3.linIni+i;
        if (coluna >= 0 && coluna < 10 && linha >= 0 && linha < 10 && tabuleiro[linha][coluna] == 0){
            tabuleiro[linha][coluna] = navio3.area[i];
        } else {
            printf("Falha posição navio 3 (i: %d,coluna: %d, linha: %d, tabuleiro: %d)",i,coluna,linha,tabuleiro[linha][coluna]);
            return -1;
        }
    }

    //navio 4
    for ( i = 0; i < 3; i++)
    {
        int coluna = navio4.colIni+i;
        int linha = navio4.linIni+i;
        if (coluna >= 0 && coluna < 10 && linha >= 0 && linha < 10 && tabuleiro[linha][coluna] == 0){
            tabuleiro[linha][coluna] = navio4.area[i];
        } else {
            printf("Falha posição navio 4 (i: %d,coluna: %d, linha: %d, tabuleiro: %d)",i,coluna,linha,tabuleiro[linha][coluna]);
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

    
    for ( i = 0; i < 10; i++) //for para exibir o tabuleiro
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