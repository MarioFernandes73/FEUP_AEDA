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
#include "BST.h"
#include "Item.h"
#include <queue>
#include <unordered_set>

/**
* Estrutura utenteHash. Cria a tabela de dispers&atilde;o para os utentes inactivos.
**/
struct utenteHash
{
	int operator() (const Utente * ut) const
	{
		return ut->getId(); // boa escolha visto que cada ID é unico
	}

	bool operator() (const Utente * ut1, const Utente * ut2) const
	{
		return ut1->getId()==ut2->getId();
	}
};

typedef unordered_set<Utente *, utenteHash, utenteHash> tabHutente;





 /**
 * Classe Piscina. Tem como par&acirc;metros strings com o nome da piscina, string com os nomes dos respectivos ficheiros e vectores correspondentes a cada ficheiro.
 **/

class Piscina {
private:
	/** Data com o dia actual. **/
	Data dia_atual;

	/** Data do &uacute;ltimo dia em que a piscina foi utilizada **/
	Data lastDayUsed;

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

	/** Nome do ficheiro da loja da piscina. **/
	string ficheiro_loja;

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

	/** Par de coordenadas reais da piscina **/
	pair<int, int> coordenadas_Reais;

	/** Par de coordenadas fict&iacute;cias da piscina **/
	pair<int, int> coordenadas_Ficticias;

	/** Fila de prioridade da piscina (para localiza&ccedil;&atilde;o da piscina) **/
	priority_queue<Piscina> piscinas;

	/** Tabela de dispers&atilde;o da piscina (para utentes inativos) **/
	tabHutente	utentes_Idle;

	/** Binary Search Tree da piscina (para a loja) **/
	BST<Item> loja;

	/** Password da piscina **/
	string password;
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
	* @param password String com a password da piscina.
	* @param ficheiro_utentes String com o nome do ficheiro de utentes.
	* @param ficheiro_professores String com o nome do ficheiro de professores.
	* @param ficheiro_horario String com o nome do ficheiro de hor&aacute;rios.
	* @param ficheiro_aulas String com o nome do ficheiro de aulas.
	* @param ficheiro_aulas_dadas String com o nome do ficheiro de aulas dadas.
	* @param ficheiro_loja String com o nome da loja da piscina.
	**/
	Piscina(string nome_piscina,string password, string lastDayUsed, int XCoord, int YCoord, string ficheiro_utentes, string ficheiro_professores, string ficheiro_horario, string ficheiro_aulas, string ficheiro_aulas_dadas, string ficheiro_loja);

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
	 * @brief M&eacute;todo para aceder ao nome do ficheiro de loja de uma certa piscina.
	 *
	 * @return Retorna o nome do ficheiro de loja da piscina em quest&atilde;o.
	 **/
	string getFichLj() const;

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
	 * @brief M&eacute;todo para definir o nome do ficheiro de loja de uma certa piscina.
	 *
	 * @param ficheiro_loja Nome do ficheiro de loja da piscina em quest&atilde;o.
	 **/
	void setFichLj(string ficheiro_loja);

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
	* @brief Destructor de uma piscina.
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

	/**
	* @brief M&eacute;todo que retorna as coordenadas fict&iacute;cias de uma piscina.
	*
	* @return Retorna as coordenadas fict&iacute;cias da piscina em quest&atilde;o.
	**/
	pair<int, int> getCoordFicticias() const;

	/**
	 * @brief M&eacute;todo que retorna as coordenadas reais de uma piscina.
	 *
	 * @return Retorna as coordenadas reais da piscina em quest&atilde;o.
	 **/
	pair<int, int> getCoordReais() const;

	/**
	 * @brief M&eacute;todo para definir as coordenadas fict&iacute;cias de uma certa piscina.
	 *
	 * @param XCoord Coordenada X da piscina em quest&atilde;o.
	 * @param YCoord Coordenada Y da piscina em quest&atilde;o.
	 **/
	void setCoordFicticias(int XCoord, int YCoord);

	/**
	 * @brief M&eacute;todo que retorna piscina mais pr&oacute;xima com uma certa aula.
	 *
	 * @param nome_aula Aula a procurar pelas piscinas mais pr&oacute;ximas.
	 * @return Retorna a piscina mais pr&oacute;xima com a aula em quest&atilde;o.
	**/
	Piscina findPiscinaPerto(string nome_aula);

	/**
	 * @brief Operador para comparar piscinas por dist&acirc;ncia.
	 *
	 * @param P1 Piscina a comparar dist&acirc;ncia.
	 * @return Retorna a piscina mais pr&oacute;xima, seguida da outra.
	**/
	bool operator<(const Piscina& P1) const;

	/**
	* @brief Operador para escrever uma piscina numa ostream.
	*
	* @param os Ostream para onde a aula vai ser escrita.
	* @param aula Aula a ser escrita na ostream.
	* @return Retorna uma string com a informa&ccedil;&atilde;o da piscina.
	**/
	friend ostream & operator<<(ostream & os, Piscina P1);

