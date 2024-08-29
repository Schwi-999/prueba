#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class player{
private: 
	short posTiro;
public:
	int nroGoles;
	player()
	{
		posTiro= 0;
		nroGoles=0;
	}
	void patear()
	{
		do
		{
			cout<<"introduzca la direccion de tiro: "<<endl;
			cin>> posTiro;
		}while(posTiro>9 or posTiro<=0);
		
	}
	short getposTiro()
	{
		return posTiro;
	}
};

class arquero{
private:
	short nroCuadros;
	short posTapada;
public:
	float altura;
	short posInicial;
	int nroAtajadas;
	arquero()
	{
		posInicial=0;
		nroAtajadas=0;
		altura=0;
		posTapada=0;
	}
	void atajar()
	{
		int random_x;
		srand(time(NULL));
		random_x = 1+rand()%9;
		posTapada= random_x;
		cout<<"el arquero se arrojo a: "<<posTapada<<endl;
	}
	short getposTapada()
	{
	return posTapada;	
	}
	void calcularposicion()
	{
	float alt;
	srand(time(NULL));
	alt=160+rand()%25;
		altura=alt;
	cout<<"la altura del arquero es: "<<altura<<"cm"<<endl;
	if(altura>=170)
		posInicial=8;
	else
		posInicial=5;
	}
void arcoInicial()
{
	if(posInicial==5)
	{
		cout<<"|[7] [8] [9]|"<<endl;
		cout<<"|[4] [x] [6]|"<<endl;
		cout<<"|[1] [x] [3]|"<<endl;
	}

else 
	if(posInicial==8)
{
	cout<<"|[7] [x] [9]|"<<endl;
	cout<<"|[4] [x] [6]|"<<endl;
	cout<<"|[1] [x] [3]|"<<endl;
	}
}
};
int main(int argc, char *argv[]) {
	
	player p1;
	arquero aq;
	aq.calcularposicion();
	aq.arcoInicial();
	p1.patear();
	aq.atajar();
	if(aq.posInicial==5)
	{
	if(p1.getposTiro()!= (aq.getposTapada()==1 or 4))
		cout<<"gol"<<endl;
	else
	if(p1.getposTiro()!= (aq.getposTapada()==2 or 5))
		cout<<"gol"<<endl;
	else
		if(p1.getposTiro()!= (aq.getposTapada()==3 or 6))
		cout<<"gol"<<endl;
	else
		cout<<"no fue gol"<<endl;
	}
	else
	   if(aq.posInicial==8)
	{
		if(p1.getposTiro()!= (aq.getposTapada()==1 or 4 or 7))
			cout<<"gol"<<endl;
		else
		if(p1.getposTiro()!= (aq.getposTapada()==2 or 5 or 8))
		cout<<"gol"<<endl;
		else
		if(p1.getposTiro()!= (aq.getposTapada()==3 or 6 or 9))
		cout<<"gol"<<endl;
		else
		cout<<"no fue gol"<<endl;
	}
	return 0;
}


