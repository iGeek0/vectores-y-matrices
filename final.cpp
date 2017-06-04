#include "iostream"
#include "stdio.h"
#include "string"
#include <sstream>
#include <iomanip>

using namespace std;

double funcionDescuento(double descuento, double precio, double cantidad){
double desc  =  ((descuento * precio) / 100) * cantidad;
return desc;
}
int main()
{
int cantidadPantalon=0;
int cantidadCami=0;
int cantidadZa=0;


//Inicia elementos de la tienda
cout << "\n*****TIENDA COMERCIAL SUPER TIENDA*****:\n";
cout << "\nPRODUCTOS DISPONIBLES:\n";

string  items[] = {"Pantalon", "Camiseta", "Zapatos"};
cout<<"----------------------------------------------------------------------------"<<endl;

double productos[3][2]={{300.00,10},{200.00,20},{600.00,5}};
cout <<left << setw(15)<<"id";
cout <<left << setw(15)<<"Producto";
cout <<right << setw(15)<<"Precio";
cout <<right << setw(15)<<"Descuento";
cout << "\n"<<endl;
for (int i = 0; i < 3; i++)
{
cout <<left << setw(15)<<i+1; //id
cout <<left << setw(15)<<items[i]; //Producto
ostringstream os;
os  << '$'<< productos[i][0];// agregamos simbolo de pesos
cout <<right << setw(15)<<os.str(); //Precio
ostringstream os2;
os2 << productos[i][1] << '%';// agregamos simbolo de descuento
cout <<right << setw(15)<<os2.str(); //Descuento
cout << "\n"<<endl;
}
cout<<"----------------------------------------------------------------------------"<<endl;
//Termina elemento de la tienda

//Inicia interaccion del usuario
bool continuar = true;
int id=0;
int cantidad=0;
double subtotal=0;
double descuento=0;
double total = 0;
while (continuar)
{

cout<<"Teclee el id del producto que desea comprar:"<<endl;
cin>>id;
cout<<"Cantidad de unidades:"<<endl;
cin>>cantidad;

switch(id){
case 1:
cantidadPantalon= cantidadPantalon + cantidad;

subtotal = subtotal + (productos[0][0]*cantidad);
descuento = descuento +funcionDescuento(productos[0][1],productos[0][0],cantidad);



break;

case 2:
cantidadCami= cantidadCami + cantidad;

subtotal = subtotal + (productos[1][0]*cantidad);
descuento = descuento +funcionDescuento(productos[1][1],productos[1][0],cantidad);


break;

case 3:
cantidadZa= cantidadZa + cantidad;
subtotal = subtotal + (productos[2][0]*cantidad);
descuento = descuento +funcionDescuento(productos[2][1],productos[2][0],cantidad);

break;

default:
cout << "No selecciono un id del producto de la lista"<< endl;
break;

}
cout<<"Desea seguir comprando(s/n)?:"<<endl;
string respuesta;
cin>>respuesta;
if(respuesta =="s")
{
continuar=true;
}
else
{
continuar=false;
}

}

//Fuera del ciclo
total = subtotal -descuento;
cout << "\nPRODUCTOS COMPRADOS:\n";
cout<<"----------------------------------------------------------------------------"<<endl;
cout <<left << setw(15)<<"id";
cout <<left << setw(15)<<"Producto";
cout <<right << setw(15)<<"Precio";
cout <<right << setw(15)<<"Cantidad";
cout <<right << setw(15)<<"Descuento";
cout << "\n"<<endl;
for (int i = 0; i < 3; i++)
{
cout <<left << setw(15)<<i+1; //id
cout <<left << setw(15)<<items[i]; //Producto
ostringstream os;
os  << '$'<< productos[i][0];// agregamos simbolo de pesos
cout <<right << setw(15)<<os.str(); //Precio
ostringstream os2;
//switch para cantidades
switch(i){
case 0:
cout <<right << setw(15)<<cantidadPantalon;
break;
case 1:
cout <<right << setw(15)<<cantidadCami;
break;
case 2:
cout <<right << setw(15)<<cantidadZa;
break;

}

os2 << productos[i][1] << '%';// agregamos simbolo de descuento
cout <<right << setw(15)<<os2.str(); //Descuento
cout << "\n"<<endl;

}
cout<<"----------------------------------------------------------------------------\n"<<endl;


cout<<"********************************TICKET**************************************"<<endl;
cout << "\n"<<endl;
cout <<right << setw(15)<<"Subtotal: $"<<subtotal; //Descuento
cout << "\n"<<endl;
cout <<right << setw(15)<<"Descuento: $"<<descuento; //Descuento
cout << "\n"<<endl;
cout <<right << setw(15)<<"Total: $"<<total; //Descuento
cout << "\n"<<endl;
cout<<"****************************************************************************"<<endl;


return 0;
}
