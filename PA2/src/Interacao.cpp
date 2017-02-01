/*
 * Interacao.cpp
 *
 *  Created on: 30 Oct 2016
 *      Author: Mário Fernandes, Cristiana Ribeiro, Sérgio Salgado
 */

#include "Interacao.h"

Utente * createUtente()
{
	string nome,temp;
	unsigned short int idade;

	cout << "Por favor insira o nome do novo utente: ";
	if((nome=tryNewTextInput()) == ""){
		throw TriesException();
	}

	cout << "Por favor insira a idade de " << nome << ": ";
	if((idade=leUnsignedShortInt(1,150))==0)
	{
		throw TriesException();
	}
	Utente * newUtente = new Utente(nome, idade);
	cout << "Sucesso!" << endl;
	return newUtente;
}

Utente * findUtente(Piscina & piscina)
{
	int id, pos;
	cout << "Por favor insira o id do utente: ";
	if((id=leUnsignedShortInt(MINIMUM_ID, MAXIMUM_ID))==0)
	{
		throw TriesException();
	}

	if((pos = idExistsOnVector(piscina.getUtentes(), id)) != -1)
	{
		cout << "Utente selecionado:" << endl << piscina.getUtentes()[pos]->printUt() << endl;
		if(confirm())
		{
			return piscina.getUtentes()[pos];
		}
		else
		{
			throw ConfirmException();
		}
	}
	else
	{
		throw IdNotExistentException(id);
	}
}

void editUtente(Utente * ut)
{
	string nome, temp, email, morada;
	int idade, telemovel;
	stringstream ss;

	cout << "Por favor insira o novo nome do utente: ";
	if((nome=tryNewTextInput()) == ""){
		throw TriesException();
	}

	cout << "Por favor insira a idade do utente: ";
	getline(cin,temp);
	if (!isNumber(temp))
	{
		throw (IsStringNumberException(temp));
	}

	ss<<temp;
	ss>>idade;
	ss.clear();
	ss.str("");

	cout << "Por favor insira o numero de telemovel do utente: ";
	getline(cin,temp);
	if (!isNumber(temp))
	{
		throw (IsStringNumberException(temp));
	}

	ss<<temp;
	ss>>telemovel;
	ss.clear();
	ss.str("");

	cout << "Por favor insira o e-mail do utente: ";
	getline(cin,email);

	cout << "Por favor insira a morada do utente: ";
	getline(cin,morada);

	ut->setNome(nome);
	ut->setIdade(idade);
	ut->setTelemovel(telemovel);
	ut->setEMail(email);
	ut->setMorada(morada);
	cout << "Sucesso!" << endl;
}


void editUtente2(Utente * ut)
{
	string temp, email, morada;
	int telemovel;
	stringstream ss;

	cout << "Por favor insira o numero de telemovel do utente: ";
	getline(cin,temp);
	if (!isNumber(temp))
	{
		throw (IsStringNumberException(temp));
	}

	ss<<temp;
	ss>>telemovel;
	ss.clear();
	ss.str("");

	cout << "Por favor insira o e-mail do utente: ";
	getline(cin,email);

	cout << "Por favor insira a morada do utente: ";
	getline(cin,morada);

	ut->setTelemovel(telemovel);
	ut->setEMail(email);
	ut->setMorada(morada);
	cout << "Sucesso!" << endl;
}

int receiveSaldoUtente()
{
	string temp;
	stringstream ss;
	int saldo;
	cout << "Por favor insira o valor do deposito/despesa do utente (omita o '-' para despesas): ";
	getline(cin,temp);
	if(stringIsEmpty(temp))
		throw EmptyStringException();
	if(!isNumber(temp))
		throw(IsStringNumberException(temp));
	ss<<temp;
	ss>>saldo;
	ss.clear();
	ss.str("");
	return saldo;
}

bool confirmRemoveUtente(Utente * ut)
{
	cout << "Deseja mesmo remover " << ut->getNome() << " da piscina?" << endl;
	if (confirm())
		return true;
	else
		return false;
}

Professor * createProfessor()
{
	string nome,temp;
	unsigned short int idade;

	cout << "Por favor insira o nome do novo professor: ";
	if((nome=tryNewTextInput()) == ""){
		throw TriesException();
	}

	cout << "Por favor insira a idade de " << nome << ": ";
	if((idade=leUnsignedShortInt(1,150))==0)
	{
		throw TriesException();
	}
	Professor * newProfessor = new Professor(nome, idade);
	cout << "Sucesso!" << endl;
	return newProfessor;
}

