/*
 * Horario.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário Fernandes, Cristiana Ribeiro, Sérgio Salgado
 */

#include "Horario.h"
#include <ctime>

Horario::Horario() {
	// TODO Auto-generated constructor stub

}

Horario::~Horario() {
	// TODO Auto-generated destructor stub
}

Horario::Horario(Data inicial, Data final)
{
	tm timeStruct = {};
	timeStruct.tm_year = inicial.getAno() - 1900;
	timeStruct.tm_mon = inicial.getMes() - 1;
	timeStruct.tm_mday = inicial.getDia();
	timeStruct.tm_hour = 12;
	mktime( &timeStruct );
	this->id=timeStruct.tm_wday+1;
	switch(id)
		{
		case 1:
			this->dia_semana="Domingo";
			break;
		case 2:
			this->dia_semana="Segunda-feira";
			break;
		case 3:
			this->dia_semana="Terca-feira";
			break;
		case 4:
			this->dia_semana="Quarta-feira";
			break;
		case 5:
			this->dia_semana="Quinta-feira";
			break;
		case 6:
			this->dia_semana="Sexta-feira";
			break;
		case 7:
			this->dia_semana="Sabado";
			break;
		}
	this->inicial=inicial;
	this->final=final;
}

Horario::Horario(int id, string inicio, string fim)
{
	this->id=id;
	switch(id)
	{
	case 1:
		this->dia_semana="Domingo";
		break;
	case 2:
		this->dia_semana="Segunda-feira";
		break;
	case 3:
		this->dia_semana="Terca-feira";
		break;
	case 4:
		this->dia_semana="Quarta-feira";
		break;
	case 5:
		this->dia_semana="Quinta-feira";
		break;
	case 6:
		this->dia_semana="Sexta-feira";
		break;
	case 7:
		this->dia_semana="Sabado";
		break;
	}
	Data inicial(inicio);
	Data final(fim);
	this->inicial=inicial;
	this->final=final;
}

Horario::Horario(string dia_semana, string inicio, string fim)
{
this->dia_semana=dia_semana;
if (dia_semana=="Domingo")
{
	this->id=1;
}
else if (dia_semana=="Segunda-feira")
{
	this->id=2;
}
else if (dia_semana=="Terca-feira")
{
	this->id=3;
}
else if (dia_semana=="Quarta-feira")
{
	this->id=4;
}
else if (dia_semana=="Quinta-feira")
{
	this->id=5;
}
else if (dia_semana=="Sexta-feira")
{
	this->id=6;
}
else if (dia_semana=="Sabado")
{
	this->id=7;
}
Data inicial(inicio);
Data final(fim);
this->inicial=inicial;
this->final=final;
}

Data Horario::getInicial() const
{
	return inicial;
}

Data Horario::getFinal() const
{
	return final;
}

int Horario::getId() const
{
	return id;
}

void Horario::setDia_semana(string dia_semana)
{
	this->dia_semana = dia_semana;
}

void Horario::setInicial(Data inicial)
{
	this->inicial = inicial;
}

void Horario::setFinal(Data final)
{
	this->final = final;
}

string Horario::getDia_semana() const
{
	return dia_semana;
}

bool operator==(const Horario & horario, const Horario & horario2)
{
	if (horario.getId()==horario2.getId() && compareShortData(horario.getInicial(),horario2.getInicial())  && compareShortData(horario.getFinal(),horario2.getFinal()))
	{
		return true;
	}

	return false;
}

bool Horario::operator <(Horario horario)
{
	return true;
}

ostream & operator<<(ostream &os, Horario hor)
{
 return os << hor.getDia_semana() << endl << hor.getInicial().printData()<< endl << hor.getFinal().printData();
}

string Horario::printHorario()
{
	string temp="";
	temp.append(this->getInicial().printData());
	temp.append("\n");
	temp.append(this->getFinal().printData());

	return temp;
}


bool verifyHorarioCompativel(Horario horario1, Horario horario_a_verificar)
{
	if(horario1.getId()==horario_a_verificar.getId())
	{
		if(horario_a_verificar.getInicial().getHora()>horario1.getInicial().getHora())
		{
			if(horario_a_verificar.getFinal().getHora()<horario1.getFinal().getHora())
				return true;
			else if(horario_a_verificar.getFinal().getHora()==horario1.getFinal().getHora())
			{
				if(horario_a_verificar.getFinal().getMinutos()<=horario1.getFinal().getHora())
					return true;
			}
		}
		else if(horario_a_verificar.getInicial().getHora()==horario1.getInicial().getHora())
		{
			if(horario_a_verificar.getInicial().getMinutos()>=horario1.getInicial().getMinutos())
			{
				//esta dentro das horas e minutos iniciais, verificar agora para as finais
				if(horario_a_verificar.getFinal().getHora()< horario1.getFinal().getHora())
					return true;
				else if (horario_a_verificar.getFinal().getHora()==horario1.getFinal().getHora())
				{
					if(horario_a_verificar.getFinal().getMinutos()<= horario1.getFinal().getMinutos())
						return true;
				}
			}
		}
	}
	return false;
}

bool verifyAulaNaoCompativel(Horario horario1, Horario horario_a_verificar)
{
	if (horario1.getInicial().getAno()!=horario_a_verificar.getInicial().getAno())
		return false;
	if (horario1.getInicial().getMes()!=horario_a_verificar.getInicial().getMes())
		return false;
	if (horario1.getInicial().getDia()!=horario_a_verificar.getInicial().getDia())
		return false;
	if((horario_a_verificar.getInicial().getHora()<horario1.getFinal().getHora()) ||
			((horario_a_verificar.getInicial().getHora()==horario1.getFinal().getHora()) &&
					(horario_a_verificar.getInicial().getMinutos()<horario1.getFinal().getMinutos())) )
	{
		//aula a verificar inicia-se mais cedo da hora do que o fim da aula 1
		//verificar se a hora/minutos a que acaba é depois da inicial da aula1
		if(horario_a_verificar.getFinal().getHora()>horario1.getInicial().getHora())
		{
			return true;
		}
		else if(horario_a_verificar.getFinal().getHora()==horario1.getInicial().getHora())
		{
			if(horario_a_verificar.getFinal().getMinutos()>horario1.getInicial().getMinutos())
			{
				return true;
			}
		}
	}
	else if(horario_a_verificar.getInicial().getHora()==horario1.getInicial().getHora())
	{
		if(horario_a_verificar.getInicial().getMinutos()==horario1.getInicial().getMinutos())
		{
			//aula a verificar inicia-se ao mesmo tempo que a aula 1 (imediatamente return true)
			return true;
		}
	}
	return false;
}
