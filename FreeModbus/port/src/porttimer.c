//��ʱ�����ò�����غ���,��Ҫ����20KHz��ʱ���ź�
/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
USHORT temp;

/* ----------------------- static functions ---------------------------------*/
void prvvTIMERExpiredISR( void );

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBPortTimersInit( USHORT usTim1Timerout50us )
{
	    //ʹ��ʱ��
	temp = usTim1Timerout50us*50;
		EALLOW;
		 SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 1; // CPU Timer2
		 EDIS;
	    /**--------���´����ǳ�ʼ��CPU��ʱ��0---------**/
	    InitCpuTimers();//��ʼ��CPU��ʱ��
	#if CPU_FRQ_150MHZ
	    ConfigCpuTimer(&CpuTimer0,150,temp);//1.2ms������
	#endif
	    CpuTimer0Regs.TCR.bit.FREE = 0x01;//�������λ����������ͣʱ����ʱ���Ĺ���״̬
	    CpuTimer0Regs.TCR.bit.SOFT = 0x00;//FREE��SOFTλ���÷������
	    CpuTimer0Regs.TCR.bit.TRB  = 0x01;//��ʱ������װ��λ,д1��ʾ������Ԥ��Ƶ�Ĵ��������ڼĴ�������װ���¼�
	    CpuTimer0Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
	    CpuTimer0Regs.TCR.bit.TIE  = 0x01;//ʹ�ܶ�ʱ���ж�
	    CpuTimer0Regs.TCR.bit.TSS  = 0x01;//��ʱ����������ֹͣλ��д1ֹͣ��ʱ����д0������ʱ��
	    CpuTimer0Regs.TIM.all      = 0;   //����������
	return TRUE;
}
void vMBPortTimersEnable(void)
{

   PieCtrlRegs.PIEACK.bit.ACK1 = 1;
   CpuTimer0Regs.TIM.all      = 0;   //����������
   CpuTimer0Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
   CpuTimer0Regs.TCR.bit.TIE  = 0x01;//ʹ�ܶ�ʱ���ж�
   ReloadCpuTimer0();
   StartCpuTimer0();
  // PieCtrlRegs.PIEIER1.bit.INTx7 = 1;//ʹ��CPU��ʱ��0���ж�


}

void vMBPortTimersDisable(void)
{
    /* Disable any pending timers. */

	CpuTimer0Regs.TCR.bit.TIE  = 0;//ʹ�ܶ�ʱ���ж�
	CpuTimer0Regs.TIM.all      = 0;   //����������
	CpuTimer0Regs.TCR.bit.TIF  = 1;//����жϱ�־λ
	StopCpuTimer0();
}

/* Create an ISR which is called whenever the timer has expired. This function
 * must then call pxMBPortCBTimerExpired( ) to notify the protocol stack that
 * the timer has expired.
 */
void prvvTIMERExpiredISR( void )
{
    ( void )pxMBPortCBTimerExpired(  );
}

/**
  *****************************************************************************
  * @Name   : CPU��ʱ��2�жϺ���
  *
  * @Brief  : none
  *
  * @Input  : none
  *
  * @Output : none
  *
  * @Return : none
  *****************************************************************************
**/
__interrupt void cpu_timer0_isr(void)
{
	if(Modbus_Master_Enable > 0 && Modbus_Slave_Enable < 1)
	{prvvMasterTIMERExpiredISR();}
	else
	{prvvTIMERExpiredISR();}
	  CpuTimer0Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
	PieCtrlRegs.PIEACK.bit.ACK1 = 1;
}
