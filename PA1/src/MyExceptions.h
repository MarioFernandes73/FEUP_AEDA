/*
 * MyExceptions.h
 *
 *  Created on: 20 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_MYEXCEPTIONS_H_
#define SRC_MYEXCEPTIONS_H_

#include <vector>
#include <string>

using namespace std;

/**
* Classe InsertVectorException. Tem como par&acirc;metros um vector de elementos compar&aacute;veis e um elemento compar&aacute;vel.
*
* &Eacute; chamada quando um elemento j&aacute; se encontra num vector.
**/

template <class Comparable>  class InsertVectorException {
private:
	/** Vector de elementos compar&aacute;veis. **/
	vector<Comparable> my_vector;

	/** Elemento compar&aacute;vel. **/
	Comparable element;
public:
	/**
	* @brief Constructor de uma InsertVectorException.
	*
	* Constr&oacute;i uma InsertVectorException sem par&acirc;metros definidos.
	**/
	InsertVectorException(){}

	/**
	* @brief Constructor de uma InsertVectorException com dois par&acirc;metros.
	*
	* @param myVector Vector de elementos compar&aacute;veis.
	* @param element Elemento a comparar.
	**/
	InsertVectorException(vector<Comparable> myVector,Comparable element)
	{
		this->my_vector=myVector;
		this->element=element;
	}

	/**
	* @brief M&eacute;todo para aceder ao elemento compar&aacute;vel.
	*
	* @return Retorna o elemento compar&aacute;vel.
	**/
	Comparable getElement() const
	{
		return element;
	}
};

/**
* Classe InBoundsException. Tem como par&acirc;metros um valor m&iacute;nimo, valor m&aacute;ximo e um valor.
*
* &Eacute; chamada quando um valor inserido se encontra fora dos limites delineados.
**/

class InBoundsException{
private:
	/** Valor m&iacute;nimo. **/
	double minimo;

	/** Valor m&aacute;ximo, **/
	double maximo;

	/** Valor a verificar, **/
	double valor;
public:

	/**
	* @brief Constructor de uma InBoundsException com tr&ecirc;s par&acirc;metros.
	*
	* @param minimo Valor m&iacute;nimo.
	* @param maximo Valor m&aacute;ximo.
	* @param valor Valor a verificar.
	**/
	InBoundsException(double minimo, double maximo, double valor)
	{
		this->minimo=minimo;
		this->maximo=maximo;
		this->valor=valor;
	}

	/**
	* @brief M&eacute;todo para aceder ao valor m&iacute;nimo.
	*
	* @return Retorna o valor m&iacute;nimo.
	**/
	double getMinimo() const
	{
		return minimo;
	}

	/**
	* @brief M&eacute;todo para aceder ao valor m&aacute;ximo.
	*
	* @return Retorna o valor m&aacute;ximo.
	**/
	double getMaximo() const
	{
		return maximo;
	}

	/**
	* @brief M&eacute;todo para aceder ao valor a verificar.
	*
	* @return Retorna o valor a verificar.
	**/
	double getValor() const
	{
		return valor;
	}

	/**
	* @brief Verifica se o valor a verificar se encontra dentro dos limites.
	*
	* @return Retorna 'true' se o valor se encontrar dentro dos limites, 'false' se n&atilde;o.
	**/
	bool notOutOfBounds() const
	{
		if (valor >= minimo && valor <=maximo)
		{
			return true;
		}
		else
			return false;
	}
};

/**
* Classe IsStringNumberException. Tem como par&acirc;metros um n&uacute;mero presente na string verificada.
*
* &Eacute; chamada quando uma string analisada n&atilde;o &eacute; n&uacute;mero.
**/

class IsStringNumberException{
private:
	/** N&uacute;mero presente na string verificada, **/
	string number;
public:

	/**
	* @brief Constructor de uma IsStringNumberException com um par&acirc;metro.
	*
	* @param number N&uacute;mero da string.
	**/
	IsStringNumberException(string number)
{
		this->number=number;
}
	/**
	* @brief M&eacute;todo para aceder ao n&uacute;mero.
	*
	* @return Retorna n&uacute;mero que estava na string.
	**/
	string getNumber()const
	{
		return number;
	}

};

/**
* Classe IsNotNumberException. Tem como par&acirc;metros uma string que era suposta ser n&uacute;mero.
*
* &Eacute; chamada quando o utilizador n&atilde;o insere um n&uacute;mero quando &eacute; suposto.
**/

