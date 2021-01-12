#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //quit if more than one com line args
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    //open memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open memory card\n");
        return 1;
    }

    BYTE buffer[512];
    char filename[8];
    int jpegCount = 0;
    FILE *img;
    while(fread(&buffer, 1, 512, file) == 512)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (jpegCount  == 0)//first jpeg
            {
                sprintf(filename, "%03i.jpg", jpegCount);
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
            }
            else
            {
                //close previous jpeg and start a new one here
                fclose(img);
                sprintf(filename, "%03i.jpg", jpegCount);
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
            }
            jpegCount++;
        }
        else
        {
            if (jpegCount > 0)
            {
                fwrite(&buffer, 1, 512, img);
            }
        }
    }
}
