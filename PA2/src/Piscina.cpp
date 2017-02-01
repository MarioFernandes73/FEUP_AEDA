/*
 * Piscina.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: Mário Fernandes, Cristiana Ribeiro, Sérgio Salgado
 */

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include "Piscina.h"
#include "Auxiliary.h"

Piscina::Piscina():loja(Item()){}

Piscina::Piscina(string nome_piscina,string password, string lastDayUsed, int XCoord, int YCoord, string ficheiro_utentes, string ficheiro_professores, string ficheiro_horario, string ficheiro_aulas, string ficheiro_aulas_dadas, string ficheiro_loja):loja(Item())
{
	Data novaData = Data(lastDayUsed);
	this->lastDayUsed=novaData;
	pair<int, int> Reais (XCoord, YCoord);
	pair<int, int> Ficticias (0, 0);
	this->coordenadas_Reais = Reais;
	this->coordenadas_Ficticias = Ficticias;
	this->nome_piscina=nome_piscina;
	this->password = password;
	this->ficheiro_utentes=ficheiro_utentes;
	this->ficheiro_professores=ficheiro_professores;
	this->ficheiro_horario=ficheiro_horario;
	this->ficheiro_aulas=ficheiro_aulas;
	this->ficheiro_aulas_dadas=ficheiro_aulas_dadas;
	this->ficheiro_loja=ficheiro_loja;

	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );

	this->dia_atual = Data(now->tm_year + 1900, now->tm_mon + 1,now->tm_mday,now->tm_hour, now->tm_min);
}

string Piscina::getNome() const
{
	return nome_piscina;
}

string Piscina::getFichUt() const
{
	return ficheiro_utentes;
}

string Piscina::getFichProf() const
{
	return ficheiro_professores;
}

string Piscina::getFichHor() const
{
	return ficheiro_horario;
}

string Piscina::getFichAulas() const
{
	return ficheiro_aulas;
}

string Piscina::getFichAulasDadas() const
{
	return ficheiro_aulas_dadas;
}

string Piscina::getFichLj() const
{
	return ficheiro_loja;
}

void Piscina::setNome(string nome_piscina)
{
	this->nome_piscina=nome_piscina;
}

void Piscina::setFichUt(string ficheiro_utentes)
{
	this->ficheiro_utentes=ficheiro_utentes;
}

void Piscina::setFichProf(string ficheiro_professores)
{
	this->ficheiro_professores = ficheiro_professores;
}

void Piscina::setFichHor(string ficheiro_horario)
{
	this->ficheiro_horario=ficheiro_horario;
}

void Piscina::setFichAulas(string ficheiro_aulas)
{
	this->ficheiro_aulas=ficheiro_aulas;
}

void Piscina::setFichLj(string ficheiro_loja)
{
	/*this->ficheiro_loja = ficheiro_loja;*/
}

bool Piscina::loadFichUt()
{
	if (existeFicheiro(getFichUt()))
	{
		int id,idade,saldo,textos, telemovel, idleDays;
		string nome, temp,temptexto, email, morada;
		vector<string>texto;
		stringstream ss;
		ifstream in;

		in.open(getFichUt());
		if(in.is_open())
		{
			while(!in.eof())
			{
				getline(in,temp);
				if(temp=="")
					break;
				ss<<temp;
				ss>>id;
				ss.clear();
				ss.str("");
				getline(in,nome);
				getline(in,temp);
				ss<<temp;
				ss>>idade;
				ss.clear();
				ss.str("");
				getline(in,temp);
				ss<<temp;
				ss>>saldo;
				ss.clear();
				ss.str("");
				getline(in,temp);
				ss<<temp;
				ss>>telemovel;
				ss.clear();
				ss.str("");
				getline(in,email);
				getline(in,morada);
				getline(in,temp);
				ss<<temp;
				ss>>idleDays;
				ss.clear();
				ss.str("");
				getline(in,temp);
				ss<<temp;
				ss>>textos;
				ss.clear();
				ss.str("");

				for(unsigned int i=0; i<textos;i++)
				{
					temptexto="";
					getline(in,temp);
					temptexto.append(temp);
					temptexto.append("\n");
					getline(in,temp);
					temptexto.append(temp);
					temptexto.append("\n");
					getline(in,temp);
					temptexto.append(temp);
					temptexto.append("\n");
					getline(in,temp);
					temptexto.append(temp);
					temptexto.append("\n");
					getline(in,temp);
					temptexto.append(temp);
					temptexto.append("\n");
					texto.push_back(temptexto);
				}
				Utente * newUtente = new Utente(id, nome, idade,saldo,texto,telemovel, email, morada, idleDays);
				utentes.push_back(newUtente);
				texto.clear();
				temptexto.clear();
			}
			in.close();
		}
		else
		{
			cout << "Erro ao abrir o ficheiro de utentes.";
			return false;
		}
	}
	else
	{
		ofstream out;
		out.open(getFichUt());
		out.close();
	}


	return true;
}

