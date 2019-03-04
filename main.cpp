#include"laberinto.h"
int main ()
{
  char lab [N][M];
  coordenadas C;
  C=new (struct coordenada);
  mapear(lab);
  limpiar(lab);
  //mostrar(lab);
    int i,j;
  busqueda_elemento(lab,&i,&j);
  cout<<i<<"  "<<j<<endl;
  C->x=i;
  C->y=j;
  C->posibles={1,-1,2,-2};
  solucionar(lab,C);
  if(solu==0)
  cout<<"el laberinto no tiene solucion"<<endl;

  //mostrar(lab);

  return 1;
}
