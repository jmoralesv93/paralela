#include <iostream>
#include <stdio.h>
#include <mpi.h>
#include <fstream>
#include <string.h>

using namespace std;

void contar_lineas_archivo(int &numero_lineas_archivo , char nombre_archivo_csv[] , int &tamanio , int &procesador) {

  string texto_archivo_csv;
  ifstream archivo_csv;

  if (procesador == 0) {
    archivo_csv.open(nombre_archivo_csv , ios::in);
    if (archivo_csv.fail()) {
      cout << "Error al intentar abrir el archivo" << endl;
    }
    else {
      while (!archivo_csv.eof()) {
        getline(archivo_csv , texto_archivo_csv);
        numero_lineas_archivo++;
      }
    }
    MPI_Send(&numero_lineas_archivo , 1 , MPI_INT , 1 , 0 , MPI_COMM_WORLD);
  }
  else if (procesador == 1) {
    MPI_Recv(&numero_lineas_archivo , 1 , MPI_INT , 0 , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE);
    cout << "Procesador 0: El procesador 1 ha contado " << numero_lineas_archivo << " lineas de archivo" << endl;
  }
  archivo_csv.close();
}

int main(int argc , char** argv){

  int tamanio , procesador;
  int numero_lineas_archivo = -2;
  char nombre_archivo_csv[10] = "UTEM.csv";
  MPI_Init(&argc , &argv);
  MPI_Comm_size(MPI_COMM_WORLD , &tamanio);
  MPI_Comm_rank(MPI_COMM_WORLD , &procesador);

  contar_lineas_archivo(numero_lineas_archivo , nombre_archivo_csv , tamanio , procesador);

  MPI_Finalize();
}