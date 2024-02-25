#include "header.h"

bool safe_domain(features urlFeatures, information info)
{
	for (int i = 0; i < info->safeDomains->size; i++){
		if (strcmp(urlFeatures->domain, info->safeDomains->data[i]) == 0)
			return true;
	}
	return false;
}

bool good_extension(features urlFeatures, information info) {
	char allowed_extensions[3][4] = {"htm", "com", "do"};
	for (int i = 0; i < 3; i++)
		if (strstr(urlFeatures->extension, allowed_extensions[i]))
			return true;
	return false;
}