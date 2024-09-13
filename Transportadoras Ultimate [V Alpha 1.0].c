#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure para armazenar os dados da transportadora
struct Transportadora {
    char nome[50];        // Nome da transportadora
    float custo_fixo;     // Custo Fixo
    float custo_por_km;   // Custo por KM
};

int main() {
    int num_transportadoras = 0;
    struct Transportadora *transportadoras = NULL;
    char adicionar_mais = 's'; 

    while (adicionar_mais == 's' || adicionar_mais == 'S') {
        // Realocação de ram para adicionar mais transportadoras
        num_transportadoras++;
        transportadoras = (struct Transportadora *)realloc(transportadoras, num_transportadoras * sizeof(struct Transportadora));

        // Prompts do usuario para as informações, e.g. nome, cf, e c/km
        printf("\nTransportadora %d:\n", num_transportadoras);
        printf("Nome: ");
        fgets(transportadoras[num_transportadoras - 1].nome, 50, stdin);

        // Remove a linha do fgets
        transportadoras[num_transportadoras - 1].nome[strcspn(transportadoras[num_transportadoras - 1].nome, "\n")] = 0;

        printf("Tem custo fixo (s/n)? ");
        char tem_custo_fixo;
        scanf(" %c", &tem_custo_fixo); 

        getchar(); 

        if (tem_custo_fixo == 's' || tem_custo_fixo == 'S') {
            printf("Custo fixo: ");
            scanf("%f", &transportadoras[num_transportadoras - 1].custo_fixo);
        } else {
            transportadoras[num_transportadoras - 1].custo_fixo = 0; 
        }

        printf("Custo por quilometro: ");
        scanf("%f", &transportadoras[num_transportadoras - 1].custo_por_km);

        printf("Adicionar outra transportadora (s/n)? ");
        scanf(" %c", &adicionar_mais); 

        getchar(); 
    }

    char calcular_novamente = 's';

    while (calcular_novamente == 's' || calcular_novamente == 'S') {
        // Prompt da distancia em km
        float km;
        printf("\nDigite a quilometragem: ");
        scanf("%f", &km);

        // Calcula os resultados e coloca na tabela
        printf("\nComparativo de Custos:\n");
        printf("-------------------------------------\n");
        printf("| Nome      | Custo Fixo | Custo/km | Custo Total |\n");
        printf("-------------------------------------\n");

        float menor_custo = -1; 
        int transportadora_mais_barata = -1;

        for (int i = 0; i < num_transportadoras; i++) {
            float custo_total = transportadoras[i].custo_fixo + transportadoras[i].custo_por_km * km;
            printf("| %-10s | %-10.2f | %-8.2f | %-11.2f |\n", 
                   transportadoras[i].nome, 
                   transportadoras[i].custo_fixo,
                   transportadoras[i].custo_por_km,
                   custo_total);

            if (menor_custo == -1 || custo_total < menor_custo) {
                menor_custo = custo_total;
                transportadora_mais_barata = i;
            }
        }
        printf("-------------------------------------\n");

        if (transportadora_mais_barata != -1) {
            printf("\nA transportadora mais barata e: %s\n", transportadoras[transportadora_mais_barata].nome);
        }

        // Pergunta se o user quer calcular novamente
        printf("Calcular para uma nova distancia (s/n)? ");
        scanf(" %c", &calcular_novamente);

        getchar(); 
    }

    printf("Software by Luciano Lopes Industries\n");

    // Libera a memória
    free(transportadoras);

    return 0;
}