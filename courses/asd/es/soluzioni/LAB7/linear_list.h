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

	void clear();
	int num_elements(position, position);
	void exchange(position, position);
	void move_min_max();
	void remove(Linear_list<T,P> &);
	
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

/*
template< class T, class P >
int Linear_list<T,P>::size() const{
   ....
}
*/

template< class T, class P >
void Linear_list<T,P>::clear() {
	while (!empty())
		erase(begin());
}

template< class T, class P >
int Linear_list<T,P>::num_elements(position p1, position p2) {
  bool checkp1, checkp2, prec;
	checkp1 = checkp2 = prec = false;
	position ap = begin();
	while (!end(ap)){
		if (ap == p1){
			checkp1 = true;
			if (!checkp2) prec = true;
		}
		if (ap == p2)
			checkp2 = true;

		ap = next(ap);
	}
	if (checkp1 && checkp2 && prec){
		position p = p1;
		int c = 0;
		while (p != p2){
			p = next(p);
			c++;		
		}
		return (c+1);
	}

}
	

template< class T, class P >
void Linear_list<T,P>::exchange(position p1, position p2) {
	value_type t;
	t = read(p1);
	write(p1, read(p2));
	write(p2, t);
}

template< class T, class P >
void Linear_list<T,P>::move_min_max() {
	position min_pos, max_pos, iter, last_pos;
	T min, max;
	if (!empty()){
		min = max = read(begin());
		max_pos = min_pos = begin();
		iter = next(begin());
		while (!end(iter)){
			if (read(iter) > max){
				max = read(iter);
				max_pos = iter;
			}
			if (read(iter) < min){
				min = read(iter);
				min_pos = iter;
			}
			last_pos = iter;
			iter = next(iter);
		}
	}
	exchange(begin(), min_pos);
	exchange(last_pos, max_pos);
}

template< class T, class P >
void Linear_list<T,P>::remove(Linear_list<T,P> & L){
	value_type v;
	position pL, p;
	if (!empty() && !L.empty()){
		pL = L.begin();
		while (!L.end(pL)){
			v = L.read(pL);
			p = begin();
			while (!end(p)){
				if (read(p) == v)
					erase(p);
				p = next(p);
			}
			pL = L.next(pL);
		}
	}
}

#endif // _LISTALIN_H