bool Piscina::loadFichProf()
{
	if (existeFicheiro(getFichProf()))
	{
		int id,idade;
		string nome, temp,dia_semana, datai, dataf;
		stringstream ss;
		ifstream in;
		vector <Horario> disponibilidade;

		in.open(getFichProf());
		if(in.is_open())
		{
			while(!in.eof())
			{
				getline(in,temp);
				if(temp=="")
					break;
				ss<<temp;
				ss>>id;
				ss.clear();
				ss.str("");
				getline(in,nome);
				getline(in,temp);
				ss<<temp;
				ss>>idade;
				ss.clear();
				ss.str("");
				while(true)
				{
					getline(in,dia_semana);
					if(dia_semana=="--------------------")
					{
						Professor * newProfessor = new Professor(id, nome, idade,disponibilidade);
						professores.push_back(newProfessor);
						disponibilidade.clear();
						break;
					}
					else
					{
						getline(in,datai);
						getline(in,dataf);

						Horario newHorario(dia_semana, datai, dataf);
						disponibilidade.push_back(newHorario);
					}
				}
			}
			in.close();
		}
		else
		{
			cout << "Erro ao abrir o ficheiro de professores.";
			return false;
		}
	}
	else
	{
		ofstream out;
		out.open(getFichUt());
		out.close();
	}

	return true;
}

bool Piscina::loadFichHor()
{
	if (existeFicheiro(getFichHor()))
	{

		string dia_semana, datai, dataf;
		ifstream in;

		in.open(getFichHor());
		if(in.is_open())
		{
			while(!in.eof())
			{
				getline(in,dia_semana);
				if(dia_semana=="")
					break;
				getline(in,datai);
				getline(in,dataf);

				Horario newHorario(dia_semana, datai, dataf);
				horario.push_back(newHorario);
			}
			in.close();
		}
		else
		{
			cout << "Erro ao abrir o ficheiro de horarios.";
			return false;
		}
	}
	else
	{
		ofstream out;
		out.open(getFichHor());
		out.close();
	}

	return true;
}


bool Piscina::loadFichAulas()
{
	if (existeFicheiro(getFichAulas()))
	{
		string identificacao_aula, temp, temp1="Livre", temp2="livre",utentes;
		string data_inicio, data_fim;
		unsigned int preco, id_professor;
		stringstream ss, stream;

		ifstream in;
		in.open(getFichAulas());

		if(in.is_open())
		{
			while(!in.eof())
			{
				getline(in,identificacao_aula);
				if(identificacao_aula=="")
					break;
				if((identificacao_aula.find(temp1)!=string::npos) || (identificacao_aula.find(temp2))!= string::npos)
				{
					getline(in,temp);
					getline(in,data_inicio);
					getline(in,data_fim);
					Horario newHorario(temp,data_inicio,data_fim);
					getline(in,utentes);
					vector<int> ids;
					if(!(utentes=="" || utentes == " "))
					{
						stream << utentes;
						while(1)
						{
							if (!stream)
								break;
							int n;
							stream >> n;
							if(!verifyIdExistsOnVector(n, ids)) {
								ids.push_back(n);
							}

						}
						stream.clear();
						stream.str("");
					}
					AulaLivre * newAula = new AulaLivre(identificacao_aula, newHorario, findUtentes(ids));
					aulas.push_back(newAula);
				}
				else
				{
					getline(in,temp);
					getline(in,data_inicio);
					getline(in,data_fim);
					Horario newHorario(temp,data_inicio,data_fim);
					getline(in,utentes);

					vector<int> ids;
					if(!(utentes=="" || utentes == " "))
					{
						stream << utentes;
						while(1)
						{
							if(!stream)
								break;
							int n;
							stream >> n;
							if(!verifyIdExistsOnVector(n, ids)) {
								ids.push_back(n);
							}
						}
						stream.clear();
						stream.str("");
					}
					getline(in,temp);
					ss<<temp;
					ss>>preco;
					ss.clear();
					ss.str("");
					getline(in,temp);
					ss<<temp;
					ss>>id_professor;
					ss.clear();
					ss.str("");

					AulaAcompanhada * newAula = new AulaAcompanhada(identificacao_aula,newHorario, findUtentes(ids), preco, this->findProfessor(id_professor));
					aulas.push_back(newAula);
				}

			}
			in.close();
		}
		else
		{
			cout << "Erro ao abrir o ficheiro de aulas.";
			return false;
		}
	}
	else
	{
		ofstream out;
		out.open(getFichAulas());
		out.close();
	}

	return true;
}

