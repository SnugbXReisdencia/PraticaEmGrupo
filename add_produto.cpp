#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Produto{
    string produto;
    int qtd=0;
    double preco=0.0;

};

void add_produto( std::vector<Produto>& produtos){
        Produto novo_produto;

        char resposta;
        int cont = 0;

        do{
            cont++;
            std::cout << " Digite o nome do produto: " << endl;
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

    vector <Produto> produtos;

    add_produto(produtos);

    return 0;
}