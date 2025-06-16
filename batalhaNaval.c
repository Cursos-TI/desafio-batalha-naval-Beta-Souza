#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int TAMANHO = 5;
    int TAM_NAVIO = 3;
    int NAVIO = 3;

    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas dos navios
    int linhaH = 2, colH = 0;  // navio horizontal
    int linhaV = 1, colV = 4;  // navio vertical

    // Valida navio horizontal dentro dos limites
    if (linhaH < 0 || linhaH >= TAMANHO || colH < 0 || colH + TAM_NAVIO > TAMANHO) {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Valida navio vertical dentro dos limites
    if (colV < 0 || colV >= TAMANHO || linhaV < 0 || linhaV + TAM_NAVIO > TAMANHO) {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verifica sobreposição antes de posicionar os navios
    int sobreposicao = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colH + i] == 3 || tabuleiro[linhaV + i][colV] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: sobreposição de navios detectada.\n");
        return 1;
    }

    // Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colH + i] = NAVIO;
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colV] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("Desafio: nível novato\n");
    printf("\nTabuleiro - 1:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    int TAM = 10;

    int tabuleiro2[TAM][TAM];
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro2[i][j] = 0;
        }
    }

    // Função para posicionar um navio
    // direcao: 0=horizontal, 1=vertical, 2=diagonal principal, 3=diagonal secundária
    int posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int direcao, int tam, int valor) {
        for (int i = 0; i < tam; i++) {
            int l = linha, c = coluna;

            if (direcao == 0) c += i;
            else if (direcao == 1) l += i;
            else if (direcao == 2) { l += i; c += i; }
            else if (direcao == 3) { l += i; c -= i; }

            if (l < 0 || l >= 10 || c < 0 || c >= 10)
                return 0;

            if (tabuleiro[l][c] != 0)
                return 0;
        }

        for (int i = 0; i < tam; i++) {
            int l = linha, c = coluna;

            if (direcao == 0) c += i;
            else if (direcao == 1) l += i;
            else if (direcao == 2) { l += i; c += i; }
            else if (direcao == 3) { l += i; c -= i; }

            tabuleiro[l][c] = valor;
        }

        return 1;
    }

    // Posicionamento dos 4 navios
    int ok = 1;

    ok &= posicionarNavio(tabuleiro2, 1, 2, 0, TAM_NAVIO, NAVIO); // horizontal
    ok &= posicionarNavio(tabuleiro2, 4, 6, 1, TAM_NAVIO, NAVIO); // vertical
    ok &= posicionarNavio(tabuleiro2, 5, 1, 2, TAM_NAVIO, NAVIO); // diagonal principal
    ok &= posicionarNavio(tabuleiro2, 5, 9, 3, TAM_NAVIO, NAVIO); // diagonal secundária

    if (!ok) {
        printf("Erro: navios fora do limite ou sobrepostos.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nDesafio: nível aventureiro\n");
    printf("\nTabuleiro - 2:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro2[i][j]);
        }
        printf("\n");
    }

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

    return 0;
}
