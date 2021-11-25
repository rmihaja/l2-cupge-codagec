INCLUDE = -I ~/Informatique/S3/include
LIBS = -L ~/Informatique/S3/lib
MODULES = lire_fin_ligne.o lire_entier.o lire_decimal.o
WARNINGS = -Wall -Werror -Wextra -ggdb3
DEST = ~/Informatique/S3/bin
TESTS = -DTESTS -DUSECOLORS

# * programme compile

run/%: $(DEST)/%
	$<


$(DEST)/%: %.c
	gcc $(INCLUDE) $(WARNINGS) $(TESTS) $(MODULES) $*.c -o $(DEST)/$*
#	gcc $(INCLUDE) $(LIBS) $(WARNINGS) $(TESTS) -o $@ $< 


# * unit tests

test/%: $(DEST)/%
	$< 12 toto argument3

testf/lire_fin_ligne: $(DEST)/lire_fin_ligne
	echo "" | $(<)
# ? printf allows '\n' character, not echo
	printf " \t  \n" | $<
	printf " \t  \nabc" | $<
	printf "azerty\n" | $< 

testf/%: $(DEST)/%
	printf "51a\n abc\n 1.3\n 5\n" | $<