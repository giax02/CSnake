#include "functions.h"

void cleanGround(char a[size][size])
{
    for(int i = 1; i < size - 2; i++)
        {
            for(int j = 1; j < size - 2; j++)
            {
                if(a[j][i] != 'x')
                    a[j][i] = ' ';
            }
        }
}

void drawGround(char a[size][size])
{
    int i, j;
    //disegno il vuoto
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            a[i][j] = ' ';
        }
    }
    //disegno la cornice
    for(i = 0; i < size; i++) 
    a[0][i] = (char)205;
    
    for(i = 0; i < size; i++) 
    a[size - 1][i] = (char)205;
    
    for(i = 0; i < size; i++) 
    a[i][0] = (char)186;
    
    for(i = 0; i < size; i++) 
    a[i][size - 1] = (char)186;
    
    a[0][0] = (char)201; a[0][size - 1] = (char)187; a[size - 1][0] = (char)200; a[size - 1][size - 1] = (char)188;
    
            
    
    //disegno gli angoli
}

void printGround(char a[size][size])
{
    system("cls");
    int i, j;
    //disegno il vuoto
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    //disegno la cornice
    //disegno gli angoli
}

void printSnake(char a[size][size], snakechunk b[ssize], int *c) //printHead
{   
    for(int i = 0; i < *c; i++)
        a[b[i].y][b[i].x] = (char)001;
}

int isInput()
{
        switch(getch())
        {
            case 'a':
                return 1;
            case 's':
                return 2;
            case 'd':
                return 3;
            case 'w':
                return 4;
            default:
                return 0;
        }
} 

void moveSnake(snakechunk a[ssize], char dir, char b[size][size], int *c, int inc)
{   

    //aggiorno la posizone del corpo
    for(int i = 1; i <= *c - 1; i++)
    {
            a[i].x = a[i - 1].x;
            a[i].y = a[i - 1].y;
    }
    //aggiorno la posizione della testa
    switch(dir)
    {
        case 4:
        a[0].y -= 1;
        break;
        case 1:
        a[0].x -= 1;
        break;
        case 2:
        a[0].y += 1;
        break;
        case 3:
        a[0].x += 1;
        break;        
    }
    
    
    //stampo la testa
    cleanGround(b);
    printSnake(b, a, c);
}

int isDead(snakechunk a[ssize], char b[size][size])
{
    if(a[0].x == size - 1 || a[0].x == 0 || a[0].y == 0 || a[0].y == size-1)
        return 1;
    return 0;
}

void gameOver()
{
    system("cls");
    printf("Hai perso!\n");
}

int dirOpposite(int dir)
{
    switch(dir)
    {
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 2;
        default:
            return 0;
    }
}

void spawnApple(char a[size][size], token *b)
{
    srand(time(NULL));
    int x = (rand() % 31) + 1;
    int y = (rand() % 31) + 1;
    do {
        b->x = x;
        b->y = y;
    } while(a[y][x] != ' ');
    a[y][x] = 'x';
}

int appleAte(snakechunk a[ssize], token *b)
{
    if(a[0].x == b->x && a[0].y == b->y)
        return 1;
    return 0;
}
