#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9

bool on_line(int sublist[], int size)
{
    bool numbers[9] = {false};
    for(int i = 0; i < size; i++)
    {
        int number = sublist[i];
        if(number != 0 && numbers[number - 1])
        {
            return true;
        }
        else if(number != 0)
        {
            numbers[number - 1] = true; 
        }
    }
    return false; // no double
}

bool on_square(int** sudoku)
{
    for(int i = 0; i < 9; i += 3)
    {
        for(int j = 0; j < 9; j += 3)
        {
            int templist[9] = {0};
            int index = 0;
            for(int k = i; k < i + 3; k++)
            {
                for(int l = j; l < j + 3; l++)
                {
                    templist[index] = sudoku[k][l];
                    index++;
                }
            }
            if (on_line(templist, 9))
            {
                return true; // erreur ( présence de doublon )
            }
        }
    }
    return false; // pas d'erreur
}

int main()
{

    int **sudoku = (int **)malloc(ROWS*sizeof(int *));
    for (int i = 0; i < 9; i++)
    {
        sudoku[i] = (int *)malloc(COLS*sizeof(int));
    }

    FILE *fp;
    fp = fopen("sudoku.txt", "r");

    if(fp == NULL)
    {
        printf("Error while opening file\n");
        exit(1);
    }
    else
    {
        printf("\n");

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                fscanf(fp, "%1d", &sudoku[i][j]);
            }
        }

        fclose(fp);
        printf("*-----------------------*\n");
        for (int i = 0; i < 9; i++) 
        {
            if(i%3==0&&i!=0)
            {
                printf("|-----------------------|\n");
            }
            printf("|");
            for (int j = 0; j < 9; j++)
            {   

                printf(" ");
                if(j%3==0&&j!=0)
                {
                    printf("| ");
                    printf("%d",sudoku[i][j]);
                }
                else
                {
                    printf("%d", sudoku[i][j]);
                }
            }
            printf(" |\n");
        }
        printf("*-----------------------*\n\n");
        
        bool error_1 = false;

        for(int i=0;i<9;i++)
        {
            int sublist[9];
            for(int a=0;a<9;a++)
            {
                sublist[a] = sudoku[i][a];
            }
            int size = sizeof(sublist) / sizeof(int);
            if(on_line(sublist, size) == true)
            {
                error_1 = true;
            }
        }

        bool error_2 = false;
        int templist_2[9];

        for(int t=0;t<9;t++)
        {
            for(int q=0;q<9;q++)
            {
                templist_2[q] = sudoku[q][t];
            }
            if(on_line(templist_2,9)==true)
            {
                error_2 = true;
            }
        }
        if(on_square(sudoku)==true||error_1==true||error_2==true) //error in square or rows or column
        {
            printf("One ore more values are invalid.");
            exit(0);
        }
        else
        {
            printf("Values are ok, the program can proceed.");
        }

        for (int a=0; a<9; free(sudoku[a++])); //free the line "a" from the array
        free(sudoku); //free the array

    }
}
