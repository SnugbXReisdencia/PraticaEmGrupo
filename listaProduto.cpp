

//recebe um vetor de struct produto  e o tamanho do vetor

void listaProdutos(Produto produtos[], int tamanho) {
    cout << "Produto           Preço        Quantidade " << endl << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << produtos[i].produto << "              " << produtos[i].preco << "           " << produtos[i].qtd << endl;
    }
    cout << "====================================================================" << endl;
}