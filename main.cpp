#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "admin.hpp"
#include "clientes.hpp"
#include "auxi.hpp"
#include "onibus.hpp"

int main() {
    int control = 0; //variável de controle para encerrar os menus.
    char id; //variável para identificar se é cliente ou administrador.
    std::string senha; //variável para pegar a senha solicitada para a entrada do administrador.
    std::map <std::string,Onibus> map_onibus {}; //variável criada para salvar as informações de todos os ônibus.
    std::vector<std::string> nome {};
    while(true){
        ler(map_onibus, nome);
        std::cout << "Identifique-se!" << std::endl;
        std::cout << "Digite C se for cliente e A se for administrador." << std::endl;
        std::cin >> id;
        if((id == 'C') || (id == 'c')){
            control = menu_cli(map_onibus, nome);
            if(control != 0){
                break;
            }
        }
        else if((id == 'A') || (id == 'a')){
            std::cout << "Insira a senha" << std::endl;
            std::cin >> senha;
            if(senha == "admin"){
                //control = menu_adm(map_onibus, nome);
                //sob_escrever(map_onibus, nome);
                if(control != 0){
                    break;
                }
            }
            else{
                std::cout << "Acesso negado!" << std::endl;
                break;
            }
        }
    }
    return 0;
}