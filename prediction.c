#include "header.h"

int too_many_subdomains(char *domain) {
	int count = 0;
	for (int i = 0; i < strlen(domain); i++)
		if (domain[i] == '.')
			count += 1;

	if (count > 5)
		return 1;

	return 0;
}

char *isUrlSafe(features urlFeatures, information info) {
	int is_trusted_domain = safe_domain(urlFeatures, info);
	if (is_trusted_domain)
		return "Safe URL";

	int known_bad_url = is_in_database(urlFeatures, info);
	if (known_bad_url)
		return "Unsafe URL, reason: known malicious URL.";

	int url_starts_with_digit = urlFeatures->domain[0] >= '0' && urlFeatures->domain[0] <= '9';
	if (url_starts_with_digit)
		return "Unsafe URL, reason: starts with digit.";

	int empty_var = strstr(urlFeatures->link, "=&") && !strstr(urlFeatures->link, "==&");
	if (empty_var)
		return "Unsafe URL, reason: empty query parameter.";

	int just_domain = (strcmp(urlFeatures->last_part, urlFeatures->domain) == 0 && urlFeatures->last_char != '/');
	if (just_domain)
		return "Unsafe URL, reason: just domain.";

	int too_long_file_name = (urlFeatures->file && urlFeatures->file - urlFeatures->last_part > 63);
	if (too_long_file_name)
		return "Unsafe URL, reason: url points to a suspicious file.";

	int no_var = (urlFeatures->last_char == '=' || (urlFeatures->frag_hash && !strchr(urlFeatures->frag_hash, '=')));
	if (no_var)
		return "Unsafe URL, reason: empty fragment hash.";
	
	int has_sus_parts = (hasSuspiciousElements(urlFeatures, info) && !good_extension(urlFeatures, info));
	if (has_sus_parts)
		return "Unsafe URL, reason: contains suspicious parts.";

	int unallowed_file_type = check_link_extension(urlFeatures, info);
	if (unallowed_file_type)
		return "Unsafe URL, reason: unsafe file extension.";

	int many_comps = too_many_subdomains(urlFeatures->domain);
	if (many_comps)
		return "Unsafe URL, reason: too many subdomains.";

	return "Safe URL, all checks passed.";
}