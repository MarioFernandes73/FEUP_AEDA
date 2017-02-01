/*
 * Auxiliary.h
 *
 *  Created on: 10 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_AUXILIARY_H_
#define SRC_AUXILIARY_H_


#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "MyExceptions.h"

#define fichload "nomes_piscina.txt"
#define TAB 			"	"
#define TAB_BIG 		"		"
#define TRIES			3
#define MINIMUM_ID		1
#define MAXIMUM_ID		9999
#define MAXIMUM_UTS		20

using namespace std;


//loads para a classe piscina

/**
* @brief Verifica se existe um ficheiro.
*
* Tenta abrir um ficheiro, verificando de seguida se ele est&aacute; aberto. Se estiver aberto, &eacute; porque existe.
*
* @param file String com o nome do ficheiro a verificar a exist&ecirc;ncia.
* @return Retorna 'true' se o ficheiro existir. 'false' caso contr&aacute;rio.
**/
bool existeFicheiro(const string file);

/**
* @brief Verifica se existe um ficheiro da piscina.
*
* Abre o ficheiro com as piscinas existentes e percorre-o at&eacute; encontrar a piscina desejada. Caso o encontre, segue medidas de autentica&ccedil;&atilde;o (password) para aceder &agrave; piscina encontrada.
*
* @param piscina String com o nome do ficheiro da piscina a verificar a exist&ecirc;ncia.
* @param ficheiro_utentes String com o nome do ficheiro de utentes da piscina.
* @param ficheiro_professores String com o nome do ficheiro de professores da piscina.
* @param ficheiro_horario String com o nome do ficheiro de hor&aacute;rio(s) da piscina.
* @param ficheiro_aulas String com o nome do ficheiro de aulas da piscina.
* @param ficheiro_aulas_dadas String com o nome do ficheiro de aulas dadas da piscina.
* @return Retorna 'true' se o ficheiro existir e a autentica&ccedil;&atilde;o tiver sido efectuada com sucesso. 'false' caso a piscina n&atilde;o tenha sido encontrada. Caso a password inserida estiver errada, fecha o programa.
**/
bool findPiscina(string & piscina, string & ficheiro_utentes, string & ficheiro_professores, string & ficheiro_horario, string & ficheiro_aulas, string & ficheiro_aulas_dadas);

/**
* @brief Cria um novo ficheiro para uma piscina.
*
* Cria uma piscina com o nome inserido, criando de seguida os ficheiros correspondentes a utentes, professores, hor&aacute;rios e aulas.
*
* @param piscina String com o nome da piscina a criar.
* @param ficheiro_utentes String com o nome do ficheiro de utentes da nova piscina.
* @param ficheiro_professores String com o nome do ficheiro de professores da nova piscina.
* @param ficheiro_horario String com o nome do ficheiro de hor&aacute;rio(s) da nova piscina.
* @param ficheiro_aulas String com o nome do ficheiro de aulas da nova piscina.
* @param ficheiro_aulas_dadas String com o nome do ficheiro de aulas dadas da piscina.
**/
void appendPiscina(const string piscina, string & ficheiro_utentes, string & ficheiro_professores, string & ficheiro_horario, string & ficheiro_aulas, string & ficheiro_aulas_dadas);

/**
* @brief Passa uma string com o dia da semana para um int.
*
* Converte a string para uma string semelhante apenas com letras min&uacute;sculas e devolve um n&uacute;mero.
*
* @param dia_semana Dia da semana a converter.
* @return Retorna o n&uacute;mero correspondente ao dia da semana, come&ccedil;ando em 1 (correspondente a Domingo), terminando em 7 (correspondente a S&aacute;bado). Se o dia inserido n&atilde;o corresponder a um dia da semana, retorna 0.
**/
int verifyDiaSemana(string dia_semana);

/**
* @brief Verifica se &eacute; um n&uacute;mero.
*
* @param number String a verificar.
* @return Retorna 'true' se a string corresponder a um n&uacute;mero, 'false' caso contr&aacute;rio.
**/
bool isNumber(string number);

/**
* @brief Verifica se &eacute; um n&uacute;mero decimal.
*
* Percorre a string &agrave; procura de um '.' (com uma verifica&ccedil;&atilde;o para evitar situa&ccedil;ões como 3.14.159) e se os restantes componentes da string s&atilde;o d&iacute;gitos.
*
* @param number String a verificar.
* @return Retorna 'true' se a string corresponder a um n&uacute;mero decimal, 'false' caso contr&aacute;rio.
**/
bool isFloat(string number);

/**
* @brief Verifica se uma string cont&eacute;m algum n&uacute;mero.
*
* @param name String a verificar.
* @return Retorna 'true' se a string n&atilde;o cont&eacute;m n&uacute;meros, 'false' caso contr&aacute;rio.
**/
bool isNotNumber(string name);

/**
* @brief Verifica se uma string &eacute; vazia.
*
* @param name String a verificar.
* @return Retorna 'true' se a string for vazia, 'false' caso contr&aacute;rio.
**/
bool stringIsEmpty(string name);

