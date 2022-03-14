#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "RPGLCG.h"
using namespace std;

template <class Tipo,class Tip>
class Admi
{
private:
    Tipo Nombre;
    Tip Numero;

public:
    Admi()
    {

    }
    Admi(Tipo _Nom, Tip _Num)
    {
        Nombre = _Nom;
        Numero = _Num;
    }
    void SetNombre(Tipo _Nom)
    {
        Nombre= _Nom;
    }
    void SetNumero(Tip _Num)
    {
        Numero = _Num;
    }

    friend ostream &operator<<(ostream &Imprimir, Admi &Obj)
    {
        Imprimir<<"NOMBRE: "<<Obj.Nombre<<endl;
        Imprimir<<"BOLETA: "<<Obj.Numero<<endl;
        return Imprimir;

    }


};
//----------------------------------------------------------------------------

struct Registro{
    char Nombre[5]="";
    char Email[41]="";
    char Comentario[8]="";

};
void Creditos();
void Intrucciones();
int main()
{

   setlocale(LC_ALL, "spanish");
   Registro Ingresa, Leer;
    char usuario;
    char rep;
    ofstream ArchivoG;
    ifstream ArchivoL;
	srand(time(NULL));
   cout<<"BIENVENIDO A:"<<endl;
   cout<<endl;
   cout<<endl;



   cout<<"\t\\      /  |         | ------------ ------------ |    /   \\      /"<<endl;
   cout<<"\t \\    /   |         |       |            |      |   /     \\    / "<<endl;
   cout<<"\t  \\  /    |         |       |            |      |  /       \\  /  "<<endl;
   cout<<"\t   \\/     |         |       |            |      | /         \\/   "<<endl;
   cout<<"\t   /      |         |       |            |      | \\         /\\   "<<endl;
   cout<<"\t  /        |       |        |            |      |  \\       /  \\  "<<endl;
   cout<<"\t /          |     |         |            |      |   \\     /    \\ "<<endl;
   cout<<"\t/            |___|     ------      ------------ |    \\ O /      \\"<<endl;
  system("PAUSE");
  system("cls");
    do{


    cout<<"         YUJIK.X        " <<endl;
    cout<<"_________________________"<<endl;
    cout<<"          MENU           " <<endl;
    cout<<"        DEL JUEGO          " <<endl;
    cout<<"_________________________"<<endl;
    cout<<"_________________________"<<endl;
    cout<<"     A) JUGAR            "<<endl;
    cout<<"     B) JUGADORES        "<<endl;
    cout<<"     C) INSTRUCCIONES    "<<endl;
    cout<<"     D) SALIR            "<<endl;
    cout<<"_________________________"<<endl;
    fflush(stdin);
    usuario=getchar();
    usuario=toupper(usuario);
    if (usuario!='A' && usuario!='B' && usuario!='C'&& usuario!='D')
    {
        cout<<"EL USUARIO NO EXISTE, FAVOR DE ESCOGER LA OPCION CORRECTA"<<endl;
        system("PAUSE");
        system("cls");
    }
    }while(usuario!='A' && usuario!='B' && usuario!='C' && usuario!='D');
    system("PAUSE");
        system("cls");
    switch(usuario)
    {
    case 'A':
        do{
    cout<<"    ~~~~~~~~~~PLAYER 1~~~~~~~~~~"<<endl;
    cout<<"    ~~~~~~~~~~ENTRANDO AL JUEGO~~~~~~~~~~"<<endl;


	Jugar();

     //INSERTA CODIGO DEL JUEGO

      cout<<" USTED HA TERMINADO EL JUEGO\n INGRESE SUS DATOS DE JUGADOR" <<endl;
      cout<<"__________________________________________"<<endl;
    ArchivoG.open("BD.txt",ios::out|ios::app);
    cin.ignore();
    cout<<"INGRESE SU NOMBRE DE JUGADOR (****)"<<endl;
    cin.getline(Ingresa.Nombre,5);
    cout<<"INGRESE SU CORREO ELECTRONICO"<<endl;
    cin.getline(Ingresa.Email,41);
    cout<<"INGRESE UNA CALIFICACION PARA NUESTRO JUEGO (BUENO,REGULAR,MALO)"<<endl;
    cin.getline(Ingresa.Comentario,8);
    ArchivoG.write((char* )&Ingresa,sizeof(Ingresa));
    ArchivoG.close();
    system("PAUSE");
    system("cls");


    //_---------------------------------------

    /*cout<<"    ~~DATOS DEL ULTIMO JUGADOR~~"<<endl;
     ArchivoL.open("BD.txt");
     ArchivoL.read((char*)&Leer, sizeof(Leer));
     cout<<"NOMBRE: "<<Leer.Nombre<<endl;
     ArchivoL.close();*/
     //_----------------------------------------------

    do{
    cout<<"¿QUIERE SEGUIR JUGANDO? S/N"<<endl;
    fflush(stdin);
    rep=getchar();
    rep=toupper(rep);
    if(rep!='s'&& rep!='S' && rep!='n'& rep!='N')
    {
          cout<<"POR FAVOR SOLO INGRESE S O N"<<endl;
          system("PAUSE");
          system("cls");

    }
    }while(rep!='s'&& rep!='S' && rep!='n'& rep!='N');


    }while(rep=='S'||rep=='s');
    if (rep=='n'|| rep=='N')
    {
        system("PAUSE");
        system("cls");
        return main();
    }

        break;

    case 'B':
system("PAUSE");
system("cls");
ArchivoL.exceptions(ifstream::failbit);
    try{
    ArchivoL.open("BD.txt");

    ArchivoL.read((char *) &Leer, sizeof(Leer));


cout<<"_____________________________JUGADORES________________________________"<<endl;
cout<<"______________________________________________________________________"<<endl;
cout<<"       NOMBRE                 CORREO                CALIFICACION         "<<endl;
cout<<"                                                     DEL JUEGO        "<<endl;
cout<<"______________________________________________________________________"<<endl;

while(ArchivoL && !ArchivoL.eof())
{

    cout<<"       \t"<<Leer.Nombre<<" "<<"          \t"<<Leer.Email<<" "<<"         \t"<<Leer.Comentario<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    ArchivoL.read((char *) &Leer, sizeof(Leer));

}

cout<<endl;
    }
    catch(ifstream::failure error)
    {
        cout<<error.what();
        cout<<"ERROR AL ABRIR LA BASE DE DATOS"<<endl;
        system("PAUSE");
        system("cls");
        return main();
    }


ArchivoL.close();


     break;

    case 'C':

         Intrucciones();
         return main();

        break;

    case 'D':
        Creditos();
        return 0;

        break;
}




    return 0;
}








