#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t byte;
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        return 1;
    }
    FILE *ip = fopen(argv[1],"r");
    if(ip==NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    FILE *op= NULL;
    byte buffer[512];
    int jpeg=0;
    char fn[8]={0};
    while (fread(buffer, 1, sizeof(byte)*512, ip) == sizeof(byte)*512)
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xE0)
        {
            if(!(jpeg==0))
            {
                fclose(op);
            }
            sprintf(fn, "%03d.jpg", jpeg++);
            op=fopen(fn,"w");
        }
        if(op!=NULL)
        {
            fwrite(buffer,1, sizeof(byte)*512, op);
        }
    }
    fclose(op);
    fclose(ip);
    return 0;
}
