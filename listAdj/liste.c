#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include <assert.h>


/*************************INITIALISATION_&_CONSULTATION************************/
void creer_liste(struct liste* ll)
{
    ll->premier = NULL;
    ll->dernier = NULL;
}

unsigned liste_vide(struct liste ll)
{
    return (ll.premier == NULL && ll.dernier == NULL);
}
void initialiser(int x,struct liste *ll)
{
    
    struct noeud* q = (struct noeud*)malloc(sizeof(struct noeud));
    q -> info = x;
    q->suivant = NULL;

    ll->premier = q;
    ll->dernier = q;
}

void affichage(struct liste ll)
{
    struct noeud* p = ll.premier;
    while(p)
    {
        printf("%d\t",p->info);
        p = p->suivant;
    }
}


/*****************************************OPERATIONS_AJOUTER********************************/
void ajouter_avant_premier(int x,struct liste *ll)
{
     if(liste_vide(*ll))
    {
        initialiser(x,ll);
        return;    
    }
   
   
    struct noeud* q = (struct noeud*)malloc(sizeof(struct noeud));
    q -> info = x;
    q->suivant = ll->premier;
    ll->premier = q;
}
void ajouter_apres_dernier(int x,struct liste *ll)
{
    if(liste_vide(*ll))
    {
        initialiser(x,ll);
        return;    
    }
    struct noeud* q = (struct noeud*)malloc(sizeof(struct noeud));
    q -> info = x;
    
    q->suivant = NULL;
    ll->dernier->suivant  = q;
    ll->dernier = q;
}
void inserer_liste(struct liste *l1) 
    //CREATION D'UNE LISTE UNIDIRECTIONELLE
{
    int x,res;
    creer_liste(l1);
   do{
        printf("\nDonner un element a inserer\t");
        scanf("%d",&x);
         ajouter_apres_dernier( x,l1);
        do{
            printf("Voulez vous ajouter un autres element (0:NON|1:OUI)\t");
            scanf("%d",&res);
            
        }while(!(res == 1 || res == 0));
   
   }while(res);

}/*********************************************OPERATIONS_SUPPRIMER********************************/
void supprime_premier(struct liste *ll){
    struct noeud *q = ll->premier;
    ll->premier = ll->premier->suivant;
    free(q);
    
}


void supprime_element(int elem,struct liste *ll){
   //3 cas: SI ELEMENT  DANS
   //premier
   //dernier
   //milieu
   //on dois considerer tous les cas
   //assert(!liste_vide(*ll));
    //on doit aussi prendre considération que la liste admet un seule element
    struct noeud* q = ll->premier;
    while(q->suivant)
    {  
       if (q->info == elem && q == ll->premier)
        {
        supprime_premier(ll);
        return;
         } 
          else if(q->suivant->info == elem)
       {
             supprime_apres_ref(q,ll); //prob is here
             return;
       }
             //q = q->suivant; So, q is gonna be automaticall changed
             //in the delete function
        else q = q->suivant;

       
    }
}
void supprimer_ref(struct noeud *p,struct liste *ll)
{       
    /*
        cas: p == ll->premier;
            p = ll->dernier;
            p in the middle
            & what if there is only one element in the list

::    */
    struct noeud* sup = NULL,*k;//sup: supprimer variable

    if(p == ll->premier && p == ll->dernier) //only one element in the list
    {
        ll->premier = ll->dernier = NULL;
        free(p);
        return;
    }
    if(p == ll->premier)
    {
        //supprime_premier(ll);
        sup = p->suivant;
        *p = *(p->suivant);
        ll->premier = p;
    }else if (p==ll->dernier){
        //loop until you reach the precedent of the last cell
        k = ll->premier;
        while(k->suivant !=ll->dernier)
            k = k->suivant;
        sup = p;

        ll->dernier = k; 
        ll->dernier->suivant = NULL;
    }else{
        sup = p->suivant;
        *p = *(p->suivant);
        
    }
        free(sup);
  }

void supprime_apres_ref(struct noeud* p,struct liste *ll){

    struct noeud *q = p->suivant;
    if(q == ll->dernier){
        ll->dernier = p;
        p->suivant = NULL;
    }
    else
         p->suivant = q->suivant;
    free(q);
}
/*COMPTE_RENDU*/
void supprimer_avant_liste(struct liste *ll){
    assert(!liste_vide(*ll));
    struct noeud*q = ll->premier,* p = q->suivant;
    while(q->suivant && p->suivant ) 
    {
        printf("\n%d was  deleted\n",q->info);
        supprimer_ref(q,ll);
        q = p->suivant;
        p = q->suivant;
       
    }
 
        //supprimer_ref(q,ll);
}
void suppression_val_apres(struct liste * ll)
{
    struct noeud *p = ll->premier,*q = p->suivant;
    
    while(p->suivant)
    {
        if(q == ll->dernier)
        {
            p->suivant = NULL;
            ll->dernier = p;
            free(q);
            break;
        }
    
        p->suivant = q->suivant;
        p = p->suivant;

        free(q);
        q = p->suivant;
    }
}
void suppression_val_apres2(struct liste *ll)
{
    struct noeud* p = ll->premier, *p2;

    while(p && p->suivant)
    {
        p2 = p->suivant;
        
        if(p2 == ll->dernier)   
            ll->dernier = p;

        p->suivant = p2->suivant;
        p = p->suivant;

    }
}
void suprimer_elem_mini(struct liste *ll)
{
    assert(!liste_vide(*ll));
    struct noeud* min = ll->premier,*q= min->suivant;
    while(q)
    {
        if(min->info > q->info)
            min = q;
        q = q->suivant;
    }
    supprimer_ref(min,ll);
}
unsigned existe(int x,struct liste ll)
{
    struct noeud* q = ll.premier;
    while(q)
    {
        if(q->info == x)
            return 0;
        q = q->suivant;
    }
    
    return 1;

}
void eclater(struct liste l1,struct liste*l2,struct liste *l3)
{
    /*L2 pour les paires 
     * l3 pour les impaaires*/
    assert(!liste_vide(l1));
    struct noeud* p = l1.premier;
    int cp3 = 0,cp2 = 0;
    while(p)
    {
        if(p->info %2 )//&& !existe(p->info,*l3))
        {
            cp3 ++;

            if (cp3 == 1)
                initialiser(p->info,l3);
            else 
                ajouter_apres_dernier(p->info,l3);
        }else
        {
           // if(!existe(p->info,*l2))
           cp2 ++;
            if(cp2== 1)
                initialiser(p->info,l2);
            else
                ajouter_apres_dernier(p->info,l2);
        }p = p->suivant;
    }


}

