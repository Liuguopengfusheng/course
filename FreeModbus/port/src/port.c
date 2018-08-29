#include "port.h"
#include "mb.h"
#include "mbport.h"
#include "mbutils.h"

#include "mb.h"
#include "mb_m.h"
#include "mbconfig.h"
#include "mbframe.h"
#include "mbutils.h"
/****************************************************slave*************************************************/

//输入寄存器
USHORT usRegInputStart = REG_INPUT_START;
USHORT usRegInputBuf[REG_INPUT_NREGS] = {0x00};
//保持寄存器
USHORT usRegHoldingStart = REG_HOLDING_START;
USHORT usRegHoldingBuf[REG_HOLDING_NREGS] = {0x00};
//线圈寄存器
USHORT CoilsReg_Start = REG_Coils_START;
UCHAR CoilsReg_Buf[3] = {0x00};
//离散寄存器
USHORT Discrete_Start = REG_Discrete_START;
UCHAR DiscreteReg_Buf[4];

/***********************************************************master*****************************************/
//输入寄存器
USHORT m_usRegInputStart = M_REG_INPUT_START;
USHORT m_usRegInputBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_INPUT_NREGS] = {0x00};
//保持寄存器
USHORT m_usRegHoldingStart = M_REG_HOLDING_START;
USHORT m_usRegHoldingBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_HOLDING_NREGS] = {0x00};
//离散寄存器
USHORT   M_Discrete_Start                             = M_REG_Discrete_START;
//#if      M_REG_Discrete_NREG%8
//UCHAR    M_DiscreteReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Discrete_NREG/8+1];
//#else
UCHAR    M_DiscreteReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Discrete_NREG/8];
//#endif
//线圈寄存器
USHORT   M_CoilsReg_Start = M_REG_Coils_START;
//#if      M_REG_Coils_NREGS%8
//UCHAR    M_CoilsReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Coils_NREGS/8+1];
//#else
UCHAR    M_CoilsReg_Buf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_Coils_NREGS/8];
//#endif




void __assert(const char * x1, const char * x2, int x3)
{
	(void)x3;
}
//以下代码是关于全局中断使能和关闭
void EnterCriticalSection(  )//关闭全局中断
{
	//__ASM volatile("cpsid i");
	asm(" setc DBGM");
	asm(" setc INTM");
}

void ExitCriticalSection(  )//使能全局中断
{
   // __ASM volatile("cpsie i");
	asm(" clrc INTM");
	asm(" clrc DBGM");
}
void INTX_DISABLE(void)
{
	asm(" setc DBGM");
 	asm(" setc INTM");
}
void  INTX_ENABLE(void)
{
	asm(" clrc INTM");
	asm(" clrc DBGM");
}

/*********************************************Main Control*****************************************/
void InitEnableModbus_Master_Slaver()//初始化主机(从机),使能主机(从机)
{
//if (Modbus_Slave_Enable > 0 && Modbus_Master_Enable < 1)
	{eMBInit(MB_RTU, 0x01, 1, 115200, MB_PAR_NONE);
	eMBEnable();
	}

//if (Modbus_Master_Enable > 0 && Modbus_Slave_Enable < 1)
	{eMBMasterInit(MB_RTU, 1, 115200, MB_PAR_NONE);
	eMBMasterEnable();}

}

void eMBModbus_Master_Slaver_poll()//主机(从机)轮询
{
if (Modbus_Master_Enable > 0 && Modbus_Slave_Enable < 1)
{
	int r,t,k;
	EALLOW;
	PieVectTable.SCIRXINTC = &Master_serial_Rx_isr;
	PieVectTable.SCITXINTC = &Master_serial_Tx_isr;
	EDIS;
      for(r=0;r<10000;r++)
      {
    	  for(k=0;k<1000;k++);
      }
	    eMBMasterReqReadInputRegister( 1, 0x0001, 5, 3 );//功能码04,读取输入
	    for(t=0;t<3;t++)
	    {
		eMBMasterPoll();
	    }
}
if (Modbus_Slave_Enable > 0 && Modbus_Master_Enable < 1)
		 {
//	eMBMasterDisable();
//	vMBPortSerialEnable( TRUE, FALSE );
	EALLOW;
	PieVectTable.SCIRXINTC = &serial_Rx_isr;
	PieVectTable.SCITXINTC = &serial_Tx_isr;
	EDIS;
	eMBPoll();}

}
/********************************************************************************************************/





