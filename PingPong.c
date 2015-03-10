#include "iostream"
using namespace std;
#include"stdlib.h"
#include"conio.h"
#include<windows.h>
#include<string.h>
#include<string>

void gotoxy(int, int);
int main()
{
	system("COLOR F1");
	char AI;
	int level=90;
	for(int q=1;q>0;q++)
	{
		int d;
		system("cls");
		gotoxy(20,18);
		cout<<"PRESS";
		gotoxy(33,16);
		cout<<"Welcome to BAAP PING-PONG";
		gotoxy(30,20);
		cout<<"1- To Start the game";
		gotoxy(30,22);
		cout<<"2- For help.";
		gotoxy(30,27);
		cout<<"-------------";
		gotoxy(39,35);
		cout<<"----CNH productions.";
		cin>> d;
		if(d==1)
			q=-1;
		if(d==2)
		{
			system("cls");
			gotoxy(20,18);
			cout<<"It's simple ping pong game. Player1 is on the bottom";
			gotoxy(20,20);
			cout<<"of the maze (Use arrow keys to move Player1's slide).";
			gotoxy(20,22);
			cout<<"Player2 is on the top(use 'a' and 'd' to move Player2's";
			gotoxy(20,24);
			cout<<"slide. Do not let the ball touch the ground.";
			gotoxy(20,28);
			cout<<"                                            Enjoy! :P";
			getch();
		}
	}
	system("cls");
	string Player1, Player2 ;
	cout<<"Enter the name of the first Player"<<endl;
	cin>>Player1;
	cout<<"Enter the name of the second Player"<<endl;
	cin>> Player2;
	cout << "Do you want to play against me (y/n)? (challenge!!!)";
	cin >> AI;
	system("cls");
	int blue;
	int navix=2 ;
	char maze[50][50];
	char slide[5];
	char move;
	char ball;
	int smove= 13;
	int smove2=13;
	int bxmove=47;
	int bymove= 30;
	for(int i= 0 ;i<50 ; i++)
	{
		for(int z = 0; z< 50; z++)
		{
		if(z==0 || z == 49 )
			maze[i][z]= 219;
		else
		{	
			maze[i][z] = ' ';
		}				
		if(i== bymove && z== bxmove)
			maze[i][z] =1;
		}
	}

	for(int i=0;i<50;i++)
	{
		for(int z=0;z<50;z++)
		{
			if(i==0 || i== 49)
				maze[i][z] =219;
			if( smove == z && i == 1)
			{	
				for(int p=0;p<5;p++)
				{
					maze[i][z+p] = '=';		
				}
			}
			if( smove2 == z && i == 48)
			{
				for(int p=0;p<5;p++)
					maze[i][z+p] = '=';
			}
				cout<<maze[i][z];
		}
		if(i==0)
				cout<< "Player1 = "<<Player1;
		if(i==1)
			cout<<"Player2 = "<<Player2;
			cout<< endl;

	}
	for(int t=0;t> -1;t++)
	{
		Sleep(level);
		gotoxy( bxmove, bymove );
		cout<<" ";
		if(AI == 'y' && bymove>30)
		{}
		else
			if(AI == 'y' && bxmove < smove)
				{
					for(int p=0;p<5;p++)
						maze[1][smove+p] = ' ';

					gotoxy(smove,1);
					cout<<"     ";
					smove-=1;
					if(smove < 1)
						smove = 1;

					for(int p=0;p<5;p++)
						maze[1][smove+p] = 'x';

					gotoxy(smove,1);
					cout<<"=====";
				}
			if(AI == 'y' && bxmove > smove+4 )
			{
					for(int p=0;p<5;p++)
						maze[1][smove+p] = ' ';

					gotoxy(smove,1);
					cout<<"     ";	
					smove+=1;
					if(smove > 46)
						smove = 46;

					for(int p=0;p<5;p++)
						maze[1][smove+p] = 'x';

					gotoxy(smove,1);
					cout<< "=====";					
				}
		if(kbhit())
		{
			//system("COLOR 09");
			if( (move = getch() ) == 224)
				move = getch();
			if(move== 'a')
			{
				for(int p=0;p<5;p++)
					maze[1][smove+p] = ' ';

				gotoxy(smove,1);
				cout<<"     ";
				//maze[1][smove-1]='x';
				smove-=1;
				if(smove < 1)
					smove = 1;

				for(int p=0;p<5;p++)
					maze[1][smove+p] = 'x';

				gotoxy(smove,1);
				cout<<"=====";
			}
			if(move== 'd')
			{
				for(int p=0;p<5;p++)
					maze[1][smove+p] = ' ';

				gotoxy(smove,1);
				cout<<"     ";	
				//maze[1][smove-5]='x';
				smove+=1;
				if(smove > 46)
					smove = 46;

				for(int p=0;p<5;p++)
					maze[1][smove+p] = 'x';

				gotoxy(smove,1);
				cout<< "=====";					
			}
			if(move == 77)
			{
				for(int p=0;p<5;p++)
					maze[48][smove2+p] = ' ';

				gotoxy(smove2,48);
				cout<<"     ";
				//maze[48][smove2-5] ='x';
				smove2+=1;
				if(smove2 > 47)
					smove2 = 47;

				for(int p=0;p<5;p++)
					maze[48][smove2+p] = 'x';

				gotoxy(smove2,48);
				cout<<"=====";
			}
			if(move == 75)
			{
				for(int p=0;p<5;p++)
					maze[48][smove2+p] = ' ';

				gotoxy(smove2,48);
				cout<<"     ";
				//maze[48][smove-1]='x';
				smove2-=1;
				if(smove2 < 1)
					smove2 = 1;
				for(int p=0;p<5;p++)
					maze[48][smove2+p] = 'x';

				gotoxy(smove2,48);
				cout<<"=====";
			}
		}
				blue=-2;
		if((bymove ==2 && navix ==0)&& maze[1][bxmove]=='x')// ball touching slide 
		{
			navix= 3;
			blue=2;
			bymove+=1;
			bxmove-=1;
		}
		if((bymove==2 && navix ==2) && maze[1][bxmove]=='x')
		{
			navix= 1;
			blue=2;
			bymove+=1;
			bxmove+=1;
		}
		if((bymove==47 && navix ==1)&& maze[48][bxmove]=='x')
		{
			navix= 2;
			blue=2;
			bymove-=1;
			bxmove+=1;
		}
		if((bymove==47 && navix ==3)&& maze[48][bxmove]=='x')
		{
			navix= 0;
			blue=2;
			bymove-=1;
			bxmove-=1;
		}
		if(bxmove< 2 && navix== 3 )// ball touching side walls
		{
			blue=2;
			bymove+=1;
			bxmove+=1;
			navix= 1;
		}
		if(bxmove> 46 && navix== 2 )
		{		
			blue=2;
			bymove-=1;
			bxmove-=1;
			navix= 0;
		}
		if(bxmove> 46 && navix== 1 )
		{
			blue=2;
			bymove+=1;
			bxmove-=1;
			navix= 3;
		}
		if(bxmove< 2 && navix== 0 )
		{
			blue=2;
			bymove-=1;
			bxmove+=1;
			navix= 2;
		}
		if(blue==2)// scaance!
		{
		}
		else//without ball touching anything.
		{
			if(navix== 1 ) 
			{	
				bymove++;
				bxmove++;
			}
			if(navix== 0 )
			{	
				bymove--;
				bxmove--;
			}
			if(navix== 2 )
			{	
				bymove--;
				bxmove++;
			}
			if(navix== 3 )
			{	
				bymove++;
				bxmove--;
			}
		}
		//system("COLOR 0C");
		gotoxy( bxmove, bymove );
		cout<<(char)1;

		gotoxy(50,3);
		if(bymove<=0 )
		{
			t=-100;
			cout<< Player2<<"Wins!";
		}	
		if(bymove>=49)
		{
			t=-100;
			cout<<Player1<<" Wins!";
		}
			gotoxy(50,2);
		
		if(level== 90)
		{	if(700-t<100)
			cout<<"time till next level= "<< 700-t;
			else
			cout<<"time till next level="<< 700-t;
		}
		else
			cout<<"max level reached!";
		if(t== 700)
		{
			gotoxy(50,2);
			cout<<"Congrats! Starting level 2";
			level= 50;
			getche();
			gotoxy(50,2);
			cout<<"                                               ";
		}
}	
  	gotoxy(50,2);
	cout<<"                                               ";
	cout<< "Game Over!";
	int game;
	cin>> game;

}

void gotoxy(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
