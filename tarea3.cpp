#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>


using namespace std;

int main(int argc, char** argv){
  int M = 9;
  int MAT[M-1][M-1];
  int i,j;
  for (i=0;i<M;i++){
    for(j=0;j<M;j++){
      MAT[i][j] = 0;
    }
  }

  string A;
  string V;
  string CADENA;
  string CADENA2;
  string CADENA3;
  string FINAL;
  cout << "Ingrese la Secuencia" << endl;
  cin >> A;
  stringstream stream(A);

  while (getline(stream,V,'"')){
    if (V != ""){
      CADENA = CADENA + V;
    }
  }

  stringstream hola(CADENA);
  while (getline(hola,V,'[')){
    if (V != ""){
      CADENA2 = CADENA2 + V;
    }
  }

  stringstream ultimo(CADENA2);
  while (getline(ultimo,V,']')){
    if(V != ""){
      CADENA3 = CADENA3 + V;
    }
  }

  stringstream casi(CADENA3);
  while (getline(casi,V,';')){
    if(V != ""){
      FINAL = FINAL + V;

    }
  }

  int LARGO = FINAL.size();

  char NUMEROS[LARGO-1];

  strcpy(NUMEROS,FINAL.c_str());
  int CONTADOR = 0;
  int X,Y;
  for (i=0;i<LARGO;i++){

    if (CONTADOR == 0){
      X = NUMEROS[i]-48;
      CONTADOR++;
    }
    if (CONTADOR == 1){
      Y = NUMEROS[i]-48;
      CONTADOR++;
    }
    if (CONTADOR == 2){
      CONTADOR = 0;
      MAT[X][Y] = NUMEROS[i]-48;
    }
  }

  for (i=0;i<M;i++){
    for(j=0;j<M;j++){
      cout << MAT[i][j];
    }
    cout << endl;
  }
}
