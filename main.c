/*
 * Snake in C by Giacomo Leandrini & Gabriele Di Carlo
 * last rev. date: 11/12/2021
 * file: "main.c"
 */

//includo l'header delle funzioni
#include "functions.h"

int main()
{
    //imposto il colore del testo della console, tutta roba da proveniente da <windows.h> trovata su stackoverflow :)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    //dichiaro il serpente e imposto la posizione iniziale
    snakechunk snake[ssize];
    token apple;
    for(int i = 0; i < ssize; i++)
    {
        snake[i].x = -1;
        snake[i].y = -1;
    }
    
    snake[0].x = size/2;
    snake[0].y = size/2;
    
    //dichiaro la matrice del campo da gioco(board)
    char board[size][size];
    //dichiaro la variabile direzione che è un valore intero che va da 1 a 4. 1 = lt; 2 = dw, 3 = rt; 4 = up
    int direction = 1;
    //dichiaro un variabile che utilizzo come buffer per la direzione alla lettura del tasto premuto
    int dirbuffer;
    int score = 0;
    int snakeLength = 1;
    int increase = 0;
    //scrivo il campo 
    drawGround(board);
    //faccio apparire una mela
    spawnApple(board, &apple);
    //scrivo lo snake nel campo alla posizione iniziale
    printSnake(board, snake, &snakeLength);
    //stampo il campo
    printGround(board, score);
    
    //VARIABILI TEMPO
    time_t moveTime = time(NULL);
    struct timeval oldT;
    struct timeval newT;
    
    //LOOP INFINITO
    while(1)
    {
        //se un tasto viene premuto
        if(kbhit())
            {   //scrivo il valore del tasto nella variabile dirbuffer
                dirbuffer = isInput();
                //verifico se la direzione del buffer è diversa dall'opposto della direzione attuale
                if(dirbuffer != dirOpposite(direction))
                    direction = dirbuffer;
            }        
        //questo if provvede al timing del gioco
        gettimeofday(&newT, NULL);
        if(time_diff(&oldT, &newT) >= speed)
        {
            gettimeofday(&oldT, NULL);
            
            moveSnake(snake, direction, board, &snakeLength, increase);
            increase = 0;
            printGround(board, score);
            cleanGround(board);
            if(appleAte(snake, &apple))
            {
                increase = 1;
                snakeLength++; 
                score++;
                spawnApple(board, &apple);
            }
            if(isDead(snake, board, &snakeLength))
            {
                gameOver();
                printf("Your score is: %d!", score);
                return 0;
            }
        }
    }
    return 0;
}
