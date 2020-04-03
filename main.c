#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
int width=20,height=20;
int x,y,fruitx,fruity,score,gameover,flag;
int tailx[100],taily[100];
int counttail;
void setup() // second method
{
    gameover=0;
    x=height/2;
    y=width/2;
    label1:
    fruitx=rand()%15;
    if(fruitx==0)
        goto label1;

    label2:
    fruity=rand()%15;
    if(fruity==0)
        goto label2;
}
void draw()     //first method
{
    int i,j,k;
    system("cls");
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
            {
                if(i==height-1 || i==0 || j==width-1 || j==0)
                {
                     printf("*");
                }
                else
                {
                      if(i==y && j==x)
                        printf("O");
                      else if(j==fruitx && i==fruity)
                        printf("F");
                      else
                      {
                          int ch=0;         //second last
                          for(k=0;k<counttail;k++)
                          {
                              if(i==tailx[k] && j==taily[k])
                              {
                                  printf("o");
                                  ch=1;
                              }
                          }
                          if (ch==0)
                           printf(" ");
                      }
                }

            }
            printf("\n");
    }
     printf("Current Score :%d",score);
}

void input() // third method
{
    if(kbhit())
    {
        switch(getch())
         {
         case 'a':
            flag=1;
            break;
         case 's':
            flag=2;
            break;
         case 'w':
            flag=3;
            break;
         case 'z':
            flag=4;
            break;
         case 'x':
            gameover=1;
            break;
         }
    }

}
void makelogic() //fourth method
{
    int i;            //third last
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=y;
    taily[0]=x;
    for(i=1;i<counttail;i++) //shifting logic
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }

    switch(flag)
    {
        case 1:
            x--;
            break;

        case 2:
            x++;
            break;

        case 3:
            y--;
            break;

        case 4:
            y++;
            break;
        default:
            break;
    }
 if(x<0 || x>width || y<0 || y>width)
 {
   gameover=1;
 }
 for(i=0;i<counttail;i++)
 {
     if(x==taily[0] && y==tailx[0])
     {
         gameover=1;
     }
 }
  if(x==fruitx && y==fruity)
 {
    label1:
    fruitx=rand()%14;
    if(fruitx==0)
        goto label1;
    label2:
    fruity=rand()%13;
    if(fruity==0)
        goto label2;
   score+=10;
   counttail++;
 }

}
int main()
{
    int m,n;
    char c;

  setup();
  while(!gameover)
  {
  draw();
  input();
  makelogic();
  for(m=0;m<=18000;m++)
   {
      for(n=0;n<=3000;n++)
      {
      }
   }
  }

   return 0;
}
