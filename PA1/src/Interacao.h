/*
 * Interacao.h
 *
 *  Created on: 30 Oct 2016
 *      Author: M&aacute;rio Fernandes, Cristiana Ribeiro, S&eacute;rgio Salgado
 */

#ifndef SRC_INTERACAO_H_
#define SRC_INTERACAO_H_

#include "Piscina.h"

/******************************
*  Interac&ccedil;&atilde;o com os utentes  *
******************************/

/**
* @brief Cria um novo utente, perguntando ao utilizador o seu nome e idade.
*
* @return Retorna um novo utente com o nome e idade especificados.
**/
Utente * createUtente();

/**
* @brief Procura um utente, perguntando ao utilizador o seu ID.
*
* Percorre o vector de utentes at&eacute; encontrar o utente desejado.
*
* @param piscina Piscina da qual queremos encontrar o utente.
* @return Retorna o utente, se for encontrado. Caso contr&aacute;rio lan&ccedil;a uma excep&ccedil;&atilde;o de ID n&atilde;o encontrado.
**/
Utente * findUtente(Piscina & piscina);

/**
* @brief Edita um utente, perguntando ao utilizador o seu novo nome e nova idade.
*
* @param ut Utente a ser editado.
**/
void editUtente(Utente * ut);

/**
* @brief Edita o saldo de um utente.
*
* @return Retorna o saldo do utente.
**/
int receiveSaldoUtente();

/**
* @brief Verifica se o utilizador pretende remover um utente, aguardando a sua confirma&ccedil;&atilde;o.
*
* @param ut Utente a ser removido.
* @return Retorna 'true' se o utilizador confirmou a remo&ccedil;&atilde;o do utente, 'false' caso contr&aacute;rio.
**/
bool confirmRemoveUtente(Utente * ut);

/**********************************
*  Interac&ccedil;&atilde;o com os professores  *
**********************************/

/**
* @brief Cria um novo professor, perguntando ao utilizador o seu nome e idade.
*
* @return Retorna um novo professor com o nome e idade especificados.
**/
Professor * createProfessor();

/**
* @brief Procura um professor, perguntando ao utilizador o seu ID.
*
* Percorre o vector de professor at&eacute; encontrar o professor desejado. Depois pergunta ao utilizador para confirmar se &eacute; aquele o professor pretendido
*
* @param piscina Piscina da qual queremos encontrar o professor.
* @return Retorna o professor. se o professor for encontrado e o utilizador confirmar. Se o professor for encontrado e o utilizador rejeitar, retorna NULL. Caso contr&aacute;rio lan&ccedil;a uma excep&ccedil;&atilde;o de ID n&atilde;o encontrado.
**/
Professor * findProfessor(Piscina & piscina);

/**
* @brief Edita um professor, perguntando ao utilizador o seu novo nome e nova idade.
*
* @param p Professor a ser editado.
**/
void editProfessor(Professor * p);

/**
* @brief Verifica se o utilizador pretende remover um professor, aguardando a sua confirma&ccedil;&atilde;o.
*
* @param p Professor a ser removido.
* @return Retorna 'true' se o utilizador confirmou a remo&ccedil;&atilde;o do professor, 'false' caso contr&aacute;rio.
**/
bool confirmRemoveProfessor(Professor * p);

/**
* @brief Verifica se o utilizador pretende remover um professor, aguardando a sua confirma&ccedil;&atilde;o.
*
* @param p Professor a ser removido.
* @return Retorna 'true' se o utilizador confirmou a remo&ccedil;&atilde;o do professor, 'false' caso contr&aacute;rio.
**/
bool removeProfessor(Professor * p);

/****************************
*  Interac&ccedil;&atilde;o com as aulas  *
****************************/

/**
* @brief Cria uma nova aula livre, perguntando ao utilizador o nome da aula.
*
* @return Retorna uma nova aula livre com o nome especificado.
**/
AulaLivre * createAulaLivre(Piscina & piscina);

/**
* @brief Cria uma nova aula acompanhada, perguntando ao utilizador o nome da aula, o ID do professor que deseja (utilizando o findProfessor(Piscina & piscina)) e o pre&ccedil;o da aula.
*
* @param piscina Piscina onde vai ser criada a nova aula acompanhada.
* @return Retorna uma nova aula acompanhada com o nome, professor e pre&ccedil;o especificados.
**/
AulaAcompanhada * createAulaAcompanhada(Piscina & piscina);

