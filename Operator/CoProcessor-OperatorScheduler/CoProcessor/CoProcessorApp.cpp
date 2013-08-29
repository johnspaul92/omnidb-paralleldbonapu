#include "CPU_Dll.h"
#include "SingularThreadOp.h"
#include "CoProcessorTest.h"
#include <iostream>
#include "HandShaking.h"
using namespace std;
double evalautedQuery=0;
double Query_UpCPUBurden=0;
double Query_LoCPUBurden=0;
double Query_UpGPUBurden=0;
double Query_LoGPUBurden=0;
double Query_LothresholdForGPUApp=0;
double Query_LothresholdForCPUApp=0;
double Query_SpeedupGPUOverCPU[12];
double RunInCPU[12];
double RunInGPU[12];

double Query_CPUBurden=0;
double Query_GPUBurden=0;
CRITICAL_SECTION OP_GPUBurdenCS;
CRITICAL_SECTION OP_CPUBurdenCS;
CRITICAL_SECTION preEMCS;


const int numQueries=30;//->corresponding to numOfThread for K_schedule
const int numThread=4;//this is fixed to 1 for Q and O schedule
int OP_rLen=2*1024*1024;
FILE *OP_ofp;
int main(int argc, char **argv)
{
	EngineStart(0,0);
	printf("Now start handshaking, please wait!\n");
	HandShake();
	printf("handshaking finished!\n\n\n");
	restore();
	InitializeCriticalSection(&(OP_GPUBurdenCS));
	InitializeCriticalSection(&(OP_CPUBurdenCS));
	InitializeCriticalSection(&(preEMCS));
	int choice;
	QUERY_TYPE qt;
	initDB2("RS.conf",TEST_MAX);
	QUERY_TYPE qT1=Q_RANGE_SELECTION;
	QUERY_TYPE qT2=Q_HJ;
	char outputFilename[50];
	sprintf(outputFilename, "./Output/O_level_Time.tony",numThread,numQueries);
	OP_ofp = fopen(outputFilename, "w");
	testQueryProcessor(qT1,qT2,numQueries,numThread);	
	EngineStop();
	fclose(OP_ofp);
	DeleteCriticalSection(&(OP_GPUBurdenCS));
	DeleteCriticalSection(&(OP_CPUBurdenCS));
	DeleteCriticalSection(&(preEMCS));
	return 0;
}