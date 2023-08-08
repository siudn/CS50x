#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

double count_letters(string text);
double count_words(string text);
double count_sentences(string text);

int main(void)
{
    string text = get_string("Enter the text: ");

    double L = count_letters(text)/count_words(text) * 100;
    double S = count_sentences(text)/count_words(text) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;
    int gradeLevel = round(index);

    if (index >= 16) {
        printf("Grade 16+\n");
    }
    else if (index < 1) {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %i\n",gradeLevel);
    }
}

double count_letters(string text) {
    double letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++) {
        if (islower(text[i]) || isupper(text[i])) {
            letters++;
        }
    }

    return letters;
}

double count_words(string text) {
    double words = 0;

    for (int i = 0, len = strlen(text); i < len; i++) {
        if (text[i] == ' ') {
            words++;
        }
    }
    words += 1;

    return words;
}

double count_sentences(string text) {
    double sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    return sentences;
}

