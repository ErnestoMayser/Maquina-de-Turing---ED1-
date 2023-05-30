//---------------------------------------------------------------------------

#ifndef CintaH
#define CintaH
//---------------------------------------------------------------------------
#include "ListaVec.h"
#include <iostream>
#include <string>
#include <vcl.h>
#include <Vcl.Grids.hpp>

using namespace std;

class Cinta {
	private:
		ListaVec *tape;
	public:
		Cinta();
		void insertarSimbolo(UnicodeString);
		void insertarEstado(UnicodeString);
		void insertarMovimientos(UnicodeString);
		UnicodeString getSimbolo(int);
		UnicodeString getEstado(int);
		UnicodeString getMovimiento(int);
		int longitud();
		bool buscar(UnicodeString);
		void cintaPasoAPaso(TStringGrid*, Cinta*);
		UnicodeString recuperarMovimiento(int);
};


#endif
