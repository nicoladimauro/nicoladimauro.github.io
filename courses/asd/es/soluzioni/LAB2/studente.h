#ifndef _STUDENTE
#define _STUDENTE

#include <string>

class studente{
 private:
	int matricola;
	string nome;
	int eta;
 public:
	bool setNome(string s){
		if (s.length() > 30)
			return false;
		nome = s;
		return true;
	}
	bool setMatricola(int m);
	string getNome(){
		return nome;
	}
};



#endif /* _STUDENTE */
