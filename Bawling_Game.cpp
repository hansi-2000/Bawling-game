#include <iostream>    // required files
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <dos.h>

using namespace std;

bool gameOver;
bool gamePlay;
char choice;
  

// Variable for cordinates
const int width = 20;
const int height = 20;

// Variable for ball positions
int x, y;
char position,input;
int force;
int chances = 1;

int obj_1x, obj_2x, obj_3x, obj_4x, obj_5x, obj_6x, obj_7x, obj_8x, obj_9x, obj_10x;
int obj_1y, obj_2y, obj_3y, obj_4y, obj_5y, obj_6y, obj_7y, obj_8y, obj_9y, obj_10y;

bool ball_print;
bool obj_1print, obj_2print, obj_3print, obj_4print, obj_5print, obj_6print, obj_7print, obj_8print, obj_9print, obj_10print;

enum e_direction {STOP = 0, UP};
e_direction dir;

// initialization of functions
void InstructionScreen();
void WelcomeScreen();
void Setup();
void Draw();
void InfoScreen();
void Input();
void Logic();

int main()
{
	WelcomeScreen();
	
	while (gamePlay)
    {
    	Setup();
    	Draw();
    	InfoScreen();


    	while(!gameOver)
    	{
    		Draw();
            Input();
            Logic(); 
            Sleep(10);
    	        
    	}

    
	    cout<<"\nDo you want to play again? (Y/N) :  ";
	    cin>>input;
	    			if(input=='Y'||input=='y')
	    			{
	    				gameOver = false;
	    				system("CLS");
	    				return main();
					}
					else
					{
						cout<<"\n\t\t\tSee you next time ....";
						return 0;
					}
		}

    
}

void WelcomeScreen()
{
	
	system("color 80");
	cout<<"\n\n\t*****************--------- BOWLING SIMULATOR 1.0 ---------*****************"<<endl;
	
	cout<<"\n\n\t\t\t<<<<< MAIN MENU >>>>>>"<<endl;
	
	cout<<"\n\n\t1. New Game (N)"<<endl;
	cout<<"\t2. Instructions (I)"<<endl;
	cout<<"\t3. Exit Game (E)"<<endl;
	
	cout<<"\n\nEnter the your selection : ";
	cin>>choice;
	
	switch (choice)
	{
		case 'n':
		case 'N': gamePlay = true;break;
		
		case 'i':
		case 'I': InstructionScreen(); ;break;
		
		default:  
		{
			cout<<"\n\n\t\t\t!!!You have entered a invalid input... Please try again!!!";
			WelcomeScreen();
			break;
		}
	}
}

void InstructionScreen() // this function contains the instructions for the user
{
	char choiceInstruction;
	
	system("cls");
	cout<<"\n\t\tWelcome to the Instruction Screen of BOWLING SIMULATOR 1.0"<<endl;
	cout<<"\n\n\t1. In this game you have to hit the pins with a ball. "<<endl;
	cout<<"\t2. There are 10 pins in this game and they are shown in 'X' symbol and ball is 'O' symbol"<<endl;
	cout<<"\t3. To win the game you have to hit all the pins"<<endl;
	cout<<"\t4. You have 3 chances to release the ball."<<endl;
	cout<<"\t5. You can select the releasing position and the force you want to apply as your wish"<<endl;
	cout<<"\t6. After selecting the releasing position and the force you have to press the space bar tp release the ball"<<endl;
	
	cout<<"\n\nTo enter to the main screen, press 'M' or to exit the game press 'E' : ";
	cin>>choiceInstruction;
	
	switch (choiceInstruction)
	{
		case 'M': 
		case 'm': WelcomeScreen(); break;
		
		case 'E':
		case 'e': break;
		
		default : cout<<"Incorrect input Please try again !!!"<<endl;break;
	}
}

