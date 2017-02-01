/*
 * Pessoa.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário Fernandes, Cristiana Ribeiro, Sérgio Salgado
 */

#include "Pessoa.h"

int Pessoa::id_atual=1;

Pessoa::Pessoa() {
	// TODO Auto-generated constructor stub

}

Pessoa::Pessoa(string nome, int idade)
{
	this->id=id_atual;
	this->nome=nome;
	this->idade=idade;
	id_atual++;
}

Pessoa::Pessoa(int id, string nome, int idade)
{
	this->id=id;
	this->nome=nome;
	this->idade=idade;
	id_atual=id+1;
}

Pessoa::~Pessoa() {
	// TODO Auto-generated constructor stub

}

int Pessoa::getId() const
{
	return id;
}


string Pessoa::getNome() const
{
	return nome;
}


int Pessoa::getIdade() const
{
	return idade;
}


void Pessoa::setNome(string nome)
{
	this->nome=nome;
}

void Pessoa::setIdade(int idade)
{
	this->idade=idade;
}

bool Pessoa::operator == (Pessoa * pessoa)
{
	if (this->getId()==pessoa->getId())
		return true;
	else
		return false;
}

string Pessoa::getInformacao() const
{
	stringstream ss;
	ss << "ID: " << id << " Nome: " << nome << " Idade: " << idade << " ";
	return ss.str();
}

ostream & operator << ( ostream &os, Pessoa & pessoa)
{
	return os << pessoa.id << endl << pessoa.nome << endl << pessoa.idade;
}