/********************************************************************************************************************
 experssion: Modbus 从机操作寄存器
 name      : 操作输入寄存器    对应功能码   0x04 -> eMBFuncReadInputRegister
           : 操作保持寄存器    对应功能码   0x06 -> eMBFuncWriteHoldingRegister
                                       0x16 -> eMBFuncWriteMultipleHoldingRegister
                                       0x03 -> eMBFuncReadHoldingRegister
                                       0x23 -> eMBFuncReadWriteMultipleHoldingRegister
           : 操作线圈               对应功能码   0x01 -> eMBFuncReadCoils
                                       0x05 -> 写单个线圈 eMBFuncWriteCoil
                                       0x15 -> 写多个线圈 eMBFuncWriteMultipleCoils
           : 操作离散寄存器   对应功能码    0x02 -> eMBFuncReadDiscreteInputs

********************************************************************************************************************/


/*******************************************************************************
* @Name   : 操作输入寄存器
*
* @Brief  : 对应功能码0x04 -> eMBFuncReadInputRegister
*
* @Input  : *pucRegBuffer：数据缓冲区，响应主机用
*           usAddress:     寄存器地址
*           usNRegs:       操作寄存器个数
*
* @Output : none
*
* @Return : Modbus状态信息
*******************************************************************************/
eMBErrorCode eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
	eMBErrorCode eStatus = MB_ENOERR;
	int          iRegIndex = 0;
	
	//
	//判断地址合法性
	//
	if ((usAddress >= REG_INPUT_START) && (usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS))
	{
		iRegIndex = (int)(usAddress - usRegInputStart);
		while (usNRegs > 0)
		{
			*pucRegBuffer++ = (UCHAR)( usRegInputBuf[iRegIndex] >> 8);  //高8位字节
			*pucRegBuffer++ = (UCHAR)( usRegInputBuf[iRegIndex] & 0xFF); //低8位字节
			iRegIndex++;
			usNRegs--;
		}
	}
	else  //错误地址
	{
		eStatus = MB_ENOREG;
	}
	
	return eStatus;
}

/**
  *****************************************************************************
  * @Name   : 操作保持寄存器
  *
  * @Brief  : 对应功能码0x06 -> eMBFuncWriteHoldingRegister
  *                    0x16 -> eMBFuncWriteMultipleHoldingRegister
  *                    0x03 -> eMBFuncReadHoldingRegister
  *                    0x23 -> eMBFuncReadWriteMultipleHoldingRegister
  *
  * @Input  : *pucRegBuffer：数据缓冲区，响应主机用
  *           usAddress:     寄存器地址
  *           usNRegs:       操作寄存器个数
  *           eMode:         功能码
  *
  * @Output : none
  *
  * @Return : Modbus状态信息
  *****************************************************************************
**/
eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
	eMBErrorCode eStatus = MB_ENOERR;
	int          iRegIndex = 0;
	//
	//判断地址是否合法
	//
	if((usAddress >= REG_HOLDING_START) && ((usAddress + usNRegs) <= (REG_HOLDING_START + REG_HOLDING_NREGS)))
	{
		iRegIndex = (int)(usAddress - usRegHoldingStart);
		//
		//根据功能码进行操作
		//
		switch(eMode)
		{
			case MB_REG_READ:  //读保持寄存器  功能码03
					while(usNRegs > 0)
					{
						*pucRegBuffer++ = (UCHAR)(usRegHoldingBuf[iRegIndex] >> 8);  //高8位字节
						*pucRegBuffer++ = (UCHAR)(usRegHoldingBuf[iRegIndex] & 0xFF); //低8位字节
						iRegIndex++;
						usNRegs--;
					}                            
					break;
					
			case MB_REG_WRITE:  //写保持寄存器  功能码06
					while(usNRegs > 0)
					{
						usRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;  //高8位字节
						usRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;  //低8位字节
						iRegIndex++;
						usNRegs--;
					}
					break;
		}
	}
	else  //错误地址
	{
		eStatus = MB_ENOREG;
	}
	
	return eStatus;
}

