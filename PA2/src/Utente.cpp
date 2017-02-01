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

Utente::Utente(int id, string nome, int idade, int saldo,vector<string>textos, int telemovel, string email, string morada, int idleDays ) : Pessoa(id, nome, idade)
{
	this->saldo=saldo;
	this->despesas=textos;
	this->telemovel=telemovel;
	this->email=email;
	this->morada=morada;
	this->idleDays=idleDays;
}


Utente::~Utente(){}

int Utente::getSaldo() const
{
	return saldo;
}

ostream &operator << ( ostream &os, Utente * ut)
{
	return os << ut->getId() << endl << ut->getNome() << endl << ut->getIdade() << endl << ut->getSaldo() << endl << ut->getTelemovel() << endl << ut->getEMail() << endl << ut->getMorada() << endl << ut->getIdleDays();
}

string Utente::getInformacao() const
{
	stringstream ss;
	ss << Pessoa::getInformacao() << "Saldo: " << saldo << " Numero de telemovel: " << telemovel << " eMail: " << email << " Morada: " << morada << endl;
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

int Utente::getIdleDays()
{
	return this->idleDays;
}

void Utente::addIdleDays(int days)
{
	this->idleDays+=days;
}

void Utente::setIdleDays(int days)
{
	this->idleDays=days;
}

int Utente::getTelemovel() const
{
	return this->telemovel;
}

void Utente::setTelemovel(int tel)
{
	this->telemovel = tel;
}

string Utente::getEMail() const
{
	return this->email;
}

void Utente::setEMail(string email)
{
	this->email = email;
}

string Utente::getMorada() const
{
	return this-> morada;
}

void Utente::setMorada(string morada)
{
	this->morada = morada;
}

string Utente::printUt() const
{
	string res, temp;
	stringstream ss;

	res.append("ID: ");
	ss<<this->getId();
	ss>>temp;
	res.append(temp);

	ss.clear();
	ss.str("");

	res.append("\n");

	res.append("Nome: ");
	res.append(this->getNome());
	res.append("\n");

	res.append("Idade: ");
	ss<<this->getIdade();
	ss>>temp;
	res.append(temp);
	res.append("\n");

	ss.clear();
	ss.str("");

	res.append("Telemovel: ");
	ss<<this->getTelemovel();
	ss>>temp;
	res.append(temp);
	res.append("\n");

	ss.clear();
	ss.str("");

	res.append("E-mail: ");
	res.append(this->getEMail());
	res.append("\n");

	res.append("Morada: ");
	res.append(this->getMorada());
	res.append("\n\n");

	return res;
}
