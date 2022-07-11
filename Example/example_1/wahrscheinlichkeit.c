#include <stdio.h>

//brechnen die wharscheinlichkeit,
//dass 2 Buchstaben gleichen sind
int main ()
 {  //Haeufingkeit eines Buchstaben im Text
    int buchstaben[26] ={59,98,36,25,54,84,57,67,51,54,40,70,87,24,73,87,34,21,68,59,72,77,79,41,18,61};
    double p = 0 ; 
    int n = 1496; // Gesamtzahl der Buchstaben im Text
    for (int i=0;i<26;i++)
        {
            p += buchstaben[i]*(buchstaben[i]-1) ;
            printf("sum = %lf \n",p);
        }
    p = p/(n*(n-1));
    printf("wahrscheinlichkeit = %lf",p);
 }