bool Piscina::loadFichAulasDadas()
{
	if (existeFicheiro(getFichAulasDadas()))
	{
		string identificacao_aula, temp, temp1="Livre", temp2="livre",utentes;
		string data_inicio, data_fim;
		unsigned int preco, id_professor;
		stringstream ss, stream;

		ifstream in;
		in.open(getFichAulasDadas());

		if(in.is_open())
		{
			while(!in.eof())
			{
				getline(in,identificacao_aula);
				if(identificacao_aula=="")
					break;
				if((identificacao_aula.find(temp1)!=string::npos) || (identificacao_aula.find(temp2))!= string::npos)
				{
					getline(in,temp);
					getline(in,data_inicio);
					getline(in,data_fim);
					Horario newHorario(temp,data_inicio,data_fim);
					getline(in,utentes);


					stream << utentes;
					vector<int> ids;
					while(1)
					{
						int n;
						stream >> n;
						if(!verifyIdExistsOnVector(n, ids)) {
							ids.push_back(n);
						}
						if(!stream)
							break;
					}

					stream.clear();
					stream.str("");
					AulaLivre * newAula = new AulaLivre(identificacao_aula, newHorario, findUtentes(ids));
					aulas_dadas.push_back(newAula);
				}
				else
				{
					getline(in,temp);
					getline(in,data_inicio);
					getline(in,data_fim);
					Horario newHorario(temp,data_inicio,data_fim);
					getline(in,utentes);

					stream << utentes;
					vector<int> ids;
					while(1)
					{
						if(!stream)
							break;
						int n;
						stream >> n;
						if(!verifyIdExistsOnVector(n, ids)) {
							ids.push_back(n);
						}
					}
					stream.clear();
					stream.str("");

					getline(in,temp);
					ss<<temp;
					ss>>preco;
					ss.clear();
					ss.str("");
					getline(in,temp);
					ss<<temp;
					ss>>id_professor;
					ss.clear();
					ss.str("");

					AulaAcompanhada * newAula = new AulaAcompanhada(identificacao_aula,newHorario, findUtentes(ids), preco, this->findProfessor(id_professor));
					aulas_dadas.push_back(newAula);
				}

			}
			in.close();
		}
		else
		{
			cout << "Erro ao abrir o ficheiro de aulas dadas.";
			return false;
		}
	}
	else
	{
		ofstream out;
		out.open(getFichAulas());
		out.close();
	}

	return true;
}

bool Piscina::loadFichLj()
{
	if (existeFicheiro(getFichLj()))
	{
		int tamanho, preco, stock;
		string nome, temp;
		stringstream ss;
		ifstream in;

		in.open(getFichLj());
		if (in.is_open())
		{
			while (!in.eof())
			{
				getline(in, nome);
				if (nome == "")
					break;
				getline(in, temp);
				ss << temp;
				ss >> tamanho;
				ss.clear();
				ss.str("");
				getline(in, temp);
				ss << temp;
				ss >> preco;
				ss.clear();
				ss.str("");
				getline(in, temp);
				ss << temp;
				ss >> stock;
				ss.clear();
				ss.str("");

				Item newItem = Item(nome, tamanho, preco, stock);
				loja.insert(newItem);

			}
			in.close();
		}
		else
		{
			cout << "Erro ao abrir o ficheiro de items.";
			return false;
		}
	}
	else
	{
		ofstream out;
		out.open(getFichLj());
		out.close();
	}


	return true;
}

bool Piscina::loadPiscinas()
{

	string nome_piscina, password, X, Y, ficheiro_utentes, ficheiro_professores, ficheiro_horario, ficheiro_aulas, ficheiro_aulas_dadas, ficheiro_loja,
	lastDayUsed;
	stringstream ss;
	int XCoord, YCoord;
	string temp;

	ifstream in;
	in.open(fichload);

	if(in.is_open())
	{
		pair<int, int> realCoordTrue = this->getCoordReais();
		while(!in.eof())
		{
			getline(in,nome_piscina);
			if(nome_piscina!=this->nome_piscina)
			{
				getline(in,password);
				getline(in,lastDayUsed);
				getline(in, X);
				ss<<X;
				ss>>XCoord;
				ss.clear();
				ss.str("");
				getline(in, Y);
				ss<<Y;
				ss>>YCoord;
				ss.clear();
				ss.str("");
				getline(in, ficheiro_utentes);
				getline(in, ficheiro_professores);
				getline(in, ficheiro_horario);
				getline(in, ficheiro_aulas);
				getline(in,ficheiro_aulas_dadas);
				getline(in, ficheiro_loja);
				Piscina tempPiscina(nome_piscina, password, lastDayUsed, XCoord, YCoord, ficheiro_utentes,  ficheiro_professores, ficheiro_horario, ficheiro_aulas, ficheiro_aulas_dadas, ficheiro_loja);

				tempPiscina.loadFichUt();
				tempPiscina.loadFichProf();
				tempPiscina.loadFichHor();
				tempPiscina.loadFichAulas();
				tempPiscina.loadFichAulasDadas();


				pair<int, int> realCoordTemp = tempPiscina.getCoordReais();

				tempPiscina.setCoordFicticias(realCoordTemp.first - realCoordTrue.first, realCoordTemp.second - realCoordTrue.second );

				this->piscinas.push(tempPiscina);
			}
			else
				for(unsigned int i=0; i<10; i++)
				{
					getline(in, temp);
				}

		}
	}
	else
	{
		cout << "Erro ao abrir o ficheiro de piscinas.";
		return false;
	}
	return true;
}


Piscina::~Piscina() {}