/**
* @brief Com um n&uacute;mero de tentativas pr&eacute;-definido, verifica se os inputs relacionados com strings est&atilde;o correctos e, em caso de inputs inv&aacute;lidos, se o utilizador j&aacute; tentou mais vezes que o pretendido.
*
* Por cada input inv&aacute;lido, apanha uma excep&ccedil;&atilde;o at&eacute; decidir parar de verificar o input.
*
* @return Retorna uma string vazia se o utilizador colocou um input v&aacute;lido.
**/
string tryNewTextInput();

/**
* @brief Com um n&uacute;mero de tentativas pr&eacute;-definido, verifica se os inputs relacionados com n&uacute;meros est&atilde;o correctos e, em caso de inputs inv&aacute;lidos, se o utilizador j&aacute; tentou mais vezes que o pretendido.
*
* Por cada input inv&aacute;lido, apanha uma excep&ccedil;&atilde;o at&eacute; decidir parar de verificar o input.
*
* @param first Limite inferior do intervalo de n&uacute;meros a ler.
* @param last Limite superior do intervalo de n&uacute;meros a ler.
* @return Retorna 0 se o utilizador colocou um input v&aacute;lido.
**/
unsigned short int leUnsignedShortInt(unsigned short int first, unsigned short int last);

/**
* @brief Confirma se o utilizador quer confirmar uma ac&ccedil;&atilde;o, escrevendo 'Y' ou 'y'.
*
* @return Retorna 'true' se o utilizador confirmou a ac&ccedil;&atilde;o correctamente, retorna 'false' no caso de outro input.
**/
bool confirm();

/**
* @brief Verifica se uma data est&aacute; colocada de forma curta, ou seja, se a data apenas apresenta horas e minutos
*
* Percorre a string, verificando se as horas e minutos est&atilde;o dentro de um valor v&aacute;lido, lan&ccedil;ando expec&ccedil;ões no caso de erros.
*
* @param data Data a verificar.
* @return Retorna 'true' se a data for v&aacute;lida, retorna 'false' caso contr&aacute;rio.
**/
bool isDataShortFormato(string data);

/**
* @brief Verifica se uma data est&aacute; colocada de forma longa, ou seja, se a data apresenta m&ecirc;s, dia, horas e minutos.
*
* Percorre a string, verificando se o m&ecirc;s, dia, horas e minutos est&atilde;o dentro de um valor v&aacute;lido, lan&ccedil;ando expec&ccedil;ões no caso de erros.
*
* @param data Data a verificar.
* @return Retorna 'true' se a data for v&aacute;lida, retorna 'false' caso contr&aacute;rio.
**/
bool isDataLongFormato(string data);

/******************************
*	       TEMPLATES          *
******************************/

template <class Comparable>
/**
* @brief Verifica se um elemento se encontra num vector.
*
* @param vetor Vector com elementos compar&aacute;veis a ser percorrido.
* @param elemento Elemento a verificar se pertence a 'vetor'.
* @return Retorna 'true' se o elemento estiver presente, retorna 'false' caso contr&aacute;rio.
**/
bool notInVector(vector <Comparable> vetor, Comparable elemento)
	{
		for (unsigned int i=0; i<vetor.size(); i++)
		{
			if (vetor[i]==elemento)
			{
				return false;
			}
		}
		return true;
	}


template <class T>
/**
* @brief Imprime um vector.
*
* @param vetor Vector a imprimir.
**/
void listarVector(vector<T> vetor)
{
	for(unsigned int i =0; i<vetor.size(); i++ )
	{
		cout << vetor[i] << endl;
	}
}

template <class T>
/**
* @brief Verifica se um ID est&aacute; presente num vector (&uacute;til para verificar IDs de pessoas relacionadas com a piscina).
*
* @param vectorTemplate Vector a percorrer para encontrar 'id'.
* @param id Inteiro a procurar em 'vectorTemplate'.
* @return Retorna o &iacute;ndice no vector percorrido de onde est&aacute; o ID, retorna -1 caso n&atilde;o encontre o ID especificado no vector.
**/
int idExistsOnVector(vector<T> vectorTemplate, int id)
{
	for(unsigned int i =0; i<vectorTemplate.size(); i++) {
		if (vectorTemplate[i]->getId() == id) {
			return i;
		}
	}
	return -1;
}

/**
* @brief Verifica se um ID est&aacute; presente num vector de IDs.
*
* @param id ID a verificar se est&aacute; no vector.
* @param ids Vector com os IDs a percorrer.
* @return Retorna 'true' se o ID estiver no vector, retorna 'false' caso contr&aacute;rio.
**/
bool verifyIdExistsOnVector(int id, vector<int> ids);

/**
* @brief Verifica se o ano &eacute; bissexto.
*
* @param ano Ano a verificar.
* @return Retorna 'true' se o ano for bissexto, retorna 'false' caso contr&aacute;rio.
**/
bool anoBi(int ano);

#endif /* SRC_AUXILIARY_H_ */
