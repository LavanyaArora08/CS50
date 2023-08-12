#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double avg=0.0;
    for(int i =0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            avg = round((image[i][j].rgbtBlue+image[i][j].rgbtGreen+image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtBlue=avg;
            image[i][j].rgbtGreen=avg;
            image[i][j].rgbtRed=avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    double sepiaRed=0.0, sepiaGreen=0.0, sepiaBlue=0.0;
    for(int i =0; i<height; i++)
    {
        for(int j=0; j<width;j++)
        {
             sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
             sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
             sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
             if(sepiaRed>255)
             {
                sepiaRed=255;
             }
             if(sepiaGreen>255)
             {
                sepiaGreen=255;
             }
             if(sepiaBlue>255)
             {
                sepiaBlue=255;
             }
             image[i][j].rgbtBlue=sepiaBlue;
             image[i][j].rgbtGreen=sepiaGreen;
             image[i][j].rgbtRed=sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0;i< height; i++)
    {
        if (width %2 == 0)
        {
            for (int j= 0;j <width/2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }

        else if(width% 2 != 0)
        {
            for (int j= 0;j < (width-1)/2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            double R=0.0,G=0.0,B=0.0,count=0.0;
            for(int r=-1;r<=1;r++)
            {
                for(int c=-1;c<=1;c++)
                {
                    if(i+r<0 || i+r>height-1)
                        continue;
                    if (j+c<0 || j+c>width-1)
                        continue;
                    B+=image[i + r][j + c].rgbtBlue;
                    G+=image[i + r][j + c].rgbtGreen;
                    R+=image[i + r][j + c].rgbtRed;
                    count++;
                }
            }
            temp[i][j].rgbtBlue=round(B/count);
            temp[i][j].rgbtGreen=round(G/count);
            temp[i][j].rgbtRed=round(R/count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }

    }
    return;
}
