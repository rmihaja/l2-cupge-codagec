LIB = ~/Informatique/S3/lib
INCLUDE = ~/Informatique/S3/include
DEST=~/Informatique/S3/bin

# dependencies compile

%.o: %.c
	gcc -Wall -I $(INCLUDE) -c $<

$(LIB)/libtri.a: tri.o
	ar rcs $@ $^

$(LIB)/libmemoire.a: memoire.o
	ar rcs $@ $^

# executable compile

$(DEST)/%: bozo.c $(LIB)/libtri.a $(LIB)/libmemoire.a
	gcc -Wall -o $@ $< -I $(INCLUDE) -L $(LIB) -ltri -lmemoire

$(DEST)/%_debug: bozo.c $(LIB)/libtri.a $(LIB)/libmemoire.a
	gcc -Wall -DDEBUG -o $@ $< -I $(INCLUDE) -L $(LIB) -ltri -lmemoire

run: $(DEST)/bozo
	$<

run: $(DEST)/bozo_debug
	$<