/**
  *****************************************************************************
  * @Name   : 操作线圈
  *
  * @Brief  : 对应功能码0x01 -> eMBFuncReadCoils
  *                    0x05 ->写单个线圈 eMBFuncWriteCoil
  *                    0x15 -> 写多个线圈 eMBFuncWriteMultipleCoils
  *
  * @Input  : *pucRegBuffer：数据缓冲区，响应主机用
  *           usAddress:     寄存器地址
  *           usNRegs:       操作寄存器个数
  *           eMode:         功能码
  *
  * @Output : none
  *
  * @Return : Modbus状态信息
  *****************************************************************************
**/
eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{
 eMBErrorCode    eStatus = MB_ENOERR;
    short           iNCoils = ( short )usNCoils;
    unsigned short  usBitOffset;

    /* Check if we have registers mapped at this block. */
    if( ( usAddress >= REG_Coils_START ) &&
        ( usAddress + usNCoils <= REG_Coils_START + REG_Coils_NREGS ) )
    {
        usBitOffset = ( unsigned short )( usAddress - REG_Coils_START );
        switch ( eMode )
        {
                /* Read current values and pass to protocol stack. */
            case MB_REG_READ:
                while( iNCoils > 0 )
                {
                    *pucRegBuffer++ =
                        xMBUtilGetBits( CoilsReg_Buf, usBitOffset, ( unsigned char )( iNCoils > 8 ? 8 : iNCoils ) );
                    iNCoils -= 8;
                    usBitOffset += 8;
                }
                break;

                /* Update current register values. */
            case MB_REG_WRITE:
                while( iNCoils > 0 )
                {
                    xMBUtilSetBits( CoilsReg_Buf, usBitOffset,
                                    ( unsigned char )( iNCoils > 8 ? 8 : iNCoils ),
                                    *pucRegBuffer++ );
                    iNCoils -= 8;
                }
                break;
        }

    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}

/*******************************************************************************
* @Name   : 操作离散寄存器
*
* @Brief  : 对应功能码0x02 -> eMBFuncReadDiscreteInputs
*
* @Input  : *pucRegBuffer：数据缓冲区，响应主机用
*           usAddress:     寄存器地址
*           usNRegs:       操作寄存器个数
*
* @Output : none
*
* @Return : Modbus状态信息
*******************************************************************************/
eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
   	eMBErrorCode    eStatus = MB_ENOERR;
    short   int        iNDiscrete = ( short int)usNDiscrete;
    unsigned short int usBitOffset;
		if((usAddress >= REG_Discrete_START)&&(usAddress+usNDiscrete <= REG_Discrete_START+REG_Discrete_NREG))
		{
			  usBitOffset = ( unsigned short )( usAddress - REG_Discrete_START );
				while(iNDiscrete > 0)
				{
					 *pucRegBuffer = xMBUtilGetBits( DiscreteReg_Buf, usBitOffset,( unsigned char )(iNDiscrete > 8?8:iNDiscrete));
						iNDiscrete -= 8;
						usBitOffset += 8;
						pucRegBuffer++;
				}
		}
		else
		{
			 eStatus = MB_ENOREG;
		}
    return eStatus;
}




/************************************************************************************************************************

 experssion: Modbus 主机操作寄存器
 name      : 操作输入寄存器    对应功能码   0x04 -> eMBFuncReadInputRegister
           : 操作保持寄存器    对应功能码   0x06 -> eMBFuncWriteHoldingRegister
                                       0x16 -> eMBFuncWriteMultipleHoldingRegister
                                       0x03 -> eMBFuncReadHoldingRegister
                                       0x23 -> eMBFuncReadWriteMultipleHoldingRegister
           : 操作线圈               对应功能码   0x01 -> eMBFuncReadCoils
                                       0x05 ->写单个线圈 eMBFuncWriteCoil
                                       0x15 -> 写多个线圈 eMBFuncWriteMultipleCoils
           : 操作离散寄存器   对应功能码    0x02 -> eMBFuncReadDiscreteInputs

********************************************************************************************************************/

/************************************************操作输入寄存器*****************************************************/

