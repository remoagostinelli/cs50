#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char letter, next_letter;
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for a string
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while ((strlen(text) < 1) & (text[0] != ' '));

    // Parse the string

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // Calculate Coleman-Liau index
    float L = ((float)letter_count / (float)word_count) * 100;
    float S = ((float)sentence_count / (float)word_count) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print text's grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int count = 0; count < strlen(text); count++)
    {
        letter = tolower(text[count]);
        if (isalpha(letter))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;
    for (int count = 0; count < strlen(text); count++)
    {
        letter = tolower(text[count]);
        next_letter = tolower(text[count + 1]);
        if (letter == ' ' | (int)next_letter == 0)
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int count = 0; count < strlen(text); count++)
    {
        letter = tolower(text[count]);
        if (letter == '.' | letter == '!' | letter == '?')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}