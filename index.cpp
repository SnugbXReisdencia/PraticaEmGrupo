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
    // };

    return 0;
}