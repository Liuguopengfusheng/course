
/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
USHORT temp1;
/* ----------------------- static functions ---------------------------------*/
void prvvMasterTIMERExpiredISR(void);

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBMasterPortTimersInit(USHORT usTimeOut50us)
{
//	  //ʹ��ʱ��
//		temp1 = usTimeOut50us*50;
//			EALLOW;
//			 SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 1; // CPU Timer2
//			 EDIS;
//		    /**--------���´����ǳ�ʼ��CPU��ʱ��0---------**/
//		    InitCpuTimers();  //��ʼ��CPU��ʱ��
//		#if CPU_FRQ_150MHZ
//		    ConfigCpuTimer(&CpuTimer1,150,temp1);//1.2ms������
//		#endif
//		    CpuTimer1Regs.TCR.bit.FREE = 0x01;//�������λ����������ͣʱ����ʱ���Ĺ���״̬
//		    CpuTimer1Regs.TCR.bit.SOFT = 0x00;//FREE��SOFTλ���÷������
//		    CpuTimer1Regs.TCR.bit.TRB  = 0x01;//��ʱ������װ��λ,д1��ʾ������Ԥ��Ƶ�Ĵ��������ڼĴ�������װ���¼�
//		    CpuTimer1Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
//		    CpuTimer1Regs.TCR.bit.TIE  = 0x01;//ʹ�ܶ�ʱ���ж�
//		    CpuTimer1Regs.TCR.bit.TSS  = 0x01;//��ʱ����������ֹͣλ��д1ֹͣ��ʱ����д0������ʱ��
//		    CpuTimer1Regs.TIM.all      = 0;   //����������
		return TRUE;
}

void vMBMasterPortTimersEnable()
{
//    /* Set current timer mode, don't change it.*/
//       vMBMasterSetCurTimerMode(MB_TMODE_T35);
//	   CpuTimer1Regs.TIM.all      = 0;   //����������
//	   CpuTimer1Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
//	   CpuTimer1Regs.TCR.bit.TIE  = 0x01;//ʹ�ܶ�ʱ���ж�
//	   ReloadCpuTimer1();
//	   StartCpuTimer1();
//	  // PieCtrlRegs.PIEIER1.bit.INTx7 = 1;//ʹ��CPU��ʱ��0���ж�
	   PieCtrlRegs.PIEACK.bit.ACK1 = 1;
	   CpuTimer0Regs.TIM.all      = 0;   //����������
	   CpuTimer0Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
	   CpuTimer0Regs.TCR.bit.TIE  = 0x01;//ʹ�ܶ�ʱ���ж�
	   ReloadCpuTimer0();
	   StartCpuTimer0();
}

void vMBMasterPortTimersDisable(void)
{
    /* Disable any pending timers. */
//
//	CpuTimer1Regs.TCR.bit.TIE  = 0;//ʹ�ܶ�ʱ���ж�
//	CpuTimer1Regs.TIM.all      = 0;   //����������
//	CpuTimer1Regs.TCR.bit.TIF  = 1;//����жϱ�־λ
//	StopCpuTimer1();
	CpuTimer0Regs.TCR.bit.TIE  = 0;//ʹ�ܶ�ʱ���ж�
	CpuTimer0Regs.TIM.all      = 0;   //����������
	CpuTimer0Regs.TCR.bit.TIF  = 1;//����жϱ�־λ
	StopCpuTimer0();
}

//__interrupt void cpu_timer1_isr(void)
//{
//	prvvMasterTIMERExpiredISR();
//	  CpuTimer1Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
//	EDIS;
//}

void prvvMasterTIMERExpiredISR(void)
{
    (void) pxMBMasterPortCBTimerExpired();
}



void vMBMasterPortTimersConvertDelayEnable()
{
 //   rt_tick_t timer_tick = MB_MASTER_DELAY_MS_CONVERT * RT_TICK_PER_SECOND / 1000;

    /* Set current timer mode, don't change it.*/
    vMBMasterSetCurTimerMode(MB_TMODE_CONVERT_DELAY);
	   CpuTimer1Regs.TIM.all      = 0;   //����������
	   CpuTimer1Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
	   CpuTimer1Regs.TCR.bit.TIE  = 0x01;//ʹ�ܶ�ʱ���ж�
	   ReloadCpuTimer0();
	   StartCpuTimer0();
}

void vMBMasterPortTimersRespondTimeoutEnable()
{
//    rt_tick_t timer_tick = MB_MASTER_TIMEOUT_MS_RESPOND * RT_TICK_PER_SECOND / 1000;

    /* Set current timer mode, don't change it.*/
    vMBMasterSetCurTimerMode(MB_TMODE_RESPOND_TIMEOUT);
	   CpuTimer1Regs.TIM.all      = 0;   //����������
	   CpuTimer1Regs.TCR.bit.TIF  = 0x01;//����жϱ�־λ
	   CpuTimer1Regs.TCR.bit.TIE  = 0x01;//ʹ�ܶ�ʱ���ж�
	   ReloadCpuTimer0();
	   StartCpuTimer0();
}
