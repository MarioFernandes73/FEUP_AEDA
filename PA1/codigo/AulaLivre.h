/*
 * AulaLivre.h
 *
 *  Created on: 23 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_AULALIVRE_H_
#define SRC_AULALIVRE_H_

#include "Aula.h"

 /**
 * Classe AulaLivre. Al&eacute;m dos par&acirc;metros herdados da classe Aula, tem como par&acirc;metros um inteiro constante correspondente ao pre&ccedil;o da aula livre.
 **/

class AulaLivre: public Aula {
private:
	/** Pre&ccedil;o da aula livre. **/
	const unsigned int preco=10;
public:
	/**
	* @brief Constructor de uma aula livre sem par&acirc;metros.
	**/
	AulaLivre();

	/**
	* @brief Construtor de uma aula livre com dois par&acirc;metros.
	*
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula a ser constru&iacute;da.
	* @param horario_aula Horario para a aula a ser constru&iacute;da.
	**/
	AulaLivre(string identificacao_aula, Horario horario_aula);

	/**
	* @brief Construtor de uma aula livre com tr&ecirc;s par&acirc;metros.
	*
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula a ser constru&iacute;da.
	* @param horario_aula Horario para a aula a ser constru&iacute;da.
	* @param utentes Vector de utentes com os utentes que participar&atilde;o na aula livre a ser constru&iacute;da.
	**/
	AulaLivre(string identificacao_aula, Horario horario_aula, vector <Utente *> utentes);

	/**
	* @brief Destrutor de uma aula livre.
	**/
	virtual ~AulaLivre();

	/**
	* @brief M&eacute;todo para aceder ao pre&ccedil;o de uma certa aula livre.
	*
	* @return Retorna o pre&ccedil;o da aula em quest&atilde;o.
	**/
	const unsigned int getPreco()const;

	/**
	* @brief Coloca uma despesa na forma de string.
	*
	* @return Retorna uma string com a despesa.
	**/
	string constroiDespesa();
};

#endif /* SRC_AULALIVRE_H_ */
