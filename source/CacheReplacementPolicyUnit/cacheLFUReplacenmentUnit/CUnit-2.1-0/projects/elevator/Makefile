OBJ_DIR  := obj
OBJ_EXTENSION := o
SRC_EXTENSION := c
SRC_DIR := testedCode/
PROG_DIR := progs/
INC_DIR := inc/

test1: $(OBJ_DIR)/test1.o $(OBJ_DIR)/cabin.o $(OBJ_DIR)/globals.o
	gcc --static  $^ -L /usr/local/lib/ -lcunit  -o $@

$(OBJ_DIR)/%.$(OBJ_EXTENSION) : $(SRC_DIR)/%.$(SRC_EXTENSION) 
	gcc -c $< -Iinc/ -o $@
$(OBJ_DIR)/%.$(OBJ_EXTENSION) : $(PROG_DIR)/%.$(SRC_EXTENSION) 
	gcc -c $< -Iinc/ -o $@

clean:
	rm -rf test1 obj/*.o *~ $(SRC_DIR)/*~ $(PROG_DIR)/*~