bool Piscina::saveUtentes()
{
	ofstream out;
	if(existeFicheiro(getFichUt()))
	{
		out.open(getFichUt(), iostream::trunc);
		if (out.is_open())
		{
			for (unsigned int i =0; i<utentes.size(); i++)
			{
				if(i!=utentes.size()-1)
				{
					if(this->utentes[i]->getDespesas().size()==0)
						out << utentes[i] <<endl << this->utentes[i]->getDespesas().size()<< endl;
					else
					{
						out << utentes[i]<<endl<< this->utentes[i]->getDespesas().size();
						for(unsigned int j=0; j<this->utentes[i]->getDespesas().size(); j++)
						{
							out << endl <<utentes[i]->getDespesas()[j];
						}
					}
				}
				else
				{
					if(this->utentes[i]->getDespesas().size()==0)
						out << utentes[i] << endl << this->utentes[i]->getDespesas().size();
					else
					{
						out << utentes[i]<<endl<< this->utentes[i]->getDespesas().size();
						for(unsigned int j=0; j<this->utentes[i]->getDespesas().size(); j++)
						{
							out << endl <<utentes[i]->getDespesas()[j];
						}
					}
				}
			}
			out.close();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Piscina::saveProfessores()
{
	ofstream out;
	if(existeFicheiro(getFichProf()))
	{
		out.open(getFichProf(), iostream::trunc);
		if (out.is_open())
		{
			for (unsigned int i =0; i<professores.size(); i++)
			{
				if(i==professores.size()-1)
					out << professores[i];
				else
					out<< professores[i] << endl;
			}
			out.close();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Piscina::saveHorario()
{
	ofstream out;
	if(existeFicheiro(getFichHor()))
	{
		out.open(getFichHor(), iostream::trunc);
		if (out.is_open())
		{
			for (unsigned int i =0; i<horario.size(); i++)
			{
				if(i==horario.size()-1)
				{
					out << horario[i];
				}
				else
				{
					out << horario[i] << endl;
				}
			}
			out.close();
			return true;
		}
		else
			return false;

	}
	else
		return false;
}

bool Piscina::saveAulas()
{
	int x;
	ofstream out;
	if(existeFicheiro(getFichAulas()))
	{
		out.open(getFichAulas(), iostream::trunc);
		if (out.is_open())
		{
			for (unsigned int i =0; i<aulas.size(); i++)
			{
				if(i==aulas.size()-1)
					out << aulas[i]->printAula();
				else
					out << aulas[i]->printAula() << endl;
			}
			out.close();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Piscina::saveAulasDadas()
{
	ofstream out;
	if(existeFicheiro(getFichAulasDadas()))
	{
		out.open(getFichAulasDadas(), iostream::trunc);
		if (out.is_open())
		{
			for (unsigned int i =0; i<aulas_dadas.size(); i++)
			{
				if(i==aulas_dadas.size()-1)
					out << aulas_dadas[i]->printAula();
				else
					out << aulas_dadas[i]->printAula() << endl;
			}
			out.close();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Piscina::saveLoja()
{
	ofstream out;
	BST<Item> temp2 = this->getLoja();
	BSTItrIn<Item> it(temp2);
	BSTItrIn<Item> it2 = it;

	if (existeFicheiro(getFichLj()))
	{
		out.open(getFichLj(), iostream::trunc);
		if (out.is_open())
		{
			while (!it.isAtEnd()) {
				it2 = it;
				it2.advance();
				if(it2.isAtEnd())
					out << it.retrieve().getNome() << endl << it.retrieve().getTamanho()<< endl << it.retrieve().getPreco() << endl << it.retrieve().getStock();
				else
					out << it.retrieve().getNome() << endl << it.retrieve().getTamanho()<< endl << it.retrieve().getPreco() << endl << it.retrieve().getStock() << endl;

				it.advance();
			}
			out.close();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void Piscina::addUtente(Utente * ut)
{
	utentes.push_back(ut);
}

void Piscina::removerUtente(Utente * ut)
{
	for (unsigned int i = 0; i< utentes.size(); i++)
	{
		if (ut==utentes[i])
		{
			utentes.erase(utentes.begin()+i);
			break;
		}
	}

	for (unsigned int i = 0; i<aulas.size(); i++)
	{
		aulas[i]->removeUtente(ut);
	}
}

vector<Utente *> Piscina::getUtentes() const
{
	return utentes;
}


void Piscina::addProfessor(Professor * p)
{
	if(notInVector(professores, p))
	{
		professores.push_back(p);
	}
	else
	{
		throw InsertVectorException<Professor *>(professores ,p);
	}

}

vector<Professor *> Piscina:: getProfessores() const
{
	return professores;
}


vector<Horario> Piscina::getHorario() const
{
	return horario;
}

vector<Aula *> Piscina::getAulas() const
{
	return aulas;
}

bool Piscina::sortUtenteByName(const Utente *p1, const Utente *p2)
{
	return p1->getNome() < p2->getNome();
}

bool Piscina::sortUtenteByID(const Utente *p1, const Utente *p2)
{
	return p1->getId() < p2->getId();
}

bool Piscina::sortUtenteByAge(const Utente *p1, const Utente *p2)
{
	return p1->getIdade() < p2->getIdade();
}

bool Piscina::sortUtenteBySaldo(const Utente *p1, const Utente *p2)
{
	return p1->getSaldo() < p2->getSaldo();
}

bool Piscina::sortProfessorByName(const Professor *p1, const Professor *p2)
{
	return p1->getNome() < p2->getNome();
}

bool Piscina::sortProfessorByID(const Professor *p1, const Professor *p2)
{
	return p1->getId() < p2->getId();
}

bool Piscina::sortProfessorByAge(const Professor *p1, const Professor *p2)
{
	return p1->getIdade() < p2->getIdade();
}

//PARA FUNCAO SAVE!!!
vector<Utente *> Piscina::findUtentes(vector<int> ids)
{

	vector<Utente *> foundUts;
	for (unsigned int i=0; i<ids.size(); i++)
	{
		for (unsigned int j=0; j<this->getUtentes().size(); j++)
		{
			if (ids[i]==this->getUtentes()[j]->getId())
				foundUts.push_back(this->getUtentes()[j]);
		}
	}
	return foundUts;
}

//PARA FUNCAO SAVE!!!
Professor * Piscina::findProfessor(int id)
{
	for (unsigned int i=0; i<this->getProfessores().size(); i++)
	{
		if (id==this->getProfessores()[i]->getId())
			return this->getProfessores()[i];
	}
	return NULL;
}

Professor * Piscina::findProfessorMenosAulas(vector<Professor *> profs_disponiveis)
{
	string temp1 = "acompanhada_", temp2 = "Acompanhada_";
	vector <Professor *> profs_iterados;
	int contador=9999,cont_temp,id=-1;
	for (unsigned int i=0; i<this->getAulas().size();i++)
	{
		if ((this->getAulas()[i]->getIdentificacaoAula().find(temp1) != string::npos) || (this->getAulas()[i]->getIdentificacaoAula().find(temp1) != string::npos))
		{
			if(find(profs_disponiveis.begin(),profs_disponiveis.end(),this->getAulas()[i]->getEncarregado())!=profs_disponiveis.end())
			{
				profs_iterados.push_back(this->getAulas()[i]->getEncarregado());
				cont_temp = 0;
				for (unsigned int j = 0; j < this->getAulas().size(); j++)
				{
					if (this->getAulas()[i]->getEncarregado() == this->getAulas()[j]->getEncarregado())
					{
						cont_temp++;
					}
				}
				if (contador > cont_temp)
				{
					contador = cont_temp;
					id = this->getAulas()[i]->getEncarregado()->getId();
				}
			}
		}
	}

	if(id==-1)
		return profs_disponiveis[0];
	else
	{
		//verificar se ha algum professor sem aulas atribuidas
		for (unsigned int i=0; i<profs_disponiveis.size(); i++)
		{
			if(find(profs_iterados.begin(),profs_iterados.end(),profs_disponiveis[i])==profs_iterados.end())
				return profs_disponiveis[i];
		}

		return this->findProfessor(id);
	}

}

void Piscina::removerProfessor(Professor * prof)
{
	string temp1 = "acompanhada_", temp2 = "Acompanhada_";

	if(professores.size()<=1)
		throw InsuficientUsersException();


	for(unsigned int k =0; k<this->getAulas().size();k++)
	{
		//verifica que é uma aula acompanhada
		if ((this->getAulas()[k]->getIdentificacaoAula().find(temp1) != string::npos) || (this->getAulas()[k]->getIdentificacaoAula().find(temp1) != string::npos))
		{
			//verificar que existe um professor disponivel para essa aula e substituir pelo que tem menos aulas associadas a ele
			vector <Professor *> profs_disponiveis;

			for(unsigned int i=0; i<this->getProfessores().size();i++)
			{
				//verificar que nao é o professor que estou a retirar
				if(this->getProfessores()[i]!=prof)
				{
					for(unsigned int j=0; j<this->getProfessores()[i]->getDisponibilidade().size();j++)
					{
						if(verifyHorarioCompativel(this->getProfessores()[i]->getDisponibilidade()[j],this->getAulas()[k]->getHorario()))
							profs_disponiveis.push_back(this->getProfessores()[i]);
					}
				}
			}

			if(profs_disponiveis.size()==0)
			{
				//lanca excepcao E PREVINE QUE SE APAGUE O PROFESSOR!
				cout << "NAO HA PROFESSORES DISPONIVEIS PARA UMA DAS AULAS" << endl;
				return;

			}

			this->getAulas()[k]->setProfessor(this->findProfessorMenosAulas(profs_disponiveis));
		}
	}
	for (unsigned int i =0; i<professores.size(); i++)
	{
		if (professores[i]->getId()==prof->getId())
		{
			professores.erase(professores.begin()+i);
			break;
		}
	}

}


/*Funções de Aulas*/

void Piscina::addAula(Aula * aula)
{
	this->aulas.push_back(aula);
	cout << "Aula criada com sucesso!" << endl;
}


void Piscina::updateAulasDadas()
{
	for(unsigned int i =0; i<this->aulas.size();i++)
	{
		if(this->aulas[i]->getHorario().getFinal()<this->dia_atual)
		{
			for(unsigned int j=0; j<this->aulas[i]->getUtentes().size(); j++)
			{
				this->aulas[i]->getUtentes()[j]->setIdleDays(0);
			}
			this->aulas_dadas.push_back(this->aulas[i]);
			this->aulas.erase(this->aulas.begin()+i);
			i--;
		}
	}
}

void Piscina::updatePagamentoDespesas()
{
	for (unsigned int i=0; i<this->aulas_dadas.size(); i++)
	{
		for(unsigned int j=0; j<this->aulas_dadas[i]->getUtentes().size(); j++)
		{
			if(this->aulas_dadas[i]->getUtentes()[j]->getSaldo()>= this->aulas_dadas[i]->getPreco())
			{
				this->aulas_dadas[i]->getUtentes()[j]->retirarSaldo(this->aulas_dadas[i]->getPreco());
				string despesa = aulas_dadas[i]->constroiDespesa();
				this->aulas_dadas[i]->getUtentes()[j]->pushDespesa(despesa);
				this->aulas_dadas[i]->removeUtente(this->aulas_dadas[i]->getUtentes()[j]);
				if(this->aulas_dadas[i]->getUtentes().size() == 0)
				{
					cout << "Aula " << this->aulas_dadas[i]->getIdentificacaoAula() << " totalmente paga!"<< endl;
					this->aulas_dadas.erase(aulas_dadas.begin()+i);
				}
			}
			else
			{
				throw SaldoInsuficienteException(this->aulas_dadas[i]->getUtentes()[j]->getNome(),this->aulas_dadas[i]->getUtentes()[j]->getSaldo());
			}
		}
	}
}

bool Piscina::removerAula(Aula * au)
{
	for(unsigned int i = 0; i < aulas.size(); i++)
	{
		if (aulas[i]->getIdentificacaoAula() == au->getIdentificacaoAula())
		{
			aulas.erase(aulas.begin() + i);
			i--;
			return true;
		}
	}
	return false;
}

void Piscina::addUtenteAAula(string id_aula, Utente * ut)
{
	for (unsigned int i = 0; i < aulas.size(); i++)
	{
		if (aulas[i]->getIdentificacaoAula() == id_aula)
		{
			if(notInVector(aulas[i]->getUtentes(), ut))
			{
				aulas[i]->getUtentes().push_back(ut);
			}
		}
	}
}


void Piscina::addHorario(Horario horario)
{
	this->horario.push_back(horario);
	cout << "Horario criado com sucesso!" << endl;
}

bool Piscina::removerHorario(Horario horario)
{
	for (unsigned int i=0; this->getHorario().size(); i++)
	{
		if (this->getHorario()[i]==horario)
		{
			this->horario.erase(this->horario.begin()+i);
			return true;
		}
	}
	return false;
}

bool Piscina::sortAulaByNome(const Aula *a1, const Aula *a2) {
	return a1->getIdentificacaoAula() < a2->getIdentificacaoAula();
}

bool Piscina::sortAulaByHorario(const Aula *a1, const Aula *a2) {
	return a1->getHorario() < a2->getHorario();
}


bool Piscina::verifyAulaNovoUtente(Aula * aula)
{
	if(dynamic_cast<AulaAcompanhada *> (aula))
	{
		//verificar se a aula está em conjunto com mais alguma aula livre
		for(unsigned int i=0; i<this->getAulas().size(); i++)
		{
			if(verifyAulaNaoCompativel(this->getAulas()[i]->getHorario(),aula->getHorario()))
			{
				//se estiver, verificar se mais 1 utente excede o limite de utentes para todas as aulas
				if(((this->getAulas()[i]->getUtentes().size())+ (aula->getUtentes().size()) + 1 ) > MAXIMUM_UTS)
				{
					//se sim, retirar o ultimo dessa aula livre
					this->aulas[i]->getUtentes().pop_back();
				}
			}
		}
		return true;
	}
	else if(dynamic_cast<AulaLivre *> (aula))
	{
		//verificar se a aula está em conjunto com mais alguma aula
		for(unsigned int i=0; i<this->getAulas().size(); i++)
		{
			if(verifyAulaNaoCompativel(this->getAulas()[i]->getHorario(),aula->getHorario()))
			{
				//se estiver, verificar se mais 1 utente excede o limite de utentes para todas as aulas
				if(((this->getAulas()[i]->getUtentes().size())+ (aula->getUtentes().size()) + 1 ) > MAXIMUM_UTS)
				{
					//se houver algum caso, nao se pode adicionar mais utentes a esta aula livre
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

Data Piscina::getDiaAtual()
{
	return this->dia_atual;
}

bool Piscina::sortHorarioPiscina(const Horario horario1, const Horario horario2)
{
	return horario1.getId()<horario2.getId();
}


void Piscina::updatePagamentoDespesas(Utente * ut)
{
	for (unsigned int i=0; i<this->aulas_dadas.size(); i++)
	{
		for(unsigned int j=0; j<this->aulas_dadas[i]->getUtentes().size(); j++)
		{
			if(this->aulas_dadas[i]->getUtentes()[j]==ut)
			{
				if(this->aulas_dadas[i]->getUtentes()[j]->getSaldo()>= this->aulas_dadas[i]->getPreco())
				{
					this->aulas_dadas[i]->getUtentes()[j]->retirarSaldo(this->aulas_dadas[i]->getPreco());
					string despesa = aulas_dadas[i]->constroiDespesa();
					this->aulas_dadas[i]->getUtentes()[j]->pushDespesa(despesa);
					this->aulas_dadas[i]->removeUtente(this->aulas_dadas[i]->getUtentes()[j]);
					if(this->aulas_dadas[i]->getUtentes().size() == 0)
					{
						cout << "Aula " << this->aulas_dadas[i]->getIdentificacaoAula() << " totalmente paga!"<< endl;
						this->aulas_dadas.erase(aulas_dadas.begin()+i);
					}
				}
				else
				{
					throw SaldoInsuficienteException(this->aulas_dadas[i]->getUtentes()[j]->getNome(),this->aulas_dadas[i]->getUtentes()[j]->getSaldo());
				}
			}
		}
	}
}


pair<int, int> Piscina::getCoordFicticias() const
{
	return this->coordenadas_Ficticias;
}

pair<int, int> Piscina::getCoordReais() const
{
	return this->coordenadas_Reais;
}


bool Piscina::operator<(const Piscina& P1) const
{
	pair<int, int> coordenadasAtuais = this->getCoordFicticias();
	pair<int, int> coordenadasOutra = P1.getCoordFicticias();

	int distance1 = sqrt(coordenadasAtuais.first^2+coordenadasAtuais.second^2);
	int distance2 = sqrt(coordenadasOutra.first^2+coordenadasOutra.second^2);

	return distance1>distance2;

}


Piscina Piscina::findPiscinaPerto(string nome_aula)
{
	for(unsigned int i=0; i<this->getAulas().size(); i++)
	{
		if(this->getAulas()[i]->getIdentificacaoAula() == nome_aula)
			return *this;
	}

	priority_queue <Piscina> temp =this->piscinas;

	while(!temp.empty())
	{
		for(unsigned int i = 0; i<temp.top().getAulas().size(); i++)
		{
			if(temp.top().getAulas()[i]->getIdentificacaoAula() == nome_aula)
				return temp.top();
		}
		temp.pop();
	}

	Piscina piscinanull = Piscina();
	piscinanull.setNome("erro");
	return piscinanull;
}

void Piscina::setCoordFicticias(int XCoord, int YCoord)
{
	pair<int, int> Ficticias (XCoord, YCoord);
	this->coordenadas_Ficticias = Ficticias;
}

string Piscina::printPiscinas()
{
	string info="";
	priority_queue<Piscina> temp = this->piscinas;
	while(!temp.empty())
	{
		info.append(temp.top().getNome());
		info.append("\n");
		temp.pop();
	}
	return info;
}

void Piscina::updateHashTable()
{
	for (unsigned int i =0; i<this->getUtentes().size(); i++)
	{
		if(this->getUtentes()[i]->getIdleDays() > IDLE_LIMIT)
		{
			this->utentes_Idle.insert(this->getUtentes()[i]);
		}
	}
}

string Piscina::printHashTable()
{
	string utentes="", temp;
	tabHutente::iterator it = this->utentes_Idle.begin();
	tabHutente::iterator ite = this->utentes_Idle.end();
	stringstream ss;
	while(it!=ite)
	{
		int id = (*it)->getId();
		ss << id;
		ss>> temp;
		ss.clear();
		ss.str("");
		utentes.append(temp);
		utentes.append("\n");
		utentes.append((*it)->getNome());
		utentes.append("\n");
		int idleDays = (*it)->getIdleDays();
		ss << idleDays;
		ss>> temp;
		ss.clear();
		ss.str("");
		utentes.append(temp);
		utentes.append("\n");
		it++;
	}

	return utentes;
}

vector<Utente*> Piscina::getIdleUts()
{
	vector<Utente *> uts;
	tabHutente::iterator it = this->utentes_Idle.begin();
	tabHutente::iterator ite = this->utentes_Idle.end();
	while(it!=ite)
	{
		uts.push_back((*it));
		it++;
	}

	return uts;
}

void Piscina::removeIdle()
{
	tabHutente::iterator it = this->utentes_Idle.begin();
	tabHutente::iterator ite = this->utentes_Idle.end();
	while(it!=ite)
	{
		(*it)->setIdleDays(0);
		it=utentes_Idle.erase(it);
	}
}

void Piscina::addIdleDays(int days)
{
	for(unsigned int i=0; i<this->getUtentes().size(); i++)
	{
		this->getUtentes()[i]->addIdleDays(days);
	}
}

Data Piscina::getLastDayUsed()
{
	return this->lastDayUsed;
}

void Piscina::addItemToStore(Item it) {
	loja.insert(it);
}

string Piscina::printInventory() {
	string info = "", temp2="", tamanhoString = "";
	stringstream ss;
	BST<Item> temp = this->loja;
	BSTItrIn<Item> it(loja);
	while (!it.isAtEnd()) {
		info.append("Item: ");
		info.append(it.retrieve().getNome());
		info.append(" Tamanho: ");
		switch (it.retrieve().getTamanho()){
		case 1:
			tamanhoString = "Small";
			break;
		case 2:
			tamanhoString = "Medium";
			break;
		case 3:
			tamanhoString = "Large";
			break;
		case 4:
			tamanhoString = "Extra Large";
			break;
		default:
			break;
		}
		info.append(tamanhoString);
		info.append(" Preco: ");
		ss << it.retrieve().getPreco();
		ss >>temp2;
		ss.clear();
		ss.str("");
		info.append(temp2);
		info.append(" Stock: ");
		ss << it.retrieve().getStock();
		ss >> temp2;
		ss.clear();
		ss.str("");
		info.append(temp2);
		info.append("\n");
		it.advance();
	}
	return info;
}

BST<Item> Piscina::getLoja()
{
	return this->loja;
}

string Piscina::getReport(string nome_aula)
{
	string res="", temp;
	stringstream ss;
	for(unsigned int i=0; i<this->getAulas().size(); i++)
	{
		if(this->getAulas()[i]->getIdentificacaoAula() == nome_aula)
		{
			res.append("Aula no dia ");
			ss<<this->getAulas()[i]->getHorario().getInicial().getAno();
			ss>>temp;
			ss.clear();
			ss.str("");
			res.append(temp);
			res.append("-");
			ss<<this->getAulas()[i]->getHorario().getInicial().getMes();
			ss>>temp;
			ss.clear();
			ss.str("");
			res.append(temp);
			res.append("-");
			ss<<this->getAulas()[i]->getHorario().getInicial().getDia();
			ss>>temp;
			ss.clear();
			ss.str("");
			res.append(temp);
			res.append(" na piscina ");
			res.append(this->getNome());
			res.append("\n\n");
		}
	}

	priority_queue <Piscina> temp2 =this->piscinas;

	while(!temp2.empty())
	{
		for(unsigned int i = 0; i<temp2.top().getAulas().size(); i++)
		{
			if(temp2.top().getAulas()[i]->getIdentificacaoAula() == nome_aula)
			{
				res.append("Aula no dia ");
				ss<<temp2.top().getAulas()[i]->getHorario().getInicial().getAno();
				ss>>temp;
				ss.clear();
				ss.str("");
				res.append(temp);
				res.append("-");
				ss<<temp2.top().getAulas()[i]->getHorario().getInicial().getMes();
				ss>>temp;
				ss.clear();
				ss.str("");
				res.append(temp);
				res.append("-");
				ss<<temp2.top().getAulas()[i]->getHorario().getInicial().getDia();
				ss>>temp;
				ss.clear();
				ss.str("");
				res.append(temp);
				res.append(" na piscina ");
				res.append(temp2.top().getNome());
				res.append("\n\n");
			}
		}
		temp2.pop();
	}

	return res;
}

void Piscina::venderItem(Utente * buyer, Item item)
{
	bool BuyerNotFound = true;
	//retirar saldo ao cliente
	for(unsigned int i=0; i<this->utentes.size(); i++)
	{
		if(utentes[i]==buyer)
		{
			BuyerNotFound = false;
			if(utentes[i]->getSaldo()>= item.getPreco())
				utentes[i]->retirarSaldo(item.getPreco());
			else
				throw NotEnoughSaldoException();
		}
	}

	if(BuyerNotFound)
		throw IllegalBuyerException();

	//remover 1 item da loja (apenas atualiza o stock)
	BSTItrIn<Item> iterator(this->loja);
	while (!iterator.isAtEnd()) {
		if (iterator.retrieve().getNome() == item.getNome() &&  iterator.retrieve().getTamanho() == item.getTamanho() && iterator.retrieve().getStock() > 0)
		{
			iterator.retrieve().setStock(iterator.retrieve().getStock()-1);
			break;
		}
		else if (iterator.retrieve().getNome() == item.getNome() &&  iterator.retrieve().getTamanho() == item.getTamanho() && iterator.retrieve().getStock() == 0)
			throw NoStockException(item.getNome());
	}
	iterator.advance();
}

void Piscina::removerItem(Item item)
{
	BSTItrIn<Item> iterator(this->loja);
	while (!iterator.isAtEnd()) {

		if(item==iterator.retrieve())
		{
			this->loja.remove(iterator.retrieve());
			return;
		}

		iterator.advance();
	}

	throw NoSuchItemException();
}

void Piscina::abastecerItem(Item item, unsigned int quantidade)
{
	BSTItrIn<Item> iterator(this->loja);
	while (!iterator.isAtEnd()) {

		if(item==iterator.retrieve())
		{
			iterator.retrieve().setStock(iterator.retrieve().getStock() + quantidade);
			return;
		}

		iterator.advance();
	}

	throw NoSuchItemException();
}

void Piscina::setLoja(BST<Item> loja)
{
	this->loja = loja;
}

ostream &operator<<(ostream & os, Piscina P1)
{
	return os << P1.getNome() << endl << P1.getPassword() << endl << P1.getLastDayUsed() << endl << P1.getCoordReais().first << endl <<
			P1.getCoordReais().second << endl << P1.getFichUt() << endl << P1.getFichProf() << endl << P1.getFichHor()
			<< endl << P1.getFichAulas() << endl << P1.getFichAulasDadas() << endl << P1.getFichLj();
}

bool Piscina::updatePiscina()
{
	ofstream out;
	if(existeFicheiro(fichload))
	{
		out.open(fichload, iostream::trunc);
		if (out.is_open())
		{
			out << this->getNome() << endl << this->getPassword() << endl << this->getDiaAtual() << endl << this->getCoordReais().first << endl <<
					this->getCoordReais().second << endl << this->getFichUt() << endl << this->getFichProf() << endl << this->getFichHor()
					<< endl << this->getFichAulas() << endl << this->getFichAulasDadas() << endl << this->getFichLj();
			if(this->getPiscinas().size() == 0)
				return true;
			else
			{
				out << endl;

				priority_queue <Piscina> temp =this->getPiscinas();

				while(!temp.empty())
				{

					if(temp.size()==1)
						out << temp.top();
					else
						out << temp.top() << endl;
					temp.pop();
				}
			}
		}
		else
			return false;
	}
	else
		return false;

	return true;

}

string Piscina::getPassword() const
{
	return this->password;
}

priority_queue<Piscina> Piscina::getPiscinas() const
{
	return this->piscinas;
}
