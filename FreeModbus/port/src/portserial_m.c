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
//		 * 关于串口波特率计算的问题
//		 * BRR = ((SYS_CLK/4)/(BaudRate*8))-1
//		 */
//		USHORT BaudRate_Reg_temp;
//		(void)ucPORT;  //不修改串口号
//		(void)ucDataBits;  //不修改数据位长度
//		(void)eParity;  //不修改检验格式
//		//(void)ulBaudRate;
//		BaudRate_Reg_temp = (USHORT)((150000000/(4*8*ulBaudRate))-1);
//		InitScibGpio();//使用串口3作为freemodbus的串口
//		EALLOW;
//			SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 1;//使能时钟
//		EDIS;
//		ScibRegs.SCICCR.bit.ADDRIDLE_MODE = 0;//选择通信协议，选择空闲模式，此模式兼容RS232协议
//		ScibRegs.SCICCR.bit.LOOPBKENA = 0;//自测试模式使能位:为1使能，为0禁用
//		ScibRegs.SCICCR.bit.PARITY = 0;//奇偶校验位选择位:0为奇校验，1为偶校验
//		ScibRegs.SCICCR.bit.PARITYENA = 0;//奇偶校验位使能:为1使能，为0禁用
//		ScibRegs.SCICCR.bit.SCICHAR = 7;//该配置选择SCI的一个字符的长度可配置为1到8位(单位bit)
//		ScibRegs.SCICCR.bit.STOPBITS = 0;//停止位的配置: 0 1位停止位  1 2位停止位
//		//SCIB控制寄存器的配置
//		ScibRegs.SCICTL1.bit.RXENA = 1;//SCI接收器使能位
//		ScibRegs.SCICTL1.bit.RXERRINTENA = 0;//SCI接受中断错误使能
//		ScibRegs.SCICTL1.bit.SLEEP = 0;//睡眠模式使能位
//		ScibRegs.SCICTL1.bit.SWRESET = 0;//SCI软件复位
//		ScibRegs.SCICTL1.bit.TXENA = 1;//SCI发送器使能位
//		ScibRegs.SCICTL1.bit.TXWAKE = 0;//SCI发送器唤醒模式选择位，具体的不是太明白
//		//-------------------------------------------------------------------
//		ScibRegs.SCICTL2.bit.RXBKINTENA = 0;//接收中断使能
//		ScibRegs.SCICTL2.bit.TXINTENA = 0;
//		//波特率计算
//		//9600
//		//ScibRegs.SCIHBAUD = 0x01;
//		//ScibRegs.SCILBAUD = 0xE7;
//		ScibRegs.SCIHBAUD = (BaudRate_Reg_temp>>8)&0xFF;
//		ScibRegs.SCILBAUD = BaudRate_Reg_temp&0xFF;
//		ScibRegs.SCICTL1.bit.SWRESET = 1;
//		//以下代码是配置SCIB的接收数据的FIFO和发送数据的FIFO
//		//-------------------接收数据的FIFO配置
//		ScibRegs.SCIFFTX.bit.SCIRST = 0;//复位SCIC模块
//		ScibRegs.SCIFFTX.bit.SCIRST = 1;//复位SCIC模块
//		ScibRegs.SCIFFTX.bit.SCIFFENA = 1;//使能FIFO功能
//		ScibRegs.SCIFFRX.bit.RXFFIENA = 1;//使能接收中断
//		ScibRegs.SCIFFRX.bit.RXFIFORESET = 0;//复位接收器的FIFO
//		ScibRegs.SCIFFRX.bit.RXFIFORESET = 1;
//		ScibRegs.SCIFFRX.bit.RXFFIL = 0x01;//接受1个字节之后产生一个中断
//		//---------------------发送数据的FIFO配置
//		ScibRegs.SCIFFTX.bit.SCIRST = 0;
//		ScibRegs.SCIFFTX.bit.SCIRST = 1;
//		ScibRegs.SCIFFTX.bit.SCIFFENA = 1;
//		ScibRegs.SCIFFTX.bit.TXFFIENA = 1;
//		ScibRegs.SCIFFTX.bit.TXFIFOXRESET=0;
//		ScibRegs.SCIFFTX.bit.TXFIFOXRESET=1;
//		ScibRegs.SCIFFTX.bit.TXFFIL = 0x01;//发送完一个字节产生中断

    return TRUE;
}

void vMBMasterPortSerialEnable(BOOL xRxEnable, BOOL xTxEnable)
{

	if (xRxEnable)  //接收使能
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx5 = 1;//SCI_C_Rx

		//接收
#if USER_RS485_Port
		RS485_Pin = RX_EN;
#endif
	}
	else  //失能
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx5 = 0;//SCI_C_Rx
		//恢复发送
#if USER_RS485_Port
		RS485_Pin = TX_EN;
#endif
	}

	if (xTxEnable)  //发送使能
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx6 = 1;//SCI_C_Tx
#if USER_RS485_Port
		RS485_Pin = TX_EN;
#endif
	}
	else  //失能
	{
		PieCtrlRegs.PIEACK.bit.ACK8 =1;
		PieCtrlRegs.PIEIER8.bit.INTx6 = 0;//SCI_C_Tx
#if USER_RS485_Port
		RS485_Pin = RX_EN;
#endif
	}
}

/*******************************************************************************
* @Name   : SCIC中断服务函数
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
	 //发送一个字节
	ScicRegs.SCITXBUF = ucByte;
	return TRUE;
}

BOOL xMBMasterPortSerialGetByte(CHAR * pucByte)
{
	*pucByte= ScicRegs.SCIRXBUF.bit.RXDT;
	return TRUE;
}