eMBErrorCode eMBMasterRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    eMBErrorCode     eStatus = MB_ENOERR;
    int              iRegIndex = 0;
    USHORT *         pusRegInputBuf;
    pusRegInputBuf = m_usRegInputBuf[ucMBMasterGetDestAddress() - 1];
    /* it already plus one in modbus function method. */
    usAddress--;
    if ((usAddress >= M_REG_INPUT_START)
            && (usAddress + usNRegs <= M_REG_INPUT_START + M_REG_INPUT_NREGS))
    {
        iRegIndex = usAddress - m_usRegInputStart;
        while (usNRegs > 0)
        {
            pusRegInputBuf[iRegIndex] = *pucRegBuffer++ << 8;
            pusRegInputBuf[iRegIndex] |= *pucRegBuffer++;
            iRegIndex++;
            usNRegs--;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

/**********************************************************操作保持寄存器*****************************************/
eMBErrorCode eMBMasterRegHoldingCB(UCHAR * pucRegBuffer, USHORT usAddress,
        USHORT usNRegs, eMBRegisterMode eMode)
{
    eMBErrorCode    eStatus = MB_ENOERR;
    int             iRegIndex = 0;
    USHORT *        pusRegHoldingBuf;
    pusRegHoldingBuf = m_usRegHoldingBuf[ucMBMasterGetDestAddress() - 1];
    /* if mode is read, the master will write the received date to buffer. */

    eMode = MB_REG_WRITE;

    /* it already plus one in modbus function method. */
    usAddress--;

    if ((usAddress >= M_REG_HOLDING_START)
            && (usAddress + usNRegs <= M_REG_HOLDING_START + M_REG_HOLDING_NREGS))
    {
        iRegIndex = usAddress - m_usRegHoldingStart;
        switch (eMode)
        {
        /* read current register values from the protocol stack. */
        case MB_REG_READ:
            while (usNRegs > 0)
            {
                *pucRegBuffer++ = (UCHAR) (pusRegHoldingBuf[iRegIndex] >> 8);
                *pucRegBuffer++ = (UCHAR) (pusRegHoldingBuf[iRegIndex] & 0xFF);
                iRegIndex++;
                usNRegs--;
            }
            break;
        /* write current register values with new values from the protocol stack. */
        case MB_REG_WRITE:
            while (usNRegs > 0)
            {
                pusRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
                pusRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
                iRegIndex++;
                usNRegs--;
            }
            break;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}

/***********************************************************操作离散寄存器******************************************/

eMBErrorCode eMBMasterRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          iRegIndex , iRegBitIndex , iNReg;
    UCHAR *         pucDiscreteInputBuf;

    iNReg =  usNDiscrete / 8 + 1;
    pucDiscreteInputBuf = M_DiscreteReg_Buf[ucMBMasterGetDestAddress() - 1];

    /* it already plus one in modbus function method. */
    usAddress--;

    if ((usAddress >= M_REG_Discrete_START)
            && (usAddress + usNDiscrete    <= M_REG_Discrete_START + M_REG_Discrete_NREG))
    {
        iRegIndex = (USHORT) (usAddress - M_Discrete_Start) / 8;
        iRegBitIndex = (USHORT) (usAddress - M_Discrete_Start) % 8;

        /* write current discrete values with new values from the protocol stack. */
        while (iNReg > 1)
        {
            xMBUtilSetBits(&pucDiscreteInputBuf[iRegIndex++], iRegBitIndex, 8,
                    *pucRegBuffer++);
            iNReg--;
        }
        /* last discrete */
        usNDiscrete = usNDiscrete % 8;
        /* xMBUtilSetBits has bug when ucNBits is zero */
        if (usNDiscrete != 0)
        {
            xMBUtilSetBits(&pucDiscreteInputBuf[iRegIndex++], iRegBitIndex,
                    usNDiscrete, *pucRegBuffer++);
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

/*******************************************************操作线圈寄存器*********************************************/

eMBErrorCode eMBMasterRegCoilsCB(UCHAR * pucRegBuffer, USHORT usAddress,
        USHORT usNCoils, eMBRegisterMode eMode)
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          iRegIndex , iRegBitIndex , iNReg;
    UCHAR *         pucCoilBuf;

    iNReg =  usNCoils / 8 + 1;

    pucCoilBuf = M_CoilsReg_Buf[ucMBMasterGetDestAddress() - 1];

    /* if mode is read,the master will write the received date to buffer. */
    eMode = MB_REG_WRITE;

    /* it already plus one in modbus function method. */
    usAddress--;

    if ((usAddress >= M_REG_Coils_START) && (usAddress + usNCoils <= M_REG_Coils_START + M_REG_Coils_NREGS))
    {
        iRegIndex = (USHORT) (usAddress - M_CoilsReg_Start) / 8;
        iRegBitIndex = (USHORT) (usAddress - M_CoilsReg_Start) % 8;
        switch (eMode)
        {
         /* read current coil values from the protocol stack. */
        case MB_REG_READ:
            while (iNReg > 0)
            {
                *pucRegBuffer++ = xMBUtilGetBits(&pucCoilBuf[iRegIndex++],
                        iRegBitIndex, 8);
                iNReg--;
            }
            pucRegBuffer--;
            /* last coils */
            usNCoils = usNCoils % 8;
            /* filling zero to high bit */
            *pucRegBuffer = *pucRegBuffer << (8 - usNCoils);
            *pucRegBuffer = *pucRegBuffer >> (8 - usNCoils);
            break;

        /* write current coil values with new values from the protocol stack. */
        case MB_REG_WRITE:
            while (iNReg > 1)
            {
                xMBUtilSetBits(&pucCoilBuf[iRegIndex++], iRegBitIndex, 8,
                        *pucRegBuffer++);
                iNReg--;
            }
            /* last coils */
            usNCoils = usNCoils % 8;
            /* xMBUtilSetBits has bug when ucNBits is zero */
            if (usNCoils != 0)
            {
                xMBUtilSetBits(&pucCoilBuf[iRegIndex++], iRegBitIndex, usNCoils,
                        *pucRegBuffer++);
            }
            break;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}








