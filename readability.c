#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    if(strcmp(text, "") == 0)
    {
        printf("No Input\n");
    }
    else
    {
        // printf("Letter count: %i \n", count_letters(text));
        // printf("Word count: %i \n", count_words(text));
        // printf("Sentence count: %i \n", count_sentences(text));

        float L = (count_letters(text) / (float)count_words(text)) * 100;
        float S = (count_sentences(text) / (float)count_words(text)) * 100;

        float index = 0.0588 * L - 0.296 * S - 15.8;

        if (index < 1)
        {
            printf("Before Grade 1 \n");
        }
        else if (index >= 16)
        {
            printf("Grade 16+ \n");
        }
        else
        {
            printf("Grade %.0f \n", round(index));
        }
        //printf("Coleman index level: %.0f \n", round(index));
    }
}

int count_letters(string text)
{
    int Lcount = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if(islower(text[i]) || isupper(text[i]))
        {
            Lcount++;
        }
    }
    return Lcount;
}

int count_words(string text)
{
    int Wcount = 1;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if(isspace(text[i]))
        {
            Wcount++;
        }
    }
    return Wcount;
}

int count_sentences(string text)
{
    int Scount = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if(text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            Scount++;
        }
    }
    return Scount;
}