Professor * findProfessor(Piscina & piscina)
{
	int id, pos;
	cout << "Por favor insira o id do Professor: ";
	if((id=leUnsignedShortInt(MINIMUM_ID, MAXIMUM_ID))==0)
	{
		throw TriesException();
	}

	if((pos = idExistsOnVector(piscina.getProfessores(), id)) != -1)
	{
		cout << "Professor selecionado:" << endl << piscina.getProfessores()[pos] << endl;
		if(confirm())
		{
			return piscina.getProfessores()[pos];
		}
		else
		{
			throw ConfirmException();
		}
	} else {
		throw IdNotExistentException(id);
	}
}

void editProfessor(Professor * p)
{
	string nome, temp;
	int idade;
	stringstream ss;

	cout << "Por favor insira o novo nome do professor: ";
	if((nome=tryNewTextInput()) == ""){
		throw TriesException();
	}

	cout << "Por favor insira a idade do professor: ";
	getline(cin,temp);
	if (!isNumber(temp))
	{
		throw (IsStringNumberException(temp));
	}

	ss<<temp;
	ss>>idade;
	ss.clear();
	ss.str("");

	p->setNome(nome);
	p->setIdade(idade);
	cout << "Sucesso!" << endl;
}

bool removeProfessor(Professor * p)
{
	cout << "Deseja mesmo remover " << p->getNome() << " da piscina?" << endl;
	if (confirm())
		return true;
	else
		return false;
}

bool confirmRemoveProfessor(Professor * prof)
{
	cout << "Deseja mesmo remover " << prof->getNome() << " da piscina?" << endl;
	if (confirm())
		return true;
	else
		return false;
}


Horario createHorarioPiscina()
{
	string dia_semana, tempI, tempF;
	int id_dia;
	cout << "Por favor insira o dia da semana (exemplo: segunda-feira): ";
	getline(cin,dia_semana);
	if((id_dia=verifyDiaSemana(dia_semana))==0)
		throw DiaSemanaException();
	cout << "Por favor insira a data inicial no formato hora-minutos: ";
	getline(cin,tempI);
	if(!isDataShortFormato(tempI))
	{
		throw DataFormatoException();
	}


	cout << "Por favor insira a data final no formato hora-minutos: ";
	getline(cin,tempF);
	isDataShortFormato(tempF);
	if(!isDataShortFormato(tempF))
	{
		throw DataFormatoException();
	}


	Data dataInicial(tempI), dataFinal(tempF);

	if(!(dataInicial<dataFinal))
		throw InvalidDataException();

	Horario horario(id_dia,tempI, tempF);
	return horario;
}


AulaLivre * createAulaLivre(Piscina & piscina)
{

	stringstream ss;
	string utente_id;
	string identificacao_aula="livre_", temp;
	cout << "Por favor insira o novo nome da nova aula livre: ";
	if((temp=tryNewTextInput()) == ""){
		throw TriesException();
	}
	for(unsigned int i=0; i<piscina.getAulas().size(); i++)
	{
		if(temp==piscina.getAulas()[i]->getIdentificacaoAula())
			throw InsertVectorException<string>();
	}
	Horario horario_aula = createHorarioAula(identificacao_aula,piscina);
	identificacao_aula.append(temp);

	bool possivel=false;

	//verificar se aula esta a ser criada no horario de abertura da piscina
	for(unsigned int i=0; i<piscina.getHorario().size(); i++)
	{
		if(verifyHorarioCompativel(piscina.getHorario()[i],horario_aula))
		{
			possivel=true;
			break;
		}
	}

	if(!possivel)
	{
		throw HorarioPiscinaException();
	}

	AulaLivre * newAula = new AulaLivre(identificacao_aula,horario_aula);
	return newAula;
}

