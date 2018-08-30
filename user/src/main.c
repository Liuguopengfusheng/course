#include "main.h"
eMBErrorCode Code;
void Modbus_Data_Init(void);
int main(void)
{
	InitSysCtrl();
	Modbus_Data_Init();
	DINT;
	DRTM;
	InitPieCtrl();
	IER = 0x00;
	IFR = 0x00;
	InitPieVectTable();
	EALLOW;
	PieVectTable.SCIRXINTC = &serial_Rx_isr;
	PieVectTable.SCITXINTC = &serial_Tx_isr;
	PieVectTable.TINT0     = &cpu_timer0_isr;
	PieVectTable.SCIRXINTB = &Master_serial_Rx_isr;
	PieVectTable.SCITXINTB = &Master_serial_Tx_isr;
//	PieVectTable.XINT13    = &cpu_timer1_isr;
	EDIS;
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;//Ê¹ÄÜCPU¶¨Ê±Æ÷0µÄÖÐ¶Ï
	InitEnableModbus_Master_Slaver();
	IER |= M_INT8;
	IER |= M_INT1;
	IER |= M_INT13;
	IER |= M_INT9;
	EINT;
	ERTM;
	while(1)
	{
		eMBModbus_Master_Slaver_poll();
	}
}
void Modbus_Data_Init(void)
{
	int cnt;
	for(cnt = 0; cnt < REG_INPUT_NREGS;cnt++)
	{
		usRegInputBuf[cnt] = cnt;
	}
	for(cnt = 0; cnt < REG_Coils_NREGS/8;cnt++)
	{
		CoilsReg_Buf[cnt] = 0;
	}
	for(cnt = 0; cnt < REG_HOLDING_NREGS;cnt++)
	{
		usRegHoldingBuf[cnt] = cnt*10;
	}
	for(cnt = 0; cnt < REG_Discrete_NREG/8;cnt++)
	{
		DiscreteReg_Buf[cnt] = 0;
	}
}
