#include "header.h"

void op_nop(/*stack_t **stack UNUSED,*/char *dolor)
{
	printf("ESTOY EN LA FUNCION NOP HACIENDO NADAAAA %s\n", dolor);
}

/*comment f5 uncomment f6*/
void match(void)
{
	int line = 0, len = 0, i = 0;
	char *argument = NULL, *command = NULL, *dolor = "dolor";

	operations bag[] = { /*bag.oper, bag.function*/
		{"nop", op_nop},
		{NULL, NULL}
	};

	/* stack_t *stack[] = { */
	/* 	{5, NULL, NULL} */
	/* }; */

	for (line = 0; lines[line]; line++)
	{
		len = strlen(lines[line]);
		if (lines[line][len - 1] == '\n')
			lines[line][len - 1] = '\0';
		if (lines[line][0])
		{
			command = strtok(lines[line], " ");
			argument = strtok(NULL, " ");
			printf("%d: %s %s\n", line, command, argument);

			for (i = 0; bag[i].oper; i++)
			{
				if (strcmp(command, bag[i].oper) == 0) /* if equal */
				{
					printf("yeah, aqui vamos....!\n");
					bag[i].function(dolor);
				}
				else
					printf("noupe\n");
			}
		}
		free(lines[line]);
	}
}

int main(int argc, char *argv[])
{
	char *buffer;
	ssize_t getted = 0;
	size_t buffer_size = BUFFERSIZE;
	FILE *file;
	int line;

	if (argc < 2)
		exit(1);
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s", argv[1]);
		fclose(file);
		return (EXIT_FAILURE);
	}
	for (line = 0; getted != -1; line++)
	{
		buffer = malloc(sizeof(char) * BUFFERSIZE);
		getted = getline(&buffer, &buffer_size, file);
		if (getted > 0)
			lines[line] = strdup(buffer);
		free(buffer);
	}
	fclose(file);
	match();
	return (EXIT_SUCCESS);
}
