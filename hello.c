#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //asking name from user
    string name = get_string("What's your name? ");
    //saying hello to <user name>
    printf("hello, %s\n", name);
}
