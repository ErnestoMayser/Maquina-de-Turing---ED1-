//---------------------------------------------------------------------------

#ifndef ListaVecH
#define ListaVecH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vcl.h>

using namespace std;

const int max = 100;

typedef int direccion;

class ListaVec {
	private:
		UnicodeString sim[max];

	public:
	int cantElem;
		ListaVec();
		direccion fin();
		direccion primero();
		direccion siguiente(direccion);
		direccion anterior(direccion);
		UnicodeString recupera(direccion);
		void insertar(direccion, UnicodeString);
		void insertarPrim(UnicodeString);
		void insertarUlt(UnicodeString);
		void suprime(direccion);
		void modifica(direccion, UnicodeString);
		bool vacia();
		int lingitud();
		UnicodeString toStr();
		direccion localiza(UnicodeString);
		bool existe(UnicodeString);
		void eliminarDato(UnicodeString);
		void anula();
};


#endif
