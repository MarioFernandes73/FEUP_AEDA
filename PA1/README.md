#AEDA PART_1

Tema 5 – Piscina (Parte 1)

Uma piscina disponibiliza aos seus utentes o uso em dois modos: modo de aula (duração de 1h com professor) e
modo livre (duração até 2h sem professor: para simplificar, considere períodos múltiplos de 30 minutos). Existe
um número máximo de utentes que podem estar em simultâneo na piscina. As aulas têm prioridade no uso da
piscina, pelo que o número de utentes admissível em modo livre em cada período é igual a
(NumMaximoUtentes - NumUtentesAula).

O preço de uso da piscina é: fixo, em modo aula; e fixo por período de 30 minutos em modo livre.
O sistema a implementar deve registar todas as ocorrências em que um utente usa a piscina, incluindo a data.
No final do mês, o utente deve pagar o uso da piscina nesse mês, sendo­lhe entregue um documento onde são
discriminadas todas as datas/horas em que frequentou a piscina. As aulas são lecionadas pelos professores
existentes, sendo o professor de determinada aula escolhido de modo a equilibrar o número de aulas por
professor.

O sistema deve permitir a consulta da ocupação da piscina, frequência de utentes, contas dos utentes, aulas
leccionadas por professores, horário de aulas, horário de professores e outras que considere relevantes.

Notas relativas à implementação (itens sujeitos a avaliação):
* Deve utilizar classes adequadas para representação das entidades envolvidas. Os atributos devem ser escolhidos de forma a caracterizar os conceitos mais importantes das entidades a representar).
* Deve utilizar o conceito de herança e polimorfismo onde considerar conveniente.
* Os dados usados pela aplicação devem ser guardados em ficheiro, para utilização em futuras execuções.
* Deve tratar convenientemente possíveis excepções.
* Deve usar algoritmos de pesquisa e ordenação (por exemplo, nas múltiplas listagens solicitadas) 
* As classes implementadas devem ser devidamente documentadas (usando Doxygen).


TL;DR: Project about managing a pool, with clients, professors, scheduled classes etc. using C++ and concepts like classes, hierarchy, polimorfism, exceptions, etc.
