


struct noeud{
    int info;
    struct noeud* suivant;

};
struct liste{
    struct noeud* premier;
    struct noeud* dernier;
};

void creer_liste(struct liste*);
unsigned liste_vide(struct liste);
void initialser(int x,struct liste * );
void ajouter_avant_premier(int x,struct liste * );
void ajouter_apres_dernier(int x,struct liste * );
void inserer_liste(struct liste * ); 
void affichage(struct liste  );
void supprime_premier(struct liste * );
void supprime_apres_ref(struct noeud* p,struct liste * );
void supprime_element(int elem,struct liste * );

void supprimer_ref(struct noeud *p,struct liste * );

void supprimer_avant_liste(struct liste * );

void suprimer_elem_mini(struct liste * );
unsigned existe(int ,struct liste );
void eclater(struct liste  ,struct liste* ,struct liste * );
