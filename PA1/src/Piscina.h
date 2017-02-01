/*
 * Piscina.h
 *
 *  Created on: 8 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_PISCINA_H_
#define SRC_PISCINA_H_

#include "Auxiliary.h"
#include "Utente.h"
#include "Professor.h"
#include "Horario.h"
#include "AulaAcompanhada.h"
#include "AulaLivre.h"

 /**
 * Classe Piscina. Tem como par&acirc;metros strings com o nome da piscina, string com os nomes dos respectivos ficheiros e vectores correspondentes a cada ficheiro.
 **/

class Piscina {
private:
	/** Data com o dia actual. **/
	Data dia_atual;

	/** Nome da piscina. **/
	string nome_piscina;

	/** Nome do ficheiro de utentes da piscina. **/
	string ficheiro_utentes;

	/** Nome do ficheiro de professores da piscina. **/
	string ficheiro_professores;

	/** Nome do ficheiro de hor&aacute;rios da piscina. **/
	string ficheiro_horario;

	/** Nome do ficheiro de aulas da piscina. **/
	string ficheiro_aulas;

	/** Nome do ficheiro de aulas dadas da piscina. **/
	string ficheiro_aulas_dadas;

	/** Vector de utentes da piscina. **/
	vector<Utente *> utentes;

	/** Vector de professores da piscina. **/
	vector<Professor *> professores;

	/** Vector de hor&aacute;rios da piscina. **/
	vector<Horario> horario;

	/** Vector de aulas da piscina. **/
	vector<Aula *> aulas;

	/** Vector de aulas dadas da piscina. **/
	vector<Aula *> aulas_dadas;
public:
	/**
	* @brief Constructor de uma piscina.
	*
	* Constr&oacute;i uma piscina sem par&acirc;metros definidos.
	**/
	Piscina();

	/**
	* @brief Construtor de uma piscina com cinco par&acirc;metros.
	*
	* Constr&oacute;i uma piscina com todos os par&acirc;metros definidos
	*
	* @param nome_piscina String com o nome da piscina.
	* @param ficheiro_utentes String com o nome do ficheiro de utentes.
	* @param ficheiro_professores String com o nome do ficheiro de professores.
	* @param ficheiro_horario String com o nome do ficheiro de hor&aacute;rios.
	* @param ficheiro_aulas String com o nome do ficheiro de aulas.
	* @param ficheiro_aulas_dadas String com o nome do ficheiro de aulas dadas.
	**/
	Piscina(string nome_piscina, string ficheiro_utentes, string ficheiro_professores, string ficheiro_horario, string ficheiro_aulas, string ficheiro_aulas_dadas);

	/**
	* @brief Guarda as mudan&ccedil;as efectuadas relativamente aos utentes.
	*
	* @return Retorna 'true' se as mudan&ccedil;as foram guardadas com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool saveUtentes();

	/**
	* @brief Guarda as mudan&ccedil;as efectuadas relativamente aos professores.
	*
	* @return Retorna 'true' se as mudan&ccedil;as foram guardadas com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool saveProfessores();

	/**
	* @brief Guarda as mudan&ccedil;as efectuadas relativamente aos hor&aacute;rios.
	*
	* @return Retorna 'true' se as mudan&ccedil;as foram guardadas com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool saveHorario();

	/**
	* @brief Guarda as mudan&ccedil;as efectuadas relativamente &agrave;s aulas.
	*
	* @return Retorna 'true' se as mudan&ccedil;as foram guardadas com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool saveAulas();

	/**
	* @brief Guarda as mudan&ccedil;as efectuadas relativamente &agrave;s aulas dadas.
	*
	* @return Retorna 'true' se as mudan&ccedil;as foram guardadas com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool saveAulasDadas();

	/**
	* @brief M&eacute;todo para aceder ao vector de utentes de uma certa piscina.
	*
	* @return Retorna o vector de utentes da piscina em quest&atilde;o.
	**/
	vector<Utente *> getUtentes() const;

	/**
	* @brief M&eacute;todo para aceder ao vector de professores de uma certa piscina.
	*
	* @return Retorna o vector de professores da piscina em quest&atilde;o.
	**/
	vector<Professor *> getProfessores() const;

