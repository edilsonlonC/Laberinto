#include <stdio.h>
#include <stdlib.h>

const int N=21;
const int M=95;
FILE * archivo;
void mapear (char lab [N][M]);


//iguala el valor de una matriz
void igual (char lab [N][M],char aux [N][M])
{
  for (int i=0;i<N;i++)
  {
    for (int j=0;j<M;j++)
    aux[i][j]=lab[i][j];
  }
}
//limpia caracteres sobrantes
void limpiar (char lab [N][M])
{
  for (int i=0;i<N;i++)
  {
    for (int j=0;j<M;j++)
    {
      if (lab[i][j]!='.'&&lab[i][j]!='#'&&lab[i][j]!='?'&&lab[i][j]!='e'&&lab[i][j]!='*'&&lab[i][j]!='\n')
      lab[i][j]='\b';
    }
  }
}



void mostrar (char lab [N][M])
{
  for (int i=0;i<N;i++)
  {
    for (int j=0;j<M;j++)
    printf("%c",lab[i][j]);
    printf("\n");

  }
}


//pasa el laberinto del archivo a la matriz
void mapear (char lab [N][M])
{
  archivo=fopen("archivo2.txt","r+b");
  fseek(archivo,0,0);
  for (int i=0;i<N;i++)
  {
    for (int j=0;j<M;j++)
    {
    fread(&lab[i][j],sizeof(char),1,archivo);

    }

  }
  fclose (archivo);
}
