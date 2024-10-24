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

#ifndef _LISTALIN_H
#define _LISTALIN_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

// classe astratta listaLinare
template< class T, class P >
class Linear_list{
 public:
	typedef T value_type;   // the type of object, T, stored in the list
	typedef P position;
	
	// operators
	virtual void create() = 0;
	virtual bool empty() const = 0; // true if the list's size is 0
	virtual value_type read(position) const = 0;
	virtual void write(const value_type & x, position p) = 0; // write x at position p
	virtual position begin() const = 0;  // returns a position pointing to the beginning of the list
	virtual bool end(position) const = 0; // returns a position pointing to the end of the list
	virtual position next(position) const = 0; // returns the next position
	virtual position previous(position) const = 0; // return the previous position
	virtual void insert(const value_type &, position) = 0; // insert an element 
	virtual void erase(position pos) = 0; // ersaes the element at position pos
	
	// funzioni di servizio
	//friend ostream& operator<< <T,P>(ostream&, const Linear_list<T,P>&);

	/* Altre funzioni di servizio implementabili */
	/*
		virtual int size() const;  // returns the size of the list
		virtual void push_front(const value_type &); // insert a new element at the beginning
		virtual void push_back(const value_type &); // insert a new element at the end
		virtual void pop_front(); // removes the first element
		virtual void pop_back(); // removes the last element
		virtual void clear(); // erases all the elements
	*/

	int size() const;  // returns the size of the list
	void reverse();
	bool palindrome();

};

/* sovraccarica <<. Attenzione se il tipo restituito da read non è primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore << 
 */
template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){
	typename Linear_list<T,P>::position p;
	p = l.begin();
	cout << "[";
	while (!l.end(p)){
		if (p != l.begin())
			cout << ", " << l.read(p);
		else
			cout << l.read(p);
		p = l.next(p);
	}
	cout << "]" << endl;
	return os;
}


template< class T, class P >
int Linear_list<T,P>::size() const{
	Linear_list<T,P>::position p;
	int d = 0;
	for (p  = begin(); !end(p); p = next(p))
		d++;
	return d;
}


template< class T, class P >
void Linear_list<T,P>::reverse() {
	Linear_list<T,P>::position left;
	Linear_list<T,P>::position right;

	left = begin();
	right = begin();
	// trovo l'ultima posizione
	while (!end(next(right)))
		right = next(right);

	Linear_list<T,P>::value_type v;
	while (left != right && right != previous(left)){
		v = read(left);
		write( read(right), left);
		write( v, right);
		left = next(left);
		right = previous(right);
	}
}

template< class T, class P >
bool Linear_list<T,P>::palindrome() {
	Linear_list<T,P>::position left;
	Linear_list<T,P>::position right;

	left = begin();
	right = begin();
	// trovo l'ultima posizione
	while (!end(next(right)))
		right = next(right);

	bool pal = true;
	Linear_list<T,P>::value_type v;
	while (left != right && right != previous(left) && pal){
		if (read(left) != read(right))
			pal = false;
		left = next(left);
		right = previous(right);
	}
	return pal;
}


#endif // _LISTALIN_H


