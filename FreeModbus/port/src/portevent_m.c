
/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "port.h"

//#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0
/* ----------------------- Defines ------------------------------------------*/
/* ----------------------- Variables ----------------------------------------*/
//static struct rt_semaphore xMasterRunRes;
// struct rt_event     xMasterOsEvent;
static BOOL     xMaster_EventInQueue;
static eMBMasterEventType Master_eQueuedEvent;
/* ----------------------- Start implementation -----------------------------*/
BOOL
xMBMasterPortEventInit( void )
{
	xMaster_EventInQueue = FALSE;
    return TRUE;
}

BOOL
xMBMasterPortEventPost( eMBMasterEventType eEvent )
{
	xMaster_EventInQueue = TRUE;
	Master_eQueuedEvent = eEvent;//EV_MASTER_FRAME_RECEIVED
    return TRUE;
}

BOOL
xMBMasterPortEventGet( eMBMasterEventType * eEvent )
{
	 BOOL  Master_xEventHappened = FALSE;

	    if( xMaster_EventInQueue )
	    {
	        *eEvent = Master_eQueuedEvent;
	        xMaster_EventInQueue = FALSE;
	        Master_xEventHappened = TRUE;
	    }
	    return Master_xEventHappened;
}



BOOL xMBMasterRunResTake( LONG lTimeOut )
{
    //If waiting time is -1 .It will wait forever
   // return rt_sem_take(&xMasterRunRes, lTimeOut) ? FALSE : TRUE ;
	return TRUE;
}

/*
 * This function is wait for modbus master request finish and return result.
 * Waiting result include request process success, request respond timeout,
 * receive data error and execute function error.You can use the above callback function.
 * @note If you are use OS, you can use OS's event mechanism. Otherwise you have to run
 * much user custom delay for waiting.
 *
 * @return request error code
 */
/*
eMBMasterReqErrCode eMBMasterWaitRequestFinish( void ) {
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;
    rt_uint32_t recvedEvent;

    rt_event_recv(&xMasterOsEvent,
            EV_MASTER_PROCESS_SUCESS | EV_MASTER_ERROR_RESPOND_TIMEOUT
                    | EV_MASTER_ERROR_RECEIVE_DATA
                    | EV_MASTER_ERROR_EXECUTE_FUNCTION,
            RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER,
            &recvedEvent);
    switch (recvedEvent)
    {
    case EV_MASTER_PROCESS_SUCESS:
        break;
    case EV_MASTER_ERROR_RESPOND_TIMEOUT:
    {
        eErrStatus = MB_MRE_TIMEDOUT;
        break;
    }
    case EV_MASTER_ERROR_RECEIVE_DATA:
    {
        eErrStatus = MB_MRE_REV_DATA;
        break;
    }
    case EV_MASTER_ERROR_EXECUTE_FUNCTION:
    {
        eErrStatus = MB_MRE_EXE_FUN;
        break;
    }
    }
    return eErrStatus;
}
*/
