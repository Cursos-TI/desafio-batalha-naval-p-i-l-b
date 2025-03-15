#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar habilidades no tabuleiro
void aplicarHabilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + 2 >= TAMANHO || coluna - 1 < 0 || coluna + 1 >= TAMANHO) return;
    
    tabuleiro[linha][coluna] = HABILIDADE;
    tabuleiro[linha + 1][coluna - 1] = HABILIDADE;
    tabuleiro[linha + 1][coluna] = HABILIDADE;
    tabuleiro[linha + 1][coluna + 1] = HABILIDADE;
    tabuleiro[linha + 2][coluna - 2] = HABILIDADE;
    tabuleiro[linha + 2][coluna - 1] = HABILIDADE;
    tabuleiro[linha + 2][coluna] = HABILIDADE;
    tabuleiro[linha + 2][coluna + 1] = HABILIDADE;
    tabuleiro[linha + 2][coluna + 2] = HABILIDADE;
}

void aplicarHabilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = HABILIDADE;
    if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = HABILIDADE;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = HABILIDADE;
    if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = HABILIDADE;
    tabuleiro[linha][coluna] = HABILIDADE;
}

void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = HABILIDADE;
    if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = HABILIDADE;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = HABILIDADE;
    if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = HABILIDADE;
    if (linha - 2 >= 0) tabuleiro[linha - 2][coluna] = HABILIDADE;
    if (linha + 2 < TAMANHO) tabuleiro[linha + 2][coluna] = HABILIDADE;
    if (coluna - 2 >= 0) tabuleiro[linha][coluna - 2] = HABILIDADE;
    if (coluna + 2 < TAMANHO) tabuleiro[linha][coluna + 2] = HABILIDADE;
    tabuleiro[linha][coluna] = HABILIDADE;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionamento das habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, 2, 5);
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 5);
    
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
