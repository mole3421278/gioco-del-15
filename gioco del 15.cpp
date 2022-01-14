#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define k 4
int m[k][k];
void carica(int m[k][k]);
void cercasposta(int m[k][k]);
int controllo(int m[k][k]);
void randomize();
main()
{
      carica(m);
      do
      {
      cercasposta(m);
      }
      while(controllo(m)==0);
      printf("HAI VINTO, NON SO COME, DIECIMILA MILIONI DI MILIARDI DI... MANATE: CONGRATULAZIONI!!!(PERCHE' IO NON RIESCO A VINCERE???");
      getch();
}
void carica(int m[k][k])
{
     int i,j,I,x,y;
     randomize();
     for(i=0;i<k;i++)
     {
                     for(j=0;j<k;j++)
                     m[i][j]=0;
     }
     I=1;
     do
     {
         x=rand()%4;
         y=rand()%4;
         if(m[x][y]==0)
         {
                       m[x][y]=I;
                       I++;
         }
     }
     while(I<16);
     for(i=0;i<k;i++)
     {
                     for(j=0;j<k;j++)
                     printf("%d\t",m[i][j]);
                     printf("\n\n");
     }
}
void cercasposta(int m[k][k])
{
     int aus,i,j,c;
     for(i=0;i<k;i++)
     {
                     for(j=0;j<k;j++)
                     {
                                     if(m[i][j]==0)
                                     {
                                                   c=getch();
                                                   if((c==56)&&(i!=0))
                                                   {
                                                                      aus=m[i][j];
                                                                      m[i][j]=m[i-1][j];
                                                                      m[i-1][j]=aus;
                                                   }
                                                   if((c==54)&&(j!=3))
                                                   {
                                                                      aus=m[i][j];
                                                                      m[i][j]=m[i][j+1];
                                                                      m[i][j+1]=aus;
                                                   }
                                                   if((c==50)&&(i!=3))
                                                   {
                                                                      aus=m[i][j];
                                                                      m[i][j]=m[i+1][j];
                                                                      m[i+1][j]=aus;
                                                   }
                                                   if((c==52)&&(j!=0))
                                                   {
                                                                     aus=m[i][j];
                                                                     m[i][j]=m[i][j-1];
                                                                     m[i][j-1]=aus;
                                                   }
                                                   system("cls");
                                                   for(i=0;i<k;i++)
     {
                     for(j=0;j<k;j++)
                     printf("%d\t",m[i][j]);
                     printf("\n\n");
     }
                                     }
                     }
     }
}
int controllo(int m[k][k])
{
     int i,j,n[16],t;
     for(i=0;i<16;i++)
     n[i]=i+1;
     t=0;
     for(i=0;i<k;i++)
     {
                     for(j=0;j<k;j++)
                     {
                                     if(m[i][j]==n[t])
                                     t++;
                     }
     }
     if(t==15)
     return 1;
     else
     return 0;
}
void randomize()
{
time_t t;
srand((unsigned) time(&t));
}
int random(int limit)
{
return rand()%limit;
}
