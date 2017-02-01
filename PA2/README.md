#AEDA PART_2

Tema 5 – Piscina (Parte 2)

Complemente o sistema já implementado com as seguintes funcionalidades:

* A piscina dispõe de uma loja onde vende artigos de natação para os seus utentes. Na loja, os artigos existentes estão guardados numa árvore binária de pesquisa, ordenada por designação e, para a mesma designação, por tamanho. A informação sobre um artigo inclui designação, tamanho e stock (e outros atributos que considere relevantes). O funcionário da loja pode vender artigos a um utente (diminuindo o stock) ou comprar artigos a fornecedores (aumentando o stock).
* A piscina pode disponibilizar aulas de uma ou mais modalidades desportivas (polo aquático, mergulho, …). Se a piscina não disponibiliza aulas da modalidade de interesse de um utente, ou não possui vagas para essa modalidade, deve indicar ao utente a piscina mais próxima que possui tal modalidade. Para tal, a informação sobre outras piscinas é guardada numa fila de prioridade, ordenada por distância.
* Os utentes que não utilizam a piscina há mais de um determinado período, são guardados numa tabela de dispersão como inativos. Sempre que um utente inativo volta a utilizar a piscina, passa novamente a ativo. As moradas e contactos dos utentes inativos são atualizadas, em campanhas promocionais, de tempos em tempos, de forma a ter esta informação sempre válida no sistema.

Notas relativas à implementação (itens sujeitos a avaliação):

* Deve utilizar classes adequadas para representação das entidades envolvidas. Os atributos devem ser escolhidos de forma a caracterizar os conceitos mais importantes das entidades a representar).
* Os dados usados pela aplicação devem ser guardados em ficheiro, para utilização em futuras execuções.
* As classes implementadas devem ser devidamente documentadas (usando Doxygen).
* Na fase de teste da aplicação, deve usar um número significativo de elementos.

TL;DR: Improve the PART_1 of the project by adding a shop sistem, a pool search system and an active/unactive system. Use binary tree for the shop, priority queue for the search system (based on distance) and a hash table for the active/unactive system.
