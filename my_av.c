#include "header.h"

char *predictUrl(char *link, features urlFeatures, information info) {
	bool is_known_safe = safe_domain(urlFeatures, info);
	if (is_known_safe)
		return "Safe URL";
	
	return isUrlSafe(urlFeatures, info);
}

void checkUrls(information info) {
	FILE *database, *output, *input;
	output = fopen("urls-predictions.out", "w");
	input = fopen("./data/urls/urls.in", "r");
	_file urls = read_file(input);
	//fclose(input);

	for (int i = 0; i < urls->size; i++){
		features urlFeatures = extractUrlFeatures(urls->data[i]);
		char *result = predictUrl(urls->data[i], urlFeatures, info);
		fprintf(output, "%s\n", result);

		cleanFeatures(urlFeatures);
	}
}

int main(int argv, char **argc) {
	information info = readInformation();
	if (argv > 1) {
		features urlFeatures = extractUrlFeatures(argc[1]);
		//printf("Domain: %s, extension: %s, file: %s, frag_hash: %s, last_char: %c, last_part: %s\n", urlFeatures->domain, urlFeatures->extension, urlFeatures->file, urlFeatures->frag_hash, urlFeatures->last_char, urlFeatures->last_part);
		char *result = predictUrl(argc[1], urlFeatures, info);
		printf("%s\n", result);	
	} else
		checkUrls(info);

	cleanInformation(info);
	return 0;
}