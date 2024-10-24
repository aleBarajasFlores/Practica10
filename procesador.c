#include <stdio.h>
#include "procesador.h"

void init_processor(processor *cpu){
  memset(cpu->memory, 0, sizeof(MEM_SIZE));
  memset(cpu->registers, 0, sizeof(NUM_REGISTERS));
  memset(cpu->flags, 0, sizeof(NUM_FLAGS));
  cpu->PC=0;
}

void load_program(processor *cpu, const char *filename){
  scanf("%s", filename);
  FILE *fp = fopen(filename, "r");
  
}

void update_flags(processor *cpu, int result);

void alu_and_control_unity(processor *cpu);

void print(processor *cpu);

void fprint(processor *cpu);