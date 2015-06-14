enum{
	PHYSICAL_VIRTUAL,
	READ_PHYSICAL,
	READ_PHYSICAL_8,
	READ_PHYSICAL_32,
	READ_PHYSICAL_64,
	READ_REGISTER_64,
	GET_MEMORYSIZE_64,
	PAUSE_VM,
	RESUME_VM,
	SEARCH_MEMORY,
	CLEAR_BP,
	SET_BP,
	VIRTUAL_PHYSICAL,
};

enum{
	RAX_REGISTER,
	RBX_REGISTER,
	RCX_REGISTER,
	RDX_REGISTER,
	R8_REGISTER,
	R9_REGISTER,
	R10_REGISTER,
	R11_REGISTER,
	R12_REGISTER,
	R13_REGISTER,
	R14_REGISTER,
	R15_REGISTER,
	RSP_REGISTER,
	RBP_REGISTER,
	RSI_REGISTER,
	RDI_REGISTER,
	RIP_REGISTER,
	DR0_REGISTER,
	DR1_REGISTER,
	DR2_REGISTER,
	DR3_REGISTER,
	DR6_REGISTER,
	DR7_REGISTER,
	CR3_REGISTER,
	CS_REGISTER,
	DS_REGISTER,
	ES_REGISTER,
	FS_REGISTER,
	GS_REGISTER,
	SS_REGISTER,
	RFLAGS_REGISTER
};


uint64_t FDP_readRegister(HANDLE toVMPipe, uint8_t registerId);
uint8_t FDP_pause(HANDLE toVMPipe);
uint8_t FDP_resume(HANDLE toVMPipe);
uint64_t FDP_searchMemory(uint8_t *patternData, uint64_t patternSize, uint64_t startOffset, HANDLE toVMPipe);

bool FDP_clearBP(uint8_t breakPointId, HANDLE toVMPipe);
bool FDP_setBP(uint8_t breakPointId, uint64_t breakAddress, HANDLE toVMPipe);

uint64_t FDP_physical_virtual(uint64_t physical_addr, HANDLE toVMPipe);
uint64_t FDP_virtual_physical(uint64_t virtual_addr, HANDLE toVMPipe);