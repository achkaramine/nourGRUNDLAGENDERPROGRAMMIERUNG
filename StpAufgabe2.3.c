#define GEIMPFT 	0
#define GETESTET 	1
#define GENESEN 	2
#define UNBEKANNT 	3
#define GET_STATUS(s) s==GEIMPFT?"Geimpft":(s==GETESTET)?"Getestet":(s==GENESEN)?"Genesen":"Unbekannt"
#define _STP_NAME_MAXLENGTH_ 32
#define _STP_MAXLENGTH_ 1000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct stP {
	char Name[_STP_NAME_MAXLENGTH_];
	long Ident;
	int Status;
} typedef stP;


stP P[1000];
int currentPosition=0;

// Just pour afficher un participant .. fainéant ..
void displayPartic ( stP *stp ) {
	printf ("{Name: %s, Id: %ld, Status: %s}\n", stp->Name, stp->Ident,GET_STATUS(stp->Status));
}

// Je cree cette fonction pour faciliter le rajout de nouveau participant dans le tableau ... fainéant .. tu connais 
stP * addPartic ( char *name, long id, int status ) {
	// Sinon on depasse la tail de notre pauvre tableau .. on va etre mal .. 
	//tu peux rajouter un joli printf avec un message d'erreur .. du coup je passe .. pas le temp
	if ( currentPosition >= 1000 ) return NULL; 

	// nouveau Stp que je veux rajouter au tableau avec les param de la fonction
	stP *newStp=malloc(sizeof (*newStp));
	newStp->Ident=id;
	newStp->Status=status;	

	// just au cas ou quelqu'un utilise ma fonction avec un "name" plus grand que _STP_NAME_MAXLENGTH_
	// Il faut toujours faire comme ca si tu veux copier une chaine de char dans une autre
	strncpy(newStp->Name, name, strlen(name)>_STP_NAME_MAXLENGTH_?_STP_NAME_MAXLENGTH_-1:strlen(name)-1);	

	// Une fois quil est crée je le rajoute au tableau
	P[currentPosition++]=*newStp;
	printf ("Paricipiant add with success -> ");
	displayPartic(newStp);	
	return newStp;
}

// La reponse a ton exercice .. 
int getStatusFromId(int parser, long id){
	if ( parser>=1000 ) return -1;
	return P[parser].Ident==id?P[parser].Status:getStatusFromId(parser+1,id);	
}

void main ( char ** args ) {

	// just pour tester que ca marche, je rajoute quelque participant
	addPartic("Nour", 1234414133, GEIMPFT);
	addPartic("Sarah", 1234141245, GEIMPFT);
	addPartic("Ahmed", 4512324122, GENESEN);
	addPartic("Amine", 1441545411, GETESTET);
	printf ("%s\n", GET_STATUS(getStatusFromId(0, 4512324122)));
}
