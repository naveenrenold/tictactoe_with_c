/**Tic tac too program in c**/
#include<stdio.h>
#include<string.h>
char a[3][4];
void draw_tictac(void);
void start_game(void);
int check_tictac(char);
int check_basic_or_win(char);
int check_double(char);
void start_singleplayer(void);
void ai_move(int);
int main()
{
int i,j,gamemode;
printf("**********WELCOME TO NAVEEN's TIC TAC TOE***********\n\n\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
a[i][j]=' ';
}                                   //
}
draw_tictac();
while(1)
{
printf("1.Single player\n2.Two Player\nChoose any game mode:");
scanf("%d",&gamemode);
if(gamemode==1)
{
start_singleplayer();
break;
}
if(gamemode==2)
{
start_game();
break;
}
else
{
printf("Invalid option\n");
}
}
return 0;
}
void draw_tictac()
{
printf("\t\t\t  0  1  2\n");
printf("\t\t\t0 %c| %c| %c\n",a[0][0],a[0][1],a[0][2]);
printf("\t\t\t __|__|__\n");
printf("\t\t\t1 %c| %c| %c\n",a[1][0],a[1][1],a[1][2]);
printf("\t\t\t __|__|__\n");
printf("\t\t\t2 %c| %c| %c\n",a[2][0],a[2][1],a[2][2]);
printf("\t\t\t   |  |  \n\n\n");
}
void start_game()//player vs player
{
char i,j,k=0,win=0;
int m,n;
while(win==0&&k<9)
{
while(1)
{
printf("Player 1's turn:\nEnter the box no:");
scanf("%d%d",&m,&n);
//printf("m=%d|n=%d\n",m,n);
if(a[m][n]==' ')
{
a[m][n]='x';
k++;
draw_tictac();
win=check_tictac('x');
break;
}
else
printf("Invalid no\n");
}
while(k<9&&win==0)
{
printf("Player 2's turn:\nEnter the box no:");
scanf("%d%d",&m,&n);
if(a[m][n]==' ')
{
a[m][n]='o';
k++;
draw_tictac();
win=check_tictac('o');
break;
}
else
printf("Invalid no\n");
}
}
}
int check_tictac(char marker){
int i,j,m1,m2,m;
for(j=0;j<3;j++)                         //horizontal
{
m1=0;
m2=0;
for(i=0;i<3;i++)
{
if(a[j][i]==marker)
{
m1++;
}
if(a[i][j]==marker)
{
m2++;
}
}
if(m1==3)
{
printf("%c wins\n",marker);
return 1;
}
if(m2==3)
{
printf("%c wins\n",marker);
return 1;
}
}                                        //horizontal
m=0;
for(i=0,j=0;i<3;i++,j++)
{
if(a[i][j]==marker)
m++;
else
break;
}
if(m==3)
{
printf("%c wins\n",marker);
return 1;
}
m=0;
for(i=0,j=2;i<3;i++,j--)
{
if(a[i][j]==marker)
m++;
else
break;
}
if(m==3)
{
printf("%c wins\n",marker);
return 1;
}
return 0;
}
void start_singleplayer(void)                               //SINGLE PLAYA
{
char i,j,k=0,win=0;
int m,n;
draw_tictac();
while(win==0&&k<9)
{
while(1)
{
printf("Player 1's turn:\nEnter the box no:");
scanf("%d%d",&m,&n);
//printf("m=%d|n=%d\n",m,n);
if(a[m][n]==' ')
{
a[m][n]='x';
k++;
draw_tictac();
win=check_tictac('x');
break;
}
else
printf("Invalid no\n");
}
while(k<9&&win==0)
{
printf("Computer's turn:\n");
/**scanf("%d%d",&m,&n);
if(a[m][n]==' ')
{
a[m][n]='o';**/
ai_move(k);                                                              //ai_move
k++;
draw_tictac();
win=check_tictac('o');
break;
}
}
}
void ai_move(int k)                                                  //HArdcore ai fun
{
int i,j,moved=0;
if(k==1)                                                           //1.check center
{
moved=1;
if(a[1][1]==' ')
a[1][1]='o';
else
a[0][0]='o';
return;
}
if(moved==0)
{
moved=check_basic_or_win('o');
}                                                                 //check center
if(moved==0)
{
moved=check_basic_or_win('x');
}
//printf("moved=%d\n",moved);
i=0,j=0;
while(moved==0){
if(a[i][j]==' ')
{
a[i][j]='o';
moved=1;
}
j++;
if(j==3)
{
j=0;
i++;
}
}
if(moved==0)
{
moved=check_double('x');
}
return;
}
int check_basic_or_win(char marker){
int i,j,m1,m2,m,wins=0;
int k1,k2,k3,k4;
for(j=0;j<3;j++)                         //horizontal
{
m1=0;
m2=0;
k1=-1,k2=-1,k3=-1,k4=-1;
for(i=0;i<3;i++)
{
if(a[j][i]==' ')
{
k1=j;
k2=i;
}
if(a[j][i]==marker)
{
m1++;
}
if(a[i][j]==' ')
{
k3=i;
k4=j;
}
if(a[i][j]==marker)
{
m2++;
}
}
if(m1==2&&k1!=-1)
{
a[k1][k2]='o';
wins++;//
}
if(m2==2&&k3!=-1)
{
a[k3][k4]='o';
wins++;//return 1;
}
}                                        //horizontal
m=0;
k1=-1,k2=-1,k3=-1,k4=-1;
for(i=0,j=0;i<3;i++,j++)
{
if(a[i][j]==' ')
{
k1=i;
k2=j;
}
if(a[i][j]==marker)
m++;
}
if(m==2&&k1!=-1)
{
a[k1][k2]='o';
wins++;//return 1;
}
m=0;
for(i=0,j=2;i<3;i++,j--)
{
if(a[i][j]==' ')
{
k3=i;
k4=j;
}
if(a[i][j]==marker)
m++;
}
if(m==2&&k3!=-1)
{
a[k3][k4]='o';
wins++;//return 1;
}
//printf("Value of wins is %d",wins);
return wins;
}
int check_double(char marker)
{
int i,j,wins;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(a[i][j]==' ')
{
a[i][j]='x';
wins=check_basic_or_win(marker);
if(wins>1)
{

}
}
}
}
return 0;
}
