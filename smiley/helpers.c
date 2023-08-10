#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            if(image[r][c].rgbtBlue==0 && image[r][c].rgbtGreen==0 && image[r][c].rgbtRed==0)
            {
                image[r][c].rgbtBlue= 102;
                image[r][c].rgbtGreen= 33;
                image[r][c].rgbtRed= 96;
            }
        }
    }
}
