#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    int j = 1;
    do
    {
        h = get_int("Give a height from 1-8: ");
    }
    while (h < 1 || h > 8);

    // Right side pyramid
    for (int i = 0; i < h; i++) // Two nested loops running "parallel"
    {
        for (int space = h - i - 1; space > 0; space--) // Spaces + hashes = height and the number row depicts the number of hashes. Must subtract 1 because first row is i = 0
        {
            printf(" ");
        }
        for (j = 0; j - 1 < i; j++) // Must subtract 1 to ensure that hash is printed on first line
        {
            printf("#");
        }
        printf("\n");
    }
}