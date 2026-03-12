#include <stdio.h>

// Constantes para movimentação
const int BISPO_MOV = 7;   // máximo de casas em diagonal
const int TORRE_MOV = 7;   // máximo de casas em linha reta
const int RAINHA_MOV = 7;  // máximo de casas em qualquer direção
const int CAVALO_MOV = 2;  // movimento em L (2x1)

// Função recursiva para movimentação do Bispo (Nível Mestre)
void moverBispoRecursivo(int x, int y, int limite) {
    if (limite == 0) return;
    printf("Bispo em (%d, %d)\n", x, y);
    moverBispoRecursivo(x+1, y+1, limite-1); // diagonal direita inferior
}

// Movimentação simples do Bispo (Nível Novato)
void moverBispo() {
    int x = 0, y = 0;
    for (int i = 0; i < BISPO_MOV; i++) {
        x++;
        y++;
        printf("Bispo em (%d, %d)\n", x, y);
    }
}

// Movimentação da Torre (Nível Novato)
void moverTorre() {
    int x = 0;
    for (int i = 0; i < TORRE_MOV; i++) {
        x++;
        printf("Torre em (%d, 0)\n", x);
    }
}

// Movimentação da Rainha (Nível Novato)
void moverRainha() {
    int x = 7;
    for (int i = 0; i < RAINHA_MOV; i++) {
        x--;
        printf("Rainha em (%d, 0)\n", x);
    }
}

// Movimentação do Cavalo (Nível Aventureiro)
void moverCavalo() {
    int x = 0, y = 0;
    for (int i = 1; i <= CAVALO_MOV; i++) {
        for (int j = 1; j <= CAVALO_MOV; j++) {
            if (i == j) continue; // cavalo não anda em linha reta
            printf("Cavalo em (%d, %d)\n", x+i, y+j);
            if (i+j > 2) break; // condição avançada para parar
        }
    }
}

int main() {
    printf("=== Nível Novato ===\n");
    moverBispo();
    moverTorre();
    moverRainha();

    printf("\n=== Nível Aventureiro ===\n");
    moverCavalo();

    printf("\n=== Nível Mestre ===\n");
    moverBispoRecursivo(0, 0, BISPO_MOV);

    return 0;
}