#include <stdio.h>
#include <string.h>

#define TAM 10 // capacidade máxima da mochila

// Estrutura para representar um item da mochila
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Funções do menu
void adicionarItem(struct Item mochila[], int *contador);
void removerItem(struct Item mochila[], int *contador);
void listarItens(struct Item mochila[], int contador);

int main() {
    struct Item mochila[TAM];
    int contador = 0; // controla quantos itens estão ocupando a mochila
    int opcao;

    do {
        printf("\n===== CÓDIGO DA ILHA – FREE FIRE =====\n");
        printf("1. Adicionar item à mochila\n");
        printf("2. Remover item da mochila\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer do teclado

        switch(opcao) {
            case 1:
                adicionarItem(mochila, &contador);
                break;
            case 2:
                removerItem(mochila, &contador);
                break;
            case 3:
                listarItens(mochila, contador);
                break;
            case 4:
                printf("Saindo do jogo... até a próxima batalha!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}

void adicionarItem(struct Item mochila[], int *contador) {
    if (*contador >= TAM) {
        printf("\nA mochila está cheia! Libere espaço antes de adicionar novos itens.\n");
        return;
    }

    struct Item novo;
    printf("\n--- Adicionar novo item ---\n");
    printf("Nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // remove \n do final

    printf("Tipo do item (ex: armamento, kit médico, proteção): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar();

    mochila[*contador] = novo;
    (*contador)++;

    printf("\nItem adicionado com sucesso à mochila!\n");
}

void removerItem(struct Item mochila[], int *contador) {
    if (*contador == 0) {
        printf("\nA mochila está vazia. Nenhum item para remover.\n");
        return;
    }

    listarItens(mochila, *contador);

    int pos;
    printf("\nDigite o número do item que deseja remover (1 a %d): ", *contador);
    scanf("%d", &pos);
    getchar();

    if (pos < 1 || pos > *contador) {
        printf("Número inválido!\n");
        return;
    }

    // Move os itens para preencher o espaço do item removido
    for (int i = pos - 1; i < *contador - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    (*contador)--;

    printf("\nItem removido com sucesso!\n");
}

void listarItens(struct Item mochila[], int contador) {
    if (contador == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    printf("\n--- Itens da Mochila ---\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}
