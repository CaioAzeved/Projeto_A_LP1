#include "onibus.hpp"

#ifndef _ADMIN_HPP
#define _ADMIN_HPP

//Função que lista todos os ônibus existentes.

void listar(std::map <std::string,Onibus> onibus, std::vector<std::string> nome);

//Função que busca um ônibus especificando a sua linha.
void buscar_linha(std::map <std::string,Onibus> onibus);

//Função que busca um ônibus específico usando o terminal.
void buscar_terminal(std::map <std::string,Onibus> onibus, std::vector<std::string> nome);

//Função que atualiza o terminal de um ônibus.
void atualizar_terminal(std::map <std::string,Onibus> &onibus, std::vector<std::string> nome);

//Função que atualiza o itinerário de um ônibus.
void atualizar_itinerario(std::map <std::string,Onibus> &onibus, std::vector<std::string> nome);

//Função que exclui um ônibus.
void excluir(std::map <std::string,Onibus> &onibus, std::vector<std::string> &nome);

//Função que lista as reclamações.
void listar_reclamacoes();

//Função responsável por mostrar o menu de opções que o admin tem.
int menu_adm(std::map <std::string,Onibus> onibus, std::vector<std::string> nome);

#endif