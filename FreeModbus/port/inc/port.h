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


//�������Ͷ���
typedef unsigned char UCHAR;
typedef char CHAR;
typedef UCHAR BOOL;
typedef unsigned short int USHORT;
typedef short int SHORT;
typedef unsigned long int ULONG;
typedef long int LONG;
//485 �ӿں궨��
//***************************************************slave*****************************************************//
#define USER_RS485_Port 1
#define RS485_Pin GpioDataRegs.GPBDAT.bit.GPIO37
//***************************************************master*****************************************************//
//#define USER_RS485_Portb 1
//#define RS485_Pinb GpioDataRegs.GPBDAT.bit.GPIO53


#define TX_EN 1
#define RX_EN 0
#define ENTER_CRITICAL_SECTION()   INTX_DISABLE()//__set_PRIMASK(1)  //�����ж�
#define EXIT_CRITICAL_SECTION()    INTX_ENABLE()//__set_PRIMASK(0)  //�����ж�
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
//����Ĵ�����ز���
#define REG_INPUT_START                          (USHORT)0x0001  //��ʼ�Ĵ���
#define REG_INPUT_NREGS                          (USHORT)40  //�Ĵ�������
//���ּĴ�����ز���
#define REG_HOLDING_START                        (USHORT)50  //���ּĴ���
#define REG_HOLDING_NREGS                        (USHORT)20  //���ּĴ�������
//��Ȧ�Ĵ�����ز���
#define REG_Coils_START                          (USHORT)80//��Ȧ�Ĵ�����ʼ��ַ
#define REG_Coils_NREGS                          (USHORT)24//��Ȧ�Ĵ�������(�����8�ı���;
//��ɢ�Ĵ�����ز���
#define REG_Discrete_START						 (USHORT)120
#define REG_Discrete_NREG						 (USHORT)32
extern USHORT usRegInputBuf[REG_INPUT_NREGS];//����Ĵ���,modbusЭ��ֻ�ܶ�ȡ�üĴ���,�����޸�
extern USHORT usRegHoldingBuf[REG_HOLDING_NREGS];//���ּĴ���,modbusЭ������޸ĸüĴ���,���ܶ�ȡ�üĴ���
extern UCHAR CoilsReg_Buf[3];//��Ȧ�Ĵ������飬�����鳤��Ϊ��Ȧ�Ĵ����ĸ�������8,���������Ϊ0,��1,�üĴ���Э��ɶ���д
extern UCHAR DiscreteReg_Buf[4];

/**********************************************Master Register Defines**********************************/
//����Ĵ�����ز���
#define M_REG_INPUT_START                          (USHORT)0x0001  //��ʼ�Ĵ���
#define M_REG_INPUT_NREGS                          (USHORT)40  //�Ĵ�������
//���ּĴ�����ز���
#define M_REG_HOLDING_START                        (USHORT)50  //���ּĴ���
#define M_REG_HOLDING_NREGS                        (USHORT)20  //���ּĴ�������
//��Ȧ�Ĵ�����ز���
#define M_REG_Coils_START                          (USHORT)80//��Ȧ�Ĵ�����ʼ��ַ
#define M_REG_Coils_NREGS                          (USHORT)24//��Ȧ�Ĵ�������(�����8�ı���;
//��ɢ�Ĵ�����ز���
#define M_REG_Discrete_START					   (USHORT)120
#define M_REG_Discrete_NREG						   (USHORT)32

/************************************************************************************************************/
extern USHORT m_usRegInputBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_INPUT_NREGS];//����Ĵ���,modbusЭ��ֻ�ܶ�ȡ�üĴ���,�����޸�
extern USHORT m_usRegHoldingBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_HOLDING_NREGS];//���ּĴ���,modbusЭ������޸ĸüĴ���,���ܶ�ȡ�üĴ���

/************************************************************************************************************
//��ɢ�Ĵ���
#if      M_REG_Discrete_NREG%8
extern UCHAR    M_DiscreteReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Discrete_NREG/8+1];
#else
extern UCHAR    M_DiscreteReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Discrete_NREG/8];
#endif
//��Ȧ�Ĵ���
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
