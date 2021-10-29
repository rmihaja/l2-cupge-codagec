# MODULES = 
INCLUDE = -I ~/Informatique/S3/include
WARNINGS = -Wall -Werror -Wextra -ggdb3
DEST = ~/Informatique/S3/bin
TESTS = -DTESTS -DUSECOLORS

# * dependencies compile 

# %.o: %.c 
# 	gcc $(OPTIONS) $(INCLUDE) $(WARNINGS) -c $*.c

# * programme compile

run/%: $(DEST)/% 
	$(DEST)/$*

$(DEST)/%: %.c
	gcc $(INCLUDE) $(WARNINGS) $(TESTS) $*.c -o $(DEST)/$*

# * unit tests

test0: $(DEST)/$(PROGRAMME)
	$(PROGRAMME)  

test1,%: $(DEST)/$(PROGRAMME)
	$(PROGRAMME) $*  

test2: $(DEST)/$(PROGRAMME)
	$(PROGRAMME) -p 0.01 3.14

