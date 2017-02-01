/*
 * Auxiliary.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário
 */

#include "Auxiliary.h"
#include <stdlib.h>

bool existeFicheiro(const string ficheiro)
{
	//verifica se o ficheiro existe
		ifstream in;
		in.open(ficheiro);
		if (in.is_open())
		{
			in.close();
			return true;
		}
		return false;
}

//verifica se existe a piscina
bool findPiscina(string & piscina, string & ficheiro_utentes, string & ficheiro_professores, string & ficheiro_horario, string & ficheiro_aulas, string & ficheiro_aulas_dadas)
{
	ifstream in;
	string temp,nextline,password;

	in.open(fichload);

	cout << "Bem vindo ao Software \"Piscina MCS\" " << endl;
	cout << "Por favor escreva o nome da sua picina: ";
	getline(cin,piscina);
	if(stringIsEmpty(piscina))
		throw EmptyStringException();

	if(in.is_open())
	{
		while(!in.eof())
		{
			getline(in,temp);
			if(temp==piscina)
			{
				//Piscina encontrada
				getline(in,password);
				cout << "Por favor escreva a password da piscina: ";
				getline(cin,temp);
				if(stringIsEmpty(temp))
					throw EmptyStringException();
				if(temp==password)
				{
					//password correta
					getline(in, ficheiro_utentes);
					getline(in, ficheiro_professores);
					getline(in, ficheiro_horario);
					getline(in, ficheiro_aulas);
					getline(in,ficheiro_aulas_dadas);
					cout << "Sucesso no encontro da piscina!"<< endl;
					in.close();
					return true;
				}
				else
				{
					cout << "Password errada, o programa irá agora fechar." << endl;
					system("pause");
					exit(1);
				}
			}
			else
			{
				for(unsigned int i=0; i<6; i++)
				{
					getline(in,nextline);
				}
			}
		}
		//Piscina nao encontrada
		return false;
	}
	else
	{
		//ficheiro não existe
		return false;
	}
}


//edita fichload com uma nova piscina.
void appendPiscina (const string piscina, string & ficheiro_utentes, string & ficheiro_professores, string & ficheiro_horario, string & ficheiro_aulas, string & ficheiro_aulas_dadas)
{
	ofstream out;
	string password;
	bool needsEndl = false;

	cout << "Por favor escreva a password da sua nova piscina: ";
	getline(cin, password);
	if(stringIsEmpty(password))
		throw EmptyStringException();

	ficheiro_utentes = piscina + "_utentes.txt";
	ficheiro_professores = piscina + "_professores.txt";
	ficheiro_horario = piscina + "_horario.txt";
	ficheiro_aulas = piscina + "_aulas.txt";
	ficheiro_aulas_dadas = piscina + "_aulas_dadas.txt";

	if(existeFicheiro(fichload))
		needsEndl=true;

	out.open(fichload,ios::app);
	if (out.is_open())
		{
			if(needsEndl)
			{
				out << endl;
				needsEndl=false;
			}
			out << piscina << endl << password << endl << ficheiro_utentes << endl << ficheiro_professores << endl << ficheiro_horario << endl << ficheiro_aulas << endl << ficheiro_aulas_dadas;
			out.close();
			out.open(ficheiro_utentes);
			out.close();
			out.open(ficheiro_professores);
			out.close();
			out.open(ficheiro_horario);
			out.close();
			out.open(ficheiro_aulas);
			out.close();
			out.open(ficheiro_aulas_dadas);
			out.close();
			cout << "Piscina acabada de criar, por favor reinicie o programa e insira a sua piscina e password." << endl;
		}
	else
	{
		cout << "File " << fichload << " is corrupted." << endl;
	}
}

int verifyDiaSemana(string temp)
{
	for (unsigned int i=0; i<temp.size(); i++)
	{
		temp[i]=tolower(temp[i]);
	}

	if(temp=="domingo")
		return 1;
	else if (temp=="segunda-feira")
		return 2;
	else if (temp=="terca-feira")
			return 3;
	else if (temp=="quarta-feira")
			return 4;
	else if (temp=="quinta-feira")
			return 5;
	else if (temp=="sexta-feira")
			return 6;
	else if (temp=="sabado")
			return 7;
	else
		return 0;

}

bool isNumber(string number)
{
	for (unsigned int i = 0; i<number.size(); i++)
			{
				if (!isdigit(number[i]))
					return false;
			}
	return true;
}

bool isFloat(string number)
{
	bool foundDot=false;
	for (unsigned int i =0; i<number.size(); i++)
	{
		if (!foundDot && number[i]=='.')
			foundDot=true;
		else if(!isdigit(number[i]))
			return false;
	}
	return true;
}

unsigned short int leUnsignedShortInt(unsigned short int first, unsigned short int last)
{
	unsigned short int input,tentativas=0;
	string temp;
	bool checking = true;
	stringstream ss;

	while(checking && tentativas<TRIES)
	{
		getline(cin,temp);
		try
		{
			if(stringIsEmpty(temp))
				throw EmptyStringException();
			if(!isNumber(temp))
			{
				IsStringNumberException teste_string (temp);
				throw IsStringNumberException(teste_string);
			}

			ss << temp;
			ss >> input;

			ss.clear();
			ss.str("");


			InBoundsException teste_bounds(first, last, input);
			if(teste_bounds.notOutOfBounds()==false)
				throw teste_bounds;
			checking=false;
			return input;
		}
		catch(EmptyStringException &e)
		{
			cout << "Por favor escreva um numero." << endl;
		}
		catch (IsStringNumberException &teste_string)
		{
			cout << "IsStringException -> " << teste_string.getNumber() << " is not a number." << endl;
			cout << "Por favor tente outra vez: ";
		}
		catch (InBoundsException &teste_bounds)
		{
			cout << "InBoundsException -> " << "O seu valor " << teste_bounds.getValor() << " tem de estar entre " << teste_bounds.getMinimo() << " e " << teste_bounds.getMaximo() << endl;
			cout << "Por favor tente outra vez: ";
		}
		tentativas++;
	}

	if(tentativas>=TRIES)
	cout << "Erro, numero de tentativas excedido." << endl;

	return 0;

}

