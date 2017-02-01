/*
 * Data.h
 *
 *  Created on: 8 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include "Auxiliary.h"

 /**
 * Classe Data. Tem como par&acirc;metros um booleano (com valor default false e que verifica se a data est&aacute; escrita numa forma curta - hora e minutos - ou longa - todos os par&acirc;metros) e n&uacute;meros inteiros correspondentes ao ano, m&ecirc;s, dia, hora e minuto.
 **/

class Data {
private:
	/** Booleano que verifica se a data est&aacute; escrita numa forma curta - hora e minutos - ou longa - todos os par&acirc;metros) **/
	bool constant;

	/** Dia da data. **/
	unsigned int dia;

	/** M&ecirc;s da data. **/
	unsigned int mes;

	/** Ano da data. **/
	unsigned int ano;

	/** Hora da data. **/
	unsigned int hora;

	/** Minutos da data **/
	unsigned int minutos;
public:
	/**
	* @brief Constructor de uma data.
	*
	* Constr&oacute;i uma data sem par&acirc;metros definidos.
	**/
	Data();

	/**
	* @brief Constructor de uma aula a partir de uma string.
	*
	* Recebe uma string, verifica se os dados desta s&atilde;o v&aacute;lidos e define os par&acirc;metros da classe com informa&ccedil;&atilde;o contida na string, constru&iacute;ndo uma data completa.
	*
	* @param data String com uma data a ser lida pela fun&ccedil;&atilde;o.
	**/
	Data(string data);

	/**
	* @brief Constructor de uma aula com cinco par&acirc;metros definidos.
	*
	* @param ano Ano da data a ser constru&iacute;da.
	* @param mes M&ecirc;s da data a ser constru&iacute;da.
	* @param dia Dia da data a ser constru&iacute;da.
	* @param hora Hora da data a ser constru&iacute;da.
	* @param minutos Minutos da data a ser constru&iacute;da.
	**/
	Data(unsigned int ano, unsigned int mes, unsigned int dia, unsigned int hora, unsigned int minutos);

	/**
	* @brief Constructor de uma aula com tr&ecirc;s par&acirc;metros definidos.
	*
	* @param dia Dia da data a ser constru&iacute;da.
	* @param hora Hora da data a ser constru&iacute;da.
	* @param minutos Minutos da data a ser constru&iacute;da.
	**/
	Data(unsigned int dia, unsigned int hora, unsigned int minutos);

	/**
	* @brief M&eacute;todo para aceder ao dia de uma certa data.
	*
	* @return Retorna o dia da data em quest&atilde;o.
	**/
	unsigned int getDia() const;

	/**
	* @brief M&eacute;todo para aceder ao m&ecirc;s de uma certa data.
	*
	* @return Retorna o m&ecirc;s da data em quest&atilde;o.
	**/
	unsigned int getMes() const;

	/**
	* @brief M&eacute;todo para aceder ao ano de uma certa data.
	*
	* @return Retorna o ano da data em quest&atilde;o.
	**/
	unsigned int getAno() const;

	/**
	* @brief M&eacute;todo para aceder &agrave; hora de uma certa data.
	*
	* @return Retorna a hora da data em quest&atilde;o.
	**/
	unsigned int getHora() const;

	/**
	* @brief M&eacute;todo para aceder aos minutos de uma certa data.
	*
	* @return Retorna os minutos da data em quest&atilde;o.
	**/
	unsigned int getMinutos() const;

	/**
	* @brief M&eacute;todo para aceder ao booleano de uma certa data.
	*
	* @return Retorna o booleano da data em quest&atilde;o.
	**/
	bool getConstant() const;

	/**
	 * @brief M&eacute;todo que converte uma data num n&uacute;mero inteiro.
	 *
	 * @return Retorna data em quest&atilde;o.
	 **/
	unsigned int convertDays();

	/**
	* @brief M&eacute;todo para estabelecer uma data em modo curto (com dia, hora e minutos).
	*
	* @param dia Dia a estabelecer da data.
	* @param hora Hora a estabelecer da data.
	* @param minutos Minutos a estabelecer da data.
	**/
	void setDataParc(unsigned int dia, unsigned int hora, unsigned int minutos);

	/**
	* @brief M&eacute;todo para estabelecer uma data em modo longo (ano, m&ecirc;s, dia, hora, minutos).
	*
	* @param dia Dia a estabelecer da data.
	* @param mes M&ecirc;s a estabelecer da data.
	* @param ano Ano a estabelecer da data.
	* @param hora Hora a estabelecer da data.
	* @param minutos Minutos a estabelecer da data.
	**/
	void setDataTot(unsigned int dia, unsigned int mes, unsigned int ano, unsigned int hora, unsigned int minutos);

	/**
	* @brief Operador para escrever uma data no ecr&atilde;.
	*
	* @param os Ostream para onde a aula vai ser escrita.
	* @param data Data a ser escrita na ostream.
	* @return Se o booleano for 'true', imprime a hora e os minutos de uma data, caso contr&aacute;rio, imprime o ano, seguido de m&ecirc;s, dia, hora e minutos de uma data.
	**/
	friend ostream& operator<<(ostream &os, Data data);

	/**
	* @brief Operador para comparar se uma data &eacute; menor que outra.
	*
	* @param data Primeira data a ser comparada.
	* @param data2 Segunda data a ser comparada.
	* @return Retorna 'true' se a primeira data for menor (mais antiga) que a segunda data. Caso contr&aacute;rio retorna 'false'.
	**/
	friend bool operator<(const Data & data, const Data & data2);

	/**
	* @brief Operador para comparar se uma data &eacute; igual a outra.
	*
	* @param data Primeira data a ser comparada.
	* @param data2 Segunda data a ser comparada.
	* @return Retorna 'true' se os par&acirc;metros da primeira data forem todos iguais aos par&acirc;metros da segunda data. Caso contr&aacute;rio retorna 'false'.
	**/
	friend bool operator==(const Data & data, const Data & data2);

	/**
	* @brief Operador para comparar se uma data &eacute; igual a outra.
	*
	* @param data Primeira data a ser comparada.
	* @param data2 Segunda data a ser comparada.
	* @return Retorna 'true' se as horas e minutos da primeira data forem todos iguais da segunda data. Caso contr&aacute;rio retorna 'false'.
	**/
	friend bool compareShortData(const Data & data, const Data & data2);

	/**
	* @brief Destructor de uma data.
	**/
	virtual ~Data();

	/**
	* @brief Coloca uma data na forma de string.
	*
	* @return Retorna uma string com a data.
	**/
	string printData();
};

#endif /* SRC_DATA_H_ */
