struct noeud{
    unsigned s;
//    unsigned valeur; //weight of the arc redirecting to sucessor s
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
unsigned arc(unsigned s1,unsigned s2);
void explorer_connexe(unsigned k);
void composant_connexe();
void explorer_largeur_path(unsigned k,unsigned y); 
void path(unsigned x,unsigned y); 
unsigned numero(unsigned x);
void ajouter_arc(unsigned x,unsigned y);
unsigned nom(unsigned x);
void transitive_closure();
void print_matrix(); 
void list_to_mat();
void mat_to_list();
void explorer_prof_mat(unsigned k);
void profondeur_mat();
void explorer_larg_mat(unsigned k);
void largeur_mat();
void error();
void explorer_circuit(unsigned k);
void detect_circuit();


