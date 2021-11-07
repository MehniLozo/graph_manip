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
