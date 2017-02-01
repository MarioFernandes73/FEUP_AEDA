#include "item.h"

string Item::getNome() const {
	return nome;
}

unsigned int Item::getTamanho() const {
	return tamanho;
}

unsigned int Item::getPreco() const {
	return preco;
}

unsigned int Item::getStock() const {
	return stock;
}

void Item::setNome(string nome) {
	this->nome = nome;
}

void Item::setTamanho(unsigned int tamanho) {
	this->tamanho = tamanho;
}

void Item::setPreco(unsigned int preco) {
	this->preco = preco;
}

void Item::setStock(unsigned int stock) {
	this->stock = stock;
}

Item::Item() {

}

Item::~Item() {

}

Item::Item(string nome, unsigned int tamanho, unsigned int preco, unsigned int stock) {
	this->nome = nome;
	this->tamanho = tamanho;
	this->preco = preco;
	this->stock = stock;
}

Item::Item(string nome, unsigned int tamanho, unsigned int preco) {
	this->nome = nome;
	this->tamanho = tamanho;
	this->preco = preco;
	this->stock = 1;
}

bool Item::operator<(const Item &i1) const {
	if (this->nome < i1.nome) {
		return this->nome < i1.nome;
	}
	else if (this->nome == i1.nome && this->tamanho < i1.tamanho) {
		return this->tamanho < i1.tamanho;
	}
}

bool Item::operator==(const Item &i1) const {
	if (this->nome == i1.nome && this->tamanho == i1.tamanho && this->preco == i1.preco) {
		return true;
	}
	return false;
}

Item::Item(string nome, unsigned int tamanho)
{
	this->nome=nome;
	this->tamanho=tamanho;
}
