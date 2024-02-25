Small phising urls detector.

Looks for the following criteria:


```
1) Domain contains too many digits
2) Misspelled_domain
3) URL tries to use a non-standard port
4) Untrusted TLD
5) Weird subdomain: contains digits or special characters
6) Domain have to many components
7) URL is just the url, with anything
8) There are hyphens in the subdomain
9) URL contains suspicious patterns
10) URL contains the @ symbol
11) Parameters with no value
12) Domain is made up only of digits
13) Parameters have ambigous names
14) Very long parameter names
15) The value of a parameter is a file
16) File name is made up only of digits
17) Very long file name
18) File is an executable file or is of a forbidden type
19) Long directory names in the path
20) URL uses non-standard protocol
21) URL is known to be bad
22) URL entropy
```
