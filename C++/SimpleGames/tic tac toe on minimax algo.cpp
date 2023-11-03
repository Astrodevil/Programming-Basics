#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#define COMPUTER 1 
#define HUMAN 2 

#define SIDE 3 // Length of the board 

// Computer will move with 'O' 
// and human with 'X' 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X' 

void Board();
void PlayerX();
void PlayerO();
void Player_win();
void check();
int win=0,wrong_X=0,wrong_O=0,chk=0;
void T(int ,int);
void C(int ,int);
void A(); void I();
void O(); void E();
void CIR(int);
void SCR(int ,int);
void start();
void playTicTacToe(int);



char name_X[30];
char name_O[30];
int pos_for_X[3][3];
int pos_for_O[3][3];
int pos_marked[3][3];

void main(){
	int i,ch,j;
	char ans;
	start();
	do
	{
		clrscr();
		printf("\n\t\t\t\tTIC TAC TOE  BY AMULYA");
		printf("\n\t\t\t\t");
		delay(2000);
		for(i=1;i<=23;i++)
		{
			delay(100);
			printf("*");
		}
		printf("\n1.Start The Game against human");
		printf("\n2.Quit The Game");
		printf("\n3.Play against PC");

		printf("\nEnter your choice(1-3) : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				chk=0;
				win=0;
				for(i=1;i<=3;i++)
				{
					for(j=1;j<=3;j++)
					{
						pos_for_X[i][j]=0;
						pos_for_O[i][j]=0;
						pos_marked[i][j]=0;
					}
				}
				printf("\n\n");
				clrscr();
				printf("\nEnter the name of the player playing for \'X\': ");
				fflush(stdin);
				gets(name_X);
				printf("\nEnter the name of the player playing for \'O\': ");
				fflush(stdin);
				gets(name_O);
				Board();
				for(;;)
				{
					if(win==1)
						break;
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS!!");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_X);
					PlayerX();
					do
					{
						if(wrong_X!=1)
							break;
						wrong_X=0;
						printf("\nTURN FOR %s:",name_X);
						PlayerX();
					}while(wrong_X==1);
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_O);
					PlayerO();
					do
					{
						if(wrong_O!=1)
							break;
						wrong_O=0;
						printf("\nTURN FOR %s:",name_O);
						PlayerO();
					}while(wrong_O==1);

					}
				Board();
				if(win!=1)
				{
					printf("\n\t\t\tMATCH DRAWS!!");
					printf("\nPress any key.......");
				}
				getch();
				break;
			case 2:
				printf("\n\n\nThank You For Playing The Game.");
				printf("\n");
				printf("\nCreated By:AMULYA KUMAR MAURYA\n");
				printf("INSTITUTION:CHANDIGARH UNIVERSITY\n");
				printf("Department: Computer Science & Engineering");
				getch();
				exit(1);
				break;
			case 3:
				printf("\n-------------------------------------------------------------------\n\n");
				printf("\t\t\t Tic-Tac-Toe\n"); 
				printf("\n-------------------------------------------------------------------\n\n");
				char cont='y';
			do {
				char choice;
	 			printf("Do you want to start first?(y/n) : ");
	 			scanf(" %c", &choice);

				if(choice=='n')
				playTicTacToe(COMPUTER);
				else if(choice=='y')
				playTicTacToe(HUMAN);
				else
				printf("Invalid choice\n"); 
        
				printf("\nDo you want to quit(y/n) : ");
     	  		scanf(" %c", &cont);
				} while(cont=='n');
				getch();
				exit(1);
				break;
		}
		printf("\nWant To Play(Y/N) ? ");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y' || ans=='Y');
}


void Board()
{
	int i,j;
	clrscr();
	printf("\n\t\t\t\tTIC TAC TOE BOARD");
	printf("\n\t\t\t\t*****************");
	printf("\n\n\n");
	printf("\n\t\t\t    1\t      2\t        3") ;
	for(i=1;i<=3;i++)
	{
		printf("\n \t\t\t _____________________________");
		printf("\n \t\t\tº\t  º\t   º\t     º");
		printf("\n\t\t%d\t",i);
		for(j=1;j<=3;j++)
		{

			if(pos_for_X[i][j]==1)
			{
				printf("    X");
				printf("     ");
			}
			else if(pos_for_O[i][j]==1)
			{
				printf("    O");
				printf("     ");
			}
			else
			{
				printf("          ");
				continue;
			}
		}
		printf("\n\t\t\tº\t  º\t   º\t     º");
	}
	printf("\n\t\t\t------------------------------");
	Player_win();
}


