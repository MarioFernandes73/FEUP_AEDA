/*
 * Utente.h
 *
 *  Created on: 8 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_UTENTE_H_
#define SRC_UTENTE_H_

#include "Pessoa.h"
#include "Auxiliary.h"

class Aula;

/**
* Classe Utente. Al&eacute;m dos par&acirc;metros herdados de Pessoa, Utente tem um n&uacute;mero correspondente ao seu saldo e um vector com as despesas relativas &agrave;s aulas em que participou.
**/

class Utente: public Pessoa {
private:
	/** Saldo do utente. &Eacute; utilizado para pagar aulas. **/
	int saldo;

	/** Vector com as despesas do utente **/
	vector<string> despesas;
public:

	/**
	* @brief Constructor de um utente.
	*
	* Constr&oacute;i um utente sem par&acirc;metros definidos.
	**/
	Utente();

	/**
	* @brief Constructor de um utente com um par&acirc;metro.
	*
	* Constr&oacute;i um utente com ID definido.
	*
	* @param id ID do utente a construir.
	**/
	Utente(int id);

	/**
	* @brief Constructor de um utente com dois par&acirc;metros.
	*
	* Constr&oacute;i um utente com nome e idade definidos.
	*
	* @param nome Nome do utente a construir.
	* @param idade Idade do utente a construir.
	**/
	Utente(string nome, int idade);

	/**
	* @brief Constructor de um utente com cinco par&acirc;metros.
	*
	* Constr&oacute;i um utente com ID, nome, idade, saldo e despesas definidos.
	*
	* @param id ID do utente a construir.
	* @param nome Nome do utente a construir.
	* @param idade Idade do utente a construir.
	* @param saldo Saldo do utente a construir.
	* @param textos String com as despesas do utente a construir.
	**/
	Utente(int id, string nome, int idade, int saldo, vector<string> textos);

	/**
	* @brief Destructor de um utente.
	**/
	virtual ~Utente();

	/**
	* @brief M&eacute;todo para aceder ao saldo de um certo utente.
	*
	* @return Retorna o saldo do utente em quest&atilde;o.
	**/
	int getSaldo() const;

	vector<string> getDespesas() const;

	/**
	* @brief M&eacute;todo para aceder &agrave; informa&ccedil;&atilde;o de um certo utente.
	*
	* @return Retorna uma string com a informa&ccedil;&atilde;o do utente em quest&atilde;o.
	**/
	string getInformacao() const;


	/**
	* @brief Operador para escrever um utente no ecr&atilde;.
	*
	* @param os Ostream para onde o utente vai ser escrito.
	* @param ut Utente a ser escrito na ostream.
	* @return Retorna uma string com o ID, numa nova linha nome, noutra a idade e numa &uacute;ltima o saldo desse utente.
	**/
	friend ostream & operator<< (ostream &os, Utente * ut);

	/**
	* @brief Adiciona saldo a um utente.
	*
	* @param valor Saldo a adicionar ao utente.
	**/
	void acrescentarSaldo(int valor);

	/**
	* @brief Retira saldo a um utente.
	*
	* @param valor Saldo a retirar ao utente.
	**/
	void retirarSaldo(int valor);

	/**
	* @brief Envia uma despesa do utente para o vector das despesas.
	*
	* @param despesa String da despesa a ser enviada para o vector das despesas do utente.
	**/
	void pushDespesa(string despesa);
};

#endif /* SRC_UTENTE_H_ */
