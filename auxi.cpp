#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "onibus.hpp"

//função feita para ler o arquivo de ônibus.

void ler(std::map<std::string, Onibus> &onibus, std::vector<std::string> &nome){
    std::vector <std::string> temp;
    std::fstream arquivo_ler;
    std::string linha;
    int j = 0;
    arquivo_ler.open("Ônibus.txt", std::ios::in);
    while(std::getline(arquivo_ler, linha)){
        temp.push_back(linha);
    }
    arquivo_ler.close();
    for(unsigned long long int i = 0; i < temp.size(); i+=3){
        nome[j] = temp[i];
        onibus[nome[j]].terminal = temp[i+1];
        onibus[nome[j]].itinerario = temp[i+2];
        ++j;
    }
}

//Função feita para sob_escrever o arquivo original sempre que um ônibus seja deletado

void sob_escrever(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::fstream excluir;
    excluir.open("Ônibus.txt", std::ios::out);
    for(int i = 0; nome.size(); ++i){
        excluir << nome[i] << std::endl;
        excluir << onibus[nome[i]].terminal << std::endl;
        excluir << onibus[nome[i]].itinerario << std::endl;
    } 
    excluir.close();
    
}