/* This file is part of the coreboot project. */
/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	/* coreboot specific header */
	0x10ec0888,
	0x104382fe,	// Subsystem ID
	13,	// Number of entries

	/* Pin Widget Verb Table */
	AZALIA_PIN_CFG(0, 0x11, 0x99430130),
	AZALIA_PIN_CFG(0, 0x14, 0x01014010),
	AZALIA_PIN_CFG(0, 0x15, 0x01011012),
	AZALIA_PIN_CFG(0, 0x16, 0x01016011),
	AZALIA_PIN_CFG(0, 0x17, 0x01012014),
	AZALIA_PIN_CFG(0, 0x18, 0x01a19840),
	AZALIA_PIN_CFG(0, 0x19, 0x02a19c50),
	AZALIA_PIN_CFG(0, 0x1a, 0x0181304f),
	AZALIA_PIN_CFG(0, 0x1b, 0x02214c20),
	AZALIA_PIN_CFG(0, 0x1c, 0x593301f0),
	AZALIA_PIN_CFG(0, 0x1d, 0x4015e601),
	AZALIA_PIN_CFG(0, 0x1e, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1f, 0x411111f0),

	/* HDMI audio */
	0x80862803,
	0x80860101,
	1,

	AZALIA_PIN_CFG(1, 0x03, 0x18560010),
};

const u32 pc_beep_verbs[0] = {};

const u32 pc_beep_verbs_size = ARRAY_SIZE(pc_beep_verbs);
const u32 cim_verb_data_size = ARRAY_SIZE(cim_verb_data);
