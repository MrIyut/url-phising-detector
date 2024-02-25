#include "header.h"

information readInformation() {
	FILE *safe_domains_file = fopen("./information/data.txt", "r");
	FILE *badExtensions = fopen("./information/badExtensions.in", "r");
	FILE *database = fopen("./data/urls/domains_database", "r");
	FILE *badTlds = fopen("./information/badTlds.in", "r");
	FILE *suspiciousElements = fopen("./information/suspiciousElements.in", "r");

	information info = calloc(1, sizeof(Information));
	char tt[255];
	info->safeDomains = read_file(safe_domains_file);
	info->badExtensions = read_file(badExtensions);
	info->database = read_file(database);
	info->badTlds = read_file(badTlds);
	info->suspiciousElements = read_file(suspiciousElements);

	return info;
}

void cleanInformation(information info) {
	cleanFile(info->badExtensions);
	cleanFile(info->badTlds);
	cleanFile(info->database);
	cleanFile(info->safeDomains);
	cleanFile(info->suspiciousElements);
	free(info);
}