	/**
	* @brief M&eacute;todo para aceder ao vector de hor&aacute;rios de uma certa piscina.
	*
	* @return Retorna o vector de hor&aacute;rios da piscina em quest&atilde;o.
	**/
	vector<Horario> getHorario()const;

	/**
	* @brief M&eacute;todo para aceder ao vector de aulas de uma certa piscina.
	*
	* @return Retorna o vector de aulas da piscina em quest&atilde;o.
	**/
	vector<Aula *> getAulas()const;

	/**
	* @brief M&eacute;todo para aceder ao nome de uma certa piscina.
	*
	* @return Retorna o nome da piscina em quest&atilde;o.
	**/
	string getNome() const;

	/**
	* @brief M&eacute;todo para aceder ao nome do ficheiro de utentes de uma certa piscina.
	*
	* @return Retorna o nome do ficheiro de utentes da piscina em quest&atilde;o.
	**/
	string getFichUt() const;

	/**
	* @brief M&eacute;todo para aceder ao nome do ficheiro de professores de uma certa piscina.
	*
	* @return Retorna o nome do ficheiro de professores da piscina em quest&atilde;o.
	**/
	string getFichProf() const;

	/**
	* @brief M&eacute;todo para aceder ao nome do ficheiro de hor&aacute;rios de uma certa piscina.
	*
	* @return Retorna o nome do ficheiro de hor&aacute;rios da piscina em quest&atilde;o.
	**/
	string getFichHor() const;

	/**
	* @brief M&eacute;todo para aceder ao nome do ficheiro de aulas de uma certa piscina.
	*
	* @return Retorna o nome do ficheiro de aulas da piscina em quest&atilde;o.
	**/
	string getFichAulas()const;

	/**
	* @brief M&eacute;todo para aceder ao nome do ficheiro de aulas dadas de uma certa piscina.
	*
	* @return Retorna o nome do ficheiro de aulas dadas da piscina em quest&atilde;o.
	**/
	string getFichAulasDadas() const;

	/**
	* @brief M&eacute;todo para definir o nome de uma certa piscina.
	*
	* @param nome Nome da piscina em quest&atilde;o.
	**/
	void setNome(string nome);

	/**
	* @brief M&eacute;todo para definir o nome do ficheiro de utentes de uma certa piscina.
	*
	* @param ficheiro_utentes Nome do ficheiro de utentes da piscina em quest&atilde;o.
	**/
	void setFichUt(string ficheiro_utentes);

	/**
	* @brief M&eacute;todo para definir o nome do ficheiro de professores de uma certa piscina.
	*
	* @param ficheiro_professores Nome do ficheiro de professores da piscina em quest&atilde;o.
	**/
	void setFichProf(string ficheiro_professores);

	/**
	* @brief M&eacute;todo para definir o nome do ficheiro de hor&aacute;rios de uma certa piscina.
	*
	* @param ficheiro_horario Nome do ficheiro de hor&aacute;rios da piscina em quest&atilde;o.
	**/
	void setFichHor(string ficheiro_horario);

	/**
	* @brief M&eacute;todo para definir o nome do ficheiro de aulas de uma certa piscina.
	*
	* @param ficheiro_aulas Nome do ficheiro de aulas da piscina em quest&atilde;o.
	**/
	void setFichAulas(string ficheiro_aulas);

	/**
	* @brief Carrega o ficheiro de utentes.
	*
	* @return Retorna 'true' se o ficheiro foi carregado com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool loadFichUt();

	/**
	* @brief Carrega o ficheiro de professores.
	*
	* @return Retorna 'true' se o ficheiro foi carregado com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool loadFichProf();

	/**
	* @brief Carrega o ficheiro de hor&aacute;rios.
	*
	* @return Retorna 'true' se o ficheiro foi carregado com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool loadFichHor();

	/**
	* @brief Carrega o ficheiro de aulas.
	*
	* @return Retorna 'true' se o ficheiro foi carregado com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool loadFichAulas();

	/**
	* @brief Carrega o ficheiro de aulas dadas.
	*
	* @return Retorna 'true' se o ficheiro foi carregado com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool loadFichAulasDadas();

	/**
	* @brief Encontra os utentes com certos IDs. Esta fun&ccedil;&atilde;o &eacute; utilizada na saveChanges().
	*
	* @param ids Vector com os IDs dos utentes que desejamos encontrar.
	* @return Retorna um vector com os utentes encontrados.
	**/
	vector<Utente *> findUtentes(vector<int> ids);

