/*
 * Aula.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário
 */

#include "Aula.h"

Aula::Aula() {
	// TODO Auto-generated constructor stub

}

Aula::~Aula() {
	// TODO Auto-generated destructor stub
}

Aula::Aula(string identificacao_aula, Horario horario_aula)
{
	this->identificacao_aula=identificacao_aula;
	this->horario_aula=horario_aula;
}

Aula::Aula(string identificacao_aula, Horario horario_aula, vector<Utente *> utentes)
{
	this->identificacao_aula=identificacao_aula;
	this->horario_aula=horario_aula;
	this->utentes=utentes;
}

vector<Utente *> Aula::getUtentes() const
{
	return utentes;
}

Horario Aula::getHorario() const
{
	return horario_aula;
}

string Aula::getIdentificacaoAula() const
{
	return identificacao_aula;
}

void Aula::addUtente(Utente * ut)
{

		if(notInVector(this->getUtentes(), ut))
		{
			utentes.push_back(ut);
		}
		else
		{
			throw InsertVectorException<Utente *>(this->getUtentes(),ut);
		}

}

bool Aula::removeUtente(Utente * ut)
{
	for (unsigned int i =0; i<utentes.size(); i++)
	{
		if (utentes[i]==ut)
		{
			utentes.erase(utentes.begin()+i);
			i=-1;
			return true;
		}
	}
	return false;
}

void Aula::setIdentificacaoAula(string identificacao_aula)
{
	this->identificacao_aula = identificacao_aula;
}

void Aula::setHorarioAula(Horario horario_aula)
{
	this->horario_aula = horario_aula;
}

string Aula::parseUtentes()
{
	string string_utentes="";
	stringstream ss;
	string temp;

	for(unsigned int i=0; i<this->getUtentes().size(); i++)
	{
		ss<<this->getUtentes()[i]->getId();
		ss >> temp;
		ss.clear();
		ss.str("");
		string_utentes.append(temp);
		string_utentes.append(" ");
	}

	return string_utentes;
}

ostream & operator<< (ostream &os, Aula * aula) {
	return os << aula->getIdentificacaoAula() << endl << aula->getHorario() << endl;
}

string Aula::printAula()
{
	string temp="";
	temp.append(this->getIdentificacaoAula());
	temp.append("\n");
	temp.append(this->getHorario().getDia_semana());
	temp.append("\n");
	temp.append(this->getHorario().printHorario());
	temp.append("\n");
	temp.append(this->parseUtentes());

	return temp;
}

bool Aula::checkNovoUt(Utente * ut)
{
	//verificar se utentes da aula excede MAXIMUM_UTS
	if(this->getUtentes().size()>=MAXIMUM_UTS)
		throw MaxUtentesException();
	//verificar se ja esta no vetor
	for(unsigned int i =0; i<this->getUtentes().size(); i++)
	{
		if(ut==this->getUtentes()[i])
		{
			throw InsertVectorException<Utente *>(this->getUtentes(),ut);
		}

	}
	return true;
}
