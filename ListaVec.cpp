//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaVec.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaVec::ListaVec() {
	this->cantElem = 0;
}

direccion ListaVec::fin() {
	if(vacia()) {
		cout << "LISTA VACIA\n";
	} else {
		return this->cantElem - 1;
	}
}

direccion ListaVec::primero() {
	if(!(vacia())) {
		return 0;
	} else {
		cout << "LISTA VACIA\n";
	}
}

direccion ListaVec::siguiente(direccion p) {
	if (!(vacia())) {
		if (p + 1 == cantElem) {
			cout << "POSICION INCORRECTA\n";
		} else {
			return p + 1;
        }
	} else {
		cout << "LISTA VACIA\n";
    }
}

direccion ListaVec::anterior(direccion p) {
	if (!(vacia())) {
		if (p == 0) {
			cout << "POSICION INCORRECTA\n";
		} else {
			return p - 1;
        }
	} else {
		cout << "LISTA VACIA\n";
    }
}

UnicodeString ListaVec::recupera(direccion p) {
	if (!(vacia())) {
		if ((p >= 0) && (p < cantElem)) {
			return this->sim[p];
		} else {
			cout << "POSICION INCORRECTA\n";
		}
	} else {
		cout << "LISTA VACIA\n";
	}
}

void ListaVec::insertar(direccion p, UnicodeString x) {
	if (cantElem == max) {
		cout << "LISTA LLENA\n";
	}
	else if (vacia()) {
			 sim[0] = x;
			 cantElem++;
		 }
		 else if ((p >= 0) && (p <= cantElem)) {
				  for (int i = cantElem; i > p; i--) {
					  sim[i] = sim[i - 1];
				  }
				  sim[p] = x;
				  cantElem++;
			  } else {
				cout << "POSICION INCORRECTA\n";
			  }
}

void ListaVec::insertarPrim(UnicodeString x) {
	insertar(0, x);
}

void ListaVec::insertarUlt(UnicodeString x) {
	insertar(cantElem, x);
}

void ListaVec::suprime(direccion p) {
	if (cantElem == 0) {
		cout << "LISTA VACIA\n";
	} else {
		if ((p >= 0) && (p <= cantElem - 1)) {
			for (int i = p; i < cantElem - 1; i--) {
				sim[i] = sim[i + 1];
			}
			cantElem--;
		} else {
			cout << "POSICION INCORRECTA\n";
        }
	}
}

void ListaVec::modifica(direccion p, UnicodeString x) {
	if (cantElem == 0) {
		cout << "LISTA VACIA\n";
	} else {
		if ((p >= 0) && (p <= cantElem - 1)) {
			sim[p] = x;
		} else {
			cout << "POSICION INCORRECTA\n";
        }
    }
}

bool ListaVec::vacia() {
	return (cantElem == 0);
}

int ListaVec::lingitud() {
	return cantElem;
}

UnicodeString ListaVec::toStr() {
	UnicodeString l = "[";
	for (int i = 0; i < cantElem; i++) {
		UnicodeString x = sim[i];
		l += x;
		if (i < cantElem - 1) {
			l += ", ";
		}
		l += "]";
	}
	return l;
}

direccion ListaVec::localiza(UnicodeString x) {
	for (int i = 0; i < cantElem; i++) {
		if (sim[i] == x) {
			return i;
		}
	}
	return -1;
}
void ListaVec::eliminarDato(UnicodeString x) {
	int i = 0;
	while(i < cantElem) {
		if (x == sim[i]) {
			for (int j = i; j < cantElem - 1; j++) {
				sim[j] = sim[j + 1];
			}
			cantElem--;
		} else {
			i++;
		}
    }
}

void ListaVec::anula() {
	cantElem = 0;
}

bool ListaVec::existe(UnicodeString x) {
    for (int i = 0; i < cantElem; i++) {
		if (sim[i] == x) {
			return true;
		}
	}
	return false;
}
