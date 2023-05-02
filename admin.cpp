#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "onibus.hpp"

//Função que lista todos os ônibus existentes.
void listar(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::cout << "Aqui está todos os ônibus:" << std::endl;
    std::fstream arquivo_ler;
    std::string linha;
    arquivo_ler.open("Ônibus.txt", std::ios::in);
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        std::cout << nome[i] << std::endl;
        std::cout << onibus[nome[i]].terminal << std::endl;
    }
}


//Função que busca um ônibus especificando a sua linha.
void buscar_linha(std::map <std::string,Onibus> onibus){
    std::string name;
    std::cout << "Insira o nome da linha:" << std::endl;
    std::cin >> name;
    std::cout << onibus[name].terminal << std::endl;
}
//Função que busca um ônibus específico usando o terminal.
void buscar_terminal(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::string term;
    std::cout << "Insira um terminal:" << std::endl;
    std::cin >> term;
    for(unsigned long long int i{0}; i < nome.size(); ++i){
        if(onibus[nome[i]].terminal == term){
            std::cout << nome[i] << std::endl;
        }
    }
}


//Função que atualiza o terminal de um ônibus.
void atualizar_terminal(std::map <std::string,Onibus> &onibus, std::vector<std::string> nome){
    std::string name, termi;
    std::cout << "Insira o nome da linha:" << std::endl;
    std::cin >> name;
    std::cout << "Insira o novo terminal dessa linha:" << std::endl;
    std::cin >> termi;
    onibus[name].terminal = termi;
}

//Função que atualiza o itinerário de um ônibus.
void atualizar_itinerario(std::map <std::string,Onibus> &onibus, std::vector<std::string> nome){
    std::string name, iti;
    std::cout << "Insira o nome da linha:" << std::endl;
    std::cin >> name;
    std::cout << "Insira o novo itinerário dessa linha:" << std::endl;
    std::getline(std::cin >> std::ws, iti);
    onibus[name].itinerario = iti;
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

int menu_adm(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    int num;
    std::cout << "Digite um dos números para realizar uma das seguintes ações." << std::endl;
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
        listar(onibus, nome);
    }
    else if(num == 2){
        buscar_linha(onibus);
    }
    else if(num == 3){
        buscar_terminal(onibus, nome);
    }
    else if(num == 4){
        atualizar_terminal(onibus, nome);
    }
    else if(num == 5){
        atualizar_itinerario(onibus, nome);
    }
    else if(num == 6){
        excluir(onibus, nome);
    }
    else if(num == 7){
        listar_reclamacoes();
    }
    else{
        return num;
    }
    return 0;
}