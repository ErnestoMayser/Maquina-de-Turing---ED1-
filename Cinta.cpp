//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cinta.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Cinta::Cinta() {
	tape = new ListaVec();
}

void Cinta::insertarSimbolo(UnicodeString x) {
	if(tape->vacia()) {
		tape->insertarPrim(x);
	} else {
		if(!(tape->existe(x))){
			tape->insertarUlt(x);
		}
    }
}

void Cinta::insertarEstado(UnicodeString est) {
	if(tape->vacia()) {
		tape->insertarPrim(est);
	} else {
		if(!(tape->existe(est))) {
			tape->insertarUlt(est);
		}
    }
}

void Cinta::insertarMovimientos(UnicodeString movi) {
	if(tape->vacia()) {
		tape->insertarPrim(movi);
	} else {
		tape->insertarUlt(movi);
	}
}

UnicodeString Cinta::getSimbolo(int pos) {
	UnicodeString simb = tape->recupera(pos);
	return simb;
}

UnicodeString Cinta::getEstado(int pos) {
	UnicodeString est = tape->recupera(pos);
	return est;
}

UnicodeString Cinta::getMovimiento(int pos) {
	UnicodeString mov = "";
	UnicodeString x = tape->recupera(pos);
	UnicodeString est = x.SubString(1, 1);
	UnicodeString ini = x.SubString(2, 1);
	UnicodeString cam = x.SubString(3, 1);
	UnicodeString sig = x.SubString(4, 1);
	UnicodeString movi = x.SubString(5, 1);
	mov = mov + est + " " + ini + "->" + cam + "," + sig + "," + movi;
	/*int i = pos;
	int cont = 0;
	while(cont < 4) {
		UnicodeString x = tape->recupera(i);
		if (cont == 0) {
			mov += x + "->";
		} else {
			mov += x + ",";
        }
		i++;
		cont++;
	}  */
	return mov;
}

int Cinta::longitud() {
	return tape->cantElem;
}

bool Cinta::buscar(UnicodeString x) {
	return tape->existe(x);
}

void Cinta::cintaPasoAPaso(TStringGrid *cinta, Cinta *movimientos) {
	int cant = movimientos->longitud();
	int i = 0;
	while(i < cant - 1) {
		UnicodeString est = movimientos->getMovimiento(i);
		UnicodeString act = est.SubString(0, 1);
		UnicodeString cam = est.SubString(1, 1);
		UnicodeString mov = est.SubString(2, 1);
		int j = 5;
		while(cinta->Cells[j][0] == act) {
			if (mov == "D") {
				j++;
			}else if (mov == "I") {
				j--;
				  } else if (mov == "H") {
							return;
						 }
		}
		i++;
    }
}

UnicodeString Cinta::recuperarMovimiento(int pos) {
	UnicodeString mov = tape->recupera(pos);
	return mov;
}
