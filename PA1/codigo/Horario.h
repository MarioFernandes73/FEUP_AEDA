/*
 * Horario.h
 *
 *  Created on: 8 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_HORARIO_H_
#define SRC_HORARIO_H_

#include "Auxiliary.h"
#include "Data.h"

 /**
 * Classe Horario. Tem como par&acirc;metros um ID correspondente a um dia da semana, uma string com o dia da semana, uma Data inicial e outra final.
 **/

class Horario {
private:
	/** ID do hor&aacute;rio. **/
	int id;

	/** String com o dia da semana do hor&aacute;rio. **/
	string dia_semana;

	/** Data inicial. **/
	Data inicial;

	/** Data final **/
	Data final;
public:
	/**
	* @brief Constructor de um hor&aacute;rio.
	*
	* Constr&oacute;i um hor&aacute;rio sem par&acirc;metros definidos.
	**/
	Horario();

	/**
	* @brief Constructor de um hor&aacute;rio com dois par&acirc;metros.
	*
	* Constr&oacute;i um hor&aacute;rio com uma data de in&iacute;cio e outra de fim.
	*
	* @param inicial Data inicial.
	* @param final Data final.
	**/
	Horario(Data inicial, Data final);

	/**
	* @brief Constructor de um hor&aacute;rio com tr&ecirc;s par&acirc;metros.
	*
	* Constr&oacute;i um hor&aacute;rio com um ID, uma data de in&iacute;cio e outra de fim. Essas datas est&atilde;o numa string, ser&atilde;o interpretadas e os devidos par&acirc;metros ser&atilde;o definidos.
	*
	* @param id Inteiro com o ID do dia da semana (1 = domingo, 7 = s&aacute;bado).
	* @param inicio String com uma data inicial.
	* @param fim String com uma data final.
	**/
	Horario(int id, string inicio, string fim);

	/**
	* @brief Constructor de um hor&aacute;rio com tr&ecirc;s par&acirc;metros.
	*
	* Constr&oacute;i um hor&aacute;rio com uma string do dia da semana, uma data de in&iacute;cio e outra de fim. Essas datas est&atilde;o numa string, ser&atilde;o interpretadas e os devidos par&acirc;metros ser&atilde;o definidos.
	*
	* @param dia_semana String com o dia da semana.
	* @param inicio String com uma data inicial.
	* @param fim String com uma data final.
	**/
	Horario(string dia_semana, string inicio, string fim);

	/**
	* @brief M&eacute;todo para aceder ao ID do dia da semana de um certo hor&aacute;rio.
	*
	* @return Retorna um inteiro com o ID do dia da semana do hor&aacute;rio em quest&atilde;o.
	**/
	int getId() const;

	/**
	* @brief M&eacute;todo para aceder &agrave; string do dia da semana de um certo hor&aacute;rio.
	*
	* @return Retorna uma string com o dia da semana do hor&aacute;rio em quest&atilde;o.
	**/
	string getDia_semana()const;

	/**
	* @brief M&eacute;todo para aceder &agrave; data inicial de um certo hor&aacute;rio.
	*
	* @return Retorna a data inicial do hor&aacute;rio em quest&atilde;o.
	**/
	Data getInicial()const;

	/**
	* @brief M&eacute;todo para aceder &agrave; data final de um certo hor&aacute;rio.
	*
	* @return Retorna a data final do hor&aacute;rio em quest&atilde;o.
	**/
	Data getFinal()const;

	/**
	* @brief M&eacute;todo para estabelecer o dia da semana de um hor&aacute;rio.
	*
	* @param dia_semana String com o dia da semana do hor&aacute;rio.
	**/
	void setDia_semana(string dia_semana);

	/**
	* @brief M&eacute;todo para estabelecer a data inicial de um hor&aacute;rio.
	*
	* @param inicial Data inicial do hor&aacute;rio.
	**/
	void setInicial(Data inicial);

	/**
	* @brief M&eacute;todo para estabelecer a data final de um hor&aacute;rio.
	*
	* @param final Data final do hor&aacute;rio.
	**/
	void setFinal(Data final);

	/**
	* @brief Destructor de um hor&aacute;rio.
	**/
	virtual ~Horario();

	/**
	* @brief Operador para comparar se um hor&aacute;rio &eacute; igual a outro.
	*
	* @param horario Primeiro hor&aacute;rio a ser comparado.
	* @param horario2 Segundo hor&aacute;rio a ser comparado.
	* @return Retorna 'true' se os par&acirc;metros do primeiro hor&aacute;rio forem todos iguais aos par&acirc;metros do segundo hor&aacute;rio. Caso contr&aacute;rio retorna 'false'.
	**/
	friend bool operator==(const Horario & horario, const Horario & horario2);

	bool operator<(Horario horario);

	/**
	* @brief Operador para escrever um hor&aacute;rio no ecr&atilde;.
	*
	* @param os Ostream para onde a aula vai ser escrita.
	* @param hor Hor&aacute;rio a ser escrito na ostream.
	* @return Retorna uma impress&atilde;o com o dia da semana, numa nova linha a data inicial e noutra a data final.
	**/
	friend ostream & operator<<(ostream &os, Horario hor);

	/**
	* @brief Coloca um hor&aacute;rio na forma de string.
	*
	* @return Retorna uma string com o hor&aacute;rio.
	**/
	string printHorario();
};

/**
* @brief Verifica se dois hor&aacute;rios s&atilde;o compat&iacute;veis.
*
* @param horario1 Horario a ser comparado.
* @param horario_a_verificar Horario a comparar.
* @return Retorna 'true' se os hor&aacute;rios forem compat&iacute;veis, 'false' caso contr&aacute;rio.
**/
bool verifyHorarioCompativel(Horario horario1, Horario horario_a_verificar);

/**
* @brief Verifica se dois hor&aacute;rios de duas aulas s&atilde;o compat&iacute;veis.
*
* @param horario1 Horario a ser comparado.
* @param horario_a_verificar Horario a comparar.
* @return Retorna 'true' se os hor&aacute;rios das aulas forem compat&iacute;veis, 'false' caso contr&aacute;rio.
**/
bool verifyAulaNaoCompativel(Horario horario1, Horario horario_a_verificar);

#endif /* SRC_HORARIO_H_ */
