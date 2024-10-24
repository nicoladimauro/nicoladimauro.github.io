insert(value_type v){
	position p;
	p = first();
	while (read(p) < v)
		p = next(p);
	insert(v, p);
}

merge(List &A, List &B){
	position pa, pb, p;

	pa = A.first();
	pb = B.first();
	p = first();

	while(!A.end(pa) && !B.end(pb)){
		if (A.read(pa) < B.read(pb)){
			insert(A.read(pa), p);
			pa = A.next(pa);
		}
		else{
			insert(B.read(pb), p);
			pb = B.next(pb);
		}
		p = next(p);
	}
}
