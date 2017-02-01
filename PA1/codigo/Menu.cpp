#include "Menu.h"

unsigned short int menuInicial()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Inicial";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Menu Utentes" << endl;
	cout << TAB << "2 - Menu Professores" << endl;
	cout << TAB << "3 - Menu Aulas" << endl;
	cout << TAB << "4 - Menu Piscina" << endl;
	cout << TAB << "0 - Guardar e sair do programa" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,4))>0)
	return opcao;
	else
	return 0;
}

void opcoesIniciais(Piscina & piscina)
{
	unsigned short int opcao;

	while((opcao=menuInicial()))
	switch (opcao)
	{
	case 1:opcoesUtentes(piscina);
	break;
	case 2:opcoesProfessores(piscina);
	break;
	case 3:opcoesAulas(piscina);
	break;
	case 4:opcoesPiscina(piscina);
	break;
	}
}

unsigned short int menuUtentes()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Inicial";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Criar Utente" << endl;
	cout << TAB << "2 - Editar Utente" << endl;
	cout << TAB << "3 - Remover Utente" << endl;
	cout << TAB << "4 - Listar Utentes" << endl;
	cout << TAB << "5 - Fazer um deposito" << endl;
	cout << TAB << "6 - Remover saldo" << endl;
	cout << TAB << "7 - Listar Despesas" << endl;
	cout << TAB << "0 - Voltar ao menu inicial" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,7))>0)
	return opcao;
	else
	return 0;
}


void opcoesUtentes(Piscina & piscina)
{
	unsigned short int opcao;

		while((opcao=menuUtentes()))
			try
				{
			switch (opcao)
		{
		case 1:
		{
			 piscina.addUtente(createUtente());
		}
		break;
		case 2:
		{
			editUtente(findUtente(piscina));
		}
		break;
		case 3:
		{
			Utente * currentUt = findUtente(piscina);
				if(confirmRemoveUtente(currentUt))
					piscina.removerUtente(currentUt);
				else
					throw ConfirmException();
		}
		break;
		case 4:
		{
			opcoesListarUtentes(piscina);
		}
		break;
		case 5:
		{
			findUtente(piscina)->acrescentarSaldo(receiveSaldoUtente());
		}
		break;
		case 6:
		{
			findUtente(piscina)->retirarSaldo(receiveSaldoUtente());
		}
		break;
			case 7:
			{
				Utente * ut=findUtente(piscina);
				if(ut->getDespesas().size()==0)
				{
					cout << "O cliente nao tem qualquer despesa associada." << endl;
				}
				for(unsigned int i=0; i<ut->getDespesas().size(); i++)
				{
					cout << "--------------------"<< endl;
					cout << ut->getDespesas()[i] << endl;
				}
			}
			break;
		}
		}
		catch (IsStringNumberException &e)
		{
			cout << e.getNumber() << " nao e um numero." << endl;
		}
		catch(InBoundsException &e)
		{
			cout << e.getValor() << " necessita de estar entre " << e.getMinimo() << " e " << e.getMaximo() << endl;
		}
		catch(TriesException &e)
		{
			cout << "Numero de tentativas excedido." << endl;
		}
		catch (IdNotExistentException &e)
		{
			cout << "ID: " << e.getId() << " nao existe no vector de utentes." << endl;
		}
		catch (ConfirmException &e)
		{
			cout << "Operacao cancelada a seu pedido." << endl;
		}

}

unsigned short int menuListarUtentes()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Listar Utentes";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Listar Utentes por ID" << endl;
	cout << TAB << "2 - Listar Utentes por Nome" << endl;
	cout << TAB << "3 - Listar Utentes por Idade" << endl;
	cout << TAB << "4 - Listar Utentes por Saldo" << endl;
	cout << TAB << "0 - Voltar ao menu de utentes" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,4))>0)
	return opcao;
	else
	return 0;
}



void opcoesListarUtentes(Piscina & piscina)
{
	unsigned short int opcao;
	vector <Utente *> tempUts = piscina.getUtentes();

		while((opcao=menuListarUtentes()))
		switch (opcao)
		{
		case 1:
		{
			sort(tempUts.begin(), tempUts.end(),piscina.sortUtenteByID);
			listarVector<Utente *>(tempUts);
		}
		break;
		case 2:
		{
			sort(tempUts.begin(), tempUts.end(), piscina.sortUtenteByName);
			listarVector<Utente *>(tempUts);
		}
		break;
		case 3:
		{
			sort(tempUts.begin(), tempUts.end(), piscina.sortUtenteByAge);
			listarVector<Utente *>(tempUts);
		}
		break;
		case 4:
		{
			sort(tempUts.begin(), tempUts.end(), piscina.sortUtenteBySaldo);
			listarVector<Utente *>(tempUts);
		}
		break;
		}
}

