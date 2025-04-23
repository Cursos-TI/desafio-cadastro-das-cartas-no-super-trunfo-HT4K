#include <stdio.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
};

// Função para ler os dados de uma carta
void lerCarta(struct Carta *carta) {
    printf("\nDigite os dados da carta:\n");

    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Código: ");
    scanf("%d", &carta->codigo);

    printf("Nome: ");
    scanf(" %[^\n]", carta->nome);

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para calcular atributos derivados
void calcularDados(struct Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib * 1e9 / carta->populacao;

    carta->super_poder =
        (float)carta->populacao +
        carta->area +
        carta->pib * 1e9 +
        (float)carta->pontos_turisticos +
        carta->pib_per_capita +
        (1.0f / carta->densidade_populacional);
}

// Função para exibir resultados das comparações
void compararECriticar(struct Carta c1, struct Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);

    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);

    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);

    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);

    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional); // menor vence

    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);
}

int main() {
    struct Carta carta1, carta2;

    // Leitura das cartas
    printf("=== Dados da Carta 1 ===");
    lerCarta(&carta1);
    calcularDados(&carta1);

    printf("\n=== Dados da Carta 2 ===");
    lerCarta(&carta2);
    calcularDados(&carta2);

    // Comparações
    compararECriticar(carta1, carta2);

    return 0;
}