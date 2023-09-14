# include <iostream>
# include <locale>

using namespace std;

int main(){
    // Verifica o sistema operacional para não dar erro 
    if (system("echo hello") == 0)
    {
        locale::global(locale(""));
        system("clear");
    }else{
        setlocale(LC_ALL, "Portuguese");
        system("cls");
    }
    
    return 0;
}