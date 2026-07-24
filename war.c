#include <stdio.h>
#include <string.h>

// CRIAÇÃO DA STRUCT TERRITORIO.
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};
       // INICIANDO A FUNÇÃO PRINCIPAL.
       int main() {
           
         printf("=========================================\n\n");
         printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");

           // CRIAÇÃO DO VETOR TERRITORIOS, QUANTIDADE MAX DE CADASTROS 5.
           struct Territorio territorios[5];  

           // FOR PARA ENTRADA DE DADOS E REPETIÇÃO DE CADASTRAMENTOS.
           for (int i = 0; i < 5; i++) {
            printf("--- Cadastrando Territorio %d ---\n", i + 1);

            printf("Nome do Territorio: ");
            fgets(territorios[i].nome, 30, stdin);
            territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
            
            printf("Cor do Exercito (ex: Azul, Verde): ");
            fgets(territorios[i].cor, 10, stdin);
            territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

            printf("Numero de Tropas: ");
            scanf("%d", &territorios[i].tropas);
            getchar();
           }

            printf("-----------------------------------\n");

           // FOR PARA SAIDA DE DADOS E PARA REPETIÇÃO DE CADASTROS FEITOS.
           for (int i = 0; i < 5; i++) {
            printf("-----------------------------------\n");
            printf("TERRITORIO %d\n", i + 1);

            printf("Nome do Territorio: %s\n", territorios[i].nome);
            printf("Cor do Exercito: %s\n", territorios[i].cor);
            printf("Numero de Tropas: %d\n", territorios[i].tropas);
  
            }
            
            printf("------------------------------------\n");




return 0; // FIM DO PROGRAMA!

}
