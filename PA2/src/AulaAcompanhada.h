/*
 * AulaAcompanhada.h
 *
 *  Created on: 23 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_AULAACOMPANHADA_H_
#define SRC_AULAACOMPANHADA_H_

#include "Aula.h"

 /**
 * Classe AulaAcompanhada. Al&eacute;m dos par&acirc;metros herdados da classe Aula, tem como par&acirc;metros um int com o pre&ccedil;o da aula e um professor encarregado.
 **/

class AulaAcompanhada: public Aula {
private:
	/** Pre&ccedil;o da aula acompanhada. **/
	unsigned int preco;

	/** Professor encarregado pela aula acompanhada. **/
	Professor * encarregado;

public:
	/**
	* @brief Constructor de uma aula acompanhada.
	*
	* @return Uma aula acompanhada sem par&acirc;metros definidos.
	**/
	AulaAcompanhada();

	/**
	* @brief Constructor de uma aula acompanhada com tr&ecirc;s par&acirc;metros.
	*
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula acompanhada.
	* @param horario_aula Horario com o hor&aacute;rio da aula acompanhada.
	* @param professor Professor encarregado pela aula acompanhada.
	**/

	AulaAcompanhada(string identificacao_aula, Horario horario_aula, Professor * professor);


	/**
	* @brief Constructor de uma aula acompanhada com cinco par&acirc;metros.
	*
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula acompanhada.
	* @param horario_aula Horario com o hor&aacute;rio da aula acompanhada.
	* @param utentes Vector de utentes participantes na aula acompanhada.
	* @param preco Pre&ccedil;o da aula acompanhada.
	* @param professor Professor encarregado pela aula acompanhada.
	**/
	AulaAcompanhada(string identificacao_aula, Horario horario_aula, vector<Utente *> utentes, unsigned int preco, Professor * professor );

	/**
	* @brief Constructor de uma aula acompanhada com quatro par&acirc;metros.
	*
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula acompanhada.
	* @param horario_aula Horario com o hor&aacute;rio da aula acompanhada.
	* @param utentes Vector de utentes participantes na aula acompanhada.
	* @param professor Professor encarregado pela aula acompanhada.
	**/
	AulaAcompanhada(string identificacao_aula, Horario horario_aula, vector<Utente *> utentes, Professor * professor );

	/**
	* @brief Destructor de uma aula acompanhada.
	**/
	virtual ~AulaAcompanhada();

	/**
	* @brief M&eacute;todo para aceder ao pre&ccedil;o de uma aula acompanhada.
	*
	* @return Retorna o pre&ccedil;o da aula em quest&atilde;o.
	**/
	unsigned int getPreco();

	/**
	* @brief M&eacute;todo para aceder ao professor de uma aula acompanhada.
	*
	* @return Retorna o professor da aula em quest&atilde;o.
	**/
	Professor * getEncarregado();

	/**
	* @brief Coloca uma aula acompanhada na forma de string.
	*
	* @return Retorna uma string com a aula acompanhada.
	**/
	string printAula();

	/**
	* @brief M&eacute;todo para estabelecer o professor de uma aula acompanhada.
	*
	* @param prof Professor encarregado da aula.
	**/
	void setProfessor (Professor * prof);

	/**
	* @brief M&eacute;todo para estabelecer o pre&ccedil;o de uma aula acompanhada.
	*
	* @param preco Pre&ccedil;o da aula acompanhada.
	**/
	void setPreco(unsigned int preco);

	/**
	* @brief Coloca uma despesa na forma de string.
	*
	* @return Retorna uma string com a despesa.
	**/
	string constroiDespesa();
};

#endif /* SRC_AULAACOMPANHADA_H_ */
