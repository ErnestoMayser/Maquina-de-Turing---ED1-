//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TuringMachine.h"
#include <string>
#include "Cinta.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
Cinta *simbolos = new Cinta();
Cinta *estados = new Cinta();
Cinta *movimientos = new Cinta();
int puntero = 5;
int contadorMovi = 0;
UnicodeString estado = "";
using namespace std;
using std::string;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SimboloClick(TObject *Sender)
{
	UnicodeString simb = InputBox("Insertar Simbolo", "Simbolo", "");
	simbolos->insertarSimbolo(simb);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	UnicodeString est = InputBox("Insertar Estado", "Estado", "");
	estados->insertarEstado(est);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	UnicodeString est = InputBox("Insertar Estado", "Estado", "");
	UnicodeString ini = InputBox("Insertar Estado inicial", "Estado", "");
	UnicodeString cam = InputBox("Insertar valor a cambiar", "Estado", "");
	UnicodeString sig = InputBox("Insertar Estado siguiente", "Estado", "");
	UnicodeString mov = InputBox("Insertar Movimiento(D, I, H)", "Movimiento", "");
	UnicodeString movi = est + ini + cam + sig + mov;
	movimientos->insertarMovimientos(movi);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	for (int i = 0; i < simbolos->longitud(); i++) {
		UnicodeString x = simbolos->getSimbolo(i);
		StringGrid1->Cells[i][0] = x;
		StringGrid1->ColCount ++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	for (int i = 0; i < estados->longitud(); i++) {
		UnicodeString x = estados->getEstado(i);
		StringGrid2->Cells[i][0] = x;
		StringGrid2->ColCount ++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int j = 0;
	for (int i = 0; i < movimientos->longitud(); i++) {
		UnicodeString x = movimientos->getMovimiento(i);
		StringGrid3->Cells[j][0] = x;
		StringGrid3->ColCount ++;
        j++;
	}
}
//---------------------------------------------------------------------------
// Preguntamos si todos los caracteres de la entrada se encuentran en nuestro vector de simbolos
bool seEncuentran(UnicodeString x) {
	int leng = x.Length();
	bool b = false;
	for (int i = 0; i < x.Length(); i++) {
		UnicodeString c = x.SubString(i,1);
		if (simbolos->buscar(c)) {
			b = true;
		} else {
			b = false;
        }
	}
	return b;
}
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	UnicodeString vacio = Edit1->Text;
	UnicodeString entrada = Edit2->Text;
	if (simbolos->buscar(vacio)) {
		for (int i = 0; i <= StringGrid4->ColCount - 1; i++) {
			StringGrid4->Cells[i][0] = vacio;
		}
	}
	if (seEncuentran(entrada)) {
		int k = 0;
		for (int j = 5; k < entrada.Length(); j++) {
			StringGrid4->Cells[j][0] = entrada.SubString(k, 1);
			k++;
		}
	}
	StringGrid4->Cells[puntero][1] = "^";
}
//---------------------------------------------------------------------------

int cantDeEst(UnicodeString est) {
	int cant = 0;
	int k = movimientos->longitud();
	UnicodeString x = movimientos->recuperarMovimiento(0);
	int i = 0;
	while(i <= k - 1) {
		UnicodeString y = x.SubString(1, 1);
		if (y == est) {
			cant++;
		}
		i++;
		x = movimientos->recuperarMovimiento(i);
	}
	return cant;
}

int buscarEstado(UnicodeString est, UnicodeString ini) {
	int pos = -1; int k = cantDeEst(est);
	UnicodeString x = movimientos->recuperarMovimiento(0);
	int cant = movimientos->longitud();
	UnicodeString y = x.SubString(1, 1);
	if (k > 1) {
		int i = 0;
		while((i <= cant - 1) && (pos < 0)) {
			UnicodeString z = x.SubString(2, 1);
			if (y == est) {
				//UnicodeString w = StringGrid4->Cells[puntero][0];
				if (z == ini) {
					pos = i;
				}
			}
			i++;
			x = movimientos->recuperarMovimiento(i);
			y = x.SubString(1, 1);
        }
	} else {
		int i = 0;
		while((i <= cant - 1) && (pos < 0)) {
			if (y == est) {
				pos = i;
			}
            i++;
			x = movimientos->recuperarMovimiento(i);
			y = x.SubString(1, 1);
        }
	}
	return pos;
}

void __fastcall TForm1::Button7Click(TObject *Sender)
{
		StringGrid4->Cells[puntero][1] = "^";
		UnicodeString movi = "";
		if (estado == "") {
			movi = movimientos->recuperarMovimiento(0);
			estado = movi.SubString(1, 1);
		} else {
			int i = buscarEstado(estado, StringGrid4->Cells[puntero][0]);
			movi = movimientos->recuperarMovimiento(i);
			estado = movi.SubString(1, 1);
        }
		UnicodeString ini = movi.SubString(2, 1);
		UnicodeString cam = movi.SubString(3, 1);
		UnicodeString sig = movi.SubString(4, 1);
		UnicodeString mov = movi.SubString(5, 1);
		if (StringGrid4->Cells[puntero][0] == ini) {
			StringGrid4->Cells[puntero][0] = cam;
			if (mov == "D") {
				StringGrid4->Cells[puntero][1] = "";
				puntero++;
				StringGrid4->Cells[puntero][1] = "^";
			} else if (mov == "I") {
						StringGrid4->Cells[puntero][1] = "";
						puntero--;
						StringGrid4->Cells[puntero][1] = "^";
				   } else if (mov == "H") {
							StringGrid4->Cells[puntero][1] = "^";
							return;
						  }
		}
		if (sig != estado) {
			estado = sig;
		}




	/*int k = StringGrid3->ColCount;
	int y = 5;
	StringGrid4->Cells[y][1] = "^";
		UnicodeString movi = movimientos->recuperarMovimiento(0);
		UnicodeString est = movi.SubString(1, 1);
		UnicodeString ini = movi.SubString(2, 1);
		UnicodeString cam = movi.SubString(3, 1);
		UnicodeString sig = movi.SubString(4, 1);
		UnicodeString mov = movi.SubString(5, 1);
		UnicodeString var = ini;
		UnicodeString vare = est;
		//while((var == ini) && (vare == est)) {
			StringGrid4->Cells[y][0] = cam;
			if (sig != est) {
				vare = sig;
			}
			UnicodeString aux = StringGrid4->Cells[y + 1][0];
			if (aux != ini) {
				var = aux;
			}
			if (mov == "D") {
				y++;
				StringGrid4->Cells[y][1] = "^";
				StringGrid4->Cells[y - 1][1] = "";

			} else if (mov == "I") {
					   y--;
					   StringGrid4->Cells[y][1] = "^";
					   StringGrid4->Cells[y + 1][1] = "";
				   } else if (mov == "H") {
							  StringGrid4->Cells[y + 1][1] = "^";
							  return;
						  }
		//}*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarSClick(TObject *Sender)
{
	simbolos = new Cinta();
	int cant = StringGrid1->ColCount;
	for (int i = 0; i < cant; i++) {
		StringGrid1->Cells[i][0] = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	estados = new Cinta();
	int cant = StringGrid2->ColCount;
	for (int i = 0; i < cant; i++) {
		StringGrid2->Cells[i][0] = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	movimientos = new Cinta();
	int cant = StringGrid3->ColCount;
	for (int i = 0; i < cant; i++) {
		StringGrid3->Cells[i][0] = "";
	}
}
//---------------------------------------------------------------------------

