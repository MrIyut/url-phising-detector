#include "header.h"

char *get_last_part(char *str, char *del) {
	char *last_part = strtok(str, del);
	char *part = strtok(NULL, del);
	while (part) {
		last_part = part;
		part = strtok(NULL, del);
	}

	last_part[strlen(last_part)] = '\0';
	return last_part;
}

char *get_last_occurence(char *string, char del, int return_null)
{
	char *occurence = NULL;
	for (int i = strlen(string) - 1; i >= 0; i--)
		if (string[i] == del) {
			occurence = string + i + 1;
			return occurence;
		}
	if (return_null)
		return NULL;
	
	return string;
}

char *get_first_occurence(char *string, char del)
{
	char *occurence = NULL;
	for (int i = 0; i < strlen(string) - 1; i++)
		if (string[i] == del) {
			occurence = string + i;
			return occurence;
		}

	return occurence;
}

features extractUrlFeatures(char *link) {
	features urlFeatures = calloc(1, sizeof(Features));

	urlFeatures->link = calloc(strlen(link) + 1, sizeof(char));
	strcpy(urlFeatures->link, link);

	char *test_link = calloc(strlen(link) + 1, sizeof(char));
	strcpy(test_link, link);
	
	char *last_part = get_last_part(link, "/");
	urlFeatures->last_part = calloc(strlen(last_part) + 1, sizeof(char));
	strcpy(urlFeatures->last_part, last_part);

	char *extension = get_last_occurence(last_part, '.', 0);
	urlFeatures->extension = calloc(strlen(extension) + 1, sizeof(char));
	strcpy(urlFeatures->extension, extension);
	char *frag_hash = get_last_occurence(last_part, '#', 1);
	if (!frag_hash)
		frag_hash = last_part + strlen(last_part);
	urlFeatures->frag_hash = calloc(strlen(frag_hash) + 1, sizeof(char));
	strcpy(urlFeatures->frag_hash, frag_hash);
	char *file = get_first_occurence(last_part, '?');
	if (!file)
		file = last_part + strlen(last_part);
	urlFeatures->file = calloc(strlen(file) + 1, sizeof(char));
	strcpy(urlFeatures->file, file);

	char last_char = test_link[strlen(test_link) - 1];
	urlFeatures->last_char = last_char;

	char *domain = strtok(test_link, "/");
	urlFeatures->domain = calloc(strlen(domain) + 1, sizeof(char));
	strcpy(urlFeatures->domain, domain);

	free(test_link);
	return urlFeatures;
}

void cleanFeatures(features urlFeatures) {
	free(urlFeatures->last_part);
	free(urlFeatures->frag_hash);
	free(urlFeatures->extension);
	free(urlFeatures->file);
	free(urlFeatures->domain);
	free(urlFeatures->link);
	free(urlFeatures);
}
