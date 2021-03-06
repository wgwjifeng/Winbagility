#include "stdafx.h"
#include "windows.h"

#include "kd.h"
#include "mmu.h"
#include "dissectors.h"
#include "utils.h"
#include "kdserver.h"
#include "kdproxy.h"
#include "FDP.h"

//TODO: !
void usage(){

}

void testFDP(){
	HANDLE toVMPipe;
	OpenNamedPipe(&toVMPipe, "\\\\.\\pipe\\debugger");

	FDP_pause(toVMPipe);

	//FDP_clearBP(0, toVMPipe);
	printf("%p\n", FDP_virtual_physical(0xFFFFF801CF45F0e4, toVMPipe));

	FDP_resume(toVMPipe);
}


//TODO: take arguments !!
int _tmain(int argc, _TCHAR* argv[]){

	//testFDP();
	//system("pause");
	//return 0;

	/*char pkt[] = {
		0x30, 0x30, 0x30, 0x30, 0x02, 0x00, 0x43, 0x00, 0x01, 0x00, 0x80, 0x80, 0x32, 0x12, 0x00, 0x00,
		0x56, 0x31, 0x00, 0x00, 0x8d, 0x3d, 0x42, 0x2d, 0x03, 0x01, 0x00, 0x00, 0xa7, 0xff, 0x00, 0x5c,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff,
		0x0b, 0x00, 0x00, 0x00, 0x78, 0x41, 0x0a, 0x08, 0x00, 0x00, 0x00, 0x80, 0xf8, 0xe1, 0x16, 0x08,
		0x38, 0x25, 0xe5, 0x5b, 0xe0, 0xe1, 0x16, 0x08, 0x45, 0x72, 0x72, 0x6f, 0x72, 0x3a, 0x20, 0x31,
		0x30, 0x30, 0x32,
	};
	ParseKDPkt((kd_packet_t*)pkt);
	//system("pause");*/
#if 1
	//This structure contains all information needed by windbg
	analysisContext_t curContext;

	//DEBUGGED RAW DMP
	//char fileName[] = "C:\\8_1_x64_DEBUG.dmp";
	//curContext.curMode = DEBUGGED_IMAGE_TYPE;

	//UNDEBUGGED RAW DMP
	char fileName[] = "C:\\8_1_x64_STOCK.dmp";
	curContext.curMode = STOCK_IMAGE_TYPE;

	//UNDEBUGGED WINDOWS IN FDP COMPLIANT VM
	//char fileName[] = "\\\\.\\pipe\\debugger"; //FDP named Pipe
	//curContext.curMode = STOCK_VBOX_TYPE;

	//LET'S START !!!
	curContext.dmpFileName = fileName;
	if (initKDServer(&curContext) == false){
		printf("Unable to initialize KD Server !\n");
		system("pause");
	}
	startKDServer();
#else
	//TODO ...
	startKDProxy();
#endif

	return 0;
}

