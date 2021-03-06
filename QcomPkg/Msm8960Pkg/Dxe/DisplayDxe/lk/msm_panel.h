/* Copyright (c) 2012-2014, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _PLATFORM_MSM_SHARED_MSM_PANEL_H_
#define _PLATFORM_MSM_SHARED_MSM_PANEL_H_


#include <fbcon.h>


/* panel type list */
#define NO_PANEL		0xffff	/* No Panel */
#define MDDI_PANEL		1	/* MDDI */
#define EBI2_PANEL		2	/* EBI2 */
#define LCDC_PANEL		3	/* internal LCDC type */
#define EXT_MDDI_PANEL		4	/* Ext.MDDI */
#define TV_PANEL		5	/* TV */
#define HDMI_PANEL		6	/* HDMI TV */
#define DTV_PANEL		7	/* DTV */
#define MIPI_VIDEO_PANEL	8	/* MIPI */
#define MIPI_CMD_PANEL		9	/* MIPI */
#define WRITEBACK_PANEL		10	/* Wifi display */
#define LVDS_PANEL		11	/* LVDS */
#define EDP_PANEL		12	/* EDP */

enum mdss_mdp_pipe_type {
	MDSS_MDP_PIPE_TYPE_VIG,
	MDSS_MDP_PIPE_TYPE_RGB,
	MDSS_MDP_PIPE_TYPE_DMA,
};

enum msm_mdp_hw_revision {
	MDP_REV_20 = 1,
	MDP_REV_22,
	MDP_REV_30,
	MDP_REV_303,
	MDP_REV_304,
	MDP_REV_31,
	MDP_REV_40,
	MDP_REV_41,
	MDP_REV_42,
	MDP_REV_43,
	MDP_REV_44,
	MDP_REV_50,
};

/* panel info type */
struct lcd_panel_info {
	UINT32 vsync_enable;
	UINT32 refx100;
	UINT32 v_back_porch;
	UINT32 v_front_porch;
	UINT32 v_pulse_width;
	UINT32 hw_vsync_mode;
	UINT32 vsync_notifier_period;
	UINT32 rev;
};

struct hdmi_panel_info {
	UINT32 h_back_porch;
	UINT32 h_front_porch;
	UINT32 h_pulse_width;
	UINT32 v_back_porch;
	UINT32 v_front_porch;
	UINT32 v_pulse_width;
};

struct lcdc_panel_info {
	UINT32 h_back_porch;
	UINT32 h_front_porch;
	UINT32 h_pulse_width;
	UINT32 v_back_porch;
	UINT32 v_front_porch;
	UINT32 v_pulse_width;
	UINT32 border_clr;
	UINT32 underflow_clr;
	UINT32 hsync_skew;
	/* Pad width */
	UINT32 xres_pad;
	/* Pad height */
	UINT32 yres_pad;
	UINT8 dual_pipe;
	UINT8 split_display;
	UINT8 pipe_swap;
	UINT8 dst_split;
};

struct mipi_panel_info {
	char mode;		/* video/cmd */
	char interleave_mode;
	int eof_bllp_power;
	UINT32 bitclock;
	char crc_check;
	char ecc_check;
	char dst_format;	/* shared by video and command */
	char num_of_lanes;
	char data_lane0;
	char data_lane1;
	char data_lane2;
	char data_lane3;
	char dlane_swap;	/* data lane swap */
	char rgb_swap;
	char b_sel;
	char g_sel;
	char r_sel;
	char rx_eot_ignore;
	char tx_eot_append;
	char t_clk_post; /* 0xc0, DSI_CLKOUT_TIMING_CTRL */
	char t_clk_pre;  /* 0xc0, DSI_CLKOUT_TIMING_CTRL */
	char vc;	/* virtual channel */
	struct mipi_dsi_phy_ctrl *dsi_phy_db;
	struct mdss_dsi_phy_ctrl *mdss_dsi_phy_db;
	struct mdss_dsi_pll_config *dsi_pll_config;
	struct mipi_dsi_cmd *panel_cmds;
	int num_of_panel_cmds;
	/* video mode */
	char pulse_mode_hsa_he;
	char hfp_power_stop;
	char hbp_power_stop;
	char hsa_power_stop;
	char eof_bllp_power_stop;
	char bllp_power_stop;
	char traffic_mode;
	char frame_rate;
	/* command mode */
	char interleave_max;
	char insert_dcs_cmd;
	char wr_mem_continue;
	char wr_mem_start;
	char te_sel;
	char stream;	/* 0 or 1 */
	char mdp_trigger;
	char dma_trigger;
	UINT32 dsi_pclk_rate;
	/* The packet-size should not bet changed */
	char no_max_pkt_size;
	/* Clock required during LP commands */
	char force_clk_lane_hs;
	char lane_swap;
	UINT8 dual_dsi;
	UINT8 broadcast;
	UINT8 mode_gpio_state;
	UINT32 signature;
	UINT32 use_enable_gpio;
};

struct edp_panel_info {
	int max_lane_count;
	unsigned long max_link_clk;
};

enum lvds_mode {
	LVDS_SINGLE_CHANNEL_MODE,
	LVDS_DUAL_CHANNEL_MODE,
};

struct lvds_panel_info {
	enum lvds_mode channel_mode;
	/* Channel swap in dual mode */
	char channel_swap;
};

struct msm_panel_info {
	UINT32 xres;
	UINT32 yres;
	UINT32 bpp;
	UINT32 type;
	UINT32 wait_cycle;
	UINT32 clk_rate;
	UINT32 rotation;
	/*  Select pipe type for handoff */
	UINT32 pipe_type;
	char     lowpowerstop;

	struct lcd_panel_info lcd;
	struct lcdc_panel_info lcdc;
	struct mipi_panel_info mipi;
	struct lvds_panel_info lvds;
	struct hdmi_panel_info hdmi;
	struct edp_panel_info edp;

	int (*on) (void);
	int (*off) (void);
	int (*pre_on) (void);
	int (*pre_off) (void);
	int (*prepare) (void);
	int (*early_config) (void *pdata);
	int (*config) (void *pdata);
	int (*rotate) (void);
};

struct msm_fb_panel_data {
	struct msm_panel_info panel_info;
	struct fbcon_config fb;
	int mdp_rev;
	int rotate;

	/* function entry chain */
	int (*power_func) (int enable);
	int (*clk_func) (int enable);
	int (*bl_func) (int enable);
	int (*pll_clk_func) (int enable, struct msm_panel_info *);
	int (*post_power_func)(int enable);
	int (*pre_init_func)(void);
};

#endif
