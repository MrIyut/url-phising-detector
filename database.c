#include "header.h"

int is_in_database(features urlFeatures, information info)
{
	for (int i = 0; i < info->database->size; i++)
		if (strcmp(urlFeatures->domain, info->database->data[i]) == 0)
			return 1;

	for (int i = 0; i < info->safeDomains->size; i++)
		if (strcmp(urlFeatures->domain, info->safeDomains->data[i]) == 0)
			return 1;
	return 0;
}