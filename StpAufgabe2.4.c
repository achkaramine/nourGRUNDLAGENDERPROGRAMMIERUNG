#define GEIMPFT 	1
#define GETESTET 	2
#define GENESEN 	3
#define UNBEKANNT 	4
// ca c'est bien de le mettre mais c'est pas demander dans l'exercice
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

//  Just pour afficher un participant .. fainéant ..
void displayPartic ( stP *stp ) {
	printf ("{Name: %s, Id: %ld, Status: %s}\n", stp->Name, stp->Ident,GET_STATUS(stp->Status));
}

// Je cree cette fonction pour faciliter (ne pas refaire a chaque fois) le rajout de nouveau participant dans le tableau ... fainéant .. tu connais 
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
	strncpy(newStp->Name, name, strlen(name)>_STP_NAME_MAXLENGTH_?_STP_NAME_MAXLENGTH_-1:strlen(name));	

	// Une fois quil est crée je le rajoute au tableau
	P[currentPosition++]=*newStp;
	printf ("Paricipiant add with success -> ");
	displayPartic(newStp);	
	return newStp;
}

// Ce qui est demander ==> La reponse a ton exercice exo2.3
int getStatusFromId(int parser, long id){
	if ( parser>=1000 ) return -1;
	return P[parser].Ident==id?P[parser].Status:getStatusFromId(parser+1,id);	
}

// Exo 2.4
// J'ai pas tros compris ce quil veut
// Je crois la fonction prend en entré un tableau stP et renvoi le nbr de vacciné
// Important .. dans la vrais vie, ne jamais mettre une tail de tableau en dure (100) dans le code .. ca doit etre dynamic
int CorAnz(stP *lstTeilnehmer) {
	int nbrGeimpftLeute=0;
	for (stP *parser=&lstTeilnehmer[0]; parser <= lstTeilnehmer + 100; parser++){
		if (parser->Status == GEIMPFT ) ++nbrGeimpftLeute;
	}
	return nbrGeimpftLeute;
}

void main ( char ** args ) {

	// Pour prouver que ca marche 
	addPartic("Nour", 1234414133, GEIMPFT);
	addPartic("Sarah", 1234141245, GEIMPFT);
	addPartic("titiSarah", 1234141245, GEIMPFT);
	addPartic("Ahmed", 4512324122, GENESEN);
	addPartic("Amine", 1441545411, GETESTET);
	printf ("Nbr geimpft: %d\n", CorAnz(P));
}
