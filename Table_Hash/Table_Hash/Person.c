#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Person.h"

int GetSSN(Person * p)
{
	return p->ssn;
}
void ShowPerInfo(Person * p)
{
	printf("주민등록번호 : %d \n",p->ssn);
	printf("이름 : %s \n", p->name);
	printf("주소 : %s \n\n", p->addr);

}
Person* MakePersonData(int ssn, char * name, char * addr)
{
	Person* np = (Person*)malloc(sizeof(Person));
	np->ssn = ssn;
	strcpy(np->name, name);
	strcpy(np->addr, addr);
	return np;
}