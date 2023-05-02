#include "onibus.hpp"
#ifndef _AUXI_HPP
#define _AUXI_HPP

//Função feita para ler o arquivo de ônibus.
void ler(std::map<std::string, Onibus> &onibus, std::vector<std::string> &nome);

//Função feita para sob_escrever o arquivo original sempre que um ônibus seja deletado
void sobrescrever(std::map <std::string,Onibus> onibus, std::vector<std::string> nome);

#endif