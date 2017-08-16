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
	printf("�ֹε�Ϲ�ȣ : %d \n",p->ssn);
	printf("�̸� : %s \n", p->name);
	printf("�ּ� : %s \n\n", p->addr);

}
Person* MakePersonData(int ssn, char * name, char * addr)
{
	Person* np = (Person*)malloc(sizeof(Person));
	np->ssn = ssn;
	strcpy(np->name, name);
	strcpy(np->addr, addr);
	return np;
}