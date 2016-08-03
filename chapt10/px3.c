/*
 * Demonstrate union and bit-field usage
 *
 * Chunis Deng @ 2009.11.28
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned dst_reg	:3;
	unsigned dst_mode	:3;
	unsigned opcode		:10;
} SGL_OP;

typedef struct {
	unsigned dst_reg	:3;
	unsigned dst_mode	:3;
	unsigned src_reg	:3;
	unsigned src_mode	:3;
	unsigned opcode		:4;
} DBL_OP;

typedef struct {
	unsigned offset		:8;
	unsigned opcode		:8;
} BRANCH;

typedef struct {
	unsigned dst_reg	:3;
	unsigned dst_mode	:3;
	unsigned src_reg	:3;
	unsigned opcode		:7;
} REG_SRC;

typedef struct {
	unsigned opcode		:16;
} MISC;

typedef union {
	unsigned short addr;
	SGL_OP sgl_op;
	DBL_OP dbl_op;
	BRANCH branch;
	REG_SRC reg_src;
	MISC misc;
} machine_inst;


int main(int argc, char *argv[])
{
	machine_inst x;

	x.addr = 0b0110100100111001;

	// 0-15 = 0x6939
	printf("x.addr: 0x%x\n", x.addr);

	// 0-15 = 0x6939
	printf("x.misc.opcode: 0x%x\n", x.misc.opcode);

	// 8-15 = 0b01101001 = 0x69
	printf("x.branch.opcode: 0x%x\n", x.branch.opcode);

	// 3-5 = 0b111 = 0x7
	printf("x.sgl_op.dst_mode: 0x%x\n", x.sgl_op.dst_mode);

	// 6-8 = 0b100 = 0x4
	printf("x.reg_src.src_reg: 0x%x\n", x.reg_src.src_reg);

	// 12-15 = 0b0110 = 0x6
	printf("x.dbl_op.opcode: 0x%x\n", x.dbl_op.opcode);

	return 0;
}

