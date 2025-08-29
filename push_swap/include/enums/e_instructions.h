#ifndef E_INSTRUCTIONS_H
# define E_INSTRUCTIONS_H

enum e_instructions
{
	INST_NONE = -1,
	INST_END = 0,
	INST_SWAP_A = 1,
	INST_SWAP_B = 2,
	INST_SWAP_AB = 3,
	INST_PUSH_A = 4,
	INST_PUSH_B = 5,
	INST_ROT_A = 6,
	INST_ROT_B = 7,
	INST_ROT_AB = 8,
	INST_RROT_A = 9,
	INST_RROT_B = 10,
	INST_RROT_AB = 11,
};


#endif
