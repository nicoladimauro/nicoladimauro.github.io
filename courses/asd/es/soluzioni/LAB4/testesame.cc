#include <iostream>
#include "esame.h"

using namespace std;

int main(){

	esame a, b("algoritmi"), c("linguaggi", 31);
	
	a.setEsame("reti");

	cout << c.getVoto();

	return 0;
}