AulaAcompanhada * createAulaAcompanhada(Piscina & piscina)
{
	string identificacao_aula="acompanhada_", temp;
	stringstream ss;
	cout << "Por favor insira o novo nome da nova aula acompanhada: ";
	if((temp=tryNewTextInput()) == ""){
		throw TriesException();
	}
	for(unsigned int i=0; i<piscina.getAulas().size(); i++)
	{
		if(temp==piscina.getAulas()[i]->getIdentificacaoAula())
			throw InsertVectorException<string>();
	}

	Horario horario_aula = createHorarioAula(identificacao_aula,piscina);
	identificacao_aula.append(temp);

	bool possivel=false;

	//verificar se aula esta a ser criada no horario de abertura da piscina
	for(unsigned int i=0; i<piscina.getHorario().size(); i++)
	{
		if(verifyHorarioCompativel(piscina.getHorario()[i],horario_aula))
		{
			possivel=true;
			break;
		}
	}

	if(!possivel)
	{
		throw HorarioPiscinaException();
	}

	for(unsigned int i=0; i<piscina.getAulas().size(); i++)
	{
		//verificar que não existe nenhuma aula acompanhada a haver nessa hora
		if(dynamic_cast<AulaAcompanhada *> (piscina.getAulas()[i]))
		{
			if(verifyAulaNaoCompativel(piscina.getAulas()[i]->getHorario(),horario_aula))
			{
				throw AulaAcompanhadaMesmoTempoException();
			}
		}
	}

	vector <Professor *> profs_disponiveis;

	//verificar que existe professores disponiveis e associar à aula
	for(unsigned int i=0; i<piscina.getProfessores().size();i++)
	{
		for(unsigned int j=0; j<piscina.getProfessores()[i]->getDisponibilidade().size();j++)
		{
			if(verifyHorarioCompativel(piscina.getProfessores()[i]->getDisponibilidade()[j],horario_aula))
				profs_disponiveis.push_back(piscina.getProfessores()[i]);
		}
	}

	if(profs_disponiveis.size()==0)
	{
		throw ProfessoresDisponiveisException();
	}

	Professor * encarregado = piscina.findProfessorMenosAulas(profs_disponiveis);
	AulaAcompanhada * newAula = new AulaAcompanhada(identificacao_aula,horario_aula,encarregado);
	return newAula;
}

Aula * findAula(Piscina & piscina)
{
	string temp, identificacao_aula;
	int id_aula;
	stringstream ss;
	cout << "Por favor insira 1 para seleccionar aula livre ou 2 para aula acompanhada: ";
	if((id_aula=leUnsignedShortInt(1,2))==0)
	{
		throw TriesException();
	}
	cout << "Por favor insira a identificacao da aula: ";
	getline(cin,temp);
	switch(id_aula)
	{
	case 1:
	{
		identificacao_aula="livre_";
	}
	break;
	case 2:
	{
		identificacao_aula="acompanhada_";
	}
	break;
	}

	identificacao_aula.append(temp);

	for(unsigned int i=0; i<piscina.getAulas().size(); i++)
	{
		if(piscina.getAulas()[i]->getIdentificacaoAula()==identificacao_aula)
		{
			return piscina.getAulas()[i];
		}
	}
	throw IdentificacaoAulaNotExitentException(temp);
}


void editAula(Aula * aula)
{
	string temp, identificacao_aula;
	stringstream ss;
	unsigned int preco;
	if(dynamic_cast<AulaAcompanhada *> (aula))
	{
		identificacao_aula="acompanhada_";
		cout << "Por favor insira a nova identificacao da aula: ";
		if((temp=tryNewTextInput()) == ""){
			throw TriesException();
		}

		identificacao_aula.append(temp);
		cout << "Por favor insira o novo preco da aula: ";
		getline(cin,temp);
		if (!isNumber(temp))
			throw IsStringNumberException(temp);
		ss << temp;
		ss>>preco;
		ss.clear();
		ss.str("");
		aula->setIdentificacaoAula(identificacao_aula);
		aula->setPreco(preco);
	}
	else if (dynamic_cast<AulaLivre *> (aula))
	{
		identificacao_aula="livre_";
		cout << "Por favor insira a nova identificacao da aula: ";
		getline(cin,temp);
		identificacao_aula.append(temp);
		aula->setIdentificacaoAula(identificacao_aula);
	}
}

bool removeAula(Aula* aula) {
	cout << "Deseja mesmo remover a aula " << aula->getIdentificacaoAula() << "?" << endl;
	if (confirm())
		return true;
	else
		return false;
}

void listarUtentesPorAula(Piscina & piscina) {
	int posAula;
	cout << "Lista de aulas disponiveis" << endl;
	for(unsigned int i=0; i< piscina.getAulas().size(); i++) {
		cout << i+1 << " - " << piscina.getAulas()[i]->getIdentificacaoAula() << endl;
	}
	cout << "Seleccione a aula que deseja para visualizar os utentes que participam na mesma" << endl;
	if((posAula=leUnsignedShortInt(1, piscina.getAulas().size()+1))==0)
	{
		throw TriesException();
	}

	Aula* aulaEscolhida = piscina.getAulas()[posAula-1];
	cout << "Total de participantes: " << aulaEscolhida->getUtentes().size() << endl;
	for(unsigned int i=0; i< aulaEscolhida->getUtentes().size(); i++) {
		cout << aulaEscolhida->getUtentes()[i]->getNome() << endl;
	}
}

