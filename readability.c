#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int countletters(string s);
int countwords(string s);
int countsentences(string s);

int main(void)
{
    string text=get_string("Text: ");
    int letters = countletters(text);
    int words = countwords(text);
    int sentences = countsentences(text);
    double l = 100.0*letters/words;
    double s = 100.0*sentences/words;

    double grade = 0.0588 * l - 0.296 * s - 15.8;

    if(grade<1)
    {
        printf("Before Grade 1\n");
    }
    else if(grade>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(grade));
    }
}

int countletters(string s)
{
    int c=0;
    for(int i =0, n=strlen(s); i<n;i++)
    {
        if(isalpha(s[i]))
        {
            c++;
        }
    }
    return c;
}

int countwords(string s)
{
    int c=0;
    for(int i =0, n=strlen(s); i<n;i++)
    {
        if(s[i]==' ')
        {
            c++;
        }
    }
    return (c+1);
}

int countsentences(string s)
{
    int c=0;
    for(int i =0, n=strlen(s); i<n;i++)
    {
        if(s[i]=='.' || s[i]=='!' || s[i]=='?')
        {
            c++;
        }
    }
    return c;
}


