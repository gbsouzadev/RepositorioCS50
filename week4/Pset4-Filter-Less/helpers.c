#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            int avg = round((red + green + blue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop trough all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate new values for r g b as per the informed formula
            float fred = (image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189);
            int red = round(fred);
            if (red > 255)
            {
                red = 255;
            }

            float fgreen = (image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168);
            int green = round(fgreen);
            if (green > 255)
            {
                green = 255;
            }

            float fblue = (image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.131);
            int blue = round(fblue);
            if (blue > 255)
            {
                blue = 255;
            }

            //assign new r g b values to the image
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //If width is an odd number
    if (width % 2 == 1)
    {
        //check for the half of width
        int half = (width + 1) / 2;

        //loop trough each pixel
        for (int i = 0; i < height; i++)
        {
            //swap width's left(wl) and right(wr) side one by one
            for (int j = 0, wl = 0, wr = width - 1; j < half; j++, wl++, wr--)
            {
                RGBTRIPLE swap = image[i][wl];
                image[i][wl] = image[i][wr];
                image[i][wr] = swap;
            }
        }
    }
    //If width is an even number
    else
    {
        int half = width / 2;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0, wl = 0, wr = width - 1; j < half; j++, wl++, wr--)
            {
                RGBTRIPLE swap = image[i][wl];
                image[i][wl] = image[i][wr];
                image[i][wr] = swap;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //loop for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            int divisor = 0;

            //loop through all surrounding pixels gathering rgb values from copy
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int xi = x + i;
                    int yj = y + j;

                    if (xi < 0 || xi > height - 1 || yj < 0 || yj > width - 1)
                    {
                        continue;
                    }
                    red += copy[xi][yj].rgbtRed;
                    green += copy[xi][yj].rgbtGreen;
                    blue += copy[xi][yj].rgbtBlue;
                    divisor++;
                }
            }
            //calculate and assign avarege rgb to orginal bmp
            image[i][j].rgbtRed = round(red / divisor);
            image[i][j].rgbtGreen = round(green / divisor);
            image[i][j].rgbtBlue = round(blue / divisor);
        }
    }
    return;
}