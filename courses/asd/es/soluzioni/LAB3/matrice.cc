#include "matrice.h" // inclusione della definizione del tipo matrice
#include <iostream>
#include <stdlib.h>     /* srand, rand */

// costruttore
matrice::matrice(int r, int c){
  colonne = c;
  righe = r;
  // allocazione dinamica della matrice


	/*              ---------
		elementi ---> | e[0]   | --> [ e[0][0], e[0][1], ..., e[0][c-1]]
		              | e[1]   | --> [ e[1][0], e[1][1], ..., e[1][c-1]]

									 .......

									| e[r-1] | --> [ e[r-1][0], e[r-1][1], ..., e[r-1][c-1]]
									---------
		
			dove ei è di tipo puntatore a tipoelem, e eij è di tipo tipoelem
			Inoltre, ei = elementi[i] e eij = elementi[i][j]
	 */

  int i,j;
	// allocazione del vettore di puntatori a tipoelem
  elementi = new tipoelem* [righe]; 
  for (i=0; i < righe; i++)
		// allocazione dei singoli vettori righe di elementi di tipo tipoelem
    elementi[i] = new tipoelem[colonne];
  // inizializzazione degli elementi a valore nullo
  for (i=0;i<righe;i++)
		for (j=0;j<colonne;j++)
			elementi[i][j]=0;
}

// costruttore di copia
matrice::matrice(const matrice &m){
	righe = m.righe;
	colonne = m.colonne;
  int i,j;
  elementi = new tipoelem* [righe]; 
  for (i=0; i < righe; i++)
    elementi[i] = new tipoelem[colonne];
  for (i=0;i<righe;i++)
		for (j=0;j<colonne;j++)
			elementi[i][j]=m.elementi[i][j];
	
}

matrice::~matrice(){
	for (int j=0; j<colonne; j++)
		delete[] elementi[j];
	delete [] elementi;
}

matrice &matrice::operator=(const matrice &m){
	// evita gli auto assegnamenti
	if (this == &m) return *this;
	else {
		int i,j;
		if (colonne != m.colonne || righe != m.righe){
			this->~matrice();
			colonne = m.colonne;
			righe = m.righe;
			elementi = new tipoelem* [righe]; 
			for (i=0; i < righe; i++)
				elementi[i] = new tipoelem[colonne];
		}
		for (i=0;i<righe;i++)
			for (j=0;j<colonne;j++)
				elementi[i][j] = m.elementi[i][j];
	}
	return *this;
}

tipoelem matrice::leggimatrice(int r, int c){
	return elementi[r][c];
}

void matrice::scrivimatrice(int r, int c, tipoelem e){
	elementi[r][c] = e;
}

void matrice::prodottoScalare(double c){
	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			elementi[i][j] = c * elementi[i][j];
}

matrice matrice::trasposta(){
	matrice T(colonne,righe);

	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			T.scrivimatrice(j,i, elementi[i][j]);
	return T; // Attenzione è errato se non si implementa il sovraccarico di operator=
}

void matrice::stampa(){
	std::cout << std::endl;
	for (int i=0; i<righe; i++){
		std::cout << std::endl;		
		for (int j=0; j<colonne; j++)
			std::cout << elementi[i][j] << " ";
	}
	std::cout << std::endl;
}

void matrice::rand(){
	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			elementi[i][j] = random() % 100;
}

