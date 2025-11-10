#include <stdio.h>
#include <stdlib.h> // para abs()

int main() {
    int i, j;
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coloca alguns navios (valor 3)
    tabuleiro[2][3] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[7][8] = 3;

    // Matrizes das habilidades (5x5)
    int cone[5][5];
    int cruz[5][5];
    int octa[5][5];

    // ======== CONE ========
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // ======== CRUZ ========
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // ======== OCTAEDRO ========
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int centro = 2;
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }

    // ======== APLICA AS HABILIDADES NO TABULEIRO ========
    // centro das habilidades no tabuleiro
    int origemConeL = 1, origemConeC = 1;
    int origemCruzL = 5, origemCruzC = 5;
    int origemOctaL = 8, origemOctaC = 3;

    int linha, coluna;

    // Cone
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            linha = origemConeL - 2 + i;
            coluna = origemConeC - 2 + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (cone[i][j] == 1) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Cruz
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            linha = origemCruzL - 2 + i;
            coluna = origemCruzC - 2 + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (cruz[i][j] == 1) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Octaedro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            linha = origemOctaL - 2 + i;
            coluna = origemOctaC - 2 + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (octa[i][j] == 1) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // ======== EXIBE O TABULEIRO FINAL ========
    printf("\n=== TABULEIRO COM AS HABILIDADES ===\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~ "); // água
            else if (tabuleiro[i][j] == 3)
                printf(" N "); // navio
            else if (tabuleiro[i][j] == 5)
                printf(" * "); // área da habilidade
        }
        printf("\n");
    }

    return 0;
}
