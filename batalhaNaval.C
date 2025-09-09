#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

void aplicarHabilidade (int tabuleiro[LINHAS][COLUNAS], int habilidade[3][5], int origemLinha, int origemColuna)
{
    int centroLinha = 1;
    int centroColuna = 2;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (habilidade[i][j] == 1)
            {
                int linha = origemLinha + (i - centroLinha);
                int coluna = origemColuna + (j - centroColuna);

                if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS)
                {
                    if (tabuleiro[linha][coluna] == 0)
                        tabuleiro[linha][coluna] = 5;
                }
            }
        }    
    }    
}

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
        char colunas [10] = {'A','B','C','D','E','F','G','H','I','J'};

        printf("   ");
       for (int j = 0; j < COLUNAS; j++)
    {
        printf("%c ", colunas[j]);
    }
        printf("\n");

    for (int i = 0; i < LINHAS; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++)
        {
            if (tabuleiro[i][j] == 0) printf("0 ");
            else if (tabuleiro[i][j] == 3) printf("3 ");
            else if (tabuleiro[i][j] == 5) printf("5 ");
        }
        printf("\n");
    }
    
}

int main ()
{
    char linha [10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro [LINHAS][COLUNAS] = {0};
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    int cruz[3][5];
    int cone[3][5];
    int octaedro[3][5];

    printf("#JOGO DE BATALHA NAVAL#\n\n");

      for (int i = 0; i < 3; i++)
    {
        tabuleiro[0][2 + i] = navio1[i];
    }

      for (int i = 0; i < 3; i++)
    {
        tabuleiro[5 + i][0] = navio2[i];
    }

      for (int i = 0; i < 3; i++)
    {
        tabuleiro[1 + i][0 + i] = navio3[i];
    }

       for (int i = 0; i < 3; i++)
    {
        tabuleiro[7 + i][2 - i] = navio4[i];
    }

        printf("   ");
       for (int j = 0; j < COLUNAS; j++)
    {
        printf("%c ", linha[j]);
    }
        printf("\n");
    
    for (int i = 0; i < LINHAS; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%d ", tabuleiro[i][j]);   
        }
            printf("\n");
    }

    printf("\n");
    printf("# CRUZ #\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 1 || j == 2){
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <  5; j++)
        {
            printf("%d  ", cruz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("# CONE #\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j >= 2 - i && j <= 2  + i){
                cone[i][j] = 1;
            } else {
                cone [i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <  5; j++)
        {
            printf("%d  ", cone[i][j]);
        }
        printf("\n");
    }
    
    printf(" \n");
    printf("# OCTAEDRO #\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 2){
                if (j == 2){
                octaedro[i][j] = 1;
                } else {
                octaedro[i][j] = 0;
                }
            }
            else {
                if (j >= 1 && j <= 3){
                    octaedro[i][j] = 1;
                } else {
                    octaedro[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <  5; j++)
        {
            printf("%d  ", octaedro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("#TABULEIRO COMPLETO#\n");
    aplicarHabilidade(tabuleiro, cruz, 1, 7);
    aplicarHabilidade(tabuleiro, cone, 8, 7);
    aplicarHabilidade(tabuleiro, octaedro, 5, 6);
    
    exibirTabuleiro(tabuleiro);
    

    return 0;
}