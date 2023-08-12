#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start=0,end=0;
    // TODO: Prompt for start size
    int ss;   //a variable for start_size
    do
    {
        ss = get_int("Start Size: ");
    }
    while (ss < 9);
    // TODO: Prompt for end size
    int es;    //a variable for end_size
    do
    {
        es = get_int("End Size: ");
    }
    while (es < ss);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (ss < es)
    {
        ss = ss + (ss / 3)-(ss / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %d\n",years);
}
