#include <iostream>
#include <cmath>
#include <cstring>
#include <locale>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

struct campeonato{
	char time1[50];
	int p1,p2,p3,p4,p5,p6,ano;
	char time2[50];
	char time3[50];
	char time4[50];
	char time5[50];
	char time6[50];
	bool excluido;
};
campeonato csgo;
fstream arquivo;

void editar()
{
	system ("cls");
	int ano,colocado;
	char op,om='s';

	cout<<"Digite o ano do campeonato desejado: ";
	cin>>ano;
	cout<<endl;


	arquivo.seekg(0,arquivo.beg);
	while(arquivo.read((char*)&csgo, sizeof(csgo)))
	{
		if(ano == csgo.ano && csgo.excluido==false)
		{
			cout<<"Campeonato de "<<csgo.ano<<endl;
			cout<<"1o colocado: "<<csgo.time1<<" "<<csgo.p1<<" pontos"<<endl;
		   	cout<<"2o colocado: "<<csgo.time2<<" "<<csgo.p2<<" pontos"<<endl;
		   	cout<<"3o colocado: "<<csgo.time3<<" "<<csgo.p3<<" pontos"<<endl;
		   	cout<<"4o colocado: "<<csgo.time4<<" "<<csgo.p4<<" pontos"<<endl;
		   	cout<<"5o colocado: "<<csgo.time5<<" "<<csgo.p5<<" pontos"<<endl;
			cout<<"6o colocado: "<<csgo.time6<<" "<<csgo.p6<<" pontos"<<endl;
			cout<<endl;
			do{
				cout<<"tem certeza que deseja editar esse campeonato ?(s/n)";
		   		cin>>op;
			}while(op!='s' && op!='n');
		   	cout<<endl;
			if(op=='s')
			{
				while(om=='s')
				{
					cout<<"Digite qual colocado deseja alterar: ";
					cin>>colocado;
					cin.ignore();
					switch(colocado)
					{
					   	case 1:
					   	   	cout<<"Entre com o nome do time: ";
					   	   	cin.getline(csgo.time1,50);
					   	   	cout<<"Entre com os pontos: ";
					   	   	cin>>csgo.p1;
					   	   	break;
						case 2:
							cout<<"Entre com o nome do time: ";
							cin.getline(csgo.time2,50);
							cout<<"Entre com os pontos: ";
							cin>>csgo.p2;
							break;
						case 3:
							cout<<"Entre com o nome do time: ";
							cin.getline(csgo.time3,50);
							cout<<"Entre com os pontos: ";
							cin>>csgo.p4;
							break;
						case 4:
							cout<<"Entre com o nome do time: ";
							cin.getline(csgo.time4,50);
							cout<<"Entre com os pontos: ";
							cin>>csgo.p4;
							break;
						case 5:
							cout<<"Entre com o nome do time: ";
							cin.getline(csgo.time5,50);
							cout<<"Entre com os pontos: ";
							cin>>csgo.p5;
							break;
						case 6:
							cout<<"Entre com o nome do time: ";
					   		cin.getline(csgo.time6,50);
							cout<<"Entre com os pontos: ";
							cin>>csgo.p6;
							break;

					}
					arquivo.seekp(arquivo.tellg()-sizeof(csgo),arquivo.beg);
					arquivo.write((char*)&csgo,sizeof(csgo));
					do{
					cout<<"Deseja fazer outra mudança ?(s/n) ";
					cin>>om;
					}while(om!='s' && om!='n');
				}
			}

		}
	}

	arquivo.clear();

	return ;
}

void pesquisar()
{
	system("cls");
	int ano;
	char op='s';

	cout<<"Digite o ano do campeonato desejado: ";
	cin>>ano;

	while(op=='s')
	{
		arquivo.seekg(0,arquivo.beg);
		while(arquivo.read((char*)&csgo, sizeof(csgo)))
		{
			if(ano==csgo.ano && csgo.excluido==false)
			{
				cout<<"Campeonato de "<<csgo.ano<<endl;
				cout<<"1o colocado: "<<csgo.time1<<" "<<csgo.p1<<" pontos"<<endl;
			   	cout<<"2o colocado: "<<csgo.time2<<" "<<csgo.p2<<" pontos"<<endl;
			   	cout<<"3o colocado: "<<csgo.time3<<" "<<csgo.p3<<" pontos"<<endl;
			   	cout<<"4o colocado: "<<csgo.time4<<" "<<csgo.p4<<" pontos"<<endl;
			   	cout<<"5o colocado: "<<csgo.time5<<" "<<csgo.p5<<" pontos"<<endl;
				cout<<"6o colocado: "<<csgo.time6<<" "<<csgo.p6<<" pontos"<<endl;
				cout<<endl;
			}

		}
		cout<<endl;
		do{
		cout<<"deseja procurar outro campeonato(s/n)? ";
		cin>>op;
		}while(op!='s' && op!='n');
		cout<<endl;
		cout<<"Digite o ano do campeonato desejado: ";
		cin>>ano;
	}


	arquivo.clear();
	system("pause");
	return ;
}