Horario createHorarioAula(string tipodeAula,Piscina & piscina)
{
	string tempI, tempF;
	cout << "Por favor insira a data inicial no formato ano-mes-dia-hora-minutos: ";
	getline(cin,tempI);
	if(stringIsEmpty(tempI))
		throw EmptyStringException();
	if(!isDataLongFormato(tempI))
	{
		throw DataFormatoException();
	}

	Data datainicial(tempI);
	if(datainicial<piscina.getDiaAtual())
		throw InvalidDataException();


	if(tipodeAula=="acompanhada_")
	{
		Data datafinal(datainicial.getAno(),datainicial.getMes(),datainicial.getDia(),datainicial.getHora()+1,datainicial.getMinutos());
		Horario horario(datainicial,datafinal);
		return horario;
	}
	else
	{
		int duracao;
		cout << "Por favor escolha a duração da aula:" << endl;
		cout << "1. 30 minutos" << endl;
		cout << "2. 1 hora" << endl;
		cout << "3. 1 hora e 30 minutos" << endl;
		cout << "4. 2 horas" << endl;

		if((duracao=leUnsignedShortInt(1,4))==0)
		{
			throw TriesException();
		}
		if(duracao == 1)
		{
			Data datafinal(datainicial.getAno(),datainicial.getMes(),datainicial.getDia(),datainicial.getHora(),datainicial.getMinutos()+30);
			Horario horario(datainicial,datafinal);
			return horario;
		}
		else if(duracao == 2)
		{
			Data datafinal(datainicial.getAno(),datainicial.getMes(),datainicial.getDia(),datainicial.getHora()+1,datainicial.getMinutos());
			Horario horario(datainicial,datafinal);
			return horario;
		}
		else if(duracao == 3)
		{
			Data datafinal(datainicial.getAno(),datainicial.getMes(),datainicial.getDia(),datainicial.getHora()+1,datainicial.getMinutos()+30);
			Horario horario(datainicial,datafinal);
			return horario;
		}
		else if(duracao == 4)
		{
			Data datafinal(datainicial.getAno(),datainicial.getMes(),datainicial.getDia(),datainicial.getHora()+2,datainicial.getMinutos());
			Horario horario(datainicial,datafinal);
			return horario;
		}
	}
}

Horario findHorarioPiscina(Piscina & piscina)
{
	Horario hor=createHorarioPiscina();
	for(unsigned int i =0; i<piscina.getHorario().size(); i++)
	{
		if (hor==piscina.getHorario()[i])
			return piscina.getHorario()[i];
	}
	throw HorarioNotExistsException();
}

bool validateTimeAulaAcompanhada(Data & dataInicial, Data & dataFinal) {
	if (dataInicial.getAno() == dataFinal.getAno())
	{
		if (dataInicial.getMes() == dataFinal.getMes())
		{
			if (dataInicial.getDia() == dataFinal.getDia())
			{
				if((dataFinal.getHora() - dataInicial.getHora())==1)
				{
					if(dataInicial.getMinutos() == dataFinal.getMinutos()){
						return true;
					}
				}
			}
		}
	}
	return false;
}

void predictNext(Piscina & piscina,int mode)
{
	unsigned int contador_aulas=0;
	unsigned int contador_receita=0;
	unsigned int contador_utentes=0;

	Data temp=piscina.getDiaAtual();
	switch(mode)
	{
	case 1:
	{
		temp.setDataTot(temp.getDia()+1,temp.getMes(),temp.getAno(),temp.getHora(),temp.getMinutos());
		break;
	}
	case 2:
	{
		temp.setDataTot(temp.getDia()+7,temp.getMes(),temp.getAno(),temp.getHora(),temp.getMinutos());
		break;
	}
	case 3:
	{
		temp.setDataTot(temp.getDia(),temp.getMes()+1,temp.getAno(),temp.getHora(),temp.getMinutos());
		break;
	}
	case 4:
	{
		temp.setDataTot(temp.getDia()+1,temp.getMes(),temp.getAno()+1,temp.getHora(),temp.getMinutos());
		break;
	}
	}

	for(unsigned int i=0; i<piscina.getAulas().size(); i++)
	{
		if(piscina.getAulas()[i]->getHorario().getFinal()<temp)
		{
			contador_aulas++;
			contador_receita+=piscina.getAulas()[i]->getPreco() * piscina.getAulas()[i]->getUtentes().size();
			contador_utentes+=piscina.getAulas()[i]->getUtentes().size();
		}
	}

	cout << endl << endl << "ESTATISTICAS: " << endl;
	cout << "Neste periodo do tempo irao decorrer " << contador_aulas << " aulas, que irao gerar " << contador_receita << " euros e vao estar presentes " << contador_utentes << " utentes."<< endl;
	system("pause");

}


