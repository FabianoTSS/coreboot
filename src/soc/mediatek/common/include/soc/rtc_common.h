/*
 * This file is part of the coreboot project.
 *
 * Copyright 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef SOC_MEDIATEK_RTC_COMMON_H
#define SOC_MEDIATEK_RTC_COMMON_H

#include <assert.h>
#include <bcd.h>
#include <console/console.h>
#include <delay.h>
#include <rtc.h>
#include <timer.h>

/*
 * Default values for RTC initialization
 * Year (YEA)        : 1970 ~ 2037
 * Month (MTH)       : 1 ~ 12
 * Day of Month (DOM): 1 ~ 31
 */

enum {
	RTC_DEFAULT_YEA = 2010,
	RTC_DEFAULT_MTH = 1,
	RTC_DEFAULT_DOM = 1,
	RTC_DEFAULT_DOW = 5
};

enum {
	RTC_2SEC_REBOOT_ENABLE  = 1,
	RTC_2SEC_MODE   = 2
};

enum {
	RTC_OSC32CON_UNLOCK1 = 0x1A57,
	RTC_OSC32CON_UNLOCK2 = 0x2B68
};

enum {
	RTC_PROT_UNLOCK1 = 0x586A,
	RTC_PROT_UNLOCK2 = 0x9136
};

enum {
	RTC_BBPU_KEY	= 0x43 << 8
};

enum {
	RTC_IRQ_STA_AL	= 1U << 0,
	RTC_IRQ_STA_TC	= 1U << 1,
	RTC_IRQ_STA_LP	= 1U << 3
};

enum {
	RTC_IRQ_EN_AL		= 1U << 0,
	RTC_IRQ_EN_TC		= 1U << 1,
	RTC_IRQ_EN_ONESHOT	= 1U << 2,
	RTC_IRQ_EN_LP		= 1U << 3,
	RTC_IRQ_EN_ONESHOT_AL	= RTC_IRQ_EN_ONESHOT | RTC_IRQ_EN_AL
};

enum {
	RTC_POWERKEY1_KEY	= 0xA357,
	RTC_POWERKEY2_KEY	= 0x67D2
};

enum {
	RTC_SPAR0_32K_LESS	= 1U << 6
};

enum {
	RTC_MIN_YEAR	= 1968,
	RTC_BASE_YEAR	= 1900,
	RTC_MIN_YEAR_OFFSET = RTC_MIN_YEAR - RTC_BASE_YEAR,

	RTC_NUM_YEARS	= 128
};

enum {
	RTC_STATE_REBOOT	= 0,
	RTC_STATE_RECOVER	= 1,
	RTC_STATE_INIT		= 2
};

/* external API */
int rtc_busy_wait(void);
int rtc_write_trigger(void);
int rtc_writeif_unlock(void);
void rtc_xosc_write(u16 val);
int rtc_reg_init(void);
u8 rtc_check_state(void);
void rtc_boot_common(void);

#endif /* SOC_MEDIATEK_RTC_COMMON_H */