unsigned short int menuProfessores()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Professores";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Criar Professor" << endl;
	cout << TAB << "2 - Editar Professor" << endl;
	cout << TAB << "3 - Remover Professor" << endl;
	cout << TAB << "4 - Listar Professor" << endl;
	cout << TAB << "0 - Voltar ao menu inicial" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,4))>0)
	return opcao;
	else
	return 0;
}

void opcoesProfessores(Piscina & piscina)
{
	unsigned short int opcao;

	while((opcao=menuProfessores()))
	{	try
	{
		switch (opcao)
		{

			case 1:
			{
				 piscina.addProfessor(createProfessor());
			}
			break;
			case 2:
			{
				editProfessor(findProfessor(piscina));
			}
			break;
			case 3:
			{
				Professor * currentProf = findProfessor(piscina);
					if(confirmRemoveProfessor(currentProf))
						piscina.removerProfessor(currentProf);
			}
			break;
			case 4:
			{
				opcoesListarProfessores(piscina);
			}
			break;
			}
	}
		catch(TriesException &e)
		{
			cout << "Numero de tentativas excedido." << endl;
		}
		catch(IsStringNumberException &e)
		{
			cout << e.getNumber() << " nao e um numero." << endl;
		}
		catch(InBoundsException &e)
		{
			cout << e.getValor() << " necessita de estar entre " << e.getMinimo() << " e " << e.getMaximo() << endl;
		}
		catch(InsuficientUsersException &e)
		{
			cout << "Impossivel remover o ultimo professor da piscina." << endl;
		}
		catch(IdNotExistentException &e) {
			cout << "ID: " << e.getId() << " nao existe no vector de professores." << endl;
		}
		catch(ConfirmException &e)
		{
			cout << "Operacao cancelada a seu pedido." << endl;
		}

}
}

unsigned short int menuListarProfessores()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Listar Professores";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Listar Professores por ID" << endl;
	cout << TAB << "2 - Listar Professores por Nome" << endl;
	cout << TAB << "3 - Listar Professores por Idade" << endl;
	cout << TAB << "0 - Voltar ao menu de Professores" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,3))>0)
	return opcao;
	else
	return 0;
}

void opcoesListarProfessores(Piscina & piscina)
{
	unsigned short int opcao;
	vector <Professor *> tempProfs = piscina.getProfessores();

		while((opcao=menuListarProfessores()))
		switch (opcao)
		{
		case 1:
		{
			sort(tempProfs.begin(), tempProfs.end(),piscina.sortProfessorByID);
			listarVector<Professor *>(tempProfs);
		}
		break;
		case 2:
		{
			sort(tempProfs.begin(), tempProfs.end(),piscina.sortProfessorByName);
			listarVector<Professor *>(tempProfs);		}
		break;
		case 3:
		{
			sort(tempProfs.begin(), tempProfs.end(),piscina.sortProfessorByAge);
			listarVector<Professor *>(tempProfs);
		}
		break;
		}
}


unsigned short int menuAulas()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Aulas";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Adicionar Aula Livre" << endl;
	cout << TAB << "2 - Adicionar Aula Acompanhada" << endl;
	cout << TAB << "3 - Editar Aula" << endl;
	cout << TAB << "4 - Remover Aula" << endl;
	cout << TAB << "5 - Listar Aulas" << endl;
	cout << TAB << "6 - Adicionar Utente a uma aula" << endl;
	cout << TAB << "7 - Remover Utente a uma aula" << endl;
	cout << TAB << "0 - Voltar ao menu Inicial" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,7))>0)
	return opcao;
	else
	return 0;
}