void Setup() // this function creates the gaming environment
{
    gameOver = false;
    dir = STOP;

    x = 9;
    y = 18;

    obj_1x=3;
    obj_2x=7; 
    obj_3x=11, obj_4x=15, obj_5x=5, obj_6x=9, obj_7x=13, obj_8x=7, obj_9x=11, obj_10x=9;

    obj_1y=1;
    obj_2y=1;
    obj_3y=1, obj_4y=1, obj_5y=3, obj_6y=3, obj_7y=3, obj_8y=5, obj_9y=5, obj_10y=7;

    ball_print = true;

    obj_1print=true, obj_2print=true, obj_3print=true, obj_4print=true, obj_5print=true, obj_6print=true, obj_7print=true, obj_8print=true, obj_9print=true, obj_10print=true;

}

void Draw()   //this function used to draw the elements on the gaming environment
{
	system("color 80");

    system("cls");

    for(int i=0; i<=width; i++)
    {
        if(i==0)
        {
            cout<<"\t\t#";

        }
        else
        {
            cout<<"#";

        }
    }
    cout<<endl;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            
            if(j==0)
            {
                cout<<"\t\t";
            }
            

            // Printing ball
            
            if(ball_print)
            {
                switch (position)
                {
                    case 'm': if (i==y && j==x)
                    {
                        cout<<"O";
                    } ; break ;
                    
                    case 'l': if (i==y && j==x-5)
                    {
                        cout<<"O";
                    } ; break ;
                                
                    case 'r': if (i==y && j==x+5)
                    {
                        cout<<"O";
                    } ; break ;			
                }
            }

            if(obj_1print)
            {
                if((i==obj_1y && j==obj_1x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_2print)
            {
                if((i==obj_2y && j==obj_2x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_3print)
            {
                if((i==obj_3y && j==obj_3x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_4print)
            {
                if((i==obj_4y && j==obj_4x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_5print)
            {
                if((i==obj_5y && j==obj_5x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_6print)
            {
                if((i==obj_6y && j==obj_6x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_7print)
            {
                if((i==obj_7y && j==obj_7x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_8print)
            {
                if((i==obj_8y && j==obj_8x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_9print)
            {
                if((i==obj_9y && j==obj_9x))
                {
                   cout<<"X"; 
                }
            }

            if(obj_10print)
            {
                if((i==obj_10y && j==obj_10x))
                {
                   cout<<"X"; 
                }
            }

            
            if(false )
            {
                cout<<"X";
            }
            
            else
            {
                cout<<" ";
            }

        }
        cout<<endl;
    }

    for(int i=0; i<=width; i++)
    {
        if(i==0)
        {
            cout<<"\t\t#";

        }
        else
        {
            cout<<"#";

        }
    }
    cout<<endl;
    cout<<"\nPress the SPACE BAR to release the ball"<<endl;
      
}

void InfoScreen()   // this functions takes the user inputs while playing the game
{
	system("color 80");

	cout<<"\n\nWhat is the position you want to release the ball (Left, middle, right) ? ";
    cout<<"\n\n____Press____ \n L   -    for left \n M   -    for middle \n R   -    for right";
    cout<<"\n\nEnter your Selection: ";        
	cin>>position;
	
	switch(position)
	{
		case 'l':
		case 'L': break;
		
		case 'm':
		case 'M': break;
		
		case 'r':
		case 'R': break;
		
		default :
			{
				cout<<"\n\t\t\t!!!!You have input a wrong input for position please try again!!!";
				InfoScreen();
			}
	}
	
    cout<<"\nEnter a force value between 0N to 60N: ";
    cin >>force;


    while(force<=0 || force>60)
    {
        cout<<"\nForce value have to be between 0N and 60N"<<endl;
        cout<<"Re Enter the force value: ";
        cin>>force;
    }
    
}

void Input()  // this function controls the user ball movement
{
	system("color 80");
    if (_kbhit())
    {
        switch (_getch())
        {

            case ' ':
            {
                dir = UP;
                break;
            }


            case 'x':
            {
                gameOver = true;
                break;
            }
        }
    }
}

void Logic()  // this function controls the logical parts like movement of ball
{
    switch (dir)
    {

        case UP:
        {
            y--;
            break;
        }
        
        case STOP:
        	{
        		break;
			}

        default:
            break;
    }


    if(force > 30 && force <= 45)
    {
        switch(position)
        {
            case 'l':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;
                    obj_9print = false;

                }

                if(y==2)
                {
                    obj_5print = false;
                    obj_6print = false;

                }

                if(y==0)
                {
                    obj_1print = false;
                    obj_2print = false;
                }
                break;
            }

            case 'm':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;
                    obj_9print = false;

                }

                if(y==2)
                {
                    obj_5print = false;
                    obj_6print = false;
                    obj_7print = false;
                    
                }
                break;

            }

            case 'r':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;
                    obj_9print = false;

                }

                if(y==2)
                {
                    obj_6print = false;
                    obj_7print = false;

                }

                if(y==0)
                {
                    obj_3print = false;
                    obj_4print = false;
                    
                }
                break;
            }
        }
        
        
        
    }

    if(force > 45 && force <= 60)
    {
        switch(position)
        {
            case 'l':
            case 'L':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;
                    obj_9print = false;

                }

                if(y==2)
                {
                    obj_5print = false;
                    obj_6print = false;
                    obj_7print = false;

                }

                if(y==0)
                {                    
                    obj_1print = false;
                    obj_2print = false;
                    obj_3print = false;
                    
                }
                break;
            }

            case 'm':
            case 'M':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;
                    obj_9print = false;

                }

                if(y==2)
                {
                    obj_5print = false;
                    obj_6print = false;
                    obj_7print = false;

                }

                if(y==0)
                {                    
                    obj_1print = false;
                    obj_2print = false;
                    obj_3print = false;
                    obj_4print = false;
                    
                }

                
                break;

            }
            case 'r':
            case 'R':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;
                    obj_9print = false;

                }

                if(y==2)
                {
                    obj_5print = false;
                    obj_6print = false;
                    obj_7print = false;

                }

                if(y==0)
                {                    
                    obj_2print = false;
                    obj_3print = false;
                    obj_4print = false;
                    
                }
                break;
            }
        }
        
        
    }

    if(force > 15 && force <= 30)
    {
        switch(position)
        {
            case 'l':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;

                }

                if(y==2)
                {
                    obj_5print = false;
                    obj_6print = false;
                    
                }
            }

            case 'm':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_8print = false;
                    obj_9print = false;
                }

                if(y==2)
                {
                    obj_6print = false;
                    
                }
            }

            case 'r':
            {
                if(y==6)
                {
                    obj_10print = false;
                }

                if(y==4)
                {
                    obj_7print = false;
                    obj_9print = false;
                }

                if(y==2)
                {
                    obj_6print = false;
                    
                }
            }
        }
        
        
    }
    
    if(y<0 || y>18 )
    {
    	if(force >0 && force <=15)
    	{
    		cout<<"\n\t\t\t!!!!NOT ENOUGH FORCE TO HIT THE PINS!!!";
		}
    	
		if(obj_1print == false && obj_2print == false && obj_3print == false && obj_4print == false && obj_5print == false && obj_6print == false && obj_7print == false && obj_8print == false && obj_9print == false && obj_10print == false)
    	{
    		cout<<"\n\t\tCongratulations You have won the game!!!!\n";
    		gameOver = true;
    		
		}
		else 
		{
			dir = STOP;
    		x=9; y=18;
    		if(chances==3)
    		{
    			
    			cout<<"\n\t\tYour 3 chances are over... Better luck next time!!!\n\n ";
    			gameOver = true;
    			
			}
			else 
			{
				cout<<"\n\n\t\t\t\tYou have "<<3-chances<<" chances left ! \n"<<endl;
				InfoScreen();
			}
		
    		chances++;
		}
    	
		
	}
    
}

