/**
  ******************************************************************************
  * @file    core.h
  * @author  shentq
  * @version V1.2
  * @date    2016/08/14
  * @brief   ���ļ�Ϊebox�����ļ�,�ṩ�����ǳ���Ҫ�Ľӿ�,���Ա���׼��c�ļ����á�
  ******************************************************************************
  * @attention
  *
  * No part of this software may be used for any commercial activities by any form 
  * or means, without the prior written consent of shentq. This specification is 
  * preliminary and is subject to change at any time without notice. shentq assumes
  * no responsibility for any errors contained herein.
  * <h2><center>&copy; Copyright 2015 shentq. All Rights Reserved.</center></h2>
  ******************************************************************************
  */
/**
 * Modification History:
 * -shentq                  -version 1.2(2016/08/17)
 *      *�޸���оƬ��Ƶֻ������Ϊ72Mhz�����ƣ�֧��������Ƶ
 *      *������cpu����Ϣ��ȡ��������������ʱ�ӣ�оƬ������оƬ����Ӽӵ�����
 */


/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __EBOX_CORE_H
#define __EBOX_CORE_H

    
#include "../core/new.h"
#include "../core/print.h"
#include "../core/binary.h"
#include "../core/mem/ebox_mem.h"
#include "../core/math/random.h"
#include "../core/math/crc.h"
#include "../core/math/math_misc.h"
#include "../core/ringbuf.h"
#include "../core/list.h"
#include "../core/util.h"


#define EBOX_VERSION "2.0"

#define EOK         0
#define EWAIT       1
#define EBUSY       2
#define ETIMEOUT    3
#define EPARA       4
#define E2LONG      5
#define EOTHER      128

////////o��?����?/////////////////////////////////


#define true 0x1
#define false 0x0

#define HIGH 0x1
#define LOW  0x0


#define LSB_FIRST 0
#define MSB_FIRST 1

#define PI 3.1415926535898


#endif