#include "onibus.hpp"
#include "auxi.hpp"

//Função que lista todos os ônibus existentes.
void listar(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::cout << "Aqui está todos os ônibus:" << std::endl;
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        std::cout << nome[i] << " - " << onibus[nome[i]].terminal << std::endl;
    }
    std::cout << std::endl;
}


//Função que busca um ônibus especificando o nome da sua linha.
void buscar_linha(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::string name;
    int fail = 0;
    std::cout << "Insira o nome da linha:" << std::endl;
    std::getline(std::cin >> std::ws, name);
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        if(nome[i] == name){
            fail = 1;
        }
    }
    if(fail != 1){
        std::cout << "Está linha não existe, tente novamente." << std::endl;
    }
    else{
        std::cout << onibus[name].terminal << std::endl;
        std::cout << onibus[name].itinerario << std::endl;
    }
}
//Função que busca um ônibus específico usando o terminal.
void buscar_terminal(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::string term;
    int fail = 0;
    std::cout << "Insira um terminal:" << std::endl;
    std::getline(std::cin >> std::ws, term);
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        if(onibus[nome[i]].terminal == term){
            std::cout << nome[i] << std::endl;
            fail = 1;
        }
    }
    if(fail != 1){
        std::cout << "Terminal inválido." << std::endl;
    }
}


//Função que atualiza o terminal de um ônibus.
void atualizar_terminal(std::map <std::string,Onibus> &onibus, std::vector<std::string> nome){
    std::string name, termi;
    int fail = 0;
    std::cout << "Insira o nome da linha:" << std::endl;
    std::cin >> name;
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        if(nome[i] == name){
            fail = 1;
        }
    }
    if(fail != 1){
        std::cout << "Está linha não existe, tente novamente." << std::endl;
    }
    else{
        std::cout << "Insira o novo terminal dessa linha:" << std::endl;
        std::getline(std::cin >> std::ws, termi);
        onibus[name].terminal = termi;
        sobrescrever(onibus, nome);
    }
}

//Função que atualiza o itinerário de um ônibus.
void atualizar_itinerario(std::map <std::string,Onibus> &onibus, std::vector<std::string> nome){
    std::string name, iti;
    int fail;
    std::cout << "Insira o nome da linha:" << std::endl;
    std::cin >> name;
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        if(nome[i] == name){
            fail = 1;
        }
    }
    if(fail != 1){
        std::cout << "Está linha não existe, tente novamente." << std::endl;
    }
    else{
        std::cout << "Insira o novo itinerário dessa linha:" << std::endl;
        std::getline(std::cin >> std::ws, iti);
        onibus[name].itinerario = iti;
        sobrescrever(onibus, nome);
    }
}

//Função que exclui um ônibus.
void excluir(std::map <std::string,Onibus> &onibus, std::vector<std::string> &nome){
    std::string destroy;
    std::cout << "Diga o nome do ônibus que deseja excluir" << std::endl;
    std::cin >> destroy;
    onibus.erase(destroy);
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        if(nome[i] == destroy){
            nome.erase(nome.end() - nome.size() +i);
        }
    }
    sobrescrever(onibus, nome);
}

//Função que lista as reclamações.
void listar_reclamacoes(){
    std::string linha;
    std::fstream reclamacoes;
    reclamacoes.open("Reclamações_anônimas.txt", std::ios::in | std::ios::app);
    while(std::getline(reclamacoes,linha)){
        std::cout << linha << std::endl;
    }
    reclamacoes.close();
}

//Função responsável por mostrar o menu de opções que o admin tem.

void menu_adm(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    int num;
    std::cout << "Digite um dos números para realizar uma das seguintes ações." << std::endl;
    while(true){
        std::cout << "1-Listar ônibus cadastrados." << std::endl;
        std::cout << "2-Buscar ônibus pela linha." << std::endl;
        std::cout << "3-Buscar ônibus pelo terminal." << std::endl;
        std::cout << "4-Atualizar o terminal." << std::endl;
        std::cout << "5-Atualizar o itinerário." << std::endl;
        std::cout << "6-Excluir ônibus" << std::endl;
        std::cout << "7-Listar reclamações." << std::endl;
        std::cout << "8-Encerrar." << std::endl;
        std::cin >> num;
        if(num == 1){
            std::cout << std::endl;
            listar(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 2){
            std::cout << std::endl;
            buscar_linha(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 3){
            std::cout << std::endl;
            buscar_terminal(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 4){
            std::cout << std::endl;
            atualizar_terminal(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 5){
            std::cout << std::endl;
            atualizar_itinerario(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 6){
            std::cout << std::endl;
            excluir(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 7){
            std::cout << std::endl;
            listar_reclamacoes();
            std::cout << std::endl;
        }
        else{
            break;
        }
        std::cout << "Deseja realizar mais alguma ação?" << std::endl;
    }
}