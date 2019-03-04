#include "operaciones.h"
#include<iostream>
#include <vector>
#include <unistd.h>
int solu=0;//cantidad de solucioes
using namespace std;
using vec=vector<int>;

//coordenadas del objeto
  struct coordenada {
 int x,y;
 vec posibles;//={1,-1,2,-2};

};
typedef coordenada *coordenadas;


//mueve el camino
void mover (char lab [N][M],coordenadas & C)
{
  system("clear");
  lab[C->x][C->y]='*';
  mostrar(lab);
  sleep(1);

}
//verifica si hay un moviento posible en la derecha
bool Verifica_der (char lab [N][M],coordenadas  & C)
{
  if (lab[C->x][C->y+1]=='.'&&lab[C->x][C->y+1]!='e')
  return true;
  else return false;
}
//verifica si hay movimieto posible por la izquierda
bool Verifica_izq (char lab [N][M],coordenadas  & C)
{
  if (lab[C->x][C->y-1]=='.')
  return true;
  else return false;
}
//verifica si hay movimieto posible por abajo
bool Verifica_abajo (char lab [N][M],coordenadas  & C)
{
  if (lab[C->x+1][C->y]=='.')
  return true;
  else return false;
}
//verifica si hay movimieto posible por arriba
bool Verifica_arriba (char lab [N][M],coordenadas  & C)
{
  if (lab[C->x-1][C->y]=='.')
  return true;
  else return false;
}


//busca la posición del elemento

void busqueda_elemento (char lab [N][M],int *c,int *d)
{
  for (int i=0;i<N;i++)
  {
    for (int j=0;j<M;j++)
    {
      if (lab[i][j]=='*')
      {
        *c=i;
        *d=j;
        return;
      }
    }
  }
}



//verifica las movidas
void mover_lab (char lab [N][M],coordenadas & C)
{

//  cout<<C.x<<C.y<<endl;
//cout<<C->posibles.top()<<endl;


  if(Verifica_der(lab,C)&&C->posibles[0]==2)
  {
  C->y=C->y+1;
  mover(lab,C);
  //mover_lab(lab,C);
  }
  if (Verifica_izq(lab,C)&&C->posibles[0]==-2)
  {
    C->y=C->y-1;
    mover(lab,C);
    //mover_lab(lab,C);
  }
  if (Verifica_arriba(lab,C)&&C->posibles[0]==1)
  {
    C->x=C->x-1;
    mover(lab,C);
    //mover_lab(lab,C);
  }
  if (Verifica_abajo(lab,C)&&C->posibles[0]==-1)
  {
    C->x=C->x+1;
    mover(lab,C);
    //mover_lab(lab,C);

}

}
//elimina un eemento
void eliminar (coordenadas & C,int elemento)
{
  for(int i=0;i<C->posibles.size();i++)
  {
    if (C->posibles[i]==elemento)
    C->posibles.erase(C->posibles.begin()+i);
  }
}

//busca los posibles movimientos y deja en en el vector los elementos correspondientes
void posiblidades (char lab [N][M],coordenadas C)
{
  if (!Verifica_arriba(lab,C))
  eliminar(C,1);
  if (!Verifica_abajo(lab,C))
  eliminar(C,-1);
  if (!Verifica_der(lab,C))
  eliminar(C,2);
  if (!Verifica_izq(lab,C))
  eliminar(C,-2);
  //mover_lab(lab,C);
}
//verifica cuanddo hay solucion
void solucion (char lab [N][M],coordenadas C)
{
  posiblidades(lab,C);
  if (C->posibles.size()==1)
  {
    mover_lab(lab,C);
    C->posibles={1,-1,2,-2};
    solucion(lab,C);
  }
}

bool es_solucion(char lab [N][M],coordenadas &C)
{
  if (lab[C->x+1][C->y]=='?'||lab[C->x-1][C->y]=='?'||lab[C->x][C->y+1]=='?'||lab[C->x][C->y-1]=='?')
  return true;
  else return false;
}

bool no_solucion (coordenadas & C)
{
  if (C->posibles.empty())
  return true;
  else return false;
}
void solucionar (char lab [N][M],coordenadas & C)
{
  solucion(lab,C);
  if (es_solucion(lab,C))
  {
    cout<<"es solucion"<<endl;
    solu++;
      mostrar(lab);
    sleep(10);

  }else
  {
    if (no_solucion(C))
    {
      cout<<"no solucion"<<endl;
    }else{
      cout<<"esta aqui!!"<<endl;
      char aux_lab[N][M];
      coordenadas aux_coor=new(struct coordenada);
      igual(lab,aux_lab);
      aux_coor->x=C->x;
      aux_coor->y=C->y;
      aux_coor->posibles={C->posibles[0]};
      solucionar(aux_lab,aux_coor);
      C->posibles.erase(C->posibles.begin());
      solucionar(lab,C);
    }
  }


}
