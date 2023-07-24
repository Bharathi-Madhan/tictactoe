#include <stdio.h>
#include <conio.h>
void board(char GB[3][3])
{
    //Displayes the board
    printf("\n\n");
    printf("\t\t\t   %c   |   %c   |   %c   \n",GB[0][0],GB[0][1],GB[0][2]);
    printf("\t\t\t   __      __      __   \n");
    printf("\t\t\t   %c   |   %c   |   %c   \n",GB[1][0],GB[1][1],GB[1][2]);
    printf("\t\t\t   __      __      __   \n");
    printf("\t\t\t   %c   |   %c   |   %c   \n",GB[2][0],GB[2][1],GB[2][2]);
    printf("\n\n");
    return;
}
int selectPlayer()
{
    /*Allows the user to select the player
    Player 1 plays with X
    Player 2 plays with O*/
    int choice;
    printf("Player 1:\tX\n");
    printf("Player 2:\tO\n");
    printf("You wish to be Player 1/Player 2? (Enter 1/2)\t");
    scanf("%d",&choice);
    if(choice==1)
        printf("\tPlayer 1 starts the game!\n");
    else
        printf("\tPlayer 2 starts the game!\n");
    printf("GOOD LUCK!!\n");
    return choice;
}
char checkwin(char GameBoard[3][3])
{
    /*To check the win status of player
    Returns W if any player wins
	Returns Z if the game is in progress
    Returns D if the game is draw*/
    if(GameBoard[0][0] =='X' && GameBoard[0][1] =='X' && GameBoard[0][2] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[1][0] =='X' && GameBoard[1][1] =='X' && GameBoard[1][2] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[2][0] =='X' && GameBoard[2][1] =='X' && GameBoard[2][2] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][0] =='X' && GameBoard[1][0] =='X' && GameBoard[2][0] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][1] =='X' && GameBoard[1][1] =='X' && GameBoard[2][1] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][2] =='X' && GameBoard[1][2] =='X' && GameBoard[2][2] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][0] =='X' && GameBoard[1][1] =='X' && GameBoard[2][2] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][2] =='X' && GameBoard[1][1] =='X' && GameBoard[2][0] =='X')
    {
        printf("\n\nCongratulations!!!!\nPlayer 1 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][0] =='O' && GameBoard[0][1] =='O' && GameBoard[0][2] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
    else if(GameBoard[1][0] =='O' && GameBoard[1][1] =='O' && GameBoard[1][2] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
    else if(GameBoard[2][0] =='O' && GameBoard[2][1] =='O' && GameBoard[2][2] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][0] =='O' && GameBoard[1][0] =='O' && GameBoard[2][0] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][1] =='O' && GameBoard[1][1] =='O' && GameBoard[2][1] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][2] =='O' && GameBoard[1][2] =='O' && GameBoard[2][2] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][0] =='O' && GameBoard[1][1] =='O' && GameBoard[2][2] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
    else if(GameBoard[0][2] =='O' && GameBoard[1][1] =='O' && GameBoard[2][0] =='O')
    {
        printf("\n\nCongratulations!!!!\nPlayer 2 Wins!!");
        return 'W';
    }
	else if(GameBoard[0][0] == '-' || GameBoard[0][1] == '-' || GameBoard[0][2] == '-' ||
			GameBoard[1][0] == '-' || GameBoard[1][1] == '-' || GameBoard[1][2] == '-' ||
			GameBoard[2][0] == '-' || GameBoard[2][1] == '-' || GameBoard[2][2] == '-')
				return 'Z';
    else
        return 'D';
}
int main()
{
    char GameBoard[3][3]={'-','-','-','-','-','-','-','-','-'};
    char win = 'Z';
    int ch;
    int row,col;
    printf("\t\tTic Tac Toe!\n\n");
    ch=selectPlayer();
    /*After the user selects the player, instructions are displayed for playing
    Player has to choose the row and column to start the game*/
    do
    {
		board(GameBoard);
        ch= (ch%2) ? 1 : 2;
        printf("-----------------------------------------------------\n\n");
        if(ch==1)
        {
            printf("Choose the row and coloumn number to play:\n");
            printf("Row 1/2/3 ?\tColumn 1/2/3 ?\t");
            scanf("%d %d",&row,&col);
			/*If the player enters correct row and column the value changes
			If the player enters row and column which is already filled 
			Or row and column entered is out of bounds (more than 3),
			error is generated.
			And the player is asked to enter the value again*/
            if(row==1&&col==1)
			{
				if(GameBoard[0][0]=='-')
					GameBoard[0][0]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==1&&col==2)
			{
				if(GameBoard[0][1]=='-')
					GameBoard[0][1]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==1&&col==3)
			{
				if(GameBoard[0][2]=='-')
					GameBoard[0][2]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==2&&col==1)
            {
				if(GameBoard[1][0]=='-')
					GameBoard[1][0]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
			else if(row==2&&col==2)
			{
				if(GameBoard[1][1]=='-')
					GameBoard[1][1]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==2&&col==3)
			{
				if(GameBoard[1][2]=='-')
					GameBoard[1][2]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==3&&col==1)
			{
				if(GameBoard[2][0]=='-')
					GameBoard[2][0]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==3&&col==2)
			{
				if(GameBoard[2][1]=='-')
					GameBoard[2][1]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==3&&col==3)
			{
				if(GameBoard[2][2]=='-')
					GameBoard[2][2]='X';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
			else
			{
				printf("Invalid move!!");
				ch--;
				getch();
			}
        }
        else
        {
            printf("Choose the row and coloumn number to play:\n");
			printf("Row 1/2/3 ?\tColumn 1/2/3 ?\t");
            scanf("%d %d",&row,&col);
			/*If the player enters correct row and column the value changes
			If the player enters row and column which is already filled 
			Or row and column entered is out of bounds (more than 3),
			error is generated
			And the player is asked to enter the value again*/
            if(row==1&&col==1)
			{
				if(GameBoard[0][0]=='-')
					GameBoard[0][0]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==1&&col==2)
			{
				if(GameBoard[0][1]=='-')
					GameBoard[0][1]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==1&&col==3)
			{
				if(GameBoard[0][2]=='-')
					GameBoard[0][2]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==2&&col==1)
			{
				if(GameBoard[1][0]=='-')
					GameBoard[1][0]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==2&&col==2)
			{
				if(GameBoard[1][1]=='-')
					GameBoard[1][1]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==2&&col==3)
			{
				if(GameBoard[1][2]=='-')
					GameBoard[1][2]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==3&&col==1)
			{
				if(GameBoard[2][0]=='-')
					GameBoard[2][0]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==3&&col==2)
			{
				if(GameBoard[2][1]=='-')
					GameBoard[2][1]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
            else if(row==3&&col==3)
			{
				if(GameBoard[2][2]=='-')
					GameBoard[2][2]='O';
				else
				{
					printf("Invalid move!");
					ch--;
					getch();
				}
			}
			else
			{
				printf("Invalid move!!");
				ch--;
				getch();
			}
        }
        win=checkwin(GameBoard);
        ch++;
    }
    while(win=='Z');
	board(GameBoard);
    //Game is played till it is won or a draw is made
    if(win=='W')
        printf("\nGAME OVER!!");
    else	//if(win=='D')
        printf("\nGAME DRAW!!");
	getch();
    return 0;
}