class IsNotNumberException{
private:
	/** String que era suposta ser n&uacute;mero, **/
	string name;
public:
	/**
	* @brief Constructor de uma IsNotNumberException com um par&acirc;metro.
	*
	* @param name String que devia ser n&uacute;mero.
	**/
	IsNotNumberException(string name)
	{
		this->name=name;
	}
	/**
	* @brief M&eacute;todo para aceder &agrave; string.
	*
	* @return Retorna string que devia ser n&uacute;mero.
	**/
	string getString()const
	{
		return name;
	}

};

/**
* Classe IdNotExistentException. Tem como par&acirc;metros um ID que n&atilde;o foi encontrado.
*
* &Eacute; chamada quando um ID procurado n&atilde;o existe.
**/

class IdNotExistentException{
private:
	/** ID que n&atilde;o foi encontrado. **/
	int id;
public:
	/**
	* @brief Constructor de uma IdNotExistentException com um par&acirc;metro.
	*
	* @param id ID n&atilde;o encontrado.
	**/
	IdNotExistentException(int id)
	{
		this->id = id;
	}

	/**
	* @brief M&eacute;todo para aceder ao ID.
	*
	* @return Retorna ID n&atilde;o encontrado.
	**/
	int getId() const
	{
		return id;
	}
};

/**
* Classe IdentificacaoAulaNotExistentException. Tem como par&acirc;metros uma identifica&ccedil;&atilde;o da aula n&atilde;o existente.
*
* &Eacute; chamada quando o utilizador procura uma aula cuja identifica&ccedil;&atilde;o n&atilde;o existe.
**/

class IdentificacaoAulaNotExitentException{
private:
	/** Identifica&ccedil;&atilde;o da aula n&atilde;o existente **/
	string identificacao;
public:
	/**
	* @brief Constructor de uma IdentificacaoAulaNotExistentException com um par&acirc;metro.
	*
	* @param id String da identifica&ccedil;&atilde;o da aula n&atilde;o encontrada.
	**/
	IdentificacaoAulaNotExitentException(string id)
	{
		this->identificacao = id;
	}

	/**
	* @brief M&eacute;todo para aceder &agrave; identifica&ccedil;&atilde;o.
	*
	* @return Retorna string da identifica&ccedil;&atilde;o n&atilde;o encontrada.
	**/
	string getIdentificacao() const
	{
		return identificacao;
	}
};

/**
* Classe HorarioNotExistsException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando um hor&aacute;rio inserido n&atilde;o existe
**/

class HorarioNotExistsException{
public:

	/**
	* @brief Constructor de uma HorarioNotExistsException.
	*
	* Constr&oacute;i uma HorarioNotExistsException sem par&acirc;metros definidos.
	**/
	HorarioNotExistsException() {}
};

/**
* Classe TriesException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando o utilizador excede o n&uacute;mero de tentativas.
**/

class TriesException{
public:

	/**
	* @brief Constructor de uma TriesException.
	*
	* Constr&oacute;i uma TriesException sem par&acirc;metros definidos.
	**/
	TriesException(){}
};

/**
* Classe EmptyStringException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando &eacute; inserida uma string vazia.
**/

class EmptyStringException{
public:

	/**
	* @brief Constructor de uma EmptyStringException.
	*
	* Constr&oacute;i uma EmptyStringException sem par&acirc;metros definidos.
	**/
	EmptyStringException(){}
};

/**
* Classe InsuficientUsersException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando n&atilde;o existem membros suficientes.
**/

class InsuficientUsersException{
public:

	/**
	* @brief Constructor de uma InsuficientUsersException.
	*
	* Constr&oacute;i uma InsuficientUsersException sem par&acirc;metros definidos.
	**/
	InsuficientUsersException(){}
};

/**
* Classe DiaSemanaException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando um dia da semana introduzido &eacute; inv&aacute;lido.
**/

class DiaSemanaException{
public:

	/**
	* @brief Constructor de uma DiaSemanaException.
	*
	* Constr&oacute;i uma DiaSemanaException sem par&acirc;metros definidos.
	**/
	DiaSemanaException(){}
};

/**
* Classe InvalidDataException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando uma data introduzida &eacute; inv&aacute;lida.
**/

class InvalidDataException{
public:

	/**
	* @brief Constructor de uma InvalidDataException.
	*
	* Constr&oacute;i uma InvalidDataException sem par&acirc;metros definidos.
	**/
	InvalidDataException(){}
};

/**
* Classe LimitTimeException. N&atilde;o tem par&acirc;metros.
**/

class LimitTimeException{
	public:
		/**
		* @brief Constructor de uma LimitTimeException.
		*
		* Constr&oacute;i uma LimitTimeException sem par&acirc;metros definidos.
		**/
	 LimitTimeException(){}
};

