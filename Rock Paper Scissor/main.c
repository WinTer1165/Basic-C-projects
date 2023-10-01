#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void winCheck(int f_robot, int f_human)
{

    if (f_robot > f_human)
    {
        printf("\nTotal Points:\nRobot: %d\nYou: %d\n---------------------You lost in the game!---------------------", f_robot, f_human);
    }
    else if (f_human > f_robot)
    {
        printf("\nTotal Points:\nYou: %d\nRobot: %d\n---------------------Congratulations! You won!---------------------", f_human, f_robot);
    }
    else if (f_human == f_robot)
    {
        printf("\nTotal Points:\nYou: %d\nRobot: %d\n--------------------Match Draw!!!-------------------", f_human, f_robot);
    }
}
int main()
{
    int robot_pick, num, i, score_human, score_robot, repeat;
    char human_command;
    printf("\n\n-------------------Welcome to the Rock-Paper-Scissor Game!-------------------\n\n");
start:
    score_human = 0;
    score_robot = 0;
    printf("Enter how many times you want to play:");
    scanf("%d", &num);
    fflush(stdin);
    printf("\n-------------------Lets start!-------------------\n");
    printf("\nNote: You will get penalty if you input invalid characters.\n\n");

    for (i = 0; i < num; i++)
    {
        fflush(stdin);
        printf("\nChoose your option: \nr. Rock\np. Paper\ns. Scissor\n\nYour choice is: ");
        scanf("%c", &human_command);
        srand(time(NULL));
        robot_pick = ((rand() % 3) + 1);
        if (robot_pick == 1)
        {
            printf("Robot picked Rock.\n");
        }
        else if (robot_pick == 2)
        {
            printf("Robot picked Paper.\n");
        }
        else if (robot_pick == 3)
        {
            printf("Robot picked Scissor.\n");
        }

        if ((human_command == 'r' && robot_pick == 1) || (human_command == 'p' && robot_pick == 2) || (human_command == 's' && robot_pick == 3))
        {
            printf("\nDraw!!!");
        }
        else if (human_command == 'r' && robot_pick == 2)
        {
            printf("\nRobot Got 1 point.");
            score_robot = score_robot + 1;
        }
        else if (human_command == 'r' && robot_pick == 3)
        {
            printf("\nYou Got 1 point.");
            score_human = score_human + 1;
        }
        else if (human_command == 'p' && robot_pick == 1)
        {
            printf("\nYou Got 1 point.");
            score_human = score_human + 1;
        }
        else if (human_command == 'p' && robot_pick == 3)
        {
            printf("\nRobot Got 1 point.");
            score_robot = score_robot + 1;
        }
        else if (human_command == 's' && robot_pick == 1)
        {
            printf("\nRobot Got 1 point.");
            score_robot = score_robot + 1;
        }
        else if (human_command == 's' && robot_pick == 2)
        {
            printf("\nYou Got 1 point.");
            score_human = score_human + 1;
        }
        else
        {
            printf("\nInvalid Input!. As a penalty, it's gonna be draw.");
        }

        printf("\n--------------");
        printf("\n--------------");
        Sleep(1);
    }
    winCheck(score_robot, score_human);
    printf("\n\n--------------------------------\n\n");
    Sleep(1);
    printf("Want to Play Again?\n1. Yes\nEnter any other key to exit\n");
    scanf("%d", &repeat);
    if (repeat == 1)
    {
        goto start;
    }
    else
    {
        printf("Thank you for playing!!!\n");
        return 0;
    }
}