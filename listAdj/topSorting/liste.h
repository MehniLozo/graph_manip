struct noeud_tete { 
    unsigned cle;
    unsigned cp;
    struct noeud_tete* suiv;
    struct noeud_queue{ 
        struct noeud_tete* id; 
        struct noeud_queue* suivant;
    }* succ

}