void PlayerX()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	fflush(stdin);
	scanf("%d",&row);
	printf("Enter the column no. : ");
	fflush(stdin);
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key.....");
		wrong_X=1;
		getch();
		Board();
	}
	else
	{
		pos_for_X[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}

void PlayerO()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	scanf("%d",&row);
	printf("Enter the column no. : ");
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key....");
		wrong_O=1;
		getch();
		Board();
	}
	else
	{
		pos_for_O[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}
void Player_win()
{
	int i;
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[i][1]==1 && pos_for_X[i][2]==1 && pos_for_X[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[1][i]==1 && pos_for_X[2][i]==1 && pos_for_X[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	if(pos_for_X[1][1]==1 && pos_for_X[2][2]==1 && pos_for_X[3][3]==1)
	{
		win=1;
		printf("\n\nRESULTL: %s wins!!",name_X);
		printf("\nPress any key......");
		return;
	}
	else if(pos_for_X[1][3]==1 && pos_for_X[2][2]==1 &&
pos_for_X[3][1]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_X);
		printf("\nPress any key.....");
		return;
	}

	for(i=1;i<=3;i++)
	{
		if(pos_for_O[i][1]==1 && pos_for_O[i][2]==1 && pos_for_O[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
			printf("\nPress any key.....");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_O[1][i]==1 && pos_for_O[2][i]==1 && pos_for_O[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
			printf("\nPress any key.....");
			return;
		}
	}
	if(pos_for_O[1][1]==1 && pos_for_O[2][2]==1 && pos_for_O[3][3]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
		printf("\nPress any key.....");
		return;
	}
	else if(pos_for_O[1][3]==1 && pos_for_O[2][2]==1 &&
pos_for_O[3][1]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
		printf("\nPress any key.....");
		return;
	}
}
void check()
{
	int i,j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(pos_marked[i][j]==1)
				chk++;
			else
				continue;
		}
	}
}

void start(){
	int gdrive=DETECT,gmode;
	initgraph(&gdrive,&gmode,"c:\\turboc3\\bgi");
	
	delay(2000);
	T(50,50); delay(100);
	I(); delay(100);
	C(160,50);delay(100);
	T(300,50); delay(100);
	A();delay(100);
	C(455,50);delay(100);
	T(160,200);delay(100);
	O();delay(100);
	C(250,200);delay(100);
	E();delay(200);
	
	for(int q=0;q<5;q++){
		SCR(80,235);
		SCR(470,235);
		CIR(235);
	}
	closegraph();
}

void CIR(int CI2){
	for(int i=0;i<40;i++){
		setcolor(i);
		circle(80+i,CI2-i,2);
		circle(470+i,CI2-i,2);
		circle(80-i,CI2+i,2);
		circle(470-i,CI2+i,2);
		circle(80-i,CI2-i,2);
		circle(470-i,CI2-i,2);
		circle(80+i,CI2+i,2);
		circle(470+i,CI2+i,2);
		circle(80,CI2-i,2);
		circle(470,CI2-i,2);
		circle(80,CI2+i,2);
		circle(470,CI2+i,2);
		circle(80-i,CI2,2);
		circle(470-i,CI2,2);
		circle(80+i,CI2,2);
		circle(470+i,CI2,2);
		delay(20);
	}
}

void SCR(int S1,int S2){
	setcolor(0);
	for(int i=0;i<88;i++){
		line((S1-45),(S2-45)+i,(S1+45),(S2-45)+i);
	}
}

void I(){
	for(int i=0;i<20;i++){
		setcolor(2);
		circle(130+i,50,3);
		delay(10); 
	}
	for(i=0;i<70;i++){
		circle(140,50+i,3);
		delay(10);
	}
	for(i=0;i<20;i++){
		setcolor(2);
		circle(130+i,120,3);
		delay(10); 
	} 
}

void C(int c1,int c2){
	for(int i=0;i<10;i++){
		setcolor(2);
		circle(c1+50,c2+10-i,3);
		delay(10);
	}
	for(i=0;i<50;i++){
		circle(c1+50-i,c2,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(c1,c2+i,3);
		delay(10);
	}
	for(i=0;i<45;i++){
		circle(c1+i,c2+70,3);
		delay(10);
	}
}

void O(){
	for(int i=0;i<70;i++){
		circle(300,270-i,3);
		delay(10);
	}
}

void T(int t1,int t2){
	for(int i=0;i<70;i++){
		setcolor(2);
		circle(t1+i,t2,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		setcolor(2);
		circle(t1+35,t2+i,3);
		delay(10);
	}
}

void A(){
	for(int i=0;i<35;i++){
		circle(410-i,50+(i*2),3);
		delay(10);
	}
	for(i=0;i<35;i++){
		circle(410+i,50+(i*2),3);
		delay(10);
	}
	for(i=0;i<20;i++){
		circle(400+i,80,3);
		delay(10);
	}
}

void E(){
	for(int i=0;i<50;i++){
		circle(365-i,200,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(315,200+i,3);
		delay(10);
	}
	for(i=0;i<50;i++){
		circle(315+i,270,3);
		delay(10);
	}
	for(i=0;i<25;i++){
		circle(315+i,235,3);
		delay(10);
	}
}


//  A function to show the current board status
void showBoard(char board[][SIDE])
{

	printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// A function to show the instructions
void showInstructions()
{
	printf("\nChoose a cell numbered from 1 to 9 as below and play\n\n");

	printf("\t\t\t 1 | 2 | 3 \n");
	printf("\t\t\t-----------\n");
	printf("\t\t\t 4 | 5 | 6 \n");
	printf("\t\t\t-----------\n");
	printf("\t\t\t 7 | 8 | 9 \n\n");
}


// A function to initialise the game
void initialise(char board[][SIDE])
{
	// Initially the board is empty
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
			board[i][j] = ' ';
	}
}

// A function to declare the winner of the game
void declareWinner(int whoseTurn)
{
	if (whoseTurn == COMPUTER)
		printf("COMPUTER has won\n");
	else
		printf("HUMAN has won\n");
}

// A function that returns true if any of the row
// is crossed with the same player's move
int rowCrossed(char board[][SIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] &&
			board[i][0] != ' ')
			return 1;
	}
	return 0;
}

// A function that returns true if any of the column
// is crossed with the same player's move
int columnCrossed(char board[][SIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		if (board[0][i] == board[1][i] &&
			board[1][i] == board[2][i] &&
			board[0][i] != ' ')
			return 1;
	}
	return 0;
}

// A function that returns true if any of the diagonal
// is crossed with the same player's move
int diagonalCrossed(char board[][SIDE])
{
	if (board[0][0] == board[1][1] &&
		board[1][1] == board[2][2] &&
		board[0][0] != ' ')
		return 1;

	if (board[0][2] == board[1][1] &&
		board[1][1] == board[2][0] &&
		board[0][2] != ' ')
		return 1;

	return 0;
}

// A function that returns true if the game is over
// else it returns a false
int gameOver(char board[][SIDE])
{
	return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board) );
}

// Function to calculate best score
int minimax(char board[][SIDE], int depth, int isAI)
{
	int score = 0;
	int bestScore = 0;
	if (gameOver(board) == 1)
	{
		if (isAI == 1)
			return -1;
		if (isAI == 0)
			return +1;
	}
	else
	{
		if(depth < 9)
		{
			if(isAI == 1)
			{
				bestScore = -999;
				for(int i=0; i<SIDE; i++)
				{
					for(int j=0; j<SIDE; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = COMPUTERMOVE;
							score = minimax(board, depth + 1, 0);
							board[i][j] = ' ';
							if(score > bestScore)
							{
								bestScore = score;
							}
						}
					}
				}
				return bestScore;
			}
			else
			{
				bestScore = 999;
				for (int i = 0; i < SIDE; i++)
				{
					for (int j = 0; j < SIDE; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = HUMANMOVE;
							score = minimax(board, depth + 1, 1);
							board[i][j] = ' ';
							if (score < bestScore)
							{
								bestScore = score;
							}
						}
					}
				}
				return bestScore;
			}
		}
		else
		{
			return 0;
		}
	}
}

