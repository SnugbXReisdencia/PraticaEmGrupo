# include <iostream>
# include <locale>

using namespace std;

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
    int opcao;
    do{
        opcao = Menu();
        switch (opcao)
        {
        case 1:
            cout << "Opção 1\n";
            break;
        case 2:
            cout << "Opção 2\n";
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