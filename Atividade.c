#include <stdio.h>
#include <string.h>
#include <locale.h>
struct conta
{
    char login[300];
    int senha;
};


struct Produto {
    char nome[333];
    float preco;
    int quantidade_estoque;
    float codigodebarra;
};


float calcular_valor_total(struct Produto produto) {
    return produto.preco * produto.quantidade_estoque;
}


void realizar_compra(struct Produto *produto) {
    int quantidade_compra;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidade_compra);

    if (quantidade_compra > 0 && quantidade_compra <= produto->quantidade_estoque) {
        produto->quantidade_estoque -= quantidade_compra;
        printf("Compra realizada com sucesso. Novo estoque: %d\n", produto->quantidade_estoque);
    } else {
        printf("Quantidade invÃ¡lida. Compra nÃ£o realizada.\n");
    }
}


void consultar_estoque(struct Produto produto) {
    printf("Nome do produto: %s\n", produto.nome);
    printf("Quantidade do produto: %d\n", produto.quantidade_estoque);
    printf("PreÃ§o por unidade: R$ %.2f\n", produto.preco);
    printf("Valor total em estoque: R$ %.2f\n", calcular_valor_total(produto));
}






void adicionar_produto(struct Produto *produto) {
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidade_estoque);
    printf("Digite o preço por unidade: ");
    scanf("%f", &produto->preco);
    printf("Código de barras:");
    scanf("%f", &produto->codigodebarra);
}

int main() {
      setlocale(LC_ALL, "");
    struct conta minhaconta; 
    struct Produto produto;
    struct Produto meuProduto;
    int escolha;

printf("\t\nDigite seu loguin:\n");
    gets(minhaconta.login);
    fflush(stdin);
    printf("\t\nDigite sua senha: \n");
    scanf("%d", &minhaconta.senha);

fflush(stdin);
 system("cls || clear");

    printf("\n\tBem - Vindo\n");

    do {
        printf("\t\n===== Menu =====\n");
        printf("\n");
        printf("\n");
        printf("\n\tEscolha uma opção: \n");
        printf("\n");
        printf("\n\t1. Adicionar produto\n");
        printf("\n");
        printf("\n\t2. Realizar uma compra\n");
        printf("\n");
        printf("\n\t3. Consultar estoque\n");
        printf("\n");
        printf("\n\t4. Consultar codigo de barra\n");
        printf("\n");
        printf("\n\t5. Sair do programa\n");
        printf("\n");
        printf("\t\n===== Menu =====\n");
        scanf("%d", &escolha);
        fflush(stdin);
        switch (escolha) {
            case 1:
                adicionar_produto(&meuProduto);
                fflush(stdin);
                break;
              
            case 2:
                realizar_compra(&meuProduto);
                break;

            case 3:
                consultar_estoque(meuProduto);
                break;
            case 4:
                printf("Código de barras do produto: %f", produto.codigodebarra);
                break;
            case 5:
                printf("Fechando o programa\n");
                break;

            default:
                printf("\n\tOpçâo inválida. Tente novamente.\n");
        }

    } while (escolha != 5);

    return 0;
}

