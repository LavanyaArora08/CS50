#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start,end;
    // TODO: Prompt for start size
    do
    {
        start = get_int("Enter start size ");
    }while(start<9);
    printf("Start number is %d \n",start);

    // TODO: Prompt for end size
    do
    {
        end = get_int("enter end size ");
    }while(end<start);
    printf("end number is %d \n",start);

    // TODO: Calculate number of years until we reach threshold
    int years=0, population = start;
    while(population!=end)
    {
        population = population + (population/3) - (population/4);
        years+=1;
    }

    // TODO: Print number of years
    printf("The number of years is: %d\n",years);
}
