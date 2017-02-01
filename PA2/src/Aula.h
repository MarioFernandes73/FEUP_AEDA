/*
 * Aula.h
 *
 *  Created on: 8 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_AULA_H_
#define SRC_AULA_H_

#include "Auxiliary.h"
#include "Horario.h"
#include "Utente.h"
#include "Professor.h"

/**
* Classe Aula. Tem como par&acirc;metros uma string de identifica&ccedil;&atilde;o da aula, um hor&aacute;rio para a aula e um vector de utentes que participar&atilde;o na aula.
**/

class Aula {
private:
	/** String com a identifica&ccedil;&atilde;o da aula. **/
	string identificacao_aula;

	/** Hor&aacute;rio da aula. **/
	Horario horario_aula;

	/** Vector de utentes que participar&atilde;o na aula. **/
	vector<Utente *> utentes;

public:
	/**
	* @brief Constructor de uma aula.
	*
	* Constr&oacute;i uma aula sem par&acirc;metros definidos.
	**/
	Aula();

	/**
	* @brief Destructor de uma aula.
	*
	* Como Aula &eacute; herdado pelas classes AulaAcompanhada e AulaLivre, este m&eacute;todo &eacute; virtual.
	**/
	virtual ~Aula();

	/**
	* @brief Construtor de uma aula com dois par&acirc;metros.
	*
	* Constr&oacute;i uma aula com a identifica&ccedil;&atilde;o e hor&aacute;rio definidos.
	*
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula a ser constru&iacute;da.
	* @param horario_aula Horario para a aula a ser constru&iacute;da.
	**/
	Aula(string identificacao_aula, Horario horario_aula);

	/**
	* @brief Construtor de uma aula com tr&ecirc;s par&acirc;metros.
	*
	* Constr&oacute;i uma aula com a identifica&ccedil;&atilde;o, hor&aacute;rio e vector de utentes definidos.
	* 
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula a ser constru&iacute;da.
	* @param horario_aula Horario para a aula a ser constru&iacute;da.
	* @param utentes Vector de utentes com os utentes que participar&atilde;o na aula a ser constru&iacute;da.
	**/
	Aula(string identificacao_aula, Horario horario_aula, vector<Utente *> utentes);

	/**
	* @brief M&eacute;todo para aceder ao vector de utentes de uma certa aula.
	*
	* @return Retorna o vector de utentes da aula em quest&atilde;o.
	**/
	vector<Utente *> getUtentes() const;

	/**
	* @brief M&eacute;todo para aceder ao hor&aacute;rio de uma certa aula.
	*
	* @return Retorna o hor&aacute;rio da aula em quest&atilde;o.
	**/
	Horario getHorario() const;

	/**
	* @brief M&eacute;todo para aceder &agrave; identifica&ccedil;&atilde;o de uma certa aula.
	*
	* @return Retorna uma string com a identifica&ccedil;&atilde;o da aula em quest&atilde;o.
	**/
	string getIdentificacaoAula() const;

	/**
	* @brief M&eacute;todo para adicionar um utente a uma aula.
	*
	* @param ut Utente a adicionar &agrave; aula.
	**/
	void addUtente(Utente * ut);

	/**
	* @brief M&eacute;todo para remover um utente de uma aula.
	*
	* @param ut Utente a remover da aula.
	* @return Retorna 'true' se o cliente foi removido com sucesso. Retorna 'false' caso contr&aacute;rio.
	**/
	bool removeUtente(Utente * ut);

	/**
	* @brief M&eacute;todo para estabelecer a identifica&ccedil;&atilde;o de uma aula.
	*
	* @param identificacao_aula String com a identifica&ccedil;&atilde;o da aula.
	**/
	void setIdentificacaoAula(string identificacao_aula);

	/**
	* @brief M&eacute;todo para estabelecer o hor&aacute;rio de uma aula.
	*
	* @param horario_aula Hor&aacute;rio da aula.
	**/
	void setHorarioAula(Horario horario_aula);

	/**
	* @brief Operador para escrever uma aula no ecr&atilde;.
	*
	* @param os Ostream para onde a aula vai ser escrita.
	* @param aula Aula a ser escrita na ostream.
	* @return Retorna uma string com a identifica&ccedil;&atilde;o da aula e numa nova linha o hor&aacute;rio dessa aula.
	**/
	friend ostream & operator<< (ostream &os, Aula * aula);

	/**
	* @brief Coloca os IDs de utentes participantes de uma aula numa string.
	*
	* Percorre o vector de utentes e vai buscar o seu ID, colocando-o de seguida numa string.
	*
	* @return Retorna uma string com o ID dos utentes participantes numa aula.
	**/
	string parseUtentes();

	/**
	* @brief Imprime a informa&ccedil;&atilde;o de uma aula.
	*
	* Como a informa&ccedil;&atilde;o varia entre os diferentes tipos de aula, este m&eacute;todo &eacute; virtual.
	*
	* @return Impress&atilde;o da string da identifica&ccedil;&atilde;o da aula, seguido do seu hor&aacute;rio e os IDs dos utentes participantes.
	**/
	virtual string printAula();

	/**
	* @brief Retorna o professor encarregado pela aula. Apenas &uacute;til nas aulas acompanhadas.
	*
	* @return Professor encarregado pela aula.
	**/
	virtual Professor * getEncarregado(){return NULL;}

	/**
	* @brief M&eacute;todo para estabelecer o professor de uma aula. Apenas &uacute;til nas aulas acompanhadas.
	*
	* @param prof Professor da aula.
	**/
	virtual void setProfessor(Professor * prof){}

	/**
	* @brief M&eacute;todo para estabelecer o pre&ccedil;o de uma aula.
	*
	* @param preco Pre&ccedil;o da aula. Varia consoante o tipo de aula.
	**/
	virtual void setPreco(unsigned int preco){}

	/**
	* @brief Verifica se um utente pode ser adicionado a uma aula, verificando se o n&uacute;mero de utentes m&aacute;ximo numa aula foi atingido. Verifica tamb&eacute;m se o utente em questão j&aacute; estava inscrito na aula.
	*
	* @param ut Utente a verificar.
	* @return Retorna 'true' se o utente atingir as condi&ccedil;&otilde;es para se inscrever na aula. Caso contr&aacute;rio lan&ccedil;a uma excep&ccedil;&atilde;o.
	**/
	bool checkNovoUt(Utente * ut);

	/**
	* @brief M&eacute;todo para aceder ao pre&ccedil;o de uma certa aula livre.
	*
	* @return Retorna o pre&ccedil;o da aula em quest&atilde;o.
	**/
	virtual unsigned int getPreco(){return 0;}

	/**
	* @brief Coloca uma despesa na forma de string.
	*
	* @return Retorna uma string com a despesa.
	**/
	virtual string constroiDespesa(){return "";}
};

#endif /* SRC_AULA_H_ */
