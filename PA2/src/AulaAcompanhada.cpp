/*
 * AulaAcompanhada.cpp
 *
 *  Created on: 23 Oct 2016
 *      Author: Mário
 */

#include "AulaAcompanhada.h"

AulaAcompanhada::AulaAcompanhada() {
	// TODO Auto-generated constructor stub

}

AulaAcompanhada::~AulaAcompanhada() {
	// TODO Auto-generated destructor stub
}

AulaAcompanhada::AulaAcompanhada(string identificacao_aula, Horario horario_aula, Professor * professor):Aula(identificacao_aula,horario_aula)
{
	this->preco=15;
	this->encarregado=professor;
}

AulaAcompanhada::AulaAcompanhada(string identificacao_aula, Horario horario_aula, vector<Utente *> utentes, unsigned int preco, Professor * professor ):Aula(identificacao_aula, horario_aula, utentes)
{
	this->preco=preco;
	this->encarregado=professor;
}

AulaAcompanhada::	AulaAcompanhada(string identificacao_aula, Horario horario_aula, vector<Utente *> utentes, Professor * professor ):Aula(identificacao_aula, horario_aula, utentes)
{
	this->preco=15;
this->encarregado=professor;
}

unsigned int AulaAcompanhada::getPreco()
{
	return preco;
}

Professor * AulaAcompanhada::getEncarregado()
{
	return encarregado;
}

string AulaAcompanhada::printAula()
{
	stringstream ss;
	string temp=Aula::printAula(), temp2;
	temp.append("\n");
	ss<<this->getPreco();
	ss>>temp2;
	ss.clear();
	ss.str("");
	temp.append(temp2);
	temp.append("\n");
	ss<<this->getEncarregado()->getId();
	ss>>temp2;
	ss.clear();
	ss.str("");
	temp.append(temp2);


	return temp;
}

void AulaAcompanhada::setProfessor(Professor * prof)
{
	this->encarregado=prof;
}

void AulaAcompanhada::setPreco(unsigned int preco)
{
	this->preco=preco;
}

string AulaAcompanhada::constroiDespesa()
{
	string temp="", precostring;
	stringstream ss;
	temp.append(this->getIdentificacaoAula());
	temp.append("\n");
	temp.append("Dia: ");
	temp.append(this->getHorario().getDia_semana());
	temp.append("\n");
	temp.append(this->getHorario().getInicial().printData());
	temp.append("\n");
	temp.append(this->getHorario().getFinal().printData());
	temp.append("\n");
	ss << this->getPreco();
	ss >> precostring;
	ss.clear();
	ss.str("");
	temp.append("Preco: ");
	temp.append(precostring);
	return temp;
}
