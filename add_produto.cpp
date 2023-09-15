#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Menu();
struct Produto{
    string produto;
    int qtd=0;
    double preco=0.0;

};

void add_produto(){
        vector <Produto> produtos;
        Produto novo_produto;

        char resposta;
        int cont = 0;

        do{
            cont++;
            cout << " Digite o nome do produto: " << endl;
            cin>> novo_produto.produto;

            cout << "Preço do produto: " << endl;
            cin>> novo_produto.preco;

            cout << "Quantidade do produto: " << endl;
            cin>> novo_produto.qtd;

            produtos.push_back(novo_produto);

            cout << " Deseja Adicionar outro produto (s/n)? " << endl;
            cin>> resposta;

        }while(resposta == 's');    

        // for para teste 
        // for (int i = 0; i < produtos.size(); i++) {
        //         cout << "Produto           Preço        Quantidade " << endl;
        //         cout << produtos[i].produto << "              " << produtos[i].preco << "           " << produtos[i].qtd  << endl;
        //         cout << "====================================================================" << endl;
        //     }

};


int main() {

        // Verifica o sistema operacional para não dar erro 
    if (system("echo hello") != 0)
    {
        locale::global(locale(""));
        system("clear");
    }else{
        setlocale(LC_ALL, "Portuguese");
        system("cls");
    }
    int opcao;
    do{
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            cout << "Opção 1\n";
            break;
        case 2:
            add_produto();
            break;
        case 3:
            cout << "Opção 3\n";
            break;
        case 4:
            cout << "Opção 4\n";
            break;
        case 0:
            cout << "Opção 0\n";
            break;
        default:
            cout << "Opção inválida !!\n";
            cout << "Por favor, escolha uma opção válida\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}


int Menu(){
    cout << "############## Menu ##############\n\n";
    cout << "1 - Adicionar Produto\n";
    cout << "2 - Atualizar Estoque\n";
    cout << "3 - Listar Produtos\n";
    cout << "4 - Calcular Valor Total de Estoque\n";
    cout << "0 - Sair\n";

    int opcao;
    wcout << L"\nEscolha uma opção: ";
    cin >> opcao;

    return opcao;
}