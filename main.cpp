#include "admin.hpp"
#include "clientes.hpp"
#include "auxi.hpp"
#include "onibus.hpp"

int main() {
    char id; //variável para identificar se é cliente ou administrador.
    std::string senha; //variável para pegar a senha solicitada para a entrada do administrador.
    std::map <std::string, Onibus> map_onibus; //variável criada para salvar as informações de todos os ônibus.
    std::vector<std::string> nome;
    std::cout << "Identifique-se!" << std::endl;
    std::cout << "Digite C se for cliente e A se for administrador." << std::endl;
    while(true){
        ler(map_onibus, nome);
        std::cin >> id;
        if((id == 'C') || (id == 'c')){
            menu_cli(map_onibus, nome);
        }
        else if((id == 'A') || (id == 'a')){
            std::cout << "Insira a senha" << std::endl;
            std::cin >> senha;
            if(senha == "admin"){
                menu_adm(map_onibus, nome);
            }
            else{
                std::cout << "Acesso negado!" << std::endl;
                break;
            }
        }
        std::cout << "Atè a próxima!" << std::endl;
        break;
    }
    return 0;
}