#include "admin.hpp"
#include "clientes.hpp"
#include "auxi.hpp"
#include "onibus.hpp"

int main() {
    char id, confirm = 'Y'; //variável para identificar se é cliente ou administrador / variável criada para confirmação de permanecer no sistema.
    std::string senha; //variável para pegar a senha solicitada para a entrada do administrador.
    std::map <std::string, Onibus> map_onibus; //variável criada para salvar as informações de todos os ônibus.
    std::vector<std::string> nome; //variável criada para salvar os nomes das linhas dos ônibus.
    std::cout << "Identifique-se!" << std::endl;
    while(true){
        if((confirm == 'Y') || (confirm == 'y')){
            std::cout << "Digite C se for cliente e A se for administrador." << std::endl;
        }
        else{
            std::cout << "Até a próxima!" << std::endl;
            break;
        }
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
        std::cout << "Deseja retornar para a identificação? [Y/N]" << std::endl;
        std::cin >> confirm;
    }
    return 0;
}