string tryNewTextInput()
{
	unsigned short int tentativas=0;
	string temp;
	bool checking = true;
	stringstream ss;

	while(checking && tentativas<TRIES)
	{
		getline(cin,temp);
		try
		{

			if(stringIsEmpty(temp)) {
				throw EmptyStringException();
			}

			if(!isNotNumber(temp))
			{
				throw IsNotNumberException(temp);
			}

			checking=false;
			return temp;
		}
		catch(EmptyStringException &e){
			cout << "Nome nao pode ser vazio!" << endl;
			cout << "Por favor tente outra vez: ";
		}
		catch(IsNotNumberException &e){
			cout << e.getString() << " contem digitos. Apenas sao validos caracteres nao numericos para o nome" << endl;
			cout << "Por favor tente outra vez: ";
		}
		tentativas++;
	}

	if(tentativas>=TRIES)
	cout << "Erro, numero de tentativas excedido." << endl;

	return "";

}


bool confirm()
{
	string temp;
	cout << "Pressione Y para aceitar ou outra tecla para cancelar: ";
	getline(cin,temp);
	if (temp=="Y" || temp == "y")
	{
		return true;
	}
	else
		return false;
}

bool isDataShortFormato(string data)
{
	bool foundT=false;
	string temp;
	int hora, minutos;
	int npos;
	stringstream ss;

for (unsigned int i=0; i<data.size(); i++)
{
	if(foundT==false && data[i]=='-')
	{
		npos=i;
		foundT=true;
	}
	else if(!isdigit(data[i]))
	return false;
}

temp=data.substr(0,npos);
ss<<temp;
ss>>hora;
ss.clear();
ss.str("");
temp=data.substr(npos+1,data.size());
ss<<temp;
ss>>minutos;
ss.clear();
ss.str("");

InBoundsException horaException(0,24,hora);
InBoundsException minutosException(0,60,minutos);
if(!horaException.notOutOfBounds())
	throw horaException;
if(!minutosException.notOutOfBounds())
	throw minutosException;

return true;
}


bool isDataLongFormato(string data)
{
	vector<int> npos;
	string temp;
	int ano, mes, dia,hora, minutos;
	stringstream ss;

for (unsigned int i=0; i<data.size(); i++)
{
	if(data[i]=='-')
	{
		npos.push_back(i);
	}
	else if(!isdigit(data[i])) {
		return false;
	}
}

if(npos.size()!=4)
	return false;

temp=data.substr(0,npos[0]);
ss<<temp;
ss>>ano;
ss.clear();
ss.str("");
temp=data.substr(npos[0]+1,npos[1]);
ss<<temp;
ss>>mes;
ss.clear();
ss.str("");
temp=data.substr(npos[1]+1,npos[2]);
ss<<temp;
ss>>dia;
ss.clear();
ss.str("");
temp=data.substr(npos[2]+1,npos[3]);
ss<<temp;
ss>>hora;
ss.clear();
ss.str("");
temp=data.substr(npos[3]+1,data.size());
ss<<temp;
ss>>minutos;
ss.clear();
ss.str("");

InBoundsException mesException(1,12,mes);


if((dia>30) && (mes==4 || mes==6 || mes==9 || mes==11))
{
	InBoundsException diaException(1,30,dia);
	if(!diaException.notOutOfBounds())
		throw diaException;
}
else if((dia>31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12))
{
	InBoundsException diaException(1,31,dia);
	if(!diaException.notOutOfBounds())
		throw diaException;
}
else if(anoBi(ano) && dia>29 && mes==2 )
{
	InBoundsException diaException(1,29,dia);
	if(!diaException.notOutOfBounds())
		throw diaException;
}
else if(!anoBi(ano) && dia>28 && mes==2)
{
	InBoundsException diaException(1,28,dia);
	if(!diaException.notOutOfBounds())
		throw diaException;
}

InBoundsException horaException(0,24,hora);
InBoundsException minutosException(0,60,minutos);
if(!mesException.notOutOfBounds())
	throw mesException;
if(!horaException.notOutOfBounds())
	throw horaException;
if(!minutosException.notOutOfBounds())
	throw minutosException;

return true;
}

bool isNotNumber(string name)
{
	for (unsigned int i = 0; i<name.size(); i++)
			{
				if (isdigit(name[i]))
					return false;
			}
	return true;
}

bool stringIsEmpty(string name)
{
	if (name.size() == 0 ) {
		return true;
	}
	return false;
}

bool verifyIdExistsOnVector(int id, vector<int> ids) {
	bool equal = false;
	for(unsigned int i=0; i< ids.size(); i++) {
		if(id == ids[i]) {
			equal = true;
		}
	}
	return equal;
}


bool anoBi(int ano)
{
	 if ((ano % 4 == 0) &&(ano % 100 == 0) && (ano % 400 == 0))
		 return true;
	 return false;
}
