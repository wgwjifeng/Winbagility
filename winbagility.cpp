#include "stdafx.h"
#include "windows.h"

#include "kd.h"
#include "mmu.h"
#include "dissectors.h"
#include "utils.h"
#include "kdserver.h"
#include "kdproxy.h"

//TODO: !
void usage(){

}


//TODO: take arguments !!
int _tmain(int argc, _TCHAR* argv[]){
	char pkt[] = {
		0x30, 0x30, 0x30, 0x30, 0x02, 0x00, 0x18, 0x01, 0x00, 0x00, 0x80, 0x80, 0x2c, 0x13, 0x00, 0x00,
		0x38, 0x31, 0x00, 0x00, 0xca, 0x9c, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x8c, 0xf3, 0xfd, 0x07, 0x14, 0x60, 0xec, 0x57, 0x30, 0x00, 0x00, 0x00, 0x38, 0xf3, 0xfd, 0x07,
		0x01, 0x00, 0x00, 0x00, 0x20, 0x60, 0xec, 0x57, 0x31, 0x00, 0x05, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x05, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xf0, 0x45, 0xcf, 0x01, 0xf8, 0xff, 0xff,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x10, 0x00, 0x80, 0x1f, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	};
	ParseKDPkt((kd_packet_t*)pkt);
	system("pause");
#if 1
	//This structure contains all information needed for windbg
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

