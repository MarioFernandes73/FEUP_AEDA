/*
 * AulaLivre.cpp
 *
 *  Created on: 23 Oct 2016
 *      Author: Mário
 */

#include "AulaLivre.h"



AulaLivre::AulaLivre() {
	// TODO Auto-generated constructor stub

}

AulaLivre::~AulaLivre() {
	// TODO Auto-generated destructor stub
}

AulaLivre::AulaLivre(string identificacao_aula, Horario horario_aula, vector <Utente *> utentes):Aula(identificacao_aula, horario_aula, utentes)
{}

AulaLivre::AulaLivre(string identificacao_aula, Horario horario_aula):Aula(identificacao_aula, horario_aula)
{}

const unsigned int AulaLivre::getPreco()const
{
	int duracao_horas = (this->getHorario().getFinal().getHora() - this->getHorario().getInicial().getHora());
	int duracao_minutos = (this->getHorario().getFinal().getMinutos() - this->getHorario().getInicial().getMinutos());
	float duracao = (duracao_horas*2)+ceil(duracao_minutos/30);

	return preco*duracao;
}

string AulaLivre::constroiDespesa()
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
