#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Produto
{
    string produto;
    int qtd = 0;
    double preco = 0.0;
};

struct ItemCarrinho
{
    Produto produto;
    int qtd;
    double Valor_Total = 0.0;
};

int Menu();

int MenuVenda();

void addProduto(vector<Produto> &produtos);

void listaProdutos(vector<Produto> &produtos);

Produto buscar_produto(vector<Produto> &produtos);

void atualizarEstoque(vector<Produto> &produtos, Produto produto_Vendido, int estoque);

void listaCarrinho(vector<ItemCarrinho> &carrinho);

void finalizar_venda(vector<Produto> &produtos, vector<ItemCarrinho> carrinho);

void valor_total_carrinho(vector<ItemCarrinho> &carrinho);

vector<ItemCarrinho> add_carrinho(vector<Produto> &produtos);

int main()
{

    // Verifica o sistema operacional para não dar erro
    if (system("echo hello") != 0)
    {
        locale::global(locale(""));
        system("clear");
    }
    else
    {
        setlocale(LC_ALL, "Portuguese");
        system("cls");
    }
    int opcao, opcao2;

    vector<Produto> produtos;
    vector<ItemCarrinho> carrinho;
    Produto aux;
    int New_estoque;

    do
    {
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            addProduto(produtos);
            break;
        case 2:
            if (produtos.size() == 0)
            {
                cout << "A lista de Produtos está vazia !!\n";
            }
            else
            {
                aux = buscar_produto(produtos);
                if (aux.produto != "")
                {
                    cout << "Informe o novo estoque desse Produto: ";
                    cin >> New_estoque;
                    atualizarEstoque(produtos, aux, New_estoque);
                }
                else
                {
                    cout << "Produto nao encontrado !!\n";
                }
            }

            break;
        case 3:
            listaProdutos(produtos);
            break;
        case 4:
            cout << "Opcao 4\n";
            break;
        case 5:
            if (produtos.size() > 0)
            {
                do
                {
                    opcao2 = MenuVenda();
                    switch (opcao2)
                    {
                    case 1:
                        carrinho = add_carrinho(produtos);
                        break;
                    case 2:
                        if(carrinho.size() > 0){
                            finalizar_venda(produtos, carrinho);
                            carrinho.clear();
                        }else{
                            cout << "A lista do carrinho está vazia !!\n";
                        }
                        break;
                    case 3:
                        if(carrinho.size() > 0){
                            listaCarrinho(carrinho);
                        }else{
                            cout << "A lista do carrinho está vazia !!\n";
                        }
                        break;
                    case 4:
                        if(carrinho.size() > 0){
                            valor_total_carrinho(carrinho);
                        }else{
                            cout << "A lista do carrinho está vazia !!\n";
                        }
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcao invalida !!\n";
                        cout << "Por favor, escolha uma opção valida\n";
                        break;
                    }

                } while (opcao2 != 0);
            }else{
                cout << "A lista de Produtos está vazia !!\n";
                cout << "Por favor, adicione produtos antes de Registrar uma venda!! \n";
            }
            break;
        case 0:
            cout << "Programa Finalizado\n";
            break;
        default:
            cout << "Opcao invalida !!\n";
            cout << "Por favor, escolha uma opção valida\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}

void addProduto(vector<Produto> &produtos)
{

    Produto novo_produto;

    char resposta;
    int cont = 0;

    do
    {
        cont++;
        cout << " Digite o nome do produto: " << endl;
        cin >> novo_produto.produto;

        cout << "Preço do produto: " << endl;
        cin >> novo_produto.preco;

        cout << "Quantidade do produto: " << endl;
        cin >> novo_produto.qtd;

        produtos.push_back(novo_produto);

        cout << " Deseja Adicionar outro produto (s/n)? " << endl;
        cin >> resposta;

    } while (resposta == 's');
};
void listaProdutos(vector<Produto> &produtos)
{
    int tamanho = produtos.size();
    cout << "====================================================================" << endl;
    cout << "========================Lista de Produtos===========================" << endl;
    cout << "====================================================================" << endl;
    cout << "Produto           Preco        Quantidade " << endl
         << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << produtos[i].produto << "              " << produtos[i].preco << "           " << produtos[i].qtd << endl;
    }
    cout << "====================================================================" << endl;
}

void atualizarEstoque(vector<Produto> &produtos, Produto alt_produto, int estoque)
{
    bool existe = false;
    for (size_t i = 0; i < produtos.size(); i++)
    {
        if (produtos[i].produto == alt_produto.produto)
        {
            produtos[i].qtd = estoque;
            existe = true;
        }
    }
    if (existe)
    {
        cout << "Produto " << alt_produto.produto << " estoque atualizado com sucesso!" << endl;
    }
    else
    {
        cout << "Produto " << alt_produto.produto << " nao existe!" << endl;
    }
}

void finalizar_venda(vector<Produto> &produtos, vector<ItemCarrinho> carrinho)
{
    bool existe = false;

    for (ItemCarrinho item : carrinho)
    {
        for (size_t i = 0; i < produtos.size(); i++)
        {
            if (produtos[i].produto == item.produto.produto)
            {
                if (produtos[i].qtd >= item.qtd)
                {
                    produtos[i].qtd -= item.qtd;
                    existe = true;
                }
                else
                {
                    cout << "O produto " << item.produto.produto << " Vendido nao realizada!" << endl;
                    cout << "Problema no estoque !" << endl;
                }
            }
        }
    }
    if (existe)
    {
        cout << "Venda finalizada com sucesso!" << endl;
    }
    else
    {
        cout << "Venda nao realizada !" << endl;
    }
}

Produto buscar_produto(vector<Produto> &produtos)
{
    string nome_Produto;
    Produto produto;
    cout << "Digite o nome do produto: " << endl;
    cin >> nome_Produto;

    for (Produto produto : produtos)
    {
        if (produto.produto == nome_Produto)
        {
            return produto;
        }
    }
    return produto;
}

vector<ItemCarrinho> add_carrinho(vector<Produto> &produtos)
{
    vector<ItemCarrinho> carrinho;
    ItemCarrinho aux;
    char resposta;
    do
    {
        aux.produto = buscar_produto(produtos);
        if (aux.produto.produto != "")
        {
            cout << "Informe a quantidade desse produto: ";
            cin >> aux.qtd;

            if (aux.produto.qtd >= aux.qtd)
            {
                aux.Valor_Total = aux.produto.preco * aux.qtd;
                carrinho.push_back(aux);
            }
            else
            {
                cout << "Produto com estoque insuficiente para essa quantia !!\n";
            }
        }
        else
        {
            cout << "Produto nao encontrado !!\n";
        }
        cout << "Deseja Adicionar outro produto (s/n)? ";
        cin >> resposta;
    } while (resposta == 's' || resposta == 'S');

    return carrinho;
}

void valor_total_carrinho(vector<ItemCarrinho> &carrinho)
{
    double total = 0.0;
    for (ItemCarrinho item : carrinho)
    {
        total += item.Valor_Total;
    }
    cout << "Valor total do carrinho: " << total << endl;
}

void listaCarrinho(vector<ItemCarrinho> &carrinho){
    int tamanho = carrinho.size();
    cout << "====================================================================" << endl;
    cout << "===========================Lista Carrinho===========================" << endl;
    cout << "====================================================================" << endl;
    cout << "Produto           Preco        Quantidade " << endl
         << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << carrinho[i].produto.produto << "              " << carrinho[i].produto.preco << "           " << carrinho[i].qtd << endl;
    }
    cout << "====================================================================" << endl;
}
int MenuVenda()
{
    cout << "############## Menu Venda ##############\n\n";
    cout << "1 - Adicionar Produto no carrinho\n";
    cout << "2 - Finalizar Venda\n";
    cout << "3 - Listar Carrinho\n";
    cout << "4 - Calcular Valor Total de Carrinho\n";
    cout << "0 - Voltar para o Menu Principal\n";

    int opcao;
    wcout << L"\nEscolha uma opcao: ";
    cin >> opcao;

    return opcao;
}
int Menu()
{
    cout << "############## Menu ##############\n\n";
    cout << "1 - Adicionar Produto\n";
    cout << "2 - Atualizar Estoque\n";
    cout << "3 - Listar Produtos\n";
    cout << "4 - Calcular Valor Total de Estoque\n";
    cout << "5 - Vender\n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opção: ";
    cin >> opcao;

    return opcao;
}