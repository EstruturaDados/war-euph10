#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// CRIAÇÃO DA STRUCT TERRITORIO.
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio; 

// --- Protótipos das Funções ---
// Declarar as finções aqui permite que a main as chame antes de ssuas definições.

// FUNÇÃO RESPONSÁVEL POR REALIZAR O ATAQUE.
void atacar(Territorio *atacante, Territorio *defensor)
{
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("=======================================\n");
    printf("RESULTADO DO ATAQUE\n");
    printf("=======================================\n");

    printf("%s tirou %d\n", atacante->nome, dadoAtacante);
    printf("%s tirou %d\n", defensor->nome, dadoDefensor);

    if(dadoAtacante > dadoDefensor)
    {
        printf("\n%s conquistou o territorio %s!\n", atacante->nome, defensor->nome);
             
        // TERRITORIO MUDA DE DONO.
        strcpy(defensor->cor, atacante->cor);

        // O ATACANTE ENVIA METADE DAS TROPAS.
        defensor->tropas = atacante->tropas /2;
        atacante->tropas = atacante->tropas - defensor->tropas;
    }
    else
    {
        printf("\n%s defendeu o territorio!\n", defensor->nome);
    
        // O ATACANTE PERDE UMA TROPA.
        if (atacante->tropas > 1)
        {
            atacante->tropas --;
        }
    }
}
    // FUNÇÃO PARA LIBERAR MEMORIA ALOCADA.
    void liberarMemoria(Territorio* mapa)
    {
        free(mapa);
    }

    // Vetor de Srings com as missões do jogo.
    char* Missoes [5] = {
        "Conquistar 3 territorios seguidos",
        "Conquistar 2 territorios seguidos",
        "Conquiste pelo menos 1 territorio",
        "Conquiste 2 territorios",
        "Conquiste 4 territorios seguidos"
    };

// função para atribuir missão aleatóriamente a cada jogador.
void atribuirMissao(char* Destino, char*Missoes[], int totalMissoes)
{
     int i = rand() % totalMissoes;
     strcpy(Destino, Missoes[i]);

     char* Missao;
     Missao = malloc((strlen(Missoes[totalMissoes]) + 1) * sizeof(char));


}
    
       // INICIANDO A FUNÇÃO PRINCIPAL.
       int main() {

        srand(time(NULL));

         printf("===================================\n");
         printf("WAR ESTRUTURADO - CADASTRO INICIAL\n");
         printf("===================================\n");

         // QUANTIDADE DE TERRITÓRIOS
         int quantidade;

         printf("Quantos territorios deseja cadastrar?  ");
         scanf("%d", &quantidade);
         getchar();

         // ALOCAÇÃO DINÂMICA DE MEMORIA.
         Territorio* territorios;

         territorios = (Territorio*) calloc(quantidade, sizeof(Territorio));

           // FOR PARA ENTRADA DE DADOS E REPETIÇÃO DE CADASTRAMENTOS.
           for (int i = 0; i < quantidade; i++) {
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

            while (1)
            {
                
            printf("===================================\n");
            printf("MAPA DO MUNDO - ESTADO ATUAL \n");
            printf("===================================\n");
            

           // FOR PARA SAIDA DE DADOS E PARA REPETIÇÃO DE CADASTROS FEITOS.
           for (int i = 0; i < quantidade; i++) {
                
                printf("[%d] %s (Exercito %s, Tropas %d)\n",
                       i + 1,
                       territorios[i].nome,
                       territorios[i].cor,
                       territorios[i].tropas);
            }

            // ESCOLHA DOS TERRITÓRIOS.
            int atacante;
            int defensor;

            printf("===================================\n");
            printf("FASE DE ATAQUE\n");
            printf("===================================\n");

            printf("Escolha o territorio atacante (1 a %d, ou 0 para sair): ", quantidade);
            scanf("%d", &atacante);
            
             if (atacante == 0)
            {
                printf("Saindo do jogo...\n");
                break;
            } 
            else
            {
            printf("Escolha o territorio defensor(1 a %d, ou 0 para sair): ", quantidade);
            scanf("%d", &defensor);
            
            if (defensor == 0)
            {
                printf("Saindo do jogo...\n");
                break;
            }
            else
            {
                atacante--;
                defensor--;
            
            // VALIDAÇÃO.
            if(atacante < 0 || atacante >= quantidade || 
               defensor < 0 || defensor >= quantidade) {

                printf("\nTerritorio invalido\n");
               }
               else if (strcmp(territorios[atacante].cor, territorios[defensor].cor) == 0) 
               {
                  printf("\nNao e permitido atacar um territorio da mesma cor!\n");
               }
               else
               {
                atacar(&territorios[atacante], &territorios[defensor]);
               }
            }
        }

                printf("Pressione enter para o proximo turno...");
                getchar();
                getchar();
    }

            //LIBERAÇÃO DE MEMÓRIA.
            liberarMemoria(territorios);


return 0; // FIM DO PROGRAMA!

}
