#include <stdio.h>

// Função recursiva para a Torre (movimento vertical)
void moverTorre(int casas, int direcao) {
    if (casas == 0) {
        return; // Caso base: terminou o movimento
    }
    
    if (direcao == 1) {
        printf("Cima\n");
    } else {
        printf("Baixo\n");
    }

    moverTorre(casas - 1, direcao); // chamada recursiva
}

// Função recursiva para o Bispo (diagonal)
// Utiliza também loops aninhados para o movimento horizontal e vertical
void moverBispo(int vertical, int horizontal) {
    if (vertical == 0) {
        return; // Caso base
    }

    // Loop externo: controla o movimento vertical
    for (int i = 0; i < vertical; i++) {
        // Loop interno: controla o movimento horizontal
        for (int j = 0; j < horizontal; j++) {
            printf("Diagonal (Cima e Direita)\n");
        }
    }

    moverBispo(vertical - 1, horizontal); // chamada recursiva
}

// Função recursiva para a Rainha
// A Rainha combina movimentos de Torre e Bispo
void moverRainha(int casas) {
    if (casas == 0) {
        return; // Caso base
    }

    printf("Cima\n");
    printf("Direita\n");
    printf("Diagonal (Cima e Direita)\n");

    moverRainha(casas - 1); // chamada recursiva
}

// Movimento complexo do Cavalo (duas para cima e uma para a direita)
// Utiliza loops aninhados e controle com break e continue
void moverCavalo(int movimentos) {
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < 3; j++) {

            // Condição para pular certos passos
            if (j == 1) {
                continue; // pula uma repetição
            }

            // Duas casas para cima
            if (j < 2) {
                printf("Cima\n");
            }

            // Uma casa para a direita no final
            if (j == 2) {
                printf("Direita\n");
                break; // sai do loop interno
            }
        }
    }
}

int main() {
    // Quantidade de casas definidas no código
    int casasTorre = 3;
    int casasBispoVertical = 2;
    int casasBispoHorizontal = 2;
    int casasRainha = 3;
    int movimentosCavalo = 2;

    printf("==========================================\n");
    printf("MOVIMENTOS DE PECAS DE XADREZ\n");
    printf("==========================================\n\n");

    // Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre, 1); // 1 = cima
    printf("\n");

    // Bispo
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispoVertical, casasBispoHorizontal);
    printf("\n");

    // Rainha
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);
    printf("\n");

    // Cavalo
    printf("Movimento do Cavalo:\n");
    moverCavalo(movimentosCavalo);
    printf("\n");

    printf("==========================================\n");
    printf("Fim dos movimentos.\n");
    printf("==========================================\n");

    return 0;
}
