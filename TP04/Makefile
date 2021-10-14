
# ? Makefile : fichier lu par la commande make

# * Warning options
# ? on dit à gcc d'être super-strict
# -Wall : afficher tous les erreurs 
# -Werror : ne pas compiler le code s'il existe une erreur
# -Wextras : afficher les messages qui ne sont pas des erreurs ou avertissements

# -ggdb3 # ? permet d'utiliser le debugger

# -DTESTS # ? compiler les codes entre #ifdef #endif

# ? output : fichier à créer 
# ~/Informatique/S3/bin/CreerMatrice
# -o ~/Informatique/S3/bin/CreerMatrice

# -c # ? pas executable, compilation partielle

# * dependencies compilation

CreerMatrice.o: CreerMatrice.c
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -Werror -Wextra CreerMatrice.c -c -o CreerMatrice.o

AfficheMatrice.o: AfficheMatrice.c
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -Werror -Wextra AfficheMatrice.c -c -o AfficheMatrice.o

# * CreerMatrice

run/CreerMatrice.c: ~/Informatique/S3/bin/CreerMatrice
	~/Informatique/S3/bin/CreerMatrice

~/Informatique/S3/bin/CreerMatrice: CreerMatrice.c
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -DTESTS -Werror -Wextra CreerMatrice.c -o ~/Informatique/S3/bin/CreerMatrice

# * AfficheMatrice

run/AfficheMatrice.c: ~/Informatique/S3/bin/AfficheMatrice 
	~/Informatique/S3/bin/AfficheMatrice

~/Informatique/S3/bin/AfficheMatrice: AfficheMatrice.c CreerMatrice.o
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -DTESTS -Werror -Wextra AfficheMatrice.c CreerMatrice.o -o ~/Informatique/S3/bin/AfficheMatrice

# * SommeMatrices

run/SommeMatrices.c: ~/Informatique/S3/bin/SommeMatrices
	~/Informatique/S3/bin/SommeMatrices

~/Informatique/S3/bin/SommeMatrices: SommeMatrices.c CreerMatrice.o AfficheMatrice.o
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -DTESTS -Werror -Wextra SommeMatrices.c CreerMatrice.o AfficheMatrice.o -o ~/Informatique/S3/bin/SommeMatrices

# * ProduitMatrices

run/ProduitMatrices.c: ~/Informatique/S3/bin/ProduitMatrices
	~Informatique/S3/bin/ProduitMatrices

~/Informatique/S3/bin/ProduitMatrices: ProduitMatrices.c CreerMatrice.o AfficheMatrice.o
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -DTESTS -Werror - Wextra ProduitMatrices.c CreerMatrice.o AfficheMatrice.o -o ~/Informatique/S3/bin/ProduitMatrices