#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

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

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    // Verifica se o navio cabe no tabuleiro
    if ((orientacao == 0 && coluna + NAVIO > TAMANHO) || (orientacao == 1 && linha + NAVIO > TAMANHO)) {
        return 0; // Falha no posicionamento
    }
    
    // Verifica se há sobreposição
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 0 && tabuleiro[linha][coluna + i] != 0) {
            return 0;
        }
        if (orientacao == 1 && tabuleiro[linha + i][coluna] != 0) {
            return 0;
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + i] = 3; // Horizontal
        } else {
            tabuleiro[linha + i][coluna] = 3; // Vertical
        }
    }
    
    return 1; // Sucesso
}

// Função para posicionar um navio diagonalmente
int posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    // Verifica se o navio cabe no tabuleiro
    if ((direcao == 0 && (linha + NAVIO > TAMANHO || coluna + NAVIO > TAMANHO)) || 
        (direcao == 1 && (linha + NAVIO > TAMANHO || coluna - NAVIO < -1))) {
        return 0; // Falha no posicionamento
    }
    
    // Verifica se há sobreposição
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 0 && tabuleiro[linha + i][coluna + i] != 0) {
            return 0;
        }
        if (direcao == 1 && tabuleiro[linha + i][coluna - i] != 0) {
            return 0;
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 0) {
            tabuleiro[linha + i][coluna + i] = 3; // Diagonal principal
        } else {
            tabuleiro[linha + i][coluna - i] = 3; // Diagonal secundária
        }
    }
    
    return 1; // Sucesso
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionamento dos navios
    int sucesso1 = posicionarNavio(tabuleiro, 2, 3, 0); // Navio horizontal
    int sucesso2 = posicionarNavio(tabuleiro, 5, 6, 1); // Navio vertical
    int sucesso3 = posicionarNavioDiagonal(tabuleiro, 1, 1, 0); // Navio diagonal principal
    int sucesso4 = posicionarNavioDiagonal(tabuleiro, 2, 8, 1); // Navio diagonal secundária
    
    // Verifica se os navios foram posicionados corretamente
    if (!sucesso1 || !sucesso2 || !sucesso3 || !sucesso4) {
        printf("Erro ao posicionar os navios.\n");
    }
    
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
