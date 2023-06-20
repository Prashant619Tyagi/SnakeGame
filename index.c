#include<stdio.h>                      
#include<stdlib.h>    
#include<conio.h> 
#include<direct.h>               
 
int height=20,width=20;              //width = j (horizontal axis)   //height = i (vertical axis)   
int x,y,fx,fy;                       //x,y are the coordinates of snake head  
int flag,score;                      //fx,fy are the coordinates of fruit
int gameOver=0;
int tx[100],ty[100];
int fat=0;
void logic()
{
    int i;
    int prevx,prevy,prev2x,prev2y;
    prevx = tx[0];
    prevy = ty[0];
    tx[0] = x;
    ty[0] = y;
    for ( i = 1 ;i < fat; i++)
    {
       prev2x = tx[i];
       prev2y = ty[i];
       tx[i] = prevx;
       ty[i] = prevy;
       prevx = prev2x;
       prevy = prev2y;
    }
    
   switch (flag)
   {
       case 1:
       {  
          x--;
          break;
       }
       case 2:
       {  
          x++;
          break;
       }
       case 3:
       {  
          y--;
          break;
       }
       case 4:
       {  
          y++;
          break;
       }
       default:
       break;
   }
    if (x==0 ||x ==height ||y==0 ||y ==width)
    {
        gameOver=1;
        printf("\nGame Over.....");
    }
    for ( i = 0; i < fat; i++)
    {
        if (x==tx[i] && y==ty[i])
        {
            gameOver=1;
            printf("\nGame Over.....");
        }
        
    }
    
    if (x==fx && y==fy)
       {
           label3:
           fx=rand()%20;
           if(fx==0)
           goto label3;
   
           label4:
           fy=rand()%20;
           if(fy==0)
           goto label4;
           score+=1;
           fat++;
        }
    
}


void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'i':
            {  
                flag=1;
                break;
            }
        case 'k':
            {  
                flag=2;
                break;
            }
        case 'j':
            {  
                flag=3;
                break;
            }

        case 'l':
            {  
                flag=4;
                break;
            }
        case 'p':
            {
                gameOver=1;
                break;
            }
            
        }
    }
}

void setup()
{  
    
    x=height/2;
    y=width/2;

    label1:
    fx=rand()%20;
    if(fx==0)
    goto label1;

    label2:
    fy=rand()%20;
    if(fy==0)
    goto label2;
    score=0;
}


void draw()
{   
    int i,j,k;
    printf("");
    for ( i = 0; i <=height; i++)
    {
        for ( j = 0; j <=width; j++)
        {
            if(i==0 || i==height || j==0 || j==width)
           { 
               printf("*");
           }
            else
            {   
                if (i==x && j==y)
                {
                    printf("^");
                }
                else if (i==fx && j==fy)
                {
                    printf("F");
                }
                else
                {
                    int ch=0;
                    for ( k = 0; k < fat; k++)
                    {
                        if (i==tx[k] && j==ty[k])
                        {
                            printf("o");
                            ch=1;
                        }
                        
                    }
                    if(ch==0)
                    printf(" ");
                }
                
            }
        }
        printf("\n");
    }
    printf("Score = %d",score);
    printf("\nClick on Terminal window to start the Game.\n");
    printf("Instructions.\n");
    printf("1.Press 'i' to move in Upward direcction \n");
    printf("2.Press 'j' to move in left direcction.\n");
    printf("3.Press 'k' to move in downward direcction.\n");
    printf("4.Press 'l' to move in right direcction\n");
    printf("Eat as much as you Can....\n");
   
}

int main()
{   int m,n;
    setup();
    while (gameOver!=1)
    {
        input();
        draw();
        logic();

        for (m = 0; m < 10000; m++)
        {
            for (n = 0; n < 10000; n++)
            {
                
            }
            
        }
    }
    return 0;
}