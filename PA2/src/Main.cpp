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
	string piscina = "", ficheiro_utentes = "" , ficheiro_professores = "", ficheiro_horario = "", ficheiro_aulas="", ficheiro_aulas_dadas="", ficheiro_loja="", password = "";
	int XCoord, YCoord;
	string lastDayUsed;

	try
{


	if(findPiscina(piscina, password, lastDayUsed, XCoord, YCoord, ficheiro_utentes, ficheiro_professores, ficheiro_horario, ficheiro_aulas,ficheiro_aulas_dadas, ficheiro_loja)==false)
	{
		appendPiscina(piscina, password, lastDayUsed, XCoord, YCoord, ficheiro_utentes, ficheiro_professores, ficheiro_horario, ficheiro_aulas, ficheiro_aulas_dadas, ficheiro_loja);
		start=false;
	}

	piscinaMCS = Piscina(piscina, password, lastDayUsed, XCoord, YCoord, ficheiro_utentes, ficheiro_professores, ficheiro_horario,ficheiro_aulas, ficheiro_aulas_dadas, ficheiro_loja);
}
catch (EmptyStringException &e)
{
	start=false;
	cout << "Input do utilizador vazio.\n O programa vai ser desligado.\n";
}
catch (NotIntException &e)
{
	start = false;
	cout << "Erro! Nao introduziu um inteiro.\n";
}



if(start){
	piscinaMCS.loadFichUt();
	piscinaMCS.loadFichProf();
	piscinaMCS.loadFichHor();
	piscinaMCS.loadFichAulas();
	piscinaMCS.loadFichAulasDadas();
	piscinaMCS.loadPiscinas();
	piscinaMCS.loadFichLj();

	piscinaMCS.updateHashTable();
	int daysPassed = piscinaMCS.getDiaAtual().convertDays() - piscinaMCS.getLastDayUsed().convertDays();
	if(daysPassed<0)
		daysPassed=0;
	piscinaMCS.addIdleDays(daysPassed);

if(piscinaMCS.getDiaAtual().getDia()==1)
{
	piscinaMCS.updateAulasDadas();
	piscinaMCS.updatePagamentoDespesas();
	updateMassUts2(piscinaMCS.getIdleUts());
}
else
	piscinaMCS.updateAulasDadas();



piscinaMCS.updatePiscina();

	opcoesIniciais(piscinaMCS);


	piscinaMCS.saveUtentes();
	piscinaMCS.saveProfessores();
	piscinaMCS.saveHorario();
	piscinaMCS.saveAulas();
	piscinaMCS.saveAulasDadas();
	piscinaMCS.saveLoja();
}
	return 0;
}
