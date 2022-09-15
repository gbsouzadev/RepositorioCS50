#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check for valid comand line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //Open and check file informed in comand line, declaring a FILE pointer towards it
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("%s is invalid", argv[1]);
        return 2;
    }

    //Set an array to receive 512byte blocks
    BYTE buffer[512];

    //Set a counter for created jpgs
    int count = 0;

    //Set an char array for jpg file name as ###.jpg
    char fname[8];

    //Declare a FILE pointer for output file
    FILE *output = NULL;

    //Loop reading trough input file
    while (fread(buffer, 1, 512, input) == 512)
    {

        //Check if block starts a new jpg as per jpgs header pattern
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            //If block is the first jpg
            if (count == 0)
            {
                //Set new jpg file name
                sprintf(fname, "%03i.jpg", count);

                //Create output file for writing
                output = fopen(fname, "w");

                //Write 512byte block into the output file
                fwrite(buffer, 1, 512, output);
            }

            //If not first jpeg.
            if (count != 0)
            {
                //Set new jpg file name
                sprintf(fname, "%03i.jpg", count);

                //Close previous output file and open a new one
                fclose(output);
                output = fopen(fname, "w");

                //Write 512byte block into the output file
                fwrite(buffer, 1, 512, output);
            }
            
            //Iterate image counter
            count++;
        }
        else
        {
            if (output != NULL)
            {
                //Keep writing 512byte block into the output file
                fwrite(buffer, 1, 512, output);
            }
        }
    }
    fclose(input);
    fclose(output);
}