void opcoesAulas(Piscina & piscina)
{
	unsigned short int opcao;
	while((opcao=menuAulas()))
	{
		try
		{
			switch (opcao)
			{
				case 1:
				{
					piscina.addAula(createAulaLivre(piscina));
				}
				break;
				case 2:
				{
					piscina.addAula(createAulaAcompanhada(piscina));
				}
				break;
				case 3:
				{
					editAula(findAula(piscina));
				}
				break;
				case 4:
				{
					Aula * currentAula = findAula(piscina);
						if(removeAula(currentAula))
							piscina.removerAula(currentAula);
				}
				break;
				case 5:
				{
					opcoesListarAulas(piscina);
				}
				break;
				case 6:
				{
					Aula * aula_novo_utente = findAula(piscina);
					Utente * novo_ut = findUtente(piscina);
					if(aula_novo_utente->checkNovoUt(novo_ut))
					{
						if(piscina.verifyAulaNovoUtente(aula_novo_utente))
							aula_novo_utente->addUtente(novo_ut);
					}
				}
				break;
				case 7:
				{
					Aula * aula_novo_utente = findAula(piscina);
					Utente * novo_ut=findUtente(piscina);
					if(!aula_novo_utente->removeUtente(novo_ut))
					{
						cout << "Erro. Utente nao esta inscrito na aula." << endl;
					}
				}
				break;
			}
		}
		catch(InsertVectorException<string> &e)
		{
			cout << "Essa aula ja esta criada, por favor escolha outro nome" << endl;
		}
		catch (EmptyStringException &e)
		{
			cout << "O nome nao pode ser vazio." << endl;
		}
		catch(TriesException &e)
		{
			cout << "Numero de tentativas excedido." << endl;
		}
		catch(InBoundsException &e)
		{
			cout << "O valor introduzido tem que ser entre " << e.getMinimo() << " e " << e.getMaximo() << endl;
		}
		catch(IsStringNumberException &e) {
			cout << e.getNumber() << " O numero introduzido nao é valido" << endl;
		}
		catch(IdentificacaoAulaNotExitentException &e) {
			cout << "Identicacao " << e.getIdentificacao() << " nao existe." << endl;
		}
		catch (InvalidDataException &e){
			cout << "A data inserida tem de ser maior do que o dia atual." << endl;
		}
		catch(IdNotExistentException &e) {
			cout << "Nao foi possivel encontrar o id escolhido" << endl;
		}
		catch(DataFormatoException &e)
		{
			cout << "A data nao esta no formato correto" << endl;
		}
		catch(HorarioPiscinaException &e)
		{
			cout << "A aula nao pode ser criada fora do horario de funcionamento da piscina." << endl;
		}
		catch(AulaAcompanhadaMesmoTempoException &e)
		{
			cout << "A aula nao pode ser criada num horario em que ja esteja a ocorrer uma outra aula acompanhada"<< endl;
		}
		catch(ProfessoresDisponiveisException &e)
		{
			cout << "Nao existem professores disponiveis para esse horario." << endl;
		}
		catch(MaxUtentesException &e)
		{
			cout << "A aula ja contem o numero maximo de utentes." << endl;
		}
		catch(InsertVectorException<Utente *> &e)
		{
			cout << e.getElement() << endl << "Este utente ja esta inscrito para esta aula." << endl;
		}
	}
}

unsigned short int menuListarAulas()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Listar Aulas";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Listar Aulas por Nome" << endl;
	cout << TAB << "2 - Listar Aulas por Horario" << endl;
	cout << TAB << "3 - Listar Utentes de uma aula" << endl;
	cout << TAB << "4 - Listar aulas a que um utente esta inscrito" << endl;
	cout << TAB << "0 - Voltar ao menu de aulas" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,4))>0)
	return opcao;
	else
	return 0;
}

void opcoesListarAulas(Piscina & piscina)
{
	unsigned short int opcao;
	vector <Aula *> tempAulas = piscina.getAulas();

		while((opcao=menuListarAulas()))
		{
			try
			{
		switch (opcao)
		{
		case 1:
		{
			sort(tempAulas.begin(), tempAulas.end(),piscina.sortAulaByNome);
			listarVector<Aula *>(tempAulas);
		}
		break;
		case 2:
		{
			sort(tempAulas.begin(), tempAulas.end(),piscina.sortAulaByHorario);
			listarVector<Aula *>(tempAulas);		}
		break;
		case 3:
		{
			listarUtentesPorAula(piscina);
		}
		break;
		case 4:
		{
			int contador=0;
			Utente * ut=findUtente(piscina);
			for(unsigned int i=0; i<piscina.getAulas().size();i++)
			{
				for(unsigned int j=0; j<piscina.getAulas()[i]->getUtentes().size(); j++)
				{
					if(piscina.getAulas()[i]->getUtentes()[j]==ut)
						{
							contador++;
							break;
						}
				}
			}
			cout << ut->getNome() << " esta neste momento inscrito a " << contador << " aulas." << endl;
		}
		}
			}
		catch(TriesException &e)
		{
			cout << "Numero de tentativas excedido." << endl;
		}
		catch(ConfirmException &e)
		{
			cout << "Operacao cancelada a seu pedido." << endl;
		}
		catch(IdNotExistentException &e)
		{
			cout << "ID: " << e.getId() << " nao existe no vector de utentes." << endl;
		}
		}
}

