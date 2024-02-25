#include "header.h"

bool hasSuspiciousElements(features urlFeatures, information info)
{
	for (int i = 0; i < info->suspiciousElements->size; i++)
		if (strstr(urlFeatures->link, info->suspiciousElements->data[i]))
			return true;
	return false;
}