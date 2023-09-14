#include <iostream>
#include <string>

using namespace std;

int main() {

    string inseri_produto, resposta;
    int inseri_qtd;
    double inseri_preco;
    int cont=0;


    struct Produto{
        string produto;
        int qtd=0;
        double preco=0.0;

        void add_produto(string produto_novo, int qtd_novo, double preco_novo){
            produto = produto_novo;
            qtd = qtd_novo;
            preco = preco_novo;
            }
    };

    Produto Produto_[10];
    int tamanha_vetor = sizeof(Produto_) / sizeof(Produto_[0]);

    for (int i = 0; i <= tamanha_vetor-1; i++) {
        cont ++;
        cout << " Digite o nome do produto: " << endl;
        cin>> inseri_produto;

        cout << "Preço do produto: " << endl;
        cin>> inseri_preco;

        cout << "Quantidade do produto: " << endl;
        cin>> inseri_qtd;

        Produto_[i].add_produto(inseri_produto, inseri_qtd, inseri_preco);

        if(cont < tamanha_vetor){
            cout << " Deseja Adicionar outro produto (sim)? " << endl;
            cin>> resposta;
        }

        if(resposta != "sim"){
            break;
        }
       
    }

    for (int i = 0; i < cont; i++) {
        cout << "Produto           Preço        Quantidade " << endl;
        cout << Produto_[i].produto << "              " << Produto_[i].preco << "           " << Produto_[i].qtd  << endl;
        cout << "====================================================================" << endl;
    }

    return 0;
}