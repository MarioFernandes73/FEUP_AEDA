/*
 * Professor.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário Fernandes, Cristiana Ribeiro, Sérgio Salgado
 */

#include "Professor.h"

Professor::Professor() {
	// TODO Auto-generated constructor stub

}

Professor::~Professor(){}


vector<Horario> Professor::getDisponibilidade() const
{
	return disponibilidade;
}

Professor::Professor(string nome, int idade) : Pessoa(nome, idade) {
}

Professor::Professor(int id, string nome, int idade):Pessoa(id,nome,idade)
{}

Professor::Professor(int id, string nome, int idade,vector<Horario> disponibilidade):Pessoa(id,nome,idade)
{
	this->disponibilidade = disponibilidade;
}


string Professor::getInformacao() const
{
	stringstream ss;
	ss << Pessoa::getInformacao() << endl;
	return ss.str();
}


ostream & operator<< (ostream &os, Professor * professor)
{
	os << professor->getId() << endl << professor->getNome() << endl << professor->getIdade();
	for(unsigned int i=0; i<professor->getDisponibilidade().size(); i++)
	{
		os<< endl << professor->getDisponibilidade()[i];
	}
	os << endl << "--------------------";
	return os;
}

