#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int main(void)
{
// get text for analysis
string text = get_string("Text: ");
int index = count_letters(text);

if (index < 1)
{
  printf("Before Grade 1\n");
}
else if(index >= 16)
{
  printf("Grade 16+\n");
}
else {
  printf("Grade %i\n", index);
}
}

int count_letters(string text)
{
  int letters = 0;
  int words = 1;
  int sentences = 0;
  for (int i = 0, n = strlen(text) ; i < n; i++)
  {
        if  (isalpha(text[i]))
        {
        letters++;
        }
        else if (isspace(text[i]))
        {
        words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
        sentences++;
        }
  }

     printf("%i\n", letters );
         printf("%i\n", words );
          printf("%i\n", sentences );

 float L = letters/(float)words * 100;
 float S = sentences/(float)words * 100;
float score = 0.0588 * L - 0.296 * S - 15.8;
         return round(score);
}