unsigned short int menuPiscina()
{
	unsigned short int opcao=-1;
	cout << TAB_BIG << "Menu Piscina";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Adicionar Horario" << endl;
	cout << TAB << "2 - Remover Horario" << endl;
	cout << TAB << "3 - Listar Horarios" << endl;
	cout << TAB << "4 - Menu Despesas" << endl;
	cout << TAB << "5 - Menu Previsoes" << endl;
	cout << TAB << "0 - Voltar ao menu inicial" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";

	if((opcao=leUnsignedShortInt(0,5))>0)
	return opcao;
	else
	return 0;
}

void opcoesPiscina(Piscina & piscina)
{
	unsigned short int opcao;
	while((opcao=menuPiscina()))
	{
		try
		{
			switch (opcao)
			{
				case 1:
				{
					piscina.addHorario(createHorarioPiscina());
				}
				break;
				case 2:
				{
					piscina.removerHorario(findHorarioPiscina(piscina));
				}
				break;
				case 3:
				{
					vector<Horario> temp=piscina.getHorario();
					sort(temp.begin(),temp.end(),piscina.sortHorarioPiscina);
					for(unsigned int i =0; i<temp.size(); i++)
					{
						cout << temp[i] << endl;
					}
				}
				break;
				case 4:
				{
					opcoesDespesas(piscina);
				}
				break;
				case 5:
				{
					opcoesPrevisoes(piscina);
				}
			}
		}
		catch (DiaSemanaException &e)
		{
			cout << "Dia da semana introduzido e invalido" << endl;
		}
		catch (HorarioNotExistsException &e) {
			cout << "O horario introduzido nao existe!" << endl;
		}
		catch (DataFormatoException &e)
		{
			cout << "A data que inseriu nao esta no formato correto." << endl;
		}
		catch(InBoundsException &e)
		{
			cout << "O valor introduzido tem que ser entre " << e.getMinimo() << " e " << e.getMaximo() << endl;
		}
		catch(InvalidDataException &e)
		{
			cout << "A data final tem de ser maior do que a data inicial." << endl;
		}
	}
}



void opcoesDespesas(Piscina & piscina)
{
	unsigned short int opcao;
		while((opcao=menuDespesas()))
		{
			try
			{
				switch (opcao)
				{
				case 1:
				{
					piscina.updatePagamentoDespesas();
				}
				break;
				case 2:
				{
					piscina.updatePagamentoDespesas(findUtente(piscina));
				}
				}
			}
			catch(SaldoInsuficienteException &e)
			{
				cout << e.getNome() << " apenas possui " << e.getSaldo() << " e nao consegue pagar todas as susas despesas." << endl;
			}
			catch(TriesException &e)
			{
				cout << "Numero de tentativas excedido." << endl;
			}
			catch(ConfirmException &e)
			{
				cout << "Operacao cancelada a seu pedido." << endl;
			}
			catch(IdNotExistentException &e)
			{
				cout << "ID: " << e.getId() << " nao existe no vector de utentes." << endl;
			}
		}
}

unsigned short int menuDespesas()
{
	unsigned short int opcao=-1;
		cout << TAB_BIG << "Menu Despesas";
		cout << endl << endl;
		cout << TAB << "Escolha a opcao que desejar.";
		cout << endl << endl;
		cout << TAB << "1 - Pagar despesas totais." << endl;
		cout << TAB << "2 - Pagar despesas de um utente." << endl;
		cout << TAB << "0 - Voltar ao menu inicial" << endl;
		cout << endl;
		cout << "Escreva aqui a sua opcao: ";

		if((opcao=leUnsignedShortInt(0,2))>0)
		return opcao;
		else
		return 0;
}

void opcoesPrevisoes(Piscina & piscina)
{
	unsigned short int opcao;
		while((opcao=menuPrevisoes()))
		{
			predictNext(piscina,opcao);
		}
}


unsigned short int menuPrevisoes()
{
	unsigned short int opcao=-1;
		cout << TAB_BIG << "Menu Previsoes";
		cout << endl << endl;
		cout << TAB << "Escolha a opcao que desejar.";
		cout << endl << endl;
		cout << TAB << "1 - Fazer previsao para amanha." << endl;
		cout << TAB << "2 - Fazer previsao para a proxima semana." << endl;
		cout << TAB << "3 - Fazer previsao para o proximo mes." << endl;
		cout << TAB << "4 - Fazer previsao para o proximo ano." << endl;
		cout << TAB << "0 - Voltar ao menu inicial" << endl;
		cout << endl;
		cout << "Escreva aqui a sua opcao: ";

		if((opcao=leUnsignedShortInt(0,4))>0)
		return opcao;
		else
		return 0;
}


