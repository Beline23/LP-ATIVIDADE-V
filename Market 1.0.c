#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 1
#define MAX_USUARIO 50
#define MAX_SENHA 20

// Struct para representar a validade de um produto
struct Validade {
    int dia;
    int mes;
    int ano;
};

// Struct para representar um produto
struct Produto {
    char nome[50];
    struct Validade validade;
    float preco;
    int quantidade;
};

void adicionar_produto(struct Produto *produto) {
    printf("\n\t Bem - Vindo");
    printf("\n");
    printf("\n");
    printf("Adicionando produtos");
    printf("\n");
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidade);
    printf("Digite o preço por unidade: ");
    scanf("%f", &produto->preco);
    printf("Digite a validade:");
    scanf("%d", &produto->validade);
     fflush(stdin);
    system("cls || clear");
}
// Função para calcular o valor total em estoque do produto
float calcularValorTotal(struct Produto produtos[], int numProdutos) {
    float valorTotal = 0.0;
    for (int i = 0; i < numProdutos; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }
    return valorTotal;
}

// Função para realizar uma compra e atualizar a quantidade em estoque e validade
void realizarCompra(struct Produto produtos[], int numProdutos) {
    char nomeProduto[50];
    int quantidadeCompra;
    int dia, mes, ano;

    printf("Informe o nome do produto: ");
    scanf("%s", nomeProduto);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            printf("Informe a quantidade a ser comprada: ");
            scanf("%d", &quantidadeCompra);

            if (quantidadeCompra <= produtos[i].quantidade) {
                produtos[i].quantidade -= quantidadeCompra;

                // Atualizando a validade ficticiamente
                printf("Informe a nova data de validade (dia mes ano): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                produtos[i].validade.dia = dia;
                produtos[i].validade.mes = mes;
                produtos[i].validade.ano = ano;

                printf("Compra realizada com sucesso!\n");
            } else {
                printf("Quantidade em estoque insuficiente!\n");
            }

            return;
        }
    }

    printf("Produto não encontrado!\n");
}

// Função para consultar o estoque
void consultarEstoque(struct Produto produtos[], int numProdutos) {
    printf("Estoque:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Nome: %s, Preço: %.2f, Quantidade em estoque: %d, Validade: %02d/%02d/%04d\n",
               produtos[i].nome, produtos[i].preco, produtos[i].quantidade,
               produtos[i].validade.dia, produtos[i].validade.mes, produtos[i].validade.ano);
    }

    printf("Valor total em estoque: %.2f\n", calcularValorTotal(produtos, numProdutos));
}

// Função para listar os produtos e suas validades
void listarProdutosValidades(struct Produto produtos[], int numProdutos) {
    printf("Produtos e suas validades:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Nome: %s, Validade: %02d/%02d/%04d\n",
               produtos[i].nome, produtos[i].validade.dia,
               produtos[i].validade.mes, produtos[i].validade.ano);
    }
}

int main() {
    char usuario[MAX_USUARIO];
    char senha[MAX_SENHA];
    int numProdutos = 0;
    struct Produto produtos[MAX_PRODUTOS];

    setlocale(LC_ALL, "portugues");
    
    // Login
    printf("\n|======| Market 1.0 |======|\n");
    printf("\nPara iniciar efetue o loguin\n");
    printf("\nInforme o usuário: ");
    scanf("%s", usuario);
    printf("\ntInforme a senha: ");
    scanf("%s", senha);
fflush(stdin);
system ("cls || clear");

    // Verificação de login (usuário e senha fictícios neste exemplo)
    if (strcmp(usuario, "admin") != 0 || strcmp(senha, "senha123") != 0) {
        printf("Usuário ou senha incorretos. Encerrando o programa.\n");
        return 1;
    }

    
    
    int escolha;
    
   adicionar_produto(produtos);
    
    do {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Consultar validade\n");
        printf("4 - Sair do programa\n");
        printf("Escolha a opção: ");
        scanf("%d", &escolha);
fflush(stdin);
system ("cls || clear");
        switch (escolha) {
            case 1: // Adicionar produto
                realizarCompra(produtos, numProdutos);                  
                break;

            case 2: // Realizar uma compra
                consultarEstoque(produtos, numProdutos);
                break;

            case 3: // Consultar estoque
                listarProdutosValidades(produtos, numProdutos);
                break;

            case 4: // Sair do programa
                break;
                printf("Encerrando o programa.\n");

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}