	/**
	 * @brief M&eacute;todo para carregar as piscinas existentes no sistema para a fila de prioridade.
	 *
	 * @return Retorna 'true' se as piscinas foram carregadas com sucesso. Retorna 'false' caso contr&aacute;rio.
	 **/
	bool loadPiscinas();

	/**
	 * @brief M&eacute;todo que imprime a fila de prioridade com as piscinas.
	 *
	 * @return Retorna uma string com a informa&ccedil;&atilde;o contida na fila de prioridade.
	 **/
	string printPiscinas();

	/**
	 * @brief M&eacute;todo que actualiza a tabela de dispers&atilde;o com os utentes inactivos.
	 **/
	void updateHashTable();

	/**
	 * @brief M&eacute;todo que imprime a tabela de dispers&atilde;o com os utentes inactivos.
	 *
	 * @return Retorna uma string com a informa&ccedil;&atilde;o contida na tabela de dispers&atilde;o.
	 **/
	string printHashTable();

	/**
	 * @brief M&eacute;todo que selecciona os utentes considerados inactivos.
	 *
	 * @return Retorna um vector de utentes com os utentes inactivos.
	 **/
	vector <Utente *> getIdleUts();

	/**
	 * @brief M&eacute;todo que remove um utente previamente inactivo da tabela de dispers&atilde;o com os utentes inactivos.
	 **/
	void removeIdle();

	/**
	 * @brief M&eacute;todo que adiciona dias ao n&uacute;mero de dias inactivos de um utente.
	 *
	 * @param days Dias a adicionar ao n&uacute;mero de dias inactivos de um utente.
	 **/
	void addIdleDays(int days);

	/**
	 * @brief M&eacute;todo que retorna a data em que a piscina foi utilizada pela &uacute;ltima vez.
	 *
	 * @return Retorna a data em que a piscina foi utilizada pela &uacute;ltima vez.
	 **/
	Data getLastDayUsed();

	/**
	 * @brief M&eacute;todo para carregar o ficheiro da loja para a BST da piscina.
	 *
	 * @return Retorna 'true' se o ficheiro da loja foi carregado com sucesso. Retorna 'false' caso contr&aacute;rio.
	 **/
	bool loadFichLj();

	/**
	 * @brief M&eacute;todo que guarda a BST da piscina para um ficheiro.
	 *
	 * @return Retorna 'true' se o ficheiro da loja foi guardado com sucesso. Retorna 'false' caso contr&aacute;rio.
	 **/
	bool saveLoja();

	/**
	 * @brief M&eacute;todo para adicionar um item &agrave; loja da piscina.
	 *
	 * @param it Item a adicionar &agrave; loja.
	 **/
	void addItemToStore(Item it);

	/**
	 * @brief M&eacute;todo que imprime o stock da loja da piscina.
	 *
	 * @return Retorna uma string com a informa&ccedil;&atilde;o contida na BST da loja da piscina.
	 **/
	string printInventory();

	/**
	 * @brief M&eacute;todo que retorna a BST da loja da piscina.
	 *
	 * @return Retorna uma BST da loja da piscina.
	 **/
	BST<Item> getLoja();

	/**
	 * @brief M&eacute;todo que imprime a informa&ccedil;&atilde;o sobre uma aula a ocorrer numa piscina pr&oacute;xima.
	 *
	 * @param nome_aula Nome da aula que o utilizador quer a informa&ccedil;&atilde;o.
	 * @return Retorna uma string com a informa&ccedil;&atilde;o da aula.
	 **/
	string getReport(string nome_aula);

	/**
	* @brief M&eacute;todo que vende um item a um utente.
	*
	* @param buyer Nome do cliente que quer comprar o item.
	* @param item Item a ser vendido.
	**/
	void venderItem(Utente * buyer, Item item);

	/**
	* @brief M&eacute;todo que remove o item de uma loja.
	*
	* @param item Item a ser removido da loja.
	**/
	void removerItem(Item item);

	/**
	* @brief M&eacute;todo que adiciona items a uma loja.
	*
	* @param item Item a ser adicionado &agrave; loja.
	* @param quantidade Quantidade de items a adicionar &agrave; loja.
	**/
	void abastecerItem(Item item, unsigned int quantidade);

	/**
	* @brief M&eacute;todo para definir a BST da loja de uma certa piscina.
	*
	* @param loja BST da loja da piscina em quest&atilde;o.
	**/
	void setLoja(BST<Item> loja);

	/**
	* @brief M&eacute;todo que guarda a informa&ccedil;&atilde;o sobre todas as piscinas no sistema.
	*
	* @return Retorna 'true' se o ficheiro com a informa&ccedil;&atilde;o foi actualizado com sucesso.
	**/
	bool updatePiscina();

	/**
	* @brief M&eacute;todo que recebe a password de uma certa piscina.
	*
	* @return Retorna uma string com a password da piscina em quest&atilde;o.
	**/
	string getPassword() const;

	/**
	* @brief M&eacute;todo que recebe a fila de prioridade das dist&acirc;ncias de uma certa piscina.
	*
	* @return Retorna a fila de prioridade das dist&acirc;ncias da piscina em quest&atilde;o.
	**/
	priority_queue<Piscina> getPiscinas() const;
};

#endif /* SRC_PISCINA_H_ */
