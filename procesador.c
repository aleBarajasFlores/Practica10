#include <stdio.h>
#include "procesador.h"

//Inicializar memoria y registros en 0
void init_processor(processor *cpu){
  memset(cpu->memory, 0, sizeof(MEM_SIZE));
  memset(cpu->registers, 0, sizeof(NUM_REGISTERS));
  memset(cpu->flags, 0, sizeof(NUM_FLAGS));
  cpu->PC=0;
}

void load_program(processor *cpu, const char *filename){
  
  //Declarar varibales y abrir archivo
  char line[256];
  int c = 0;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL){
    printf("Archivo no encontrado\n");
    return;
  }

  //Leer lineas de fp y guardarlas en arreglo line hasta que se acabe el documento o el maximo de instrucciones posibles
  while(fgets(line, sizeof(line), fp) != NULL && c < MAX_INSTRUCTIONS){ 
    strcpy(cpu->code_memory[c].operator, strtok(line, " "));

    //Guardar primer operando
    char *op1 = strtok(NULL, " ");
        if (op1 != NULL) {
            cpu->code_memory[c].operand1 = op1[0];
        }

    //Guardar segundo operando
    char *op2 = strtok(NULL, " ");
        if (op2 != NULL) {
            cpu->code_memory[c].operand2 = atoi(op2);
        } else {
            cpu->code_memory[c].operand2 = 0; 
        }

    c++;
  }

  fclose(fp);
  
}

void update_flags(processor *cpu, int result);

void alu_and_control_unity(processor *cpu) {
  while (cpu->PC < MAX_INSTRUCTIONS) {
        instruction *instr = &cpu->code_memory[cpu->PC];

        if (strcmp(instr->operator, "MOV") == 0) {
            int reg_index = instr->operand1 - 'A';
            if (reg_index >= 0 && reg_index < NUM_REGISTERS) {
                cpu->registers[reg_index] = instr->operand2;
            }
        } else if (strcmp(instr->operator, "ADD") == 0) {
            int reg_index = instr->operand1 - 'A';
            if (reg_index >= 0 && reg_index < NUM_REGISTERS) {
                cpu->registers[reg_index] += instr->operand2;
            }
        } else if (strcmp(instr->operator, "SUB") == 0) {
            int reg_index = instr->operand1 - 'A';
            if (reg_index >= 0 && reg_index < NUM_REGISTERS) {
                cpu->registers[reg_index] -= instr->operand2;
            }
        }
        // Implement other operators as needed (MUL, DIV, etc.)

        // Increment the program counter
        cpu->PC++;
  }
}

void print(processor *cpu);

void fprint(processor *cpu);