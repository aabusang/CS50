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
    int wide = width - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            int leftRed = image[i][j].rgbtRed;
            int leftGreen = image[i][j].rgbtGreen;
            int leftBlue = image[i][j].rgbtBlue;

            int rightRed = image[i][wide - j].rgbtRed;
            int rightGreen = image[i][wide - j].rgbtGreen;
            int rightBlue = image[i][wide - j].rgbtBlue;

            image[i][wide - j].rgbtRed = leftRed;
            image[i][wide - j].rgbtGreen = leftGreen;
            image[i][wide - j].rgbtBlue = leftBlue;

            image[i][j].rgbtRed = rightRed;
            image[i][j].rgbtGreen = rightGreen;
            image[i][j].rgbtBlue = rightBlue;
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

            if (i == 0)
            {
                if (j == 0) //top left corner
                {
                    newRed = image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                    image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                    newGreen = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                    image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                    newBlue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                    image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;

                    number = 4;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
                else if (j == width - 1) //top right corner
                {
                    newRed = image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                    image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed;

                    newGreen = image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                    image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen;

                    newBlue = image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                    image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue;

                    number = 4;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
                else //then j must be between 0 and width - 1
                {
                    newRed = image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed +
                             image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed;
                    newGreen = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen +
                             image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen;
                    newBlue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                             image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue;
                    number = 6;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
            }
            if (i == height - 1)
            {
                if (j == 0) //bottom left corner
                {
                    newRed = image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                    image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed;

                    newGreen = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                    image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen;

                    newBlue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                    image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue;
                    number = 4;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
                else if (j == width - 1) //bottom right corner
                {
                    newRed = image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                    image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed;

                    newGreen = image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                    image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen;

                    newBlue = image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                    image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue;
                    number = 4;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
                else //Upper Edges.... then j must be between 0 and width - 1 exclusively
                {
                    newRed = image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed +
                             image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed;
                    newGreen = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen +
                             image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen;
                    newBlue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                             image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue;
                    number = 6;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
            }
            if (i > 0 && i < height - 1) //edges or middle pixel
            {
                if (j == 0) //left edges
                {
                    newRed = image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                          image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

                    newGreen = image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                            image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

                    newBlue = image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                           image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;

                    number = 6;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
                else if (j == width - 1) //right edges
                {
                    newRed = image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed +
                          image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed;

                    newGreen = image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                            image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen;

                    newBlue = image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                           image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue;

                    number = 6;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
                else    //middle pixels
                {
                    for (int x = -1; x <= 1; x++)
                    {
                        for (int y = -1; y <= 1; y++)
                        {
                            newRed += image[i + x][j + y].rgbtRed;
                            newGreen += image[i + x][j + y].rgbtGreen;
                            newBlue += image[i + x][j + y].rgbtBlue;
                        }
                    }
                    number = 9;
                    newRed = round(newRed/(float)number);
                    newGreen = round(newGreen/(float)number);
                    newBlue = round(newBlue/(float)number);
                }
            }

            temp[i][j].rgbtRed = newRed;
            temp[i][j].rgbtGreen = newGreen;
            temp[i][j].rgbtBlue = newBlue;
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
