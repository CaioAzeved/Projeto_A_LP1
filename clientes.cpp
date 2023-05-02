#include "onibus.hpp"

//Função que lista todos os ônibus existentes.
void listar2(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::cout << "Aqui está todos os ônibus:" << std::endl;
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        std::cout << nome[i] << " - " << onibus[nome[i]].terminal << std::endl;
    }
    std::cout << std::endl;
}
//Função que busca um ônibus específico usando o terminal.
void buscar_terminal2(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
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

//Função que consegue ver o itinerário de um ônibus específico usando o nome da linha
void ver(std::map <std::string,Onibus> onibus){
    std::string name;
    std::cout << "Insira o nome da linha:" << std::endl;
    std::cin >> name;
    std::cout << "Este é o itinerário do ônibus " << name << ":"<< std::endl;
    std::cout << onibus[name].itinerario << std::endl;
}

//Função para criar reclamações anônimas 
void reclamar(){
    std::fstream reclamacoes;
    std::string Data, rec;
    reclamacoes.open("Reclamações_anônimas.txt", std::ios::out | std::ios::app);
    std::cout << "Escreva a sua reclamação abaixo:" << std::endl;
    std::cout << "Informe a data:" << std::endl;
    std::getline(std::cin >> std::ws, Data);
    reclamacoes << Data << std::endl;
    std::cout << "Informe sua reclamação:" << std::endl;
    std::getline(std::cin >> std::ws, rec);
    reclamacoes << rec << std::endl;
    reclamacoes.close();
    std::cout << "Obrigado pelo feedback, iremos fazer o possível para melhorar." << std::endl;
}

//Função que irá mostrar o menu.

void menu_cli(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    int num;
    std::cout << "Digite um dos números para realizar uma das seguintes ações." << std::endl;
    while(true){
        std::cout << "1-Listar ônibus cadastrados." << std::endl;
        std::cout << "2-Buscar ônibus." << std::endl;
        std::cout << "3-Mostrar itininerário." << std::endl;
        std::cout << "4-Fazer uma reclamação." << std::endl;
        std::cout << "5-Encerrar." << std::endl;
        std::cin >> num;
        if(num == 1){
            std::cout << std::endl;
            listar2(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 2){
            std::cout << std::endl;
            buscar_terminal2(onibus, nome);
            std::cout << std::endl;
        }
        else if(num == 3){
            std::cout << std::endl;
            ver(onibus);
            std::cout << std::endl;
        }
        else if(num == 4){
            std::cout << std::endl;
            reclamar();
            std::cout << std::endl;
        }
        else{
            break;
        }
        std::cout << "Deseja realizar mais alguma ação?" << std::endl;
    }
}