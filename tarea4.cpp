#include <iostream>

using namespace std;

void MostrarMatriz(int Matriz[][9]){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout<<Matriz[i][j]<<" ";
    }
    cout<<endl;
  }
}

void LlenarMatriz(char* inputC,int Matriz[][9]){
  bool var=true,var2=true;
  string input = inputC;
  string token,token2,auxiliar;
  int largo = input.length(), pos,n=0,pos2,aux;
  int numero[2];
  char delimitador = ']',delimitador2= ';';
   // cout<<input<<endl;
  while(n<largo){
    pos = input.find(delimitador);
    if(pos != -1 && var == true){
      if(pos == -1){
        var = false;
      }
      token = input.substr(1,pos-1);
      auxiliar = token;
      for(int i=0;i<3;i++){
        if(i!=2){
          pos2= auxiliar.find(delimitador2);
          token2 = auxiliar.substr(0,pos2);
          aux = stoi(token2);
          numero[i] = aux;
          auxiliar.erase(0,pos2+1);
        //cout<<token2<<endl;
        }else{
          //cout<<auxiliar<<endl;
          aux = stoi(auxiliar);
          if(numero[0] >= 0 && numero[0] <= 9 && numero[1] >= 0 && numero[1] <= 9 && aux >=1 && aux <=9){
            Matriz[numero[1]][numero[0]] = aux;
          }else{
            cout<<"Ingrese valor en los rangos correctos"<<endl;
            n=largo;
            var2=false;
          }
        }
      }
      input.erase(0,pos+1);
    //cout<<token<<endl;
      n++;
    }else{
      n=largo;

    }
  }
  if(var2== true){
   MostrarMatriz(Matriz);
  }

}
void InicializarMatriz(int Matriz[][9]){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      Matriz[i][j] = 0;
    }
  }
}

bool RevisarFila(int fila,int valor,int Matriz[][9]){
  for(int i=0;i<9;i++){
    if(Matriz[fila][i] == valor){
      cout<<"El Número "<<valor<<" se encuentra en la fila n°: "<<fila<<endl;
      return false;
    }
  }
  return true;
}
bool RevisarColumna(int columna,int valor,int Matriz[][9]){
  for(int i=0;i<9;i++){
    if(Matriz[i][columna] == valor){
      cout<<"El Número "<<valor<<" se encuentra en la columna n°: "<<columna<<endl;
      return false;
    }
  }
  return true;
}




bool RevisarSubmatriz(int SubMatriz,int valor,int Matriz[][9]){
  int fila=0,columna=0;
  switch(SubMatriz){
    case 1: fila=0; columna=0;
        break;
    case 2: fila=0; columna=3;
        break;
    case 3: fila=0; columna=6;
        break;
    case 4: fila=3; columna=0;
        break;
    case 5: fila=3; columna=3;
        break;
    case 6: fila=3; columna=6;
        break;
    case 7: fila=6; columna=0;
        break;
    case 8: fila=6; columna=3;
        break;
    case 9: fila=6; columna=6;
        break;
  }
  for(int i=fila;i<fila+3;i++){
    for(int j=columna;j<columna+3;j++){
      if(Matriz[i][j] == valor){
        cout<<"El Número "<<valor<<" se encuentra en la SubMatriz n°: "<<SubMatriz<<endl;
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char* argv[]){
  int Matriz[9][9];
  InicializarMatriz(Matriz);
  LlenarMatriz(argv[1],Matriz);
  int opcion,fila,columna,SubMatriz,valor;
  bool var=true;
  while(var){
    cout<<"Ingrese Opcion: "<<endl;
    cin>>opcion;
    switch(opcion){
      case 1: cout<<"Fila"<<endl;
          cin>>fila;
          cout<<"Valor"<<endl;
          cin>>valor;
          RevisarFila(fila,valor,Matriz);
          break;
      case 2: cout<<"Columna"<<endl;
          cin>>columna;
          cout<<"Valor"<<endl;
          cin>>valor;
          RevisarColumna(columna,valor,Matriz);
          break;
      case 3: cout<<"Submatriz"<<endl;
          cin>>SubMatriz;
          cout<<"Valor"<<endl;
          cin>>valor;
          RevisarSubmatriz(SubMatriz,valor,Matriz);
          break;
      default: var=false;
          break;
    }

  }
}
