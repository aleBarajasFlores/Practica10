#ifndef PROCESADOR_H
#define PROCESADOR_H
#include <stdbool.h>

#define MEM_SIZE 256
#define MAX_INSTRUCTIONS 100
#define NUM_REGISTERS 2
#define NUM_FLAGS 2

#define ZF 0
#define NF 1

typedef struct {
  char operator[6];
  char operand1;
  int operand2;
} instruction;

typedef struct {
  int PC;
  int memory[MEM_SIZE];
  int registers[NUM_REGISTERS];
  bool flags[NUM_FLAGS];
  instruction code_memory[MAX_INSTRUCTIONS];
} processor;

void init_processor(processor *cpu);
void load_program(processor *cpu, const char *filename);
void update_flags(processor *cpu, int result);
void alu_and_control_unity(processor *cpu);
void print(processor *cpu);
void fprint(processor *cpu);

#endif