/*
 * FreeModbus Libary: RT-Thread Port
 * Copyright (C) 2013 Armink <armink.ztl@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: portserial_m.c,v 1.60 2013/08/13 15:07:05 Armink add Master Functions $
 */

#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
//#include "rtdevice.h"
//#include "bsp.h"

/* ----------------------- static functions ---------------------------------*/
//static void prvvUARTTxReadyISR(void);
//static void prvvUARTRxISR(void);

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBMasterPortSerialInit(UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits,
        eMBParity eParity)
{
//    /**
//     * set 485 mode receive and transmit control IO
//     * @note MODBUS_MASTER_RT_CONTROL_PIN_INDEX need be defined by user
//     */
//	//USHORT temp;
//		/*
//		 * ���ڴ��ڲ����ʼ��������
//		 * BRR = ((SYS_CLK/4)/(BaudRate*8))-1
//		 */
//		USHORT BaudRate_Reg_temp;
//		(void)ucPORT;  //���޸Ĵ��ں�
//		(void)ucDataBits;  //���޸�����λ����
//		(void)eParity;  //���޸ļ����ʽ
//		//(void)ulBaudRate;
//		BaudRate_Reg_temp = (USHORT)((150000000/(4*8*ulBaudRate))-1);
//		InitScibGpio();//ʹ�ô���3��Ϊfreemodbus�Ĵ���
//		EALLOW;
//			SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 1;//ʹ��ʱ��
//		EDIS;
//		ScibRegs.SCICCR.bit.ADDRIDLE_MODE = 0;//ѡ��ͨ��Э�飬ѡ�����ģʽ����ģʽ����RS232Э��
//		ScibRegs.SCICCR.bit.LOOPBKENA = 0;//�Բ���ģʽʹ��λ:Ϊ1ʹ�ܣ�Ϊ0����
//		ScibRegs.SCICCR.bit.PARITY = 0;//��żУ��λѡ��λ:0Ϊ��У�飬1ΪżУ��
//		ScibRegs.SCICCR.bit.PARITYENA = 0;//��żУ��λʹ��:Ϊ1ʹ�ܣ�Ϊ0����
//		ScibRegs.SCICCR.bit.SCICHAR = 7;//������ѡ��SCI��һ���ַ��ĳ��ȿ�����Ϊ1��8λ(��λbit)
//		ScibRegs.SCICCR.bit.STOPBITS = 0;//ֹͣλ������: 0 1λֹͣλ  1 2λֹͣλ
//		//SCIB���ƼĴ���������
//		ScibRegs.SCICTL1.bit.RXENA = 1;//SCI������ʹ��λ
//		ScibRegs.SCICTL1.bit.RXERRINTENA = 0;//SCI�����жϴ���ʹ��
//		ScibRegs.SCICTL1.bit.SLEEP = 0;//˯��ģʽʹ��λ
//		ScibRegs.SCICTL1.bit.SWRESET = 0;//SCI�����λ
//		ScibRegs.SCICTL1.bit.TXENA = 1;//SCI������ʹ��λ
//		ScibRegs.SCICTL1.bit.TXWAKE = 0;//SCI����������ģʽѡ��λ������Ĳ���̫����
//		//-------------------------------------------------------------------
//		ScibRegs.SCICTL2.bit.RXBKINTENA = 0;//�����ж�ʹ��
//		ScibRegs.SCICTL2.bit.TXINTENA = 0;
//		//�����ʼ���
//		//9600
//		//ScibRegs.SCIHBAUD = 0x01;
//		//ScibRegs.SCILBAUD = 0xE7;
//		ScibRegs.SCIHBAUD = (BaudRate_Reg_temp>>8)&0xFF;
//		ScibRegs.SCILBAUD = BaudRate_Reg_temp&0xFF;
//		ScibRegs.SCICTL1.bit.SWRESET = 1;
//		//���´���������SCIB�Ľ������ݵ�FIFO�ͷ������ݵ�FIFO
//		//-------------------�������ݵ�FIFO����
//		ScibRegs.SCIFFTX.bit.SCIRST = 0;//��λSCICģ��
//		ScibRegs.SCIFFTX.bit.SCIRST = 1;//��λSCICģ��
//		ScibRegs.SCIFFTX.bit.SCIFFENA = 1;//ʹ��FIFO����
//		ScibRegs.SCIFFRX.bit.RXFFIENA = 1;//ʹ�ܽ����ж�
//		ScibRegs.SCIFFRX.bit.RXFIFORESET = 0;//��λ��������FIFO
//		ScibRegs.SCIFFRX.bit.RXFIFORESET = 1;
//		ScibRegs.SCIFFRX.bit.RXFFIL = 0x01;//����1���ֽ�֮�����һ���ж�
//		//---------------------�������ݵ�FIFO����
//		ScibRegs.SCIFFTX.bit.SCIRST = 0;
//		ScibRegs.SCIFFTX.bit.SCIRST = 1;
//		ScibRegs.SCIFFTX.bit.SCIFFENA = 1;
//		ScibRegs.SCIFFTX.bit.TXFFIENA = 1;
//		ScibRegs.SCIFFTX.bit.TXFIFOXRESET=0;
//		ScibRegs.SCIFFTX.bit.TXFIFOXRESET=1;
//		ScibRegs.SCIFFTX.bit.TXFFIL = 0x01;//������һ���ֽڲ����ж�

    return TRUE;
}

void vMBMasterPortSerialEnable(BOOL xRxEnable, BOOL xTxEnable)
{

	if (xRxEnable)  //����ʹ��
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx5 = 1;//SCI_C_Rx

		//����
#if USER_RS485_Port
		RS485_Pin = RX_EN;
#endif
	}
	else  //ʧ��
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx5 = 0;//SCI_C_Rx
		//�ָ�����
#if USER_RS485_Port
		RS485_Pin = TX_EN;
#endif
	}

	if (xTxEnable)  //����ʹ��
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx6 = 1;//SCI_C_Tx
#if USER_RS485_Port
		RS485_Pin = TX_EN;
#endif
	}
	else  //ʧ��
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx6 = 0;//SCI_C_Tx
#if USER_RS485_Port
		RS485_Pin = RX_EN;
#endif
	}
}

/*******************************************************************************
* @Name   : SCIC�жϷ�����
*
* @Brief  : none
*
* @Input  : none
*
* @Output : none
*
* @Return : none
*******************************************************************************/
__interrupt void Master_serial_Rx_isr(void)
{
	if(ScicRegs.SCIFFRX.bit.RXFFINT == 1)
	{
		pxMBMasterFrameCBByteReceived();
		ScicRegs.SCIFFRX.bit.RXFFINTCLR = 1;
		ScicRegs.SCIFFRX.bit.RXFFOVRCLR = 1;
	}
	PieCtrlRegs.PIEACK.bit.ACK8 =1;
}
__interrupt void Master_serial_Tx_isr(void)
{
	if(ScicRegs.SCIFFTX.bit.TXFFINT == 1)
	{
		pxMBMasterFrameCBTransmitterEmpty();
		ScicRegs.SCIFFTX.bit.TXFFINTCLR = 1;
	}
	PieCtrlRegs.PIEACK.bit.ACK8 = 1;
}

BOOL xMBMasterPortSerialPutByte(CHAR ucByte)
{
	 //����һ���ֽ�
	ScicRegs.SCITXBUF = ucByte;
	return TRUE;
}

BOOL xMBMasterPortSerialGetByte(CHAR * pucByte)
{
	*pucByte= ScicRegs.SCIRXBUF.bit.RXDT;
	return TRUE;
}
