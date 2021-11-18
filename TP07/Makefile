INCLUDE = -I ~/Informatique/S3/include
LIBS = -L ~/Informatique/S3/lib
MODULES = 
WARNINGS = -Wall -Werror -Wextra -ggdb3
DEST = ~/Informatique/S3/bin
TESTS = -DTESTS -DUSECOLORS

# * dependencies compile 

%.o: %.c 
	gcc $(OPTIONS) $(INCLUDE) $(WARNINGS) -c -o $@ $

# * programme compile

run/%: $(DEST)/%
	$<


$(DEST)/%: %.c
	gcc $(INCLUDE) $(WARNINGS) $(TESTS) $(MODULES) $*.c -o $(DEST)/$*
#	gcc $(INCLUDE) $(LIBS) $(WARNINGS) $(TESTS) -o $@ $< 


# * unit tests

test/%: $(DEST)/%
	$< toto 12 argument3
