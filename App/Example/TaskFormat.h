/*
********************************************************************************************
*
*				  Copyright (c): 2014 - 2014 + 5, Aaron.sun
*							   All rights reserved.
*
* FileName: App\Example\TaskFormat.h
* Owner: Aaron.sun
* Date: 2014.5.16
* Time: 18:01:36
* Desc:
* History:
*    <author>	 <date> 	  <time>	 <version>	   <Desc>
*    Aaron.sun     2014.5.16     18:01:36   1.0
********************************************************************************************
*/

#ifndef __APP_EXAMPLE_TASKFORMAT_H__
#define __APP_EXAMPLE_TASKFORMAT_H__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   global variable declare
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API Declare
*
*---------------------------------------------------------------------------------------------------------------------
*/
extern rk_err_t TestTask_Shell(HDC dev, uint8 * pstr);
extern void TestTask_Enter(void);
extern rk_err_t TestTask_DevInit(void *pvParameters);
extern rk_err_t TestTask_Init(void *pvParameters);



#endif

