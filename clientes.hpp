#include "onibus.hpp"

#ifndef _CLIENTES_HPP
#define _CLIENTES_HPP

//Função que lista todos os ônibus existentes.
void listar2(std::map <std::string,Onibus> onibus, std::vector<std::string> nome);

//Função que busca um ônibus específico usando o terminal.
void buscar_terminal2(std::map <std::string,Onibus> onibus, std::vector<std::string> nome);

//Função que consegue ver o itinerário de um ônibus específico usando o nome da linha
void ver(std::map <std::string,Onibus> onibus);

//Função para criar reclamações anônimas 
void reclamar();

//Função que irá mostrar o menu.

int menu_cli(std::map <std::string,Onibus> onibus, std::vector<std::string> nome);

#endif