/*
 * Data.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário Fernandes, Cristiana Ribeiro, Sérgio Salgado
 */

#include "Data.h"

Data::Data() {
	// TODO Auto-generated constructor stub

}

Data::~Data() {
	// TODO Auto-generated destructor stub
}


Data::Data(unsigned int ano, unsigned int mes, unsigned int dia, unsigned int hora, unsigned int minutos)
{
	if(minutos==60)
	{
		this->minutos=0;
		this->hora=hora+1;
	}
	else
	{
		this->minutos=minutos;
		this->hora=hora;
	}
	this->ano=ano;
	this->mes=mes;
	this->dia=dia;
	this->constant=false;
}


Data::Data(string data)
{
	unsigned int type=0, ano, mes, dia, hora, minutos;
	vector <unsigned int> npos;
	stringstream ss;
	string temp;

	for(unsigned int i =0; i<data.size(); i++)
	{
		if (data[i]=='-')
		{
			type++;
			npos.push_back(i);
		}
	}

	switch(type)
	{
		case 1:
		{
			temp=data.substr(0,npos[0]);
			ss<<temp;
			ss>>hora;
			ss.clear();
			ss.str("");
			temp=data.substr(npos[0]+1,data.size());
			ss<<temp;
			ss>>minutos;
			ss.clear();
			ss.str("");
			this->hora=hora;
			this->minutos=minutos;
			this->constant=true;
			break;
		}
		case 4:
		{
			temp=data.substr(0,4);
			ss<<temp;
			ss>>ano;
			ss.clear();
			ss.str("");
			temp=data.substr(5,2);
			ss<<temp;
			ss>>mes;
			ss.clear();
			ss.str("");
			temp=data.substr(8,2);
			ss<<temp;
			ss>>dia;
			ss.clear();
			ss.str("");
			temp=data.substr(11,2);
			ss<<temp;
			ss>>hora;
			ss.clear();
			ss.str("");
			temp=data.substr(14,2);
			ss<<temp;
			ss>>minutos;
			ss.clear();
			ss.str("");
			this->ano=ano;
			this->mes=mes;
			this->dia=dia;
			this->hora=hora;
			this->minutos=minutos;
			this->constant=false;
			break;
		}
	}
}

unsigned int Data::getDia() const
{
	return dia;
}
unsigned int Data::getMes() const
{
	return mes;
}
unsigned int Data::getAno() const
{
	return ano;
}
unsigned int Data::getHora() const
{
	return hora;
}
unsigned int Data::getMinutos() const
{
	return minutos;
}

void Data::setDataParc(unsigned int dia, unsigned int hora, unsigned int minutos)
{
	this->dia = dia;
	this->hora = hora;
	this->minutos = minutos;
}

void Data::setDataTot(unsigned int dia, unsigned int mes, unsigned int ano, unsigned int hora, unsigned int minutos)
{
	this->minutos = (minutos%60);
	int horad=(floor(minutos/60));
	horad=horad%24;
	this->hora=horad+hora;
	this->dia=dia+(floor(hora/24));

bool checking=true;
while(checking)
{
	if((dia>30) && (mes==4 || mes==6 || mes==9 || mes==11))
	{
		this->dia=dia-30;
		this->mes=mes+1;
		checking=true;
	}
	else if((dia>31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12))
	{
		this->dia=dia-31;
		this->mes=mes+1;
		checking=true;
	}
	else if(anoBi(ano) && dia>29 && mes==2 )
	{
		this->dia=dia-29;
		this->mes=mes+1;
		checking=true;
	}
	else if(!anoBi(ano) && dia>28 && mes==2)
	{
		this->dia=dia-28;
		this->mes=mes+1;
		checking=true;
	}
	else
	{
		this->dia=dia;
		this->mes=mes;
		checking=false;
	}
}

	this->mes = (mes%12);
	this->ano = ano+(floor(mes/12));
}

bool Data::getConstant() const
{
	return constant;
}

bool operator<(const Data & data, const Data & data2) //data1 < data2, logo data2 é mais recente que a data1
{
	if(data.getAno() < data2.getAno())
	{
		return true;
	}
	else if(data.getAno() == data2.getAno())
	{
		if(data.getMes() < data2.getMes())
		{
			return true;
		}
		else if(data.getMes() == data2.getMes())
		{
			if(data.getDia() < data2.getDia())
			{
				return true;
			}else if (data.getDia()== data2.getDia())
			{
				if (data.getHora() < data2.getHora())
				{
					return true;
				} else if (data.getHora() == data2.getHora())
				{
					if(data.getMinutos() < data2.getMinutos())
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool operator==(const Data & data, const Data & data2)
{
	if((data.getAno() == data2.getAno()) && (data.getMes() == data2.getMes()) && (data.getDia() == data2.getDia()) && (data.getHora() == data2.getHora()) && (data.getMinutos() == data.getMinutos()))
	{
		return true;
	}
	return false;
}
unsigned int Data::convertDays()
{
	int mes = (this->getMes() + 9) % 12;
	int ano = this->getAno() - mes/10;
	return floor(365*ano + ano/4 - ano/100 + ano/400 + (mes*306 + 5)/10 + ( this->getDia() - 1 ));
}

ostream& operator<<(ostream &os, Data data)
{
	if(data.getConstant())
	{
		return os << data.getHora() << "-" << data.getMinutos();
	}
	else
	{
		return os << data.getAno() << "-" << data.getMes() << "-" << data.getDia() << "-" << data.getHora() << "-" << data.getMinutos();
	}
}

bool compareShortData(const Data & data, const Data & data2)
{
	if ((data.getHora()==data2.getHora()) && (data.getMinutos() == data2.getMinutos()))
	{
		return true;
	}
	else return false;
}

string Data::printData()
{
	stringstream ss;
	string temp="", temp2;
	unsigned int size;
	if(this->getAno()<5000)
	{
	ss<<this->getAno();
	ss>>temp2;
	ss.clear();
	ss.str("");
	temp.append(temp2);
	if (temp2.size()<4)
	{
		size=4-temp2.size();
		for (unsigned int i=0; i<size; i++ )
		{
			temp2.append("0");
		}
	}
	temp.append("-");


	if(this->getMes()<10)
		temp.append("0");
	ss<<this->getMes();
	ss>>temp2;
	ss.clear();
	ss.str("");
	temp.append(temp2);
	if(this->getMes()==10)
		temp.append("0");
	temp.append("-");
	if (this->getDia()<10)
		temp.append("0");
	ss<<this->getDia();
	ss>>temp2;
	ss.clear();
	ss.str("");
	temp.append(temp2);
	if(temp2.size()!=2 && this->getDia()>9)
		temp.append("0");
	temp.append("-");
	}
	if(this->getHora()<10)
		temp.append("0");
	ss<<this->getHora();
	ss>>temp2;
	ss.clear();
	ss.str("");
	temp.append(temp2);
	if(temp2.size()!=2 && this->getHora()>9)
		temp.append("0");
	temp.append("-");
	if(this->getMinutos()<10)
		temp.append("0");
	ss<<this->getMinutos();
	ss>>temp2;
	ss.clear();
	ss.str("");
	temp.append(temp2);
	if (temp2.size()!=2 && this->getMinutos()>9)
	return temp;
}
