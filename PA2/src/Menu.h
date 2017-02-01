/*
 * Menu.h
 *
 *  Created on: 23 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_


#include "Auxiliary.h"
#include "Piscina.h"
#include "Interacao.h"


 /**
 * @brief Lista as op&ccedil;&otilde;es do menu inicial. Ramifica-se em sub-menus.
 *
 * @param piscina Piscina a ser utilizada.
 **/
void opcoesIniciais(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu de utentes.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesUtentes(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu de listar utentes.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesListarUtentes(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu de professores.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesProfessores(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu de listar professores.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesListarProfessores(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu de aulas.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesAulas(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu da piscina.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesPiscina(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu de listar aulas.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesListarAulas(Piscina & piscina);

/**
* @brief Op&ccedil;&otilde;es do menu inicial.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuInicial();

/**
* @brief Op&ccedil;&otilde;es do menu de utentes.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuUtentes();

/**
* @brief Op&ccedil;&otilde;es do menu de listar utentes.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuListarUtentes();

/**
* @brief Op&ccedil;&otilde;es do menu de professores.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuProfessores();

/**
* @brief Op&ccedil;&otilde;es do menu de listar professores.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuListarProfessores();

/**
* @brief Op&ccedil;&otilde;es do menu de aulas.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuAulas();

/**
* @brief Op&ccedil;&otilde;es do menu da piscina.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuPiscina();

/**
* @brief Op&ccedil;&otilde;es do menu de listar aulas.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuListarAulas();

/**
* @brief Lista as op&ccedil;&otilde;es do menu de despesas.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesDespesas(Piscina & piscina);

/**
* @brief Lista as op&ccedil;&otilde;es do menu de previs&otilde;es.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesPrevisoes(Piscina & piscina);

/**
* @brief Op&ccedil;&otilde;es do menu de despesas.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuDespesas();

/**
* @brief Op&ccedil;&otilde;es do menu de previs&otilde;es.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuPrevisoes();

/**
* @brief Lista as op&ccedil;&otilde;es do menu de encontrar a piscina mais pr&oacute;xima.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesEncontrar(Piscina & piscina);

/**
* @brief Op&ccedil;&otilde;es do menu de encontrar a piscina mais pr&oacute;xima.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuEncontrar();

/**
* @brief Lista as op&ccedil;&otilde;es do menu de utilizadores inactivos.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesIdle(Piscina & piscina);

/**
* @brief Op&ccedil;&otilde;es do menu de utilizadores inactivos.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuIdle();

/**
* @brief Lista as op&ccedil;&otilde;es do menu de loja da piscina.
*
* @param piscina Piscina a ser utilizada.
**/
void opcoesLoja(Piscina & piscina);

/**
* @brief Op&ccedil;&otilde;es do menu de loja da piscina.
*
* @return Retorna a op&ccedil;&atilde;o seleccionada se dentro dos limites definidos, caso contr&aacute;rio retorna 0.
**/
unsigned short int menuLoja();
#endif /* SRC_MENU_H_ */
