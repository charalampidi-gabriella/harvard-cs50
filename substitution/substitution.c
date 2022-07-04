#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int key_length = strlen(argv[1]);
        if (key_length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        for (int i = 0; i < key_length; i++)
        {
            char *key = argv[1];
            unsigned char c = key[i];

            if (argv[1][i] < 65 || argv[1][i] > 122)
            {
                printf("The key must contain only letters.\n");
                return 1;
            }
            else if (strchr(key + i + 1, c))
            {
                printf("The key must not contain duplicate letters.\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");

    // length of plaintext
    int length = strlen(plaintext);

    // array of characters of the final text
    char final[length];

    for (int i = 0; i < length; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            final[i] = toupper(argv[1][toupper(plaintext[i]) - 65]); // if word BAT and key ZXY...  B = 66 but in key it is argv[1][1]. B-65 = 1
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            final[i] = tolower(argv[1][toupper(plaintext[i]) - 65]); // if word BAT and key ZXY...  B = 66 but in key it is argv[1][1]. B-65 = 1
        }
        else
        {
            final[i] = plaintext[i];
        }
    }

    printf("ciphertext: ");

    for (int j = 0; j < length; j++)
    {
        printf("%c", final[j]);
    }
    printf("\n");
    return 0;
}