	/**
	* @brief Encontra o professor com um certo ID. Esta fun&ccedil;&atilde;o &eacute; utilizada na saveChanges().
	*
	* @param id ID do professor que desejamos encontrar.
	* @return Retorna o professor, caso tenha sido encontrado. Caso contr&aacute;rio retorna 'NULL'.
	**/
	Professor * findProfessor(int id);

	/**
	* @brief Encontra o professor com maior disponibilidade.
	*
	* @param profs_disponiveis Vector de professores com disponibilidade.
	* @return Retorna o professor com maior disponibilidade (menos aulas a dar). Se existirem dois ou mais professores com a maior disponibilidade, retorna o professor com o ID mais pequeno.
	**/
	Professor * findProfessorMenosAulas(vector<Professor *> profs_disponiveis);

	/**
	* @brief Destructor de uma aula.
	**/
	virtual ~Piscina();

	/******************************
	* Fun&ccedil;ões relativas a utentes *
	******************************/

	/**
	* @brief Adiciona um utente ao vector de utentes.
	*
	* @param ut Utente a adicionar.
	**/
	void addUtente(Utente * ut);

	/**
	* @brief Remove um utente do vector de utentes.
	*
	* @param ut Utente a remover.
	**/
	void removerUtente(Utente * ut);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de utentes por nome, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param p1 Primeiro utente a comparar.
	* @param p2 Segundo utente a comparar.
	* @return Retorna que nome do primeiro &eacute; menor que o nome do segundo.
	**/
	static bool sortUtenteByName(const Utente *p1, const Utente *p2);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de utentes por ID utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param p1 Primeiro utente a comparar.
	* @param p2 Segundo utente a comparar.
	* @return Retorna que ID do primeiro &eacute; menor que o ID do segundo.
	**/
	static bool sortUtenteByID(const Utente *p1, const Utente *p2);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de utentes por idade, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param p1 Primeiro utente a comparar.
	* @param p2 Segundo utente a comparar.
	* @return Retorna que idade do primeiro &eacute; menor que o idade do segundo.
	**/
	static bool sortUtenteByAge(const Utente *p1, const Utente *p2);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de utentes por saldo, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param p1 Primeiro utente a comparar.
	* @param p2 Segundo utente a comparar.
	* @return Retorna que saldo do primeiro &eacute; menor que o saldo do segundo.
	**/
	static bool sortUtenteBySaldo(const Utente *p1, const Utente *p2);

	/**********************************
	* Fun&ccedil;ões relativas a professores *
	**********************************/

	/**
	* @brief Adiciona um professor ao vector de professor.
	*
	* @param p Professor a adicionar.
	**/
	void addProfessor(Professor * p);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de professores por nome, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param p1 Primeiro professor a comparar.
	* @param p2 Segundo professor a comparar.
	* @return Retorna que nome do primeiro &eacute; menor que o nome do segundo.
	**/
	static bool sortProfessorByName(const Professor *p1, const Professor *p2);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de professores por ID, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param p1 Primeiro professor a comparar.
	* @param p2 Segundo professor a comparar.
	* @return Retorna que ID do primeiro &eacute; menor que o ID do segundo.
	**/
	static bool sortProfessorByID(const Professor *p1, const Professor *p2);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de professores por idade, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param p1 Primeiro professor a comparar.
	* @param p2 Segundo professor a comparar.
	* @return Retorna que idade do primeiro &eacute; menor que o idade do segundo.
	**/
	static bool sortProfessorByAge(const Professor *p1, const Professor *p2);

	/***********************************
	*  aulas irao ficar sem professor  *
	***********************************/

	/**
	* @brief Remove um professor ao vector de professor, removendo-o das aulas a que ele estava atribu&iacute;do.
	*
	* @param prof Professor a remover.
	**/
	void removerProfessor(Professor * prof);

	/****************************
	* Fun&ccedil;ões relativas a aulas *
	****************************/

