struct noeud_tete { 
    unsigned cle;
    unsigned cp;
    struct noeud_tete* suiv;
    struct noeud_succ{ 
        struct noeud_tete* contenue; 
        struct noeud_succ* succ;
    }* succ

}
