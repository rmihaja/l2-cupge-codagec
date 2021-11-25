MODULES = lire_fin_ligne.o lire_entier.o lire_decimal.o lire_format.o

# * dependencies compile 

%.o: %.c 
	gcc $(OPTIONS) $(INCLUDE) $(WARNINGS) -c -o $@ $<

~/Informatique/S3/lib/libentrees.a: $(MODULES)
	ar rcs $@ $^
