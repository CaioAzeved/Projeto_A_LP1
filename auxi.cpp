#include "onibus.hpp"

//função feita para ler o arquivo de ônibus.

void ler(std::map<std::string, Onibus> &onibus, std::vector<std::string> &nome){
    std::vector <std::string> temp{}; //string temporária
    std::fstream arquivo_ler;
    std::string linha;
    int j = 0;
    arquivo_ler.open("onibus.txt", std::ios::in);
    while(std::getline(arquivo_ler, linha)){
        temp.push_back(linha);
    }
    arquivo_ler.close();
    for(unsigned long long int i = 0; i < temp.size(); i+=3){
        nome.push_back(temp[i]);
        onibus[nome[j]].terminal = temp[i+1];
        onibus[nome[j]].itinerario = temp[i+2];
        ++j;
    }
}

//Função feita para sobrescrever o arquivo original sempre que um ônibus seja deletado

void sobrescrever(std::map <std::string,Onibus> onibus, std::vector<std::string> nome){
    std::fstream excluir;
    excluir.open("onibus.txt", std::ios::out);
    for(unsigned long long int i = 0; i < nome.size(); ++i){
        excluir << nome[i] << std::endl;
        excluir << onibus[nome[i]].terminal << std::endl;
        excluir << onibus[nome[i]].itinerario << std::endl;
    } 
    excluir.close();
}