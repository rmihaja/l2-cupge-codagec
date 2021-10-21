# * variables init

INCLUDE=-I ~/Informatique/S3/include
LIB=-lm
TESTS=-DTESTS -DUSECOLORS
WARNINGS=-ggdb3 -Wall -Wextra -Werror
OUTPUTDIR=~/Informatique/S3/bin
MODULES=nouvelle_fraction.o

# * variables init

%.o: %.c
	gcc $(INCLUDE) $(WARNINGS) -c $*.c

$(OUTPUTDIR)/%: %.c
	gcc $(INCLUDE) $(WARNINGS) $(TESTS) $*.c $(MODULES) -o $(OUTPUTDIR)/$*

run/%.c: $(OUTPUTDIR)/%
	$(OUTPUTDIR)/$*

# ! old declaration

# * dependencies

# nouvelle_fraction.o: nouvelle_fraction.c
# 	gcc $(INCLUDE) $(WARNINGS) nouvelle_fraction.c -c

# fonctionX.o: fonctionX.c
# 	gcc $(INCLUDE) $(WARNINGS) fonctionX.c -c fonctionX.o

# * fraction

# $(OUTPUTDIR)/nouvelle_fraction: nouvelle_fraction.c
# 	gcc $(INCLUDE) $(WARNINGS) $(TESTS) nouvelle_fraction.c -o $(OUTPUTDIR)/nouvelle_fraction

# run/nouvelle_fraction.c: $(OUTPUTDIR)/nouvelle_fraction
# 	$(OUTPUTDIR)/nouvelle_fraction
