
# .SILENT
PROGRAMME = recherche# notre variable, fichier à compiler

MODULES = addition_cancre.o eval_fraction.o fractioncmp.o ftofraction.o nouvelle_fraction.o print_fraction.o 
INCLUDE = -I ~/Informatique/S3/include
WARNINGS = -Wall -Werror -Wextra -ggdb3
DEST = ~/Informatique/S3/bin
TESTS = -DTESTS -DUSECOLORS
LFRAC = ~/Informatique/S3/lib/libfraction.a
LIB = -L ~/Informatique/S3/lib -lm -lfraction
# ? on prend le dossier .../lib et on selectionne les fichiers librairies libm.a et libfraction.a
# ? CONVENTION : -lX => fichiers libXXX 

# * lib compile

~/Informatique/S3/lib/libfraction.a: $(MODULES)
	ar rcs ~/Informatique/S3/lib/libfraction.a $(MODULES) 
# ? l'ordre est important

$(DEST)/%: %.c ~/Informatique/S3/lib/libfraction.a
	gcc $(OPTIONS) $(TESTS) $(INCLUDE) $(WARNINGS) -o $(DEST)/$* $*.c $(LIB) 
# ? $(LIB) => tous les fichiers .o de ma lib sont rajoutés

# * dependencies compile

%.o: %.c
	gcc $(OPTIONS) $(INCLUDE) $(WARNINGS) -c $*.c

# * programme compile

run/%: $(DEST)/% 
	$(DEST)/$*

$(PROGRAMME): $(PROGRAMME).c $(LFRAC)
	gcc $(OPTIONS) $(INCLUDE) $(WARNINGS) -o $(PROGRAMME) $(PROGRAMME).c $(LIB)

# * unit tests

test0: $(DEST)/$(PROGRAMME)
	$(PROGRAMME)  

test1,%: $(DEST)/$(PROGRAMME)
	$(PROGRAMME) $*  

test2: $(DEST)/$(PROGRAMME)
	$(PROGRAMME) -p 0.01 3.14
