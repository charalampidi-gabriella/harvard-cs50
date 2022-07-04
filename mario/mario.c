#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (int row = 1; row <= height; row++)
    {
        //spaces for 1st wedge
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        //dashes for 1st wedge
        for (int dash = 0; dash < row; dash++)
        {
            printf("#");
        }

        //gaps
        printf("  ");

        //dashes for 2nd wedge
        for (int dash = 0; dash < row; dash++)
        {
            printf("#");
        }
        printf("\n");
    }
}