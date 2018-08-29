#ifndef _PORT_H
#define _PORT_H


#include <inttypes.h>
#include "mbconfig.h"
//#include <assert.h>
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

#define PR_BEGIN_EXTERN_C           extern "C" {
#define	PR_END_EXTERN_C             }
#define assert(e) ((e) ? (void)0 :  1)
void __assert(const char * x1, const char * x2, int x3);


//数据类型定义
typedef unsigned char UCHAR;
typedef char CHAR;
typedef UCHAR BOOL;
typedef unsigned short int USHORT;
typedef short int SHORT;
typedef unsigned long int ULONG;
typedef long int LONG;
//485 接口宏定义
//***************************************************slave*****************************************************//
#define USER_RS485_Port 1
#define RS485_Pin GpioDataRegs.GPBDAT.bit.GPIO37
//***************************************************master*****************************************************//
//#define USER_RS485_Portb 1
//#define RS485_Pinb GpioDataRegs.GPBDAT.bit.GPIO53


#define TX_EN 1
#define RX_EN 0
#define ENTER_CRITICAL_SECTION()   INTX_DISABLE()//__set_PRIMASK(1)  //关总中断
#define EXIT_CRITICAL_SECTION()    INTX_ENABLE()//__set_PRIMASK(0)  //开总中断
#ifndef TRUE
#define TRUE            1
#endif
#ifndef FALSE
#define FALSE           0
#endif
void INTX_DISABLE(void);
void  INTX_ENABLE(void);
__interrupt void serial_Rx_isr(void);
__interrupt void serial_Tx_isr(void);
__interrupt void cpu_timer0_isr(void);

__interrupt void Master_serial_Rx_isr(void);
__interrupt void Master_serial_Tx_isr(void);
//__interrupt void cpu_timer1_isr(void);
void prvvMasterTIMERExpiredISR(void);
/**********************************************Slave Register Defines**********************************/
//输入寄存器相关参数
#define REG_INPUT_START                          (USHORT)0x0001  //起始寄存器
#define REG_INPUT_NREGS                          (USHORT)40  //寄存器个数
//保持寄存器相关参数
#define REG_HOLDING_START                        (USHORT)50  //保持寄存器
#define REG_HOLDING_NREGS                        (USHORT)20  //保持寄存器个数
//线圈寄存器相关参数
#define REG_Coils_START                          (USHORT)80//线圈寄存器起始地址
#define REG_Coils_NREGS                          (USHORT)24//线圈寄存器个数(最好是8的倍数;
//离散寄存器相关参数
#define REG_Discrete_START						 (USHORT)120
#define REG_Discrete_NREG						 (USHORT)32
extern USHORT usRegInputBuf[REG_INPUT_NREGS];//输入寄存器,modbus协议只能读取该寄存器,不能修改
extern USHORT usRegHoldingBuf[REG_HOLDING_NREGS];//保持寄存器,modbus协议既能修改该寄存器,又能读取该寄存器
extern UCHAR CoilsReg_Buf[3];//线圈寄存器数组，该数组长度为线圈寄存器的个数除以8,如果余数不为0,加1,该寄存器协议可读可写
extern UCHAR DiscreteReg_Buf[4];

/**********************************************Master Register Defines**********************************/
//输入寄存器相关参数
#define M_REG_INPUT_START                          (USHORT)0x0001  //起始寄存器
#define M_REG_INPUT_NREGS                          (USHORT)40  //寄存器个数
//保持寄存器相关参数
#define M_REG_HOLDING_START                        (USHORT)50  //保持寄存器
#define M_REG_HOLDING_NREGS                        (USHORT)20  //保持寄存器个数
//线圈寄存器相关参数
#define M_REG_Coils_START                          (USHORT)80//线圈寄存器起始地址
#define M_REG_Coils_NREGS                          (USHORT)24//线圈寄存器个数(最好是8的倍数;
//离散寄存器相关参数
#define M_REG_Discrete_START					   (USHORT)120
#define M_REG_Discrete_NREG						   (USHORT)32

/************************************************************************************************************/
extern USHORT m_usRegInputBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_INPUT_NREGS];//输入寄存器,modbus协议只能读取该寄存器,不能修改
extern USHORT m_usRegHoldingBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_HOLDING_NREGS];//保持寄存器,modbus协议既能修改该寄存器,又能读取该寄存器

/************************************************************************************************************
//离散寄存器
#if      M_REG_Discrete_NREG%8
extern UCHAR    M_DiscreteReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Discrete_NREG/8+1];
#else
extern UCHAR    M_DiscreteReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Discrete_NREG/8];
#endif
//线圈寄存器
#if      M_REG_Coils_NREGS%8
extern UCHAR    M_CoilsReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Coils_NREGS/8+1];
#else
extern UCHAR    M_CoilsReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Coils_NREGS/8];
#endif
*********************************************************************************************************************/


/* master mode: holding register's all address */
#define          M_HD_RESERVE                     0
/* master mode: input register's all address */
#define          M_IN_RESERVE                     0
/* master mode: coil's all address */
#define          M_CO_RESERVE                     0
/* master mode: discrete's all address */
#define          M_DI_RESERVE                     0

#endif
