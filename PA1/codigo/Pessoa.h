/*
 * Pessoa.h
 *
 *  Created on: 8 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_PESSOA_H_
#define SRC_PESSOA_H_


#include "Auxiliary.h"

 /**
 * Classe Pessoa. Tem como par&acirc;metros o ID da pessoa, o seu nome e a sua idade. Tem como &uacute;ltimo par&acirc;metro um ID est&aacute;tico que se incrementa automaticamente.
 **/

class Pessoa {
protected:
	/** ID de uma pessoa **/
	int id;

	/** Nome de uma pessoa **/
	string nome;

	/** Idade de uma pessoa **/
	int idade;

	/** ID est&aacute;tico **/
	static int id_atual;
public:

	/**
	* @brief Constructor de uma pessoa.
	*
	* Constr&oacute;i uma pessoa sem par&acirc;metros definidos.
	**/
	Pessoa();

	/**
	* @brief Construtor de uma pessoa com dois par&acirc;metros.
	*
	* Constr&oacute;i uma pessoa com o nome e idade definidos.
	*
	* @param nome String com o nome da pessoa a ser constru&iacute;da.
	* @param idade Inteiro para a idade da pessoa a ser constru&iacute;da.
	**/
	Pessoa(string nome, int idade);

	/**
	* @brief Construtor de uma pessoa com tr&ecirc;s par&acirc;metros.
	*
	* Constr&oacute;i uma pessoa com o id, nome e idade definidos.
	*
	* @param id Inteiro com o ID da pessoa a ser constru&iacute;da.
	* @param nome String com o nome da pessoa a ser constru&iacute;da.
	* @param idade Inteiro para a idade da pessoa a ser constru&iacute;da.
	**/
	Pessoa(int id, string nome, int idade);

	/**
	* @brief Destructor de uma pessoa.
	*
	* Como Pessoa &eacute; herdado pelas classes Utente e Professor, este m&eacute;todo &eacute; virtual.
	**/
	virtual ~Pessoa();

	/**
	* @brief M&eacute;todo para aceder ao ID de uma certa pessoa.
	*
	* @return Retorna o ID da pessoa em quest&atilde;o.
	**/
	int getId() const;

	/**
	* @brief M&eacute;todo para aceder ao nome de uma certa pessoa.
	*
	* @return Retorna o nome da pessoa em quest&atilde;o.
	**/
	string getNome() const;

	/**
	* @brief M&eacute;todo para aceder &agrave; idade de uma certa pessoa.
	*
	* @return Retorna a idade da pessoa em quest&atilde;o.
	**/
	int getIdade() const;

	/**
	* @brief M&eacute;todo para estabelecer o nome de uma pessoa.
	*
	* @param nome Nome da pessoa.
	**/
	void setNome(string nome);

	/**
	* @brief M&eacute;todo para estabelecer a idade de uma pessoa.
	*
	* @param idade Idade da pessoa.
	**/
	void setIdade(int idade);

	/**
	* @brief M&eacute;todo para aceder &agrave; informa&ccedil;&atilde;o de uma certa pessoa (ID, nome e idade).
	*
	* @return Retorna uma string com ID, nome e idade da pessoa em quest&atilde;o.
	**/
	virtual string getInformacao() const;

	/**
	* @brief Operador para comparar se uma pessoa &eacute; igual a outra.
	*
	* @param pessoa Pessoa a ser comparada.
	* @return Retorna 'true' se os par&acirc;metros da primeira pessoa forem todos iguais aos par&acirc;metros da segunda pessoa. Caso contr&aacute;rio retorna 'false'.
	**/
	bool operator == (Pessoa * pessoa);

	/**
	* @brief Operador para escrever uma pessoa no ecr&atilde;.
	*
	* @param os Ostream para onde a pessoa vai ser escrita.
	* @param pessoa Pessoa a ser escrita na ostream.
	* @return Retorna uma string com ID, numa nova linha o nome e noutra linha a idade dessa pessoa.
	**/
	friend ostream & operator<< (ostream &os, Pessoa & pessoa);
};

#endif /* SRC_PESSOA_H_ */