/**
* @brief Procura ao utilizador qual o tipo de aula de deseja procurar, seguido do nome de identifica&ccedil;&atilde;o desta.
*
* @param piscina Piscina onde vai ser procurada a aula.
* @return Retorna a aula no vector das aulas correspondente, se a encontrar. Caso contr&aacute;rio, lan&ccedil;a uma excep&ccedil;&atilde;o.
**/
Aula * findAula(Piscina & piscina);

/**
* @brief Edita uma aula existente.
*
* Verifica se a aula &eacute; uma aula livre ou acompanhada e dependendo do tipo de aula, a edi&ccedil;&atilde;o ser&aacute; diferente.
*
* @param aula Aula a ser editada.
**/
void editAula(Aula * aula);

/**
* @brief Cria um hor&aacute;rio para a aula, perguntando ao utilizador por uma data inicial e por uma final, verificando se ambos os inputs e a ordem de escrita est&atilde;o correctos.
*
* @param tipodeAula String com o tipo de aula para a qual o hor&aacute;rio est&aacute; a ser criado.
* @param piscina Piscina na qual o utilizados pretende criar uma hor&aacute;rio para aula.
* @return Retorna o hor&aacute;rio criado, se as verifica&ccedil;ões estiverem todas correctas. Caso contr&aacute;rio, lan&ccedil;a uma excep&ccedil;&atilde;o.
**/
Horario createHorarioAula(string tipodeAula,Piscina & piscina);

/**
* @brief Remove uma aula existente.
*
* @param aula Aula a ser removida.
* @return Retorna 'true' se a aula foi removida, 'false' caso contr&aacute;rio.
**/
bool removeAula(Aula* aula);

/**
* @brief Imprime a lista de utentes de uma aula, mostrando ao utilizador uma lista das aulas, perguntando de seguida qual a aula que ele deseja ver os utentes participantes.
*
* @param piscina Piscina que o utilizador pretende listar utentes por aula.
**/
void listarUtentesPorAula(Piscina & piscina);

/**
* @brief Verifica se as datas de in&iacute;cio e fim de uma aula acompanhada s&atilde;o v&aacute;lidas.
*
* @param dataInicial Data do in&iacute;cio da aula.
* @param dataFinal Data do fim da aula.
* @return Retorna 'true' se entre a data inicial e final existir um intervalo v&aacute;lido para uma aula acompanhada, 'false' caso contr&aacute;rio.
**/
bool validateTimeAulaAcompanhada(Data & dataInicial, Data & dataFinal);

/*****************************
*  Interac&ccedil;&atilde;o com a piscina  *
*****************************/

/**
* @brief Cria um hor&aacute;rio para a piscina (em que dias est&aacute; aberta e entre que horas).
*
* @return Retorna o hor&aacute;rio criado, se as verifica&ccedil;ões estiverem todas correctas. Caso contr&aacute;rio, lan&ccedil;a uma excep&ccedil;&atilde;o.
**/
Horario createHorarioPiscina();

/**
* @brief Procura por um hor&aacute;rio dentro dos hor&aacute;rios j&aacute; existentes da piscina. Pede ao utilizador para criar um novo hor&aacute;rio, verificando se ele j&aacute; existe.
*
* @param piscina Piscina da qual se pretende encontrar o hor&aacute;rio.
* @return Retorna o hor&aacute;rio criado, se ele j&aacute; existir, caso contr&aacute;rio, lan&ccedil;a uma excep&ccedil;&atilde;o.
**/
Horario findHorarioPiscina(Piscina & piscina);

/**
* @brief Remove um hor&aacute;rio existente de uma piscina.
*
* @param h Hor&aacute;rio a remover.
* @return Retorna 'true' se o hor&aacute;rio foi removido, 'false' caso contr&aacute;rio.
**/
bool removeHorario(Horario h);


//mode -> 1 = dia, 2=semana ,3=mes, 4=ano
/**
* @brief Prev&ecirc; as estat&iacute;sticas da piscina daqui a um intervalo de tempo escolhido pelo utilizador.
*
* Imprime no ecr&atilde; o n&uacute;mero de aulas que v&atilde;o ser dadas nesse intervalo, a receita gerada pelas aulas e o n&uacute;mero de utentes que a piscina ter&aacute;
*
* @param piscina Piscina a prever estat&iacute;sticas.
* @param mode Modo de utiliza&ccedil;&atilde;o que determina o intervalo de tempo a avan&ccedil;ar (entre 1 e 4). 1 avan&ccedil;a um dia, 2 avan&ccedil;a uma semana, 3 avan&ccedil; um m&ecirc;s e 4 avan&ccedil;a um ano.
**/
void predictNext(Piscina & piscina,int mode);


#endif /* SRC_INTERACAO_H_ */