/**
* Classe LimitAulaLivreTimeException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando se tenta criar uma aula livre com dura&ccedil;&atilde;o superior a duas horas ou inferior a trinta minutos.
**/

class LimitAulaLivreTimeException{
public:
	/**
	* @brief Constructor de uma LimitAulaLivreTimeException.
	*
	* Constr&oacute;i uma LimitAulaLivreTimeException sem par&acirc;metros definidos.
	**/
	LimitAulaLivreTimeException(){}
};

/**
* Classe ConfirmException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando o utilizador cancela uma confirma&ccedil;&atilde;o.
**/
class ConfirmException{
public:
	/**
	* @brief Constructor de uma ConfirmException.
	*
	* Constr&oacute;i uma ConfirmException sem par&acirc;metros definidos.
	**/
	ConfirmException(){}
};

/**
* Classe DataFormatoException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando encontra uma data com o formato errado.
**/
class DataFormatoException{
public:
	/**
	* @brief Constructor de uma DataFormatoException.
	*
	* Constr&oacute;i uma DataFormatoException sem par&acirc;metros definidos.
	**/
	DataFormatoException(){}
};

/**
* Classe HorarioPiscinaException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando se tenta criar uma aula fora do hor&aacute;rio de funcionamento da piscina.
**/
class HorarioPiscinaException{
public:
	/**
	* @brief Constructor de uma HorarioPiscinaException.
	*
	* Constr&oacute;i uma HorarioPiscinaException sem par&acirc;metros definidos.
	**/
	HorarioPiscinaException(){}
};

/**
* Classe AulaAcompanhadaMesmoTempoException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando se tenta criar uma aula acompanhada ao mesmo tempo que outra.
**/
class AulaAcompanhadaMesmoTempoException{
public:
	/**
	* @brief Constructor de uma AulaAcompanhadaMesmoTempoException.
	*
	* Constr&oacute;i uma AulaAcompanhadaMesmoTempoException sem par&acirc;metros definidos.
	**/
	AulaAcompanhadaMesmoTempoException(){}
};

/**
* Classe ProfessoresDisponiveisException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando n&atilde;o existem professores suficientes para uma aula.
**/
class ProfessoresDisponiveisException{
public:
	/**
	* @brief Constructor de uma ProfessoresDisponiveisException.
	*
	* Constr&oacute;i uma ProfessoresDisponiveisException sem par&acirc;metros definidos.
	**/
	ProfessoresDisponiveisException(){}
};

/**
* Classe MaxUtentesException. N&atilde;o tem par&acirc;metros.
*
* &Eacute; chamada quando se tenta colocar um utente numa aula lotada.
**/
class MaxUtentesException{
public:
	/**
	* @brief Constructor de uma MaxUtentesException.
	*
	* Constr&oacute;i uma MaxUtentesException sem par&acirc;metros definidos.
	**/
	MaxUtentesException(){}
};

/**
* Classe SaldoInsuficienteException. Tem como par&acirc;metros o nome do utente que n&atilde;o tem saldo, e respectivo saldo.
*
* &Eacute; chamada quando encontra um utente com saldo insuficiente para pagar uma aula.
**/
class SaldoInsuficienteException{
private:
	/** Nome do utente que n&atilde;o tem saldo. **/
	string nome;

	/** Saldo do utente **/
	int saldo;
public:
	/**
	* @brief Constructor de uma SaldoInsuficienteException.
	*
	* Constr&oacute;i uma SaldoInsuficienteException sem par&acirc;metros definidos.
	**/
	SaldoInsuficienteException();

	/**
	* @brief Constructor de uma SaldoInsuficienteException.
	*
	* Constr&oacute;i uma SaldoInsuficienteException com dois par&acirc;metros definidos.
	*
	* @param nome Nome do cliente com saldo insuficiente.
	* @param saldo Saldo do cliente.
	**/
	SaldoInsuficienteException(string nome, int saldo)
	{
		this->nome=nome;
		this->saldo=saldo;
	}

	/**
	* @brief M&eacute;todo para aceder ao nome do cliente com saldo insuficiente.
	*
	* @return Retorna o nome do cliente com saldo insuficiente.
	**/
	string getNome()
	{
		return nome;
	}

	/**
	* @brief M&eacute;todo para aceder ao saldo do cliente com saldo insuficiente.
	*
	* @return Retorna o saldo do cliente com saldo insuficiente.
	**/
	int getSaldo()
	{
		return saldo;
	}
};


#endif /* SRC_MYEXCEPTIONS_H_ */
