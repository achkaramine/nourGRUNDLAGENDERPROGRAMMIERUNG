#define GEIMPFT 	0
#define GETESTET 	1
#define GENESEN 	2
#define UNBEKANNT 	3

#define _STP_NAME_MAXLENGTH_ 32

#include <stdio.h>
#include <string.h>

 struct stP {
	char Name[_STP_NAME_MAXLENGTH_];
	long Ident;
	int Status;
} typedef stP;

stP P[1000];
