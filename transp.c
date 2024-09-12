#include <stdio.h>

// Funções de preço por transportadoras (ajuste os valores de acordo com a necessidade)
float custo_a(float km) {
    return 2.5 * km + 10;  // Ex.:
}

float custo_b(float km) {
    return 3.0 * km + 5;   
}

float custo_c(float km) {
    return 2.0 * km + 15;  
}

float custo_d(float km) {
    return 2.8 * km + 8; 
}

float custo_e(float km) {
    return 3.2 * km;
}

// Estrutura para dar as informações de cada transportadora
struct Transportadora {
    char nome[2];  // Nome da transportadora (e.g., "A", "B")
    float (*custo)(float); // Pointer pra cada custo da função
    char funcao[10]; // Array/string com para representar o custo da função
    float custo_calculado; // Custo calculado para a distância dada
};

int main() {
    // Array para armazenar dados da transportadora
    struct Transportadora transportadoras[] = {
        {"A", custo_a, "2.5x + 10"},
        {"B", custo_b, "3.0x + 5"},
        {"C", custo_c, "2.0x + 15"},
        {"D", custo_d, "2.8x + 8"},
        {"E", custo_e, "3.2x"}
    };
    int num_transportadoras = sizeof(transportadoras) / sizeof(transportadoras[0]);

    printf("Comparativo de Precos de Transportadoras\n");

    float km;
    printf("Digite a quilometragem: ");
    scanf("%f", &km);

    if (km <= 0) {
        printf("Esta quilometragem esta fora do dominio da distancia.\n");
    } else {
        // Calcular o custo de cada transportadora
        for (int i = 0; i < num_transportadoras; i++) {
            transportadoras[i].custo_calculado = transportadoras[i].custo(km);
        }

        // Encontrar a transportadora com o menor custo
        int vencedor_index = 0;
        for (int i = 1; i < num_transportadoras; i++) {
            if (transportadoras[i].custo_calculado < transportadoras[vencedor_index].custo_calculado) {
                vencedor_index = i;
            }
        }

        // Mostrar os resultados
        printf("Resultados:\n");
        for (int i = 0; i < num_transportadoras; i++) {
            printf("- %s: R$ %.2f (%s)\n", 
                   transportadoras[i].nome, 
                   transportadoras[i].custo_calculado, 
                   transportadoras[i].funcao);
        }

        printf("A transportadora com o menor preco e a %s\n", transportadoras[vencedor_index].nome);
    }

    return 0;
}