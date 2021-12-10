#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sys/time.h>
#include <time.h>

//definisco delle costanti globali
#define size 33 //lato del campo da gioco
#define ssize 64
#define speed 0.6 //velocità di refresh del gioco
#define startx size/2 //coordinate della posizione iniziale dello snake 
#define starty size/2

//definsco il tipo di struttura per lo snake che una coppia di coordinate 
typedef struct {
    int x;
    int y;
} snakechunk;

//definisco il tipo di dato token che serve per la mela
typedef struct {
    int x;
    int y;
} token;

//verifica l'input da tastiera e se non è compreso tra {w,a,s,d} restituisce 0 sennò restituisce la direzione associata a valore intero rispetto al tasto
int isInput();

//scrive lo snake nel campo da gioco(board)
void printSnake(char a[size][size], snakechunk b[ssize], int *c);

//scrive il campo da gioco(mette caratteri vuoti all'interno e aggiunge una cornice) nella matrice in ingresso
void drawGround(char a[size][size]);

//stampa il campo da gioco al terminale dopo aver cancellato il testo al terminale
void printGround(char a[size][size]);

//muove lo snake a seconda della direzione e lo stampa sulla matrice campo da gioco 
void moveSnake(snakechunk a[ssize], char dir, char b[size][size], int *c, int inc);

//restituisce 1 se lo snake sarà morto nel prossimo frame
int isDead(snakechunk a[ssize], char b[size][size]);

//cancella il terminale e stampa "Hai perso!"
void gameOver();

//restuisce la direzione opposta alla direzione in ingresso
int dirOpposite(int dir);

//spawna la mela e resituisce scrive le coordinate nella mela nell'elemento token parametro
void spawnApple(char a[size][size], token *b);

//restituisce 1 se lo snake è sulla mela
int appleAte(snakechunk a[ssize], token *b);

void cleanGround(char a[size][size]);