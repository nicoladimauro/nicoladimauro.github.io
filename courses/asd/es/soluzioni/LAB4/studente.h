#include "esame.h"
#include <iostream>

using namespace std;

class studente{
 public:
	studente(){
		esami[0].setEsame("A");
		esami[1].setEsame("B");
		esami[2].setEsame("C");
		esami[3].setEsame("D");
		esami[4].setEsame("E");
	}
	void setMatricola(string m){ matricola = m;}
	void setNome(string m){ nome = m;}
	string getMatricola(){ return matricola;}
	string getNome(){ return nome;}

	void setEsame(int v, int k){
		esami[k-1].setVoto(v);
	}
	
	double getMedia(){
		int c = 0;
		double mean = 0;
		for (int i=0;i<5;i++)
			if (esami[i].isSostenuto()){
				c++;
				mean += esami[i].getVoto();
			}
		return mean/c;
	}

	void print(){
		for (int i=0;i<5;i++)
			if (esami[i].isSostenuto()){
				cout << esami[i].getEsame() << " " << esami[i].getVoto() << endl;
			}
		
	}

 private:
	esame esami[5];
	string matricola;
	string nome;
};
