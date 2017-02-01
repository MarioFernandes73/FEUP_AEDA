/*
 * Main.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário
 */


#include <stdlib.h>
#include "Piscina.h"
#include "Menu.h"

int main()
{
	Piscina piscinaMCS;
	bool start=true;
	string piscina = "", ficheiro_utentes = "" , ficheiro_professores = "", ficheiro_horario = "", ficheiro_aulas="", ficheiro_aulas_dadas="";
try
{
	if(findPiscina(piscina, ficheiro_utentes, ficheiro_professores, ficheiro_horario, ficheiro_aulas,ficheiro_aulas_dadas)==false)
	{
		appendPiscina(piscina, ficheiro_utentes, ficheiro_professores, ficheiro_horario, ficheiro_aulas, ficheiro_aulas_dadas);
		start=false;
	}

	piscinaMCS = Piscina(piscina, ficheiro_utentes, ficheiro_professores, ficheiro_horario,ficheiro_aulas, ficheiro_aulas_dadas);
}
catch (EmptyStringException &e)
{
	start=false;
	cout << "Input do utilizador vazio.\n O programa vai ser desligado.\n";
}
if(start){
	piscinaMCS.loadFichUt();
	piscinaMCS.loadFichProf();
	piscinaMCS.loadFichHor();
	piscinaMCS.loadFichAulas();
	piscinaMCS.loadFichAulasDadas();

if(piscinaMCS.getDiaAtual().getDia()==1)
	piscinaMCS.updatePagamentoDespesas();
else
	piscinaMCS.updateAulasDadas();



	opcoesIniciais(piscinaMCS);


	piscinaMCS.saveUtentes();
	piscinaMCS.saveProfessores();
	piscinaMCS.saveHorario();
	piscinaMCS.saveAulas();
	piscinaMCS.saveAulasDadas();
}
	return 0;
}
