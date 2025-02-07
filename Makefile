SRC_DIR = src
INC = -I$(SRC_DIR)/include
CFLAGS = -Wall -Wpedantic -Wextra  -Wno-unused-parameter -Wno-unused-function -Werror -ffreestanding -std=gnu99

all:
	:

debug:
	gcc -g -o bprintf_debug $(SRC_DIR)/*.c $(INC) $(CFLAGS) -O0 #TODO figure out if this is what I should use for an embedded situation. 

clean:
	rm -rf bprintf_debug *.dSYM #TODO figure out if more things need to be removed later.
