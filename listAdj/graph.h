struct noeud{
    unsigned s;
    unsigned valeur; //weight of the arc redirecting to sucessor s
    struct noeud* suivant;
};

void remplir();
void display_checker();
void explorer_prof(unsigned k);
void profondeur();
void explorer_larg(unsigned k);
void largeur();
unsigned deg_int(unsigned s);
unsigned ieme_succ(unsigned i,unsigned s);


