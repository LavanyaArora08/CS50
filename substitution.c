#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkfornum(string k);
int checkforrepeat(string k);
void tocipher(string s, string k);

int main(int argc, string argv[])
{
    if(argc==1)
    {
        printf("%s, KEY\n",argv[0]);
        return 1;
    }
    else if(argc>2)
    {
        printf("Enter a single key without spaces");
        return 1;
    }
    else if(argc==2)
    {
        if(strlen(argv[1])<26 || strlen(argv[1])>26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        else if(checkfornum(argv[1])==1)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        else if(checkforrepeat(argv[1])==1)
        {
            printf("Key must not contain repeated characters.");
            return 1;
        }
        else
        {
            string str=get_string("plaintext: ");
            tocipher(str, argv[1]);
        }
    }
}


int checkfornum(string k)
{
    for(int i =0 ; i<26; i++)
    {
        if(!isalpha(k[i]))
        {
            return 1;
        }
    }
    return 0;
}

int checkforrepeat(string k)
{
    int flag=0;
    for(int i=0; i<26;i++)
    {
        k[i]=toupper(k[i]);
        int c=0;
        for(int j=0;j<26;j++)
        {
            if(i!=j && k[i]==k[j])
            {
                c++;
            }
        }
        if(c>0)
        {
            flag=1;
            break;
        }
    }
    return flag;
}

void tocipher(string s, string k)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (isalpha(c))
        {
            if (isupper(c))
            {
                s[i] = k[c - 'A'];
            }
            else
            {
                s[i] = tolower(k[c - 'a']);
            }
        }
    }
    printf("ciphertext: %s\n", s);
}

