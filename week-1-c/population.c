#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("Give a starting population size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    int o;
    do
    {
        o = get_int("Give an ending population size: ");
    }
    while (o < n);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (n < o)
    {
        n = n + n/3 - n/4;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}