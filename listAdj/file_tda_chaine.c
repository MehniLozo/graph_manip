#include "file_tda_chaine.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
struct file f;

void creer_file()
{
	f.tete = NULL;
	f.queue = NULL;
}

unsigned file_vide()
{
	return ((f.tete == NULL) && (f.tete == NULL));
}
unsigned premier()
{
	assert(!file_vide(f));
	return f.tete->cle;
}
void enfiler(unsigned info)
{
	struct element *q;
	q = (struct element*)malloc(sizeof(struct element));
	q->cle = info;
	q->suivant = NULL;//as we always add from the queue
	


    //we have two cases
    //either:
    //you have an empty queue or filled one
	if(!file_vide(f))
	
		f.queue->suivant = q;
	else
		f.tete = q;
    f.queue = q;
}
void defiler()
{
	assert(!file_vide(f));
	struct element *q;


	q = f.tete;
	f.tete = f.tete->suivant;

	free(q);
//we always check if our QUEUE HEADER is NULL or NOT
	if(f.tete == NULL)
		f.queue = NULL;
}
