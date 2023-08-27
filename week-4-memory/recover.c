#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    BYTE buffer[512];
    char filename[8];
    int counter = 0;
    FILE *img = NULL;
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("File could not be opened.\n");
        return 2;
    }

    while (fread(&buffer, 512, 1, f))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // if start of new JPEG
        {
            if (counter != 0) // if not first jpeg
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }
        if (counter != 0) // once jpeg has been found
        {
            fwrite(&buffer, 512, 1, img);
        }
    }

    fclose(img);
    fclose(f);

    return 0;
}