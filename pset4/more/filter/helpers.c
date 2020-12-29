#include "helpers.h"
#include "math.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
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
            //put leftmost pixels in temporary storage
            int tempRed = image[i][j].rgbtRed;
            int tempGreen = image[i][j].rgbtGreen;
            int tempBlue = image[i][j].rgbtBlue;
            //set current pixel colors to it's equivalent rightward pixel
            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;
            //set rightward pixels colors to the temp colors
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE temp[height][width];
    int redGxSum, greenGxSum, blueGxSum, redGySum, greenGySum, blueGySum;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            redGxSum = greenGxSum = blueGxSum = redGySum = greenGySum = blueGySum = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    //in index is out of range/bound, skip that loop else do the math
                    if ((i + x < 0 || i + x > height - 1) || (j + y < 0 || j + y > width - 1))
                    {
                        continue;
                    }
                    else
                    {
                        redGxSum += (image[i + x][j + y].rgbtRed * Gx[x + 1][y + 1]);
                        greenGxSum += (image[i + x][j + y].rgbtGreen * Gx[x + 1][y + 1]);
                        blueGxSum += (image[i + x][j + y].rgbtBlue * Gx[x + 1][y + 1]);
                        //Gy
                        redGySum += (image[i + x][j + y].rgbtRed * Gy[x + 1][y + 1]);
                        greenGySum += (image[i + x][j + y].rgbtGreen * Gy[x + 1][y + 1]);
                        blueGySum += (image[i + x][j + y].rgbtBlue * Gy[x + 1][y + 1]);
                    }

                    //Gx
                }
            }
            int newRed = round(sqrt(pow(redGxSum , 2) + pow(redGySum, 2)));
            int newGreen = round(sqrt(pow(greenGxSum, 2) + pow(greenGySum, 2)));
            int newBlue = round(sqrt(pow(blueGxSum, 2) + pow(blueGySum, 2)));

            if (newRed > 255)
                newRed = 255;
            if (newGreen > 255)
                newGreen = 255;
            if (newBlue > 255)
                newBlue = 255;


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
