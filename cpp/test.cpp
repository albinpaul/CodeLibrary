#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.8
#define n 50
typedef struct PARACHUTISTE
{
    double masse;
    double trainee;
    double tempsf;
} PARACHUTISTE;
//Prototype de fonction//
PARACHUTISTE obtienEntree(PARACHUTISTE *);
double calculeVitesses(PARACHUTISTE, double**); /*calculate the speed in a while loop*/
void afficheTable(PARACHUTISTE, double**);
/*---------------------------------------------------------------------------------------------------------------------------------*/
void main()
{
    double **v;
    double vitessestemps[51][2];
    v = vitessestemps;
    PARACHUTISTE para;
    para = obtienEntree(&para);
    calculeVitesses(para, v);
    afficheTable(para, v);
}
PARACHUTISTE obtienEntree(PARACHUTISTE *para)
{
    printf("Veuillez entrez la masse du parachutiste (en kg):");
    scanf("%lg", &para->masse);
    printf("Veuillez entrer le coefficient de tra\214n\202e du parachute (en kg/s):");
    scanf("%lg", &para->trainee);
    printf("Veuillez entrez le temps \202coul\202 (en secondes):");
    scanf("%lg", &para->tempsf);
    return (*para);
}
double calculeVitesses(PARACHUTISTE para, double **v)
{
    double x, t, p;
    int o;
    p = para.tempsf/n;
    t = 0;
    o = 0;
    while(t<=para.tempsf && o<=51) /*o<51 still causes SIGSEGV*/
    {
        x = -(para.trainee/para.masse)*(t);
        v[0+o][0] = ((g*para.masse)/para.trainee)*(1-pow(M_E, x)); /*getting SIGSEGV here*/
        t = t+p;
        v[0+o][1] = t;
        o = o+1;
    }
    return(**v);
}
void afficheTable(PARACHUTISTE para, double **v) /*incomplete; can be disregarded; going to be used to print the 2d array*/
{
    printf("%g", v[0][1]);
}