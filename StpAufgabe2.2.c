#define GEIMPFT 	0
#define GETESTET 	1
#define GENESEN 	2
#define UNBEKANNT 	3
#define _STP_NAME_MAXLENGTH_ 32
#define _STP_MAXLENGTH_ 1000


#include <stdio.h>
#include <string.h>

struct stP {
	char Name[_STP_NAME_MAXLENGTH_];
	long Ident;
	int Status;
} typedef stP;


int currentPosition=0;
stP P[1000]; // Pas trop fan, on doit plutot utiliser un truc comme ca: _STP_MAXLENGTH_ , le l exo est comme ca .. je fais avec

void main ( char ** args ) {
  // input data
	long id=4711;
	char name[_STP_NAME_MAXLENGTH_]="Otto";
	int status=GEIMPFT;
// -->  start main
  // create otto 
	stP pOtto;
	strncpy(pOtto.Name, name, strlen(name)>_STP_NAME_MAXLENGTH_?_STP_NAME_MAXLENGTH_-1:strlen(name)-1);
	pOtto.Ident=id;
	pOtto.Status=status;
  // add otto to list of participent
	P[currentPosition++]=pOtto;


  // UNIT TESTS FOR NOUR -- pas inclue dans la reponse, just pour to montrer comment verifer que ton truc marche (normalement ca doit etre dans un fichier separé pour les tests)
	stP getOtto=P[currentPosition-1];
	getOtto.Ident==id?printf ("UNIT TEST 1 [OK]\n"):printf ("UNIT TEST 1 [KO]\n");
	strcmp(getOtto.Name,name)?printf ("UNIT TEST 2 [OK]\n"):printf ("UNIT TEST 2 [KO]\n");
	getOtto.Status==status?printf ("UNIT TEST 3 [OK]\n"):printf ("UNIT TEST 3 [KO]\n");
}