string findNomeAula()
{
	string aula,temp;

	cout << "Deseja ter uma aula acompanhada?" << endl;

	if(confirm())
	{
		aula="acompanhada_";
	}
	else
	{
		aula="livre_";
	}

	cout << "Por favor insira o nome da aula que deseja frequentar: ";

	getline(cin, temp);

	aula.append(temp);

	return aula;
}

void updateMassUts(vector <Utente *> uts)
{
	for(unsigned int i=0; i<uts.size(); i++)
	{
		cout << "Deseja atualizar o utente " << uts[i]->getNome() << " com ID " << uts[i]->getId()<< "?" << endl;
		if(confirm())
		{
			editUtente(uts[i]);
		}
	}
}

void updateMassUts2(vector <Utente *> uts)
{
	for(unsigned int i=0; i<uts.size(); i++)
	{
		cout << "Deseja atualizar o utente " << uts[i]->getNome() << " com ID " << uts[i]->getId()<< "?" << endl;
		if(confirm())
		{
			editUtente2(uts[i]);
		}
	}
}

Item getNewItem(Piscina & piscina) {
	string temp, nome;
	stringstream ss;
	unsigned int tamanho, preco;

	cout << "Insira o nome do novo item a adicionar a loja: ";
	getline(cin, nome);

	cout << "Insira o tamanho do novo item a adicionar a loja: ";
	if((tamanho=leUnsignedShortInt(1, 4))==0)
	{
		throw TriesException();
	}
	ss << temp;
	ss >> tamanho;
	ss.clear();
	ss.str("");


	cout << "Insira o preco do novo item a adicionar a loja: ";
	getline(cin, temp);
	if (!isNumber(temp))
		throw IsStringNumberException(temp);
	ss << temp;
	ss >> preco;
	ss.clear();
	ss.str("");

	Item newItem = Item(nome, tamanho, preco, 1);
	return newItem;
}

Item getItemDaLoja(Piscina & piscina) {

	string temp, nome;
	int tamanho;
	stringstream ss;

	cout << "Insira o nome do item que deseja : ";
	getline(cin, nome);

	cout << "Insira o tamanho do item a que se refere (entre 1 a 4): ";

	if((tamanho=leUnsignedShortInt(1, 4))==0)
	{
		throw TriesException();
	}
	ss << temp;
	ss >> tamanho;
	ss.clear();
	ss.str("");

	Item item = Item(nome, tamanho);

	BST<Item> temp2 = piscina.getLoja();
	BSTItrIn<Item> iterator(temp2);
	while (!iterator.isAtEnd()) {
		if (iterator.retrieve().getNome() == item.getNome() &&  iterator.retrieve().getTamanho() == item.getTamanho())
			return iterator.retrieve();
		iterator.advance();
	}
	throw NoSuchItemException();
	return item;
}

void editarItem(Piscina & piscina, Item item) {

	string temp;
	unsigned int novoPreco;
	stringstream ss;


	cout << "Insira o novo preco do item: ";
	getline(cin, temp);
	if (!isNumber(temp))
	{
		throw (IsStringNumberException(temp));
	}
	ss << temp;
	ss >> novoPreco;
	ss.clear();
	ss.str("");

	BST<Item> temp2 = piscina.getLoja();
	BSTItrIn<Item> iterator(temp2);
	while (!iterator.isAtEnd()) {
		if (iterator.retrieve().getNome() == item.getNome() &&  iterator.retrieve().getTamanho() == item.getTamanho())
		{
			iterator.retrieve().setPreco(novoPreco);
			break;
		}
		iterator.advance();
	}

	piscina.setLoja(temp2);


	cout << "Sucesso!" << endl;

}

unsigned int getQuantidadeAbastecer()
{
	unsigned int quantidade;
	string temp;
	stringstream ss;

	cout << "Qual a quantidade do item que deseja abastecer?" << endl;
	getline(cin, temp);
	if (!isNumber(temp))
	{
		throw (IsStringNumberException(temp));
	}
	ss<<temp;
	ss>> quantidade;
	ss.clear();
	ss.str("");

	return quantidade;
}


void listarVectorUts (vector <Utente *> uts)
{
	for(unsigned int i =0; i<uts.size(); i++ )
	{
		cout << uts[i]->printUt() << endl;
	}
}