void Intrucciones()
{

    cout<<"\t\tGRACIAS POR JUGAR YUJIK.X"<<endl;

cout<<"EN ESTE JUEGO TU OBJETIVO PRINCIPAL ES HACER\nQUE LA VIDA DE TU OPONENTE LLEGUE A 0 ANTES\nQUE LA TUYA."<<endl;
cout<<"PARA ESTO, CUENTAS CON:"<<endl;
cout<<"	1. ATAQUE DÉBIL- ESTE ATAQUE HACE\n\tPOCO DAÑO, PERO ES 100%\n\tEFECTIVO!"<<endl;
cout<<"	2. ATAQUE FUERTE- SI QUIERES HACER\n\tMÁS DAÑO DEBES USAR ESTE\n\tATAQUE. TIENE UN 50% DE\n\tEFECTIVIDAD."<<endl;
cout<<"	3. PODER ESPECIAL- LA ACCIÓN DE\n\tESTA HABILIDAD VARÍA DEPENDIENDO\n\tDEL EQUIPO DE TU PERSONAJE, SOLO\n\tTIENE 25% DE EFECTIVIDAD, PERO\n\tPERO VALE MUCHO LA PENA!"<<endl;
system("PAUSE");
system("cls");
cout<<"HAY CUATRO EQUIPOS:"<<endl;
cout<<"	- ROSE: AUMENTA LA VIDA DEL JUGADOR\n\tEN 10 PUNTOS."<<endl;
cout<<"	- DARK: HACE 10 PUNTOS DE DAÑO,\n\tMÁS QUE CUALQUIER ATAQUE FUERTE!"<<endl;
cout<<"        - HERO: AUMENTA LA VIDA DEL JUGADOR\n\tEN 5 PUNTOS Y HACE 5 PUNTOS DE\n\tDAÑO AL MISMO TIEMPO."<<endl;
cout<<"        -CHAOTIX: ESTE ES ESPECIAL PARA\n\tLOS QUE CREEN QUE LA SUERTE ESTÁ\n\tDE SU LADO. SI EL PODER ES\n\tEFECTIVO, AUMENTA LA VIDA DEL\n\tJUGADOR EN 5 PUNTOS, ADEMÁS DE\n\tHACER 15 PUNTOS DE DAÑO!\n\tPERO SI NO ES EFECTIVO, EL\n\tJUGADOR SE HARÁ 3 PUNTOS DE\n\tDAÑO A SI MISMO!"<<endl;
system("PAUSE");
system("cls");
cout<<"PARA ADAPTARSE A TU ESTILO DE JUEGO,\n\tEXISTEN TRES TIPOS DE PERSONAJES QUE\n\tMODIFICAN LOS PUNTOS DE DAÑO QUE HACEN\n\tLOS ATAQUES DÉBILES Y FUERTES; OFRECIENDO\n\tESTILOS DE JUEGO LENTOS Y SEGUROS, RÁPIDOS\n\tY DE AZAROSOS, Y BALANCEADOS:"<<endl;
cout<<"	~ SPEED\n\t1.-DÉBIL: 2\n\t2.-FUERTE: 5"<<endl;
cout<<"	~ POWER\n\t1.-DÉBIL: 1\n\t2.-FUERTE: 6"<<endl;
cout<<"	~ FLY\n\t1.-DÉBIL: 3\n\t2.-FUERTE: 4"<<endl;
system("PAUSE");
system("cls");
cout<<"DE ESTA MANERA, EXISTEN 12 PERSONAJES\nDISTINTOS Y MÁS DE 140 POSIBILIDADES DE\nJUEGO!"<<endl;
cout<<"Selecciona el que más te guste:"<<endl;
cout<<"Personajes|Rose | Dark |  Hero  |Chaotix"<<endl;
cout<<"----------|-----|------|--------|-------"<<endl;
cout<<"   Speed  | Amy |Shadow| Sonic  |Espio  "<<endl;
cout<<"----------|-----|------|--------|-------"<<endl;
cout<<"   Power  | Big |Omega |Knuckles|Vector "<<endl;
cout<<"----------|-----|------|--------|-------"<<endl;
cout<<"   Fly    |Cream|Rouge | Tails  |Charmy "<<endl;
system("PAUSE");
system("cls");
cout<<"AL FINAL DEL JUEGO, MIENTRAS MÁS VIDA TE\n\tHAYA QUEDADO Y MENOS TURNOS HAYAS OCUPADO\n\tPARA CUMPLIR TU OBJETIVO, TU PUNTUACIÓN\n\tAUMENTARÁ. COMPITE POR EL PUNTAJE MÁS ALTO\n\tY QUE TU NOMBRE SE QUEDE EN EL JUEGO!"<<endl;
system("PAUSE");
system("cls");
cout<<"ESO ES TODO LO QUE NECESITAS SABER DE ESTE\n\tJUEGO... A JUGAR!"<<endl;
system("PAUSE");
system("cls");

}

void Creditos()
{
    Admi<string, int>ing1("KHERI SAÚL CHAVIRA LEAL",2018352231), ing2("GUILLERMO XOLALPA MARTÍNEZ", 2015131498);
    cout<<"\t~~DESARROLLADORES~~"<<endl;
    cout<<ing1;
    cout<<ing2;


}

