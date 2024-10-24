#ifndef _ESAME_H
#define _ESAME_H
 
#include <string>

using namespace std;

class esame{
 public:
	esame(){
		sostenuto = false;
	}
	esame(string n){
		nome = n;
		sostenuto = false;
	}
	esame(string n, int v){
		nome = n;
		voto = v;
		sostenuto = true;
	}
	string getEsame(){
		return nome;
	}
	void setEsame(string n){
		nome = n;
	}
	int getVoto(){ 
		if (sostenuto) return voto;
		return -1;
	}
	void setVoto(int v){ voto = v; sostenuto=true;}
	bool isSostenuto(){return sostenuto;}
 private:
   string nome;
	 bool sostenuto;
	 int voto;
 };


#endif // _ESAME_H 
