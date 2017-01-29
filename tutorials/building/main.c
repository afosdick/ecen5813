#include "my_file.h"
#include "my_memory.h"

extern char memory[MAX_LENGTH];

/* A pretty boring main file */
int main(void){

  clear_all(memory, MAX_LENGTH);
  set_value(memory, 0xAA, 0);
  set_value(memory, 0xFF, 1);

  return 0;
}

