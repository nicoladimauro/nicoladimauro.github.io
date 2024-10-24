/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "list_vector.h"
#include <iostream>
#include <math.h>

using namespace std;

class polinomio{
public:
	polinomio(){
		P.create();
		grado = 0;
	}
	void input(){
		cout << "Inserire il grado del polinomio :";
		cin >> grado;
		for (int i = 0; i <= grado; i++){
			double c;
			cout << "Inserire il coeff. del termine di grado " << grado - i << ":" ;
			cin >> c;
			P.insert(c, P.begin());
		}
	}
	void output(){
		List_vector<double>::position i;
		i = P.begin();
		cout << "Polinomio: ";
		int g = 0;
		double v;
		while (!P.end(i)){
			v = P.read(i);
			if (v != 0)
				cout << v << "*x^" << g << " + ";
			g++;
			i = P.next(i);
		}
		cout << endl;
	}
	double valore(double x){
		List_vector<double>::position i;
		i = P.begin();
		double v = 0;
		int g = 0;
		while (!P.end(i)){
			v = v + P.read(i) * pow(x, g);
			g++;
			i = P.next(i);
		}
		return v;
		cout << endl;
	}
	void somma(polinomio &pol){
		List_vector<double>::position i, ipol;
		ipol = pol.P.begin();
		i = P.begin();	
		int g = 0;
		double v;
		while (!pol.P.end(ipol) && !P.end(i)){
			P.write(P.read(i) + pol.P.read(ipol), i);
			ipol = pol.P.next(ipol);
			i = P.next(i);
		}
		if (P.end(i) && !pol.P.end(ipol)){
			while (!pol.P.end(ipol)){
				P.insert(pol.P.read(ipol), i);
				ipol = pol.P.next(ipol);
				i = P.next(i);
			}
		}
	}
private:
	List_vector<double> P;
	int grado;
};



int main(){
	polinomio pol;
	pol.input();
	pol.output();
	cout << "Valore per x = 3.6: " << pol.valore(3.6) << endl;
	polinomio pol2;
	pol2.input();
	pol.somma(pol2);
	pol.output();
	
	
}

