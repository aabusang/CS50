#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //average the rgb of a given pixel and
    //make r = g = b = average for that pixel's r g and b
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int average = round((red + green + blue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int newRed = round((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue));
            int newGreen = round((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue));
            int newBlue = round((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue));

            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtBlue = newBlue;
            if (newRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            if (newGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (newBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            int tempRed = image[i][j].rgbtRed;
            int tempGreen = image[i][j].rgbtGreen;
            int tempBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;

            image[i][width - (j + 1)].rgbtRed = tempRed;
            image[i][width - (j + 1)].rgbtGreen = tempGreen;
            image[i][width - (j + 1)].rgbtBlue = tempBlue;

        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int newRed = 0, newGreen = 0, newBlue = 0;
            float number = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if ((i + x < 0 || i + x > height - 1) || (j + y < 0 || j + y > width - 1))
                    {
                        continue;
                    }
                    else
                    {
                        newRed += image[i + x][j + y].rgbtRed;
                        newGreen += image[i + x][j + y].rgbtGreen;
                        newBlue += image[i + x][j + y].rgbtBlue;
                        number++;
                    }
                }
            }
            temp[i][j].rgbtRed = round(newRed/number);
            temp[i][j].rgbtGreen = round(newGreen/number);
            temp[i][j].rgbtBlue = round(newBlue/number);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
