#include "monty.h"

#define MAX_LINE_LENGTH 1024

/**
 * main - main function for monty interpreter
 * @argc: number of arguments
 * @argv: m file location
 * Return: 0 if success
 */


montyf_t montyf = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
    FILE *file;
    char content[MAX_LINE_LENGTH];
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    montyf.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(content, sizeof(content), file) != NULL)
    {
        counter++;
        cmd(content, &stack, counter, file);
    }

    free_stack(stack);
    fclose(file);

    return (0);
}
