struct noeud{
    unsigned s;
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

struct element{
	unsigned  cle;
	struct element* suivant;
};

struct file{
	struct element* tete;
	struct element *queue;
};

void creer_file();
unsigned file_vide();
unsigned premier();
void enfiler(unsigned);
void defiler();
