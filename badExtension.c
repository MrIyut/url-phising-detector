#include "header.h"

bool is_unallowed_extension(char *extension, _file badExtensions) {
	for (int i = 0; i < badExtensions->size; i++)
		if (strcmp(extension, badExtensions->data[i]) == 0)
			return true;
	return false;
}

bool check_link_extension(features urlFeatures, information info) {
	return is_unallowed_extension(urlFeatures->extension, info->badExtensions);
}