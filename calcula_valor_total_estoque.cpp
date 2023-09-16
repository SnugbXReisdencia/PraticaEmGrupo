//Função que recebe os produtos do estoque e retorna o valor total somado dos protutos cadastrados.

double calcularValorTotalEstoque(Produto *produtos){
    double valorTotal = 0;

    for(int i = 0; i < quantidade; i++){
        valorTotal += produtos[i].preco * produtos[i].qtd;
    }

    return valorTotal;
}