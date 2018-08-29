
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
//	  //使能时钟
//		temp1 = usTimeOut50us*50;
//			EALLOW;
//			 SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 1; // CPU Timer2
//			 EDIS;
//		    /**--------以下代码是初始化CPU定时器0---------**/
//		    InitCpuTimers();  //初始化CPU定时器
//		#if CPU_FRQ_150MHZ
//		    ConfigCpuTimer(&CpuTimer1,150,temp1);//1.2ms的周期
//		#endif
//		    CpuTimer1Regs.TCR.bit.FREE = 0x01;//仿真控制位，当仿真暂停时，定时器的工作状态
//		    CpuTimer1Regs.TCR.bit.SOFT = 0x00;//FREE和SOFT位配置仿真控制
//		    CpuTimer1Regs.TCR.bit.TRB  = 0x01;//定时器重新装载位,写1表示将发生预分频寄存器和周期寄存器重新装载事件
//		    CpuTimer1Regs.TCR.bit.TIF  = 0x01;//清除中断标志位
//		    CpuTimer1Regs.TCR.bit.TIE  = 0x01;//使能定时器中断
//		    CpuTimer1Regs.TCR.bit.TSS  = 0x01;//定时器的启动和停止位，写1停止定时器，写0启动定时器
//		    CpuTimer1Regs.TIM.all      = 0;   //计数器清零
		return TRUE;
}

void vMBMasterPortTimersEnable()
{
//    /* Set current timer mode, don't change it.*/
//       vMBMasterSetCurTimerMode(MB_TMODE_T35);
//	   CpuTimer1Regs.TIM.all      = 0;   //计数器清零
//	   CpuTimer1Regs.TCR.bit.TIF  = 0x01;//清除中断标志位
//	   CpuTimer1Regs.TCR.bit.TIE  = 0x01;//使能定时器中断
//	   ReloadCpuTimer1();
//	   StartCpuTimer1();
//	  // PieCtrlRegs.PIEIER1.bit.INTx7 = 1;//使能CPU定时器0的中断
	   PieCtrlRegs.PIEACK.bit.ACK1 = 1;
	   CpuTimer0Regs.TIM.all      = 0;   //计数器清零
	   CpuTimer0Regs.TCR.bit.TIF  = 0x01;//清除中断标志位
	   CpuTimer0Regs.TCR.bit.TIE  = 0x01;//使能定时器中断
	   ReloadCpuTimer0();
	   StartCpuTimer0();
}

void vMBMasterPortTimersDisable(void)
{
    /* Disable any pending timers. */
//
//	CpuTimer1Regs.TCR.bit.TIE  = 0;//使能定时器中断
//	CpuTimer1Regs.TIM.all      = 0;   //计数器清零
//	CpuTimer1Regs.TCR.bit.TIF  = 1;//清除中断标志位
//	StopCpuTimer1();
	CpuTimer0Regs.TCR.bit.TIE  = 0;//使能定时器中断
	CpuTimer0Regs.TIM.all      = 0;   //计数器清零
	CpuTimer0Regs.TCR.bit.TIF  = 1;//清除中断标志位
	StopCpuTimer0();
}

//__interrupt void cpu_timer1_isr(void)
//{
//	prvvMasterTIMERExpiredISR();
//	  CpuTimer1Regs.TCR.bit.TIF  = 0x01;//清除中断标志位
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
	   CpuTimer1Regs.TIM.all      = 0;   //计数器清零
	   CpuTimer1Regs.TCR.bit.TIF  = 0x01;//清除中断标志位
	   CpuTimer1Regs.TCR.bit.TIE  = 0x01;//使能定时器中断
	   ReloadCpuTimer0();
	   StartCpuTimer0();
}

void vMBMasterPortTimersRespondTimeoutEnable()
{
//    rt_tick_t timer_tick = MB_MASTER_TIMEOUT_MS_RESPOND * RT_TICK_PER_SECOND / 1000;

    /* Set current timer mode, don't change it.*/
    vMBMasterSetCurTimerMode(MB_TMODE_RESPOND_TIMEOUT);
	   CpuTimer1Regs.TIM.all      = 0;   //计数器清零
	   CpuTimer1Regs.TCR.bit.TIF  = 0x01;//清除中断标志位
	   CpuTimer1Regs.TCR.bit.TIE  = 0x01;//使能定时器中断
	   ReloadCpuTimer0();
	   StartCpuTimer0();
}
