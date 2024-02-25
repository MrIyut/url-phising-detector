#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char **data;
	int size;
} _File, *_file;

typedef struct {
	char *last_part, *extension, *file;
	char *frag_hash, *domain, last_char;
	char *link;
} Features, *features;

typedef struct {
	_file safeDomains, badExtensions;
	_file database, badTlds;
	_file suspiciousElements;
} Information, *information;

information readInformation();
features extractUrlFeatures(char *link);
void cleanFeatures(features urlFeatures);
_file read_file(FILE *File);
void cleanFile(_file file);
bool check_link_extension(features urlFeatures, information info);
bool safe_domain(features urlFeatures, information info);
int is_in_database(features urlFeatures, information info);
char *isUrlSafe(features urlFeatures, information info);
void cleanInformation(information info);
bool hasSuspiciousElements(features urlFeatures, information info);
bool good_extension(features urlFeatures, information info);