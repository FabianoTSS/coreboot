/* This file is part of the coreboot project. */
/*
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _SKXSP_TP_IIO_H_
#define _SKXSP_TP_IIO_H_

#include <FspmUpd.h>
#include <soc/pci_devs.h>

enum tp_iio_bifur_table_index {
	Skt0_Iou0 = 0,
	Skt0_Iou1,
	Skt0_Iou2,
	Skt0_Mcp0,
	Skt0_Mcp1,
	Skt1_Iou0,
	Skt1_Iou1,
	Skt1_Iou2,
	Skt1_Mcp0,
	Skt1_Mcp1
};

/*
 * Standard Tioga Pass Iio Bifurcation Table
 * This is SS 2x16 config. As documented in OCP TP spec, there are
 * 3 configs. SS 2x16 is the most common.
 * TODO: figure out config through board SKU ID and through PCIe
 * config GPIO setting (SLT_CFG0 / SLT_CFG1).
 */
static const UPD_IIO_BIFURCATION_DATA_ENTRY tp_iio_bifur_table[] = {
	{ Iio_Socket0, Iio_Iou0, IIO_BIFURCATE_xxxxxx16 }, /* 1A x16 */
	{ Iio_Socket0, Iio_Iou1, IIO_BIFURCATE_xxxxxx16 }, /* 2A x16 */
	{ Iio_Socket0, Iio_Iou2, IIO_BIFURCATE_xxxxxx16 }, /* 3A x16 */
	{ Iio_Socket0, Iio_Mcp0, IIO_BIFURCATE_xxxxxxxx }, /* No MCP */
	{ Iio_Socket0, Iio_Mcp1, IIO_BIFURCATE_xxxxxxxx }, /* No MCP */
	{ Iio_Socket1, Iio_Iou0, IIO_BIFURCATE_xxxxxxxx }, /* no IOU0 */
	{ Iio_Socket1, Iio_Iou1, IIO_BIFURCATE_xxxxxxxx }, /* no IOU1 */
	{ Iio_Socket1, Iio_Iou2, IIO_BIFURCATE_xxx8xxx8 }, /* 3A x8, 3C x8 */
	{ Iio_Socket1, Iio_Mcp0, IIO_BIFURCATE_xxxxxxxx }, /* No MCP */
	{ Iio_Socket1, Iio_Mcp1, IIO_BIFURCATE_xxxxxxxx }, /* No MCP */
};

/*
 * Standard Tioga Pass Iio PCIe Port Table
 */
static const UPD_PCI_PORT_CONFIG tp_iio_pci_port_skt0[] = {
	// PortIndex |  HidePort  | DeEmphasis | PortLinkSpeed | MaxPayload |
	// DfxDnTxPreset | DfxRxPreset | DfxUpTxPreset | Sris | PcieCommonClock | NtbPpd |
	// NtbSplitBar | NtbBarSizePBar23 | NtbBarSizePBar4 | NtbBarSizePBar5 |
	// NtbBarSizePBar45 | NtbBarSizeSBar23 | NtbBarSizeSBar4 | NtbBarSizeSbar5 |
	// NtbBarSizeSBar45 | NtbSBar01Prefetch | NtbXlinkCtlOverride
	{ PORT_1A, NOT_HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_1B, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_1C, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_1D, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_2A, NOT_HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_2B, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_2C, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_2D, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_3A, NOT_HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_3B, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_3C, NOT_HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
	{ PORT_3D, HIDE, 0x00, PcieAuto, 0x0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
		NTB_PORT_TRANSPARENT, 0x00, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
		0x16, 0x00, 0x03 },
};

/*
 * Standard Tioga Pass PCH PCIe Port Table
 */
static const UPD_PCH_PCIE_PORT tp_pch_pci_port_skt0[] = {
	//PortIndex ; ForceEnable ; PortLinkSpeed
	{ 0x00, 0x00, PcieAuto },
	{ 0x04, 0x00, PcieAuto },
	{ 0x05, 0x00, PcieAuto },
};

#endif /* _SKXSP_TP_IIO_H_ */
