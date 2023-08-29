#include "helpers.h"
#include <math.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg = 0.00;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.00);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float originalRed = 0.00;
    float originalGreen = 0.00;
    float originalBlue = 0.00;
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tempRed[width - 1];
    int tempGreen[width - 1];
    int tempBlue[width - 1];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= (width - 1) / 2; j++)
        {
            tempRed[j] = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;

            tempGreen[j] = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;

            tempBlue[j] = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;
        }
        for (int j = (width - 1); j > (width - 1) / 2; j--)
        {
            image[i][j].rgbtRed = tempRed[width - (j + 1)];
            image[i][j].rgbtGreen = tempGreen[width - (j + 1)];
            image[i][j].rgbtBlue = tempBlue[width - (j + 1)];
        }
    }
    return;
}

bool inBounds(int i, int j, int height, int width)
{
    if (i < 0 || i > height - 1 || j < 0 || j > width - 1)
    {
        return false;
    }
    return true;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE origCopy[height][width];
    float surroundRed = 0.00;
    float surroundGreen = 0.00;
    float surroundBlue = 0.00;
    float counter = 0.00;
    // make copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            origCopy[i][j].rgbtRed = image[i][j].rgbtRed;
            origCopy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            origCopy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    // change pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (inBounds(i + x, j + y, height, width))
                    {
                        surroundRed += origCopy[i + x][j + y].rgbtRed;
                        surroundGreen += origCopy[i + x][j + y].rgbtGreen;
                        surroundBlue += origCopy[i + x][j + y].rgbtBlue;
                        counter++;
                    }
                }
            }
            image[i][j].rgbtRed = round(surroundRed/counter);
            image[i][j].rgbtGreen = round(surroundGreen/counter);
            image[i][j].rgbtBlue = round(surroundBlue/counter);
            // reset variables
            surroundRed = 0.00;
            surroundGreen = 0.00;
            surroundBlue = 0.00;
            counter = 0.00;
        }
    }
    return;
}
