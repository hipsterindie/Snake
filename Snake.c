#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>


#define WIDTH 30
#define HEIGHT 30


int head = 0, tail = 0;
int newhead;
int i, j, fruitx, fruity, flag;
int gameover, score;
int x, y; 
void Draw();
void Setup();
void Input();
void Logic();


void main (){
    int m, n;
    Setup();
    while(!gameover){
        Draw();
        Input();
        Logic();
    }
}

void Draw(){
    system("cls");
    for (i = 0; i < HEIGHT; i++){
        for (j = 0; j < WIDTH; j++){
            if ( i == 0 || i == (WIDTH - 1) || j == 0 || (j == HEIGHT - 1)){
                printf("#");
            }
            else{
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }


    //print score after game ends
    printf("score = %d", score);
    printf("\n");
    printf("press X to exit the game");
    fflush(stdout);
}

void Setup(){
    
    
    gameover = 0;
    x = HEIGHT/2;
    y = WIDTH/2;
    label1:
      fruitx = rand()%25;
      if(fruitx==0)
        goto label1;
    label2:
      fruity = rand()%25;
      if(fruity==0)
        goto label2;
    score=0;
}

void Input(){
    if(kbhit()){
        switch(getch()){
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'd':
            flag=3;
            break;
        case 'w':
            flag=4;
            break;
        case 'x':
            gameover=1;
            break;
        }
    }
}

void Logic(){
    //how the fuck can i stop that blinking seizure inducing
    Sleep(10);
    switch(flag){
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    //game is over
    if(x<0 || x>HEIGHT || y<0 || y>WIDTH)
        gameover=1;
    //snake reaches the fruit, update score
    //maybe make snek longer?? how???
    if(x==fruitx && y==fruity){
        label3:
          fruitx=rand()%25;
          if(fruitx==0)
            goto label3;

        //after eating the fruit above (if statement)
        //make a new fruit (label 3 & 4)
        label4:
          fruity=rand()%25;
          if(fruity==0)
            goto label4;
        score+=10;
    }   
    else    
        tail = (tail + 1) % 1000;
}