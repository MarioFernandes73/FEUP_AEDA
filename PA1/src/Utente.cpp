/*
 * Utente.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário Fernandes, Cristiana Ribeiro, Sérgio Salgado
 */

#include "Utente.h"

Utente::Utente() {
	// TODO Auto-generated constructor stub

}

Utente::Utente(int id)
{
	this->id=id;
}

Utente::Utente(string nome, int idade)
{
	this->id=id_atual;
	this->nome=nome;
	this->idade=idade;
	this->saldo=0;
	id_atual++;
}

Utente::Utente(int id, string nome, int idade, int saldo,vector<string>textos) : Pessoa(id, nome, idade)
{
	this->saldo=saldo;
	this->despesas=textos;
}

Utente::~Utente(){}

int Utente::getSaldo() const
{
	return saldo;
}

ostream &operator << ( ostream &os, Utente * ut)
{
	return os << ut->getId() << endl << ut->getNome() << endl << ut->getIdade() << endl << ut->getSaldo();
}

string Utente::getInformacao() const
{
	stringstream ss;
	ss << Pessoa::getInformacao() << "Saldo: " << saldo << endl;
	return ss.str();
}

vector<string> Utente::getDespesas() const
{
	return this->despesas;
}

void Utente::acrescentarSaldo(int valor){
	saldo += valor;
}

void Utente::retirarSaldo(int valor){
	InBoundsException exception(0,saldo,valor);
	if (exception.notOutOfBounds())
	saldo -= valor;
	else throw exception;
}

void Utente::pushDespesa(string despesa)
{
	this->despesas.push_back(despesa);
}
