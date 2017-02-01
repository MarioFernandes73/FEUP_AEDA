#pragma once

#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_


#include "Auxiliary.h"

class Item {
private:
	/** String com o nome do item **/
	string nome;

	/** Inteiro com o tamanho do item **/
	unsigned int tamanho;

	/** Inteiro com o pre&ccedil;o do item **/
	unsigned int preco;

	/** Inteiro com o stock do item na loja **/
	unsigned int stock;
public:
	/**
	 * @brief M&eacute;todo para aceder ao nome de um item.
	 *
	 * @return Retorna o nome do item em quest&atilde;o.
	 **/
	string getNome() const;

	/**
	 * @brief M&eacute;todo para aceder ao tamanho de um item.
	 *
	 * @return Retorna o tamanho do item em quest&atilde;o.
	 **/
	unsigned int getTamanho() const;

	/**
	 * @brief M&eacute;todo para aceder ao pre&ccedil;o de um item.
	 *
	 * @return Retorna o pre&ccedil;o do item em quest&atilde;o.
	 **/
	unsigned int getPreco() const;

	/**
	 * @brief M&eacute;todo para aceder ao stock de um item.
	 *
	 * @return Retorna o stock do item em quest&atilde;o.
	 **/
	unsigned int getStock() const;

	/**
	 * @brief M&eacute;todo para definir o nome de um item.
	 *
	 * @param nome String com o nome do item.
	 **/
	void setNome(string nome);

	/**
	 * @brief M&eacute;todo para definir o tamanho de um item.
	 *
	 * @param tamanho Inteiro com o tamanho do item.
	 **/
	void setTamanho(unsigned int tamanho);

	/**
	 * @brief M&eacute;todo para definir o pre&ccedil;o de um item.
	 *
	 * @param preco Inteiro com o pre&ccedil;o do item.
	 **/
	void setPreco(unsigned int preco);

	/**
	 * @brief M&eacute;todo para definir o stock de um item.
	 *
	 * @param stock Inteiro com o stock do item.
	 **/
	void setStock(unsigned int stock);

	/**
	 * @brief Constructor de um item.
	 *
	 * Constr&oacute;i um item sem par&acirc;metros definidos.
	 **/
	Item();

	/**
	 * @brief Destructor de um item.
	 **/
	~Item();

	/**
	 * @brief Construtor de um item com todos os par&acirc;metros.
	 *
	 * Constr&oacute;i um item com o nome, tamanho, pre&ccedil;o e stock definidos.
	 *
	 * @param nome String com o nome do item a ser constru&iacute;do.
	 * @param tamanho Inteiro com o tamanho do item a ser constru&iacute;do.
	 * @param preco Inteiro com o pre&ccedil;o do item a ser constru&iacute;do.
	 * @param stock Inteiro com a quantidade do item a ser constru&iacute;do que existe na loja.
	 **/
	Item(string nome, unsigned int tamanho, unsigned int preco, unsigned int stock);

	/**
	 * @brief Construtor de um item com tr&ecirc;s par&acirc;metros.
	 *
	 * Constr&oacute;i um item com o nome, tamanho e pre&ccedil;o definidos.
	 *
	 * @param nome String com o nome do item a ser constru&iacute;do.
	 * @param tamanho Inteiro com o tamanho do item a ser constru&iacute;do.
	 * @param preco Inteiro com o pre&ccedil;o do item a ser constru&iacute;do.
	 **/
	Item(string nome, unsigned int tamanho, unsigned int preco);

	/**
	* @brief Construtor de um item com dois par&acirc;metros.
	*
	* Constr&oacute;i um item com o nome e tamanho definidos.
	*
	* @param nome String com o nome do item a ser constru&iacute;do.
	* @param tamanho Inteiro com o tamanho do item a ser constru&iacute;do.
	**/
	Item(string nome, unsigned int tamanho);

	/**
	 * @brief Operador para comparar dois items.
	 *
	 * Um item &eacute; menor que outro se o seu nome for menor, ou em caso de nomes iguais, se o seu tamanho for menor.
	 *
	 * @param i1 item a ser comparado.
	 * @return Retorna o menor item seguido do maior.
	 **/
	bool operator<(const Item &i1) const;

	/**
	 * @brief Operador para comparar se dois items s&atilde;o iguais.
	 *
	 * Um item &eacute; igual a outro se todos os par&acirc;metros forem iguais.
	 *
	 * @param i1 item a ser comparado.
	 * @return Retorna 'true' se os items forem iguais. Retorna 'false' caso contr&aacute;rio.
	 **/
	bool operator==(const Item &i1) const;
};

#endif /*SRC_ITEM_H*/