	/**
	* @brief Adiciona uma aula ao vector de aulas.
	*
	* @param aula Aula a adicionar.
	**/
	void addAula(Aula * aula);

	/**
	* @brief Remove uma aula do vector de aulas, retirando essa aula da informa&ccedil;&atilde;o dos utentes e professores.
	*
	* @param au Aula a remover.
	* @return Retorna 'true' se a aula foi removida com sucesso. 'false' caso contr&aacute;rio.
	**/
	bool removerAula(Aula * au);

	/**
	* @brief Adicionar um utente a uma aula.
	*
	* @param id_aula Identifica&ccedil;&atilde;o da aula &agrave; qual queremos adicionar o utente.
	* @param ut Utente que queremos adicionar &agrave; aula.
	**/
	void addUtenteAAula(string id_aula, Utente * ut);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de aulas por identifica&ccedil;&atilde;o, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param a1 Primeira aula a comparar.
	* @param a2 Segunda aula a comparar.
	* @return Retorna que a identifica&ccedil;&atilde;o da primeira &eacute; menor que a identifica&ccedil;&atilde;o da segunda.
	**/
	static bool sortAulaByNome(const Aula *a1, const Aula *a2);

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar o vector de aulas por data, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param a1 Primeira aula a comparar.
	* @param a2 Segunda aula a comparar.
	* @return Retorna que a data da primeira &eacute; menor que a data da segunda.
	**/
	static bool sortAulaByHorario(const Aula *a1, const Aula *a2);

	/**
	* @brief Verifica se a aula em quest&atilde;o pode receber mais um utente.
	*
	* @param aula Aula a verificar a quantidade de utentes.
	* @return Retorna 'true' se a aula pode receber mais um utente. 'false' caso contr&aacute;rio.
	**/
	bool verifyAulaNovoUtente(Aula * aula);


	/******************************
	* Funcoes relativas &agrave; piscina *
	******************************/

	/**
	* @brief Adiciona um hor&aacute;rio ao vector de hor&aacute;rios.
	*
	* @param horario Hor&aacute;rio a adicionar.
	**/
	void addHorario(Horario horario);

	/**
	* @brief Remove um hor&aacute;rio do vector de hor&aacute;rios, removendo as aulas a essa hora.
	*
	* @param horario Hor&aacute;rio a remover.
	*
	* @return Retorna 'true' se o hor&aacute;rio foi removido com sucesso. Retorna 'false' caso contr&aacute;rio.
	**/
	bool removerHorario(Horario horario);

	//remover aula e colocar em aulas dadas
	/**
	* @brief Move uma Aula do vector de aulas para o vector de aulas_dadas.
	**/
	void updateAulasDadas();

	/**
	* @brief Actualiza as despesas de todos os utentes, retirando-lhes saldo conforme as aulas em que participaram.
	*
	* Se conseguir, retira o saldo (se poss&iacute;vel) das suas contas. Caso contr&aacute;rio, avisa o utilizador dos utentes que n&atilde;o t&ecirc;m saldo.
	**/
	void updatePagamentoDespesas();

	/**
	* @brief M&eacute;todo para aceder ao dia actual.
	*
	* @return Retorna a Data correspondente ao dia actual.
	**/
	Data getDiaAtual();

	/**
	* @brief Fun&ccedil;&atilde;o para ordenar os hor&aacute;rios da piscina por ID, utilizando a fun&ccedil;&atilde;o sort.
	*
	* @param horario1 Primeiro hor&aacute;rio a comparar.
	* @param horario2 Segundo hor&aacute;rio a comparar.
	* @return Retorna que o primeiro hor&aacute;rio &eacute; menor que o segundo.
	**/
	static bool sortHorarioPiscina(const Horario horario1, const Horario horario2);

	/**
	* @brief Verifica se um utente consegue pagar uma aula em que participou. 
	*
	* Se conseguir, retira o saldo (se poss&iacute;vel) da sua conta. Caso contr&aacute;rio, avisa o utilizador que o utente em causa n&atilde;o tem saldo.
	*
	* @param ut Utente que o utilizador deseja actualizar o saldo.
	**/
	void updatePagamentoDespesas(Utente * ut);

};

#endif /* SRC_PISCINA_H_ */
