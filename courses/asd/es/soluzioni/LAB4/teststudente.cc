#include "studente.h"

int main(){
	studente a, b;

	a.print();
	a.setEsame(21, 2);
	a.print();
	cout << a.getMedia();
	
	return 0;
}