void cadastrar()
{
	system("cls");
	cout<<"Entre com o ano do campeonato: ";
	cin>>csgo.ano;
	cout<<"Entre com o nome do time em 1o lugar: ";
	cin.ignore();
	cin.getline(csgo.time1,50);
	cout<<"Entre com sua pontuação: ";
	cin>>csgo.p1;
	cin.ignore();
	cout<<"Entre com o nome do time em 2o lugar: ";
	cin.getline(csgo.time2,50);
	cout<<"Entre com sua pontuação: ";
	cin>>csgo.p2;
	cin.ignore();
	cout<<"Entre com o nome do time em 3o lugar: ";
	cin.getline(csgo.time3,50);
	cout<<"Entre com sua pontuação: ";
	cin>>csgo.p3;
	cin.ignore();
	cout<<"Entre com o nome do time em 4o lugar: ";
	cin.getline(csgo.time4,50);
	cout<<"Entre com sua pontuação: ";
	cin>>csgo.p4;
	cin.ignore();
	cout<<"Entre com o nome do time em 5o lugar: ";
	cin.getline(csgo.time5,50);
	cout<<"Entre com sua pontuação: ";
	cin>>csgo.p5;
	cin.ignore();
	cout<<"Entre com o nome do time em 6o lugar: ";
	cin.getline(csgo.time6,50);
	cout<<"Entre com sua pontuação: ";
	cin>>csgo.p6;
	cin.ignore();
	cout<<endl;
	cout<<"Campeonato de "<<csgo.ano<<endl;
	cout<<"1o colocado: "<<csgo.time1<<" "<<csgo.p1<<" pontos"<<endl;
	cout<<"2o colocado: "<<csgo.time2<<" "<<csgo.p2<<" pontos"<<endl;
	cout<<"3o colocado: "<<csgo.time3<<" "<<csgo.p3<<" pontos"<<endl;
	cout<<"4o colocado: "<<csgo.time4<<" "<<csgo.p4<<" pontos"<<endl;
	cout<<"5o colocado: "<<csgo.time5<<" "<<csgo.p5<<" pontos"<<endl;
	cout<<"6o colocado: "<<csgo.time6<<" "<<csgo.p6<<" pontos"<<endl;

	arquivo.seekp(0,arquivo.end);
	arquivo.write((char*)&csgo, sizeof(csgo));

	return;
}

void excluir()
{
	system("cls");
	int ano;
	char op;
	cout<<"Digite o ano do campeonato que deseja excluir: ";
	cin>>ano;

	arquivo.seekg(0,arquivo.beg);
	while(arquivo.read((char*)&csgo, sizeof(csgo)))
	{
		if(ano==csgo.ano && csgo.excluido==false)
		{
			cout<<"Campeonato de "<<csgo.ano<<endl;
	   	   	cout<<"1o colocado: "<<csgo.time1<<" "<<csgo.p1<<" pontos"<<endl;
			cout<<"2o colocado: "<<csgo.time2<<" "<<csgo.p2<<" pontos"<<endl;
			cout<<"3o colocado: "<<csgo.time3<<" "<<csgo.p3<<" pontos"<<endl;
			cout<<"4o colocado: "<<csgo.time4<<" "<<csgo.p4<<" pontos"<<endl;
			cout<<"5o colocado: "<<csgo.time5<<" "<<csgo.p5<<" pontos"<<endl;
			cout<<"6o colocado: "<<csgo.time6<<" "<<csgo.p6<<" pontos"<<endl;

			do{
				cout<<"deseja excluir esse campeonato?(s/n) ";
				cin>>op;
			}while(op!='s' && op!='n');
			if(op=='s'){
				csgo.excluido=true;
				arquivo.seekp(arquivo.tellg()-sizeof(csgo),arquivo.beg);
				arquivo.write((char*)&csgo,sizeof(csgo));
			}
		}
	}
	arquivo.clear();
	return;
}
void listar()
{
	system("cls");
	arquivo.seekg(0,arquivo.beg);
	while(arquivo.read((char*)&csgo,sizeof(csgo)))
	{
		if(csgo.excluido==false){
			cout<<"Campeonato de "<<csgo.ano<<endl;
		   	cout<<"1o colocado: "<<csgo.time1<<" "<<csgo.p1<<" pontos"<<endl;
			cout<<"2o colocado: "<<csgo.time2<<" "<<csgo.p2<<" pontos"<<endl;
			cout<<"3o colocado: "<<csgo.time3<<" "<<csgo.p3<<" pontos"<<endl;
			cout<<"4o colocado: "<<csgo.time4<<" "<<csgo.p4<<" pontos"<<endl;
			cout<<"5o colocado: "<<csgo.time5<<" "<<csgo.p5<<" pontos"<<endl;
			cout<<"6o colocado: "<<csgo.time6<<" "<<csgo.p6<<" pontos"<<endl;
			cout<<endl;
		}
	}
	arquivo.clear();
	return;
}
int main ()
{
	setlocale(LC_ALL,"Portuguese");

	int opcao;

	arquivo.open("campeonatos de CSGO.txt",ios::in | ios::out | ios::binary);
	if(arquivo.is_open()==false)
		   arquivo.open("campeonatos de CSGO.txt",ios::in | ios::out | ios::binary | ios::trunc);

	do{
		cout<<" 				MENU "<<endl;
		cout<<"1.Cadastrar novo campeonato"<<endl;
		cout<<"2.Pesquisar campeonato"<<endl;
		cout<<"3.Editar campeonato"<<endl;
		cout<<"4.Excluir campeonato"<<endl;
		cout<<"5.Listar campeonatos "<<endl;
		cout<<"6.Sair"<<endl;
		cout<<endl;
		cout<<"Escolha uma opção: ";
		cin>>opcao;
		while(opcao > 6 || opcao < 1)
		{
			cout<<"ERRO! Digite novamente a opção: ";
			cin>>opcao;
		}

		switch(opcao){
			case 1:
				cadastrar();
				break;
			case 2:
				pesquisar();
				break;
			case 3:
				editar();
				break;
			case 4:
				excluir();
				break;
			case 5:
				listar();
				break;
		}


	}while(opcao != 6);

	arquivo.close();
	return 0;
}
