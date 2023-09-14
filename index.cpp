#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    vector<string> vec;

    struct Produto{
        string produto[100];
        int qtd[100];
    };
    
    // criar função dentro do struct, 
    //     struct Produto{
    //     string produto[100];
    //     int qtd[100];
    //     void add_procuto(nome, qtd );
    // produto1:: add_procuto(nome, qtd );
    // Produto pro1
    // pro1.add_procuto(produto, qtd);
    // };

    return 0;
}