// Function to calculate best move
int bestMove(char board[][SIDE], int moveIndex)
{
	int x = -1, y = -1;
	int score = 0, bestScore = -999;
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = COMPUTERMOVE;
				score = minimax(board, moveIndex+1, 0);
				board[i][j] = ' ';
				if(score > bestScore)
				{
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}
	return x*3+y;
}

// A function to play Tic-Tac-Toe 
void playTicTacToe(int whoseTurn) 
{ 
	char board[SIDE][SIDE]; 
	int moveIndex = 0, x = 0, y = 0;

	initialise(board);
	showInstructions(); 
	
	// Keep playing till the game is over or it is a draw 
	while (gameOver(board) == 0 && moveIndex != SIDE*SIDE) 
	{ 
		int n;
		if (whoseTurn == COMPUTER) 
		{
			n = bestMove(board, moveIndex);
			x = n / SIDE;
			y = n % SIDE;
			board[x][y] = COMPUTERMOVE; 
			printf("COMPUTER has put a %c in cell %d\n\n", COMPUTERMOVE, n+1);
			showBoard(board);
			moveIndex ++; 
			whoseTurn = HUMAN;
		} 
		
		else if (whoseTurn == HUMAN) 
		{
			printf("You can insert in the following positions : ");
			for(int i=0; i<SIDE; i++)
				for (int j = 0; j < SIDE; j++)
					if (board[i][j] == ' ')
						printf("%d ", (i * 3 + j) + 1);
			printf("\n\nEnter the position = ");
			scanf("%d",&n);
			n--;
			x = n / SIDE;
			y = n % SIDE; 
			if(board[x][y] == ' ' && n<9 && n>=0)
			{
				board[x][y] = HUMANMOVE; 
				printf ("\nHUMAN has put a %c in cell %d\n\n", HUMANMOVE, n+1); 
				showBoard(board); 
				moveIndex ++; 
				whoseTurn = COMPUTER;
			}
			else if(board[x][y] != ' ' && n<9 && n>=0)
			{
				printf("\nPosition is occupied, select any one place from the available places\n\n");
			}
			else if(n<0 || n>8)
			{
				printf("Invalid position\n");
			}
		} 
	} 

	// If the game has drawn 
	if (gameOver(board) == 0 && moveIndex == SIDE * SIDE) 
		printf("It's a draw\n"); 
	else
	{ 
		// Toggling the user to declare the actual winner 
		if (whoseTurn == COMPUTER) 
			whoseTurn = HUMAN; 
		else if (whoseTurn == HUMAN) 
			whoseTurn = COMPUTER; 
		
		declareWinner(whoseTurn); 
	} 
} 
