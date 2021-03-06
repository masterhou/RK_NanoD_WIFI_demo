/*
********************************************************************************
*          Copyright (C),2004-2007, Fuzhou Rockchip Electronics Co.,Ltd.
*                             All Rights Reserved
*
*Description: AD sampling,battery voltage check program.
*
$Header: /cvs_database/cvs_server_rk26/mp3_project/RK260x_SDK/System/Driver/Adc/Adc.c,v 1.1.1.5 2007/12/27 07:58:59 ke Exp $
$Author: ke $
$Date: 2007/12/27 07:58:59 $
$Revision: 1.1.1.5 $
********************************************************************************
*/
#ifdef __DRIVER_AD_ADCDEVICE_C__
#define _IN_ADC_

#include <typedef.h>
#include <BSPConfig.h>
#include <DriverInclude.h>


/*
--------------------------------------------------------------------------------
  Function name : void AdcInit(void)
  Author        : Zhengyongzhi
  Description   :

  Input         : null

  Return        : null

  History:     <author>         <time>         <version>
              anzhiguo     2009-3-24         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
void AdcPowerDown(void)
{
	Adc->ADC_CTRL &= ~ADC_POWERUP ;
}

void AdcPowerUp(void)
{
	Adc->ADC_CTRL |= ADC_POWERUP ;
}

/*
--------------------------------------------------------------------------------
  Function name : void AdcStart(uint8 StartCh)
  Author        : Zhengyongzhi
  Description   : start ad sampling.
  				  AD sampling is started in systick and timer interruption,if adc is processing,
  				  then suspend the channel.after finish this ad sampling, start the interrupt in
  				  interrupt service again.
  Input         : null
  Return        : null
  History:     <author>         <time>         <version>
                anzhiguo     2009-3-24         Ver1.0
  desc:          ORG //register system interruption, used for key scan and battery detect.
--------------------------------------------------------------------------------
*/
void AdcStart(uint8 StartCh)
{
    uint8  ch;
    uint32 temp;
    uint32 IsEnable;

    ch = StartCh;
    Adc->ADC_CTRL &= ~ADC_START;
    temp = Adc->ADC_CTRL & (~ADC_CH_MASK);
    Adc->ADC_CTRL = temp | ch | ADC_START;
}

/*
--------------------------------------------------------------------------------
  Function name : uint32 CheckAdcState(uint8 ch)
  Author        : Zhengyongzhi
  Description   :

  Input         : null
  Return        : null
  History:     <author>         <time>         <version>
                anzhiguo     2009-3-24         Ver1.0
  desc:          ORG
--------------------------------------------------------------------------------
*/
uint32 CheckAdcState(uint8 ch)
{
    uint32 temp;

    temp = Adc->ADC_STAS;
	return(temp);
}

/*
--------------------------------------------------------------------------------
  Function name : uint32 GetAdcData(uint8 ch)
  Author        : Zhengyongzhi
  Description   :

  Input         : null
  Return        : null
  History:     <author>         <time>         <version>
                anzhiguo     2009-3-24         Ver1.0
  desc:          ORG
--------------------------------------------------------------------------------
*/
uint32 GetAdcData(uint8 ch)
{
    return(Adc->ADC_DATA);
}
#endif
/*
********************************************************************************
*
*                         End of Adc.c
*
********************************************************************************
*/

