CreerMatrice.o: CreerMatrice.c
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -Werror -Wextra CreerMatrice.c -o CreerMatrice.o

run/CreerMatrice.c: ~/Informatique/S3/bin/CreerMatrice
	~/Informatique/S3/bin/CreerMatrice

~/Informatique/S3/bin/CreerMatrice: CreerMatrice.c
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -DTESTS -Werror -Wextra CreerMatrice.c -o ~/Informatique/S3/bin/CreerMatrice

run/AfficheMatrice.c: ~/Informatique/S3/bin/AfficheMatrice.c CreerMatrice.o 
	gcc -I ~/Informatique/S3/include -ggdb3 -Wall -DTESTS -Werror -Wextra AfficheMatrice.c CreerMatrice.o -o ~/Informatique/S3/bin/AfficheMatrice