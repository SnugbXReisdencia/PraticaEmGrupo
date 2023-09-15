# include <iostream>
# include <locale>

# define TAM 10

using namespace std;
struct Produto
{
    string produto;
    int qtd = 0;
    double preco = 0.0;
    int id;
};

struct Estoque
{
    Produto produto_vet[TAM];
    double valorTotal = 0.0;
};

Produto gera_produto(); // Metodo para criar um produto
double calcularValorTotal(Produto vetor[], int tamanhoVetor); // Metodo para calcular o valor total de estoque
void listarProduto(Produto vetor[], int tamanhoVetor); // Metodo para listar os produtos
void add_produto(Produto produto_novo, Produto vetor[], int &contProduto); // Metodo para adicionar um produto
// Produto busca_Produto(Produto vetor[], int tamanhoVetor); // Metodo para buscar um produto
// void atualizarEstoque(Produto produto, Produto vetor[], int tamanhoVetor, Estoque estoque); // Metodo para atualizar um produto no estoque

int Menu();

int main(){
    // Verifica o sistema operacional para não dar erro 
    if (system("echo hello") != 0)
    {
        locale::global(locale(""));
        system("clear");
    }else{
        setlocale(LC_ALL, "Portuguese");
        system("cls");
    }
    
    Estoque estoque;
    Produto produto;
    bool ini = false;
    int posi = 0;

    int opcao;

    do{
        system("echo hello") != 0 ? system("cls") : system("clear");
        opcao = Menu();
        
        switch (opcao)
        {
        case 1:
            produto = gera_produto();
            add_produto(produto, estoque.produto_vet, posi);
            ini = true;
            break;
        case 2:
            // produto = estoque.busca_Produto(estoque.produto_vet, TAM);
            // estoque.atualizarEstoque(produto, estoque.produto_vet, TAM, estoque);
            break;
        case 3:
            if(ini){
                listarProduto(estoque.produto_vet, TAM);
            }else{
                cout << "\nNao ha produto cadastrado ainda !!\n";
            }
            break;
        case 4:
            // estoque.valorTotal = estoque.calcularValorTotal(estoque.produto_vet, TAM);
            break;
        case 0:
            cout << "Programa encerrado !!\n";
            break;
        default:
            cout << "Opcao invalida !!\n" <<
                "Por favor, escolha uma opcao valida.\n";
            break;
        }
        system("pause");
    } while (opcao != 0);


    return 0;
}

Produto gera_produto(){
    Produto produto1;
    cout << "Digite o nome do produto: ";
    cin >> produto1.produto;
    cout << "Digite o preco do produto: ";
    cin >> produto1.preco;
    cout << "Digite a quantidade do produto: ";
    cin >> produto1.qtd;
    return produto1;
}

void add_produto(Produto produto_novo, Produto vetor[], int &posi){
    
    if(posi<TAM){
        vetor[posi] = produto_novo;
        posi++;
    }else{
        cout << "\nEstoque cheio !! Nao foi possivel gardar esse produto\n";
    }
    
}

void listarProduto(Produto vetor[], int tamanhoVetor){
    for (int i = 0; i < tamanhoVetor; i++)
    {
        cout << "Produto           Preco        Quantidade " << endl;
        cout << vetor[i].produto << "              " << vetor[i].preco << "           " << vetor[i].qtd  << endl;
        cout << "====================================================================" << endl;
    }
}

double calcularValorTotal(Produto vetor[], int tamanhoVetor){
    double valorTotal = 0;
    for (int i = 0; i < tamanhoVetor; i++)
    {
        valorTotal += vetor[i].preco * vetor[i].qtd;
    }

    return valorTotal;
}

// Produto busca_Produto(Produto vetor[], int tamanhoVetor){
//     return vetor[tamanhoVetor];
// }

int Menu(){
    cout << "############## Menu ##############\n\n";
    cout << "1 - Adicionar Produto\n";
    cout << "2 - Atualizar Estoque\n";
    cout << "3 - Listar Produtos\n";
    cout << "4 - Calcular Valor Total de Estoque\n";
    cout << "0 - Sair\n";

    int opcao;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}