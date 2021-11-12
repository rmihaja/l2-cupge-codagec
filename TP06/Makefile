INCLUDE = -I ~/Informatique/S3/include
LIBS = -L ~/Informatique/S3/lib
MODULES = creer_matrice.o lire_matrice.o afficher_matrice.o somme_matrices.o
WARNINGS = -Wall -Werror -Wextra -ggdb3
DEST = ~/Informatique/S3/bin
TESTS = -DTESTS -DUSECOLORS

# * dependencies compile 

%.o: %.c 
# 	? before
# 	gcc $(OPTIONS) $(INCLUDE) $(WARNINGS) -c $*.c
	gcc $(OPTIONS) $(INCLUDE) $(WARNINGS) -c -o $@ $<

~/Informatique/S3/lib/libmatrices.a: $(MODULES)
	ar rcs $@ $^

# * programme compile

run/%: $(DEST)/%
# 	? before 
#	$(DEST)/$*
	$<


$(DEST)/%: %.c
# #	? before
	gcc $(INCLUDE) $(WARNINGS) $(TESTS) $(MODULES) $*.c -o $(DEST)/$*
# gcc $(INCLUDE) $(LIBS) $(WARNINGS) $(TESTS) -o $@ $< 


# * unit tests

test/lire_matrice: $(DEST)/lire_matrice
	echo "1 2 3 4 5 6" | $<

test/produit_matrices: $(DEST)/produit_matrices
	$< < ~/Informatique/S3/TP/TP06/test-produit_matrices

