#include "header.h"

_file read_file(FILE *File) {
	_file file = calloc(1, sizeof(_File));
	file->data = calloc(1, sizeof(char *));
	if (!file->data) {
		perror("Unable to allocate memory");
		exit(1);
	}
	char *aux = NULL;
	size_t len = 0;

	while (getline(&aux, &len, File) != -1) {
		int len = strlen(aux);
        if (aux[0] == '\n')
            break;
        if (aux[len - 1] == '\n')
		    aux[strlen(aux) - 1] = '\0';

		char **test = realloc(file->data, (file->size + 1) * sizeof(char *));
		if (test) {
			file->data = test;
		} else {
			free(aux);
			for (int i = 0; i < file->size; i++)
				free(file->data[i]);
			free(file->data);
			perror("Unable to reallocate memory!");
			exit(1);
		}
		file->data[file->size] = calloc(strlen(aux) + 1, sizeof(char));
		memcpy(file->data[file->size++], aux, strlen(aux));
		file->data[file->size - 1][strlen(aux)] = '\0';
		if (feof(File))
			break;
	}

	if (aux)
		free(aux);

	fclose(File);
	return file;
}

void cleanFile(_file file) {
	for (int i = 0; i < file->size; i++)
		free(file->data[i]);
	free(file->data);
	free(file);
}