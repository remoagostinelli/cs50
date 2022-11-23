#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Set pyramids height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 | height > 8);

    // Build two pyramids
    int num_spaces = height - 1;
    int num_blocks = 1;
    for (int row = 1; row <= height; row++)
    {
        printf("%*s", num_spaces, "");
        printf("%.*s", num_blocks, "########");
        printf("  ");
        printf("%.*s\n", num_blocks, "########");
        num_spaces--;
        num_blocks++;
    }
}