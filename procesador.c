#include <stdio.h>
#include "procesador.h"

void init_processor(processor *cpu){
  memset(cpu->memory, 0, sizeof(MEM_SIZE));
  memset(cpu->registers, 0, sizeof(NUM_REGISTERS));
  memset(cpu->flags, 0, sizeof(NUM_FLAGS));
  cpu->PC=0;
}

void load_program(processor *cpu, const char *filename){
  
  char line[256];
  int c = 0;
  scanf("%s", filename);
  FILE *fp = fopen(filename, "r");
  if(fp == NULL){
    printf("Archivo no encontrado\n");
    return;
  }

  while(fgets(*line, 256, fp) != NULL){ 
    strcpy(cpu->code_memory->operator, strtok(line, " "));
    cpu->code_memory->operand1 = strtok(NULL, " ")[0];
  }

  fclose(fp);

  
}

void update_flags(processor *cpu, int result);

void alu_and_control_unity(processor *cpu);

void print(processor *cpu);

void fprint(processor *cpu);