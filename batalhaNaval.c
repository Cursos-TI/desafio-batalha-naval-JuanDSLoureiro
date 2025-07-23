#include <stdio.h>
#define linhasHab 3 //tamanho de linhas da habilidade
#define colunasHab 5 //tamanho de colunas da habilidade
#define TAMANHO_TAB 10 //tamanho do tabuleiro
int tabuleiro[TAMANHO_TAB][TAMANHO_TAB] = {0};  //inicia o tabuleiro {10x10} tudo com 0

struct navio
{
    int area[3];
    int colIni;
    int linIni;
};

struct habilidade
{
    int area[linhasHab][colunasHab];
    int coluna;
    int linha;
};

//função para desenhar os navios no tabuleiro
//orientacao(0 = horizontal,1 = vertical,2 = diagonal)
int desenhaNavio(struct navio navio,int orientacao){
    switch (orientacao)//seleciona em qual direção o navio deve ser desenhado
    {
    case 0: //horizontal
        for ( int i = 0; i < 3; i++)
        {
            int pos = navio.colIni+i;
            if (pos >= 0 && pos < TAMANHO_TAB && tabuleiro[navio.linIni][pos] == 0){
                tabuleiro[navio.linIni][pos] = navio.area[i];
            } else {
                printf("Falha posição navio (i: %d,pos: %d, tabuleiro: %d)\n",i,pos,tabuleiro[navio.linIni][pos]);
                return -1;
            }
        }
        return 0;
    break;
    case 1: //vertical
        for ( int i = 0; i < 3; i++)
        {
            int pos = navio.linIni+i;
            if (pos >= 0 && pos < TAMANHO_TAB && tabuleiro[pos][navio.colIni] == 0){
                tabuleiro[pos][navio.colIni] = navio.area[i];
            } else {
                printf("Falha posição navio (i: %d,pos: %d, tabuleiro: %d)\n",i,pos,tabuleiro[pos][navio.colIni]);
                return -1;
            }
        }
    break;
    case 2: //diagonal
        for ( int i = 0; i < 3; i++)
        {
            int coluna = navio.colIni+i;
            int linha = navio.linIni+i;
            if (coluna >= 0 && coluna < TAMANHO_TAB && linha >= 0 && linha < TAMANHO_TAB && tabuleiro[linha][coluna] == 0){
                tabuleiro[linha][coluna] = navio.area[i];
            } else {
                printf("Falha posição navio (i: %d,coluna: %d, linha: %d, tabuleiro: %d)\n",i,coluna,linha,tabuleiro[linha][coluna]);
                return -1;
            }
        }
    break;

    default:
        return -1;
        break;
    }
}

//função para desenhar uma habilidade
int desenhaHabilidade(struct habilidade habilidade){
    int linIni = habilidade.linha - 1;
    int colIni = habilidade.coluna -2;

    for ( int i = 0; i < linhasHab; i++)
    {
        for ( int j = 0; j < colunasHab; j++)
        {
            if(habilidade.area[i][j] != 0){
                int linha = linIni + i;
                int coluna = colIni + j;

                tabuleiro[linha][coluna] = habilidade.area[i][j];
            }
        }
    }
    return 0;
}
//função para desenhar o tabuleiro completo
void desenhaTabuleiro(){
    char linha [10] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("Tabuleiro da Batalha Naval \n    ");

    for ( int i = 0; i < TAMANHO_TAB; i++) //for para exibir o cabeçalho
    {
        printf("\033[4m %c\033[0m",linha[i]);
    }

    for ( int i = 0; i < TAMANHO_TAB; i++) //for para exibir o tabuleiro
    {
        i < (TAMANHO_TAB-1) ? printf("\n  %d|",i + 1):printf("\n %d|",i + 1); //caso i < 9 imprimir um espasso a mais na frente

        for ( int j = 0; j < TAMANHO_TAB; j++)
        {
            switch (tabuleiro[i][j])
            {
            case 5:
                printf("\033[1;32m %d\033[0m",tabuleiro[i][j]);
            break;

            case 3:
                printf("\033[1;34m %d\033[0m",tabuleiro[i][j]);
            break;
            
            default:
                printf(" %d",tabuleiro[i][j]);
            break;
            }
        }
    }
    printf ("\n");
}
//jogo batalha naval
int main (){
    
    //posiciona os navios
    //Inicialização de navios {area},colIni,linIni
    //navio 1
    struct navio navio1 = { {3, 3, 3}, 4, 3 };//horizontal
    if (desenhaNavio (navio1,0) == -1){
        printf("Falha posição navio 1\n");
        return -1;
    }

    //navio 2
    struct navio navio2 = { {3, 3, 3}, 1, 4 };//vertical
    if (desenhaNavio (navio2,1) == -1){
        printf("Falha posição navio 2\n");
        return -1;
    }
    //navio 3
    struct navio navio3 = { {3, 3, 3}, 6, 0 };//diagonal
    if (desenhaNavio (navio3,2) == -1){
        printf("Falha posição navio 3\n");
        return -1;
    }

    //navio 4
    struct navio navio4 = { {3, 3, 3}, 5, 7 };//diagonal
    if (desenhaNavio (navio4,2) == -1){
        printf("Falha posição navio 4\n");
        return -1;
    }

    // Inicialização das habilidades {area},coluna,linha
    //cone
    struct habilidade cone  = {
        {
            {0, 0, 5, 0, 0},
            {0, 5, 5, 5, 0},
            {5, 5, 5, 5, 5}
        },
        7,  // coluna
        5   // linha
    };
    desenhaHabilidade (cone);
    
    //cruz
    struct habilidade cruz = { 
        {
            {0,0,5,0,0},
            {5,5,5,5,5},
            {0,0,5,0,0}
        },
        2,  // coluna
        8   // linha
    };
    desenhaHabilidade (cruz);
    //octaedro
    struct habilidade octaedro = { 
        {
            {0,0,5,0,0},
            {0,5,5,5,0},
            {0,0,5,0,0}
        },
        2,  // coluna
        1   // linha 
    };
    desenhaHabilidade (octaedro);
    
    //exibe o tabuleiro
    desenhaTabuleiro();

    return 0;
}