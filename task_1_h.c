//
// Created by Леонид Шайхутдинов on 30.04.2023.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
	const char *varname = "MY_ENVVAR";
	char *varvalue = getenv(varname);
	if (varvalue != NULL) {
		printf("Value of %s is %s\n", varname, varvalue);
	} else {
		printf("%s is not set\n", varname);
	}
	return 0;
}
