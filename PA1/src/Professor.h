/*
 *
 *  Created on: 8 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_PROFESSOR_H_
#define SRC_PROFESSOR_H_

#include "Pessoa.h"
#include "Auxiliary.h"
#include "Horario.h"

class Aula;

/**
* Classe Professor. Al&eacute;m dos par&acirc;metros herdados de Pessoa, Professor tem um vector de hor&aacute;rios relativo &agrave; sua disponibilidade.
**/

class Professor: public Pessoa {
private:
	/** Vector de hor&aacute;rios de um professor, indicando a sua disponibilidade para dar aulas. **/
	vector<Horario> disponibilidade;
public:

	/**
	* @brief Constructor de um professor.
	*
	* Constr&oacute;i um professor sem par&acirc;metros definidos.
	**/
	Professor();

	/**
	* @brief Construtor de um professor com dois par&acirc;metros.
	*
	* Constr&oacute;i um professor com o nome e idade definidos.
	*
	* @param nome Nome do professor a construir.
	* @param idade Idade do professor a construir.
	**/
	Professor(string nome, int idade);

	/**
	* @brief Construtor de um professor com tr&ecirc;s par&acirc;metros.
	*
	* Constr&oacute;i um professor com o ID, nome e idade definidos.
	*
	* @param id ID do professor a construir.
	* @param nome Nome do professor a construir.
	* @param idade Idade do professor a construir.
	**/
	Professor(int id, string nome, int idade);

	/**
	* @brief Construtor de um professor com tr&ecirc;s par&acirc;metros.
	*
	* Constr&oacute;i um professor com o ID, nome, idade e vector com a sua disponibilidade definidos.
	*
	* @param id ID do professor a construir.
	* @param nome Nome do professor a construir.
	* @param idade Idade do professor a construir.
	* @param disponibilidade Hor&aacute;rio em que o professor est&aacute; dispon&iacute;vel.
	**/
	Professor(int id, string nome, int idade, vector<Horario> disponibilidade);

	/**
	* @brief M&eacute;todo para aceder &agrave; informa&ccedil;&atilde;o de um certo professor.
	*
	* @return Retorna uma string com a informa&ccedil;&atilde;o do professor em quest&atilde;o.
	**/
	string getInformacao() const;

	/**
	* @brief Destructor de um professor.
	**/
	virtual ~Professor();

	/**
	* @brief M&eacute;todo para aceder &agrave; disponibilidade de um certo professor.
	*
	* @return Retorna um vector dos hor&aacute;rios dispon&iacute;veis do professor em quest&atilde;o.
	**/
	vector<Horario> getDisponibilidade() const;

	/**
	* @brief Operador para escrever um professor no ecr&atilde;.
	*
	* @param os Ostream para onde o professor vai ser escrito.
	* @param professor Professor a ser escrito na ostream.
	* @return Retorna uma string com o ID, numa nova linha nome e noutra a idade desse professor.
	**/
	friend ostream & operator<< (ostream &os, Professor * professor);
};

#endif /* SRC_PROFESSOR_H_ */
