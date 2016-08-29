struct ip178g_registers {

  // 20.0 registers 0 
  uint16_t software_reset_register = 0x55AA;

  // 20.1 registers 1
	bool priority_rate=0; // bit 15
	bool reduce_ipg   =1; // bit 12
	bool drop16       =0; // bit 11
	bool modify_carrier_algorithm=0; // bit9
	bool bk_en=1; // bit8
	bool bp_kind=0; // bit7
	bool bf_stm_en=0; // bit5
	uint16_t aging=0b10; // bits 3 and 2
	bool modbck=0; // bit 1
	bool learn_dis_pause=0; // bit0

  // 20.2 reigster 2
  uint16_t tmode_sel=0; // bit 10 to 15
	bool input_filter=0; // bit7
	uint16_t hash_mode=0; // but 5 and 6

	// 20.3 register 3
	bool port_mirror_en=0; // bit15
	uint16_t port_mirror_mode =0; //bit 13/14
	uint16_t sel_rx_port_mirror=1; //bit 0 to 7

	// 20.4 register 4
	uint16_t sel_mirror_port=0b111; //bit 13 to 15
  uint16_t sel_tx_port_mirror=1; // bit 0 to 7

	//20.5 register 5
	uint16_t crc_counter=0; //bit 0 to 7

	//20.6 register 6
	uint16_t pause_trigger=0; // bit 8 to 15
	uint16_t pause_flag   =0; // bit 0 to 7

	//20.7 register 7
	bool thr_setting=0; // bit 15
	bool read_thr=0; // bit 14
	bool wait_backoff=0; // bit 13
	uint16_t unit_default_threshold=12; // bit 0 to 7

	//20.8 register 8
	uint16_t share_high_threshold=0; // bit 8 to 15 - no default in datasheet
	uint16_t share_low_threshold=0;  // bit 0 to 7 - no default in datasheet

	//20.9 register 9
	uint16_t pkt_high_threshold=96; // bit 8 to 15
	uint16_t pkt_low_threshold=80;  // bit 0 to 7

	//20.10 reigster 10
  uint16_t unit_high_threshold=0; //bit 8 to 15 - no default in datasheet
	uint16_t unit_low_threshold =0; //bit 0 to 7 - no default in datasheet

	//20.11 reigster 11
	bool mon_en=0; // bit 15
	uint16_t unit_low_num=224; // bit 0 to 8

	//20.12 register 12
	uint16_t share_high_num=224; // bit 0 to 8

	//20.13 register 13
	uint16_t fiber_duplex=0b11; // bit 14 and 15
	bool buf_aging_en=0; // bit 13
	bool src_blk_protect=1; // bit 12
	uint16_t port_backpressure_en=0; //bit 0 to 7

	//20.14 reigster 14
  uint16_t lpp_aging_en=0; //bit 8 to 15
	uint16_t userdef_range_en=0b11; // bit 4 and 5
	uint16_t predef_port_en=0xF; // bit 0 to 3
	
	//20.15 register 15
	uint16_t userdef_range0_high=23; // 0 to 15
	
	//20.16 register 16
	uint16_t userdef_range0_low=23; // 0 to 15

	//20.17 register 17
	uint16_t userdef_range1_high=5800; // 0 to 15

	//20.18 register 18
	uint16_t userdef_range1_low=5800; // 0 to 15

  //20.19 register 19
	bool fast_mode=0; // bit 15
	uint16_t test_latin=0; // bit 2 to 12
	uint16_t test_sel=0; // bit 0 and 1

	//21.0 register 20
	bool port0_cos_en=0; // bit 10
	bool port0_high_priority=0; // bit 9

	//21.1 register 21
	bool port1_cos_en=0; // bit 10
	bool port1_high_priority=0; // bit9

	//21.2 register 22
	bool port2_cos_en=0; // bit 10
	bool port2_high_priority=0; //bit 9

	//21.3 register 23
	bool port3_cos_en=0; // bit 10
	bool port3_high_priority=0; // bit 9

	//21.4 register 24
	bool port4_cos_en=0; //bit 10
	bool port4_high_priority=0; // bit 9

	//21.5 register 25
	bool port5_cos_en=0; //bit 10
	bool port5_high_priority=0; // bit9

	//21.6 register 26
	bool port6_cos_en=0; //bit 10
	bool port6_high_priority=0; //bit 9

	//21.7 register 27
	bool port7_cos_en=0; // bit10
	bool port7_high_priority=0; // bit 9

	//21.8 register 28
	//NOTHING

	//21.9 register 29
  uint16_t bf_stm_thr_sel=0; // bit 14 and 15
	uint16_t share_full_thr_sel=0; // bit 12 and 13
	uint16_t unit_default_thr_sel=0; // 10 and 11
	uint16_t unit_low_thr_sel=0; // 8 and 9
	uint16_t unit_high_thr_sel=0; // 6 and 7
	bool predrop_en=0; // bit 4
	uint16_t pkt_low_thr_sel=0; // 2 and 3
	uint16_t pkt_high_thr_sel=0; // 0 and 1

	//21.10 register 30
	uint16_t driver=0b010; // 12 to 14
	bool bf_stm_en_qm=0; // 11
	bool hp_dis_flow_en=0; // 10
	bool two_part=1; // 9
	bool allpass=0; // 8
	uint16_t analog_off_time=0b01; // 6 and 7

  // It's unclear if any value past this point are loaded from SPI flash (datasheet isn't very explicit about flash format)

  //21.11 31
	bool pause_filter=0; // bit 15
	bool rsvd_gmac_filter_4=1; // bit 14
	bool rsvd_gmac_filter_3=1; // bit 13
	bool rsvd_gmac_filter_2a=0; // bit 12
	bool rsvd_gmac_filter_2b=0; // bit  11
	bool rsvd_gmac_filter_2c=0; // bit 10
	bool rsvd_gmac_filter_1a=1; // bit 9
	bool rsvd_gmac_filter_1b=0; // bit 8
	bool rsvd_gmac_filter_0a=0; // bit 7
	bool rsvd_gmac_filter_0b=1; // bit 6
	bool rsvd_gmac_filter_0c=0; // bit 5
	bool rsvd_gmac_filter_0d=0; // bit 4
	bool rsvd_gmac_filter_0e=1; // bit 3
	bool rsvd_gmac_filter_0f=1; // bit 2
	bool rsvd_gmac_filter_0g=0; // bit 1
	bool rsvd_gmac_filter_0h=1; // bit 0

  //21.12 32
	uint16_t rsvd_future_0_filter=0; // bits 2 to 10
	bool     rsvd_mac_ctrl_filter=0; // bit 1
	bool mpcp_filter=0; // bit 0

	//21.13 33
	uint16_t rsvd_future_1_filter=0; // bits 0 to 13

	//21.14 34
	uint16_t ieee802_1ag_filter=0xFFFF; // bits 0 to 15

	//21.15 35
	//21.16 36
	//21.17 37
	//21.18 38
	//21.19 39
	//21.20 40
	//21.21 41
	//21.22 42
	//21.23 43
	//21.24 44
	//21.25 45
	//21.26 46
	//21.27 47
	//21.28 48
	//21.29 49

	//21.30 50
  bool diffserv_en =0; // bit 13
	bool bf_ffff_only=0; // bit 12
	bool special_add_forward=0xD; // bit 8 to 11
	bool fwd_mac_ctl =1; // bit 7
	uint16_t drop_extra_long_packet=0; // bit 0 and 1

  //22.0 51
	uint16_t eee_en=0xFF; // bits 0 to 7

	//22.1 52
	uint16_t sleep_time_unit=2;// bits 14 and 15
	uint16_t sleep_time=15; // bits 0 to 11

  //22.2 53
	uint16_t wake_time_unit_p0=2; // bits 14 and 15
	uint16_t wake_time_p0=35; // bits 0 to 11

	//22.3 54
	uint16_t wake_time_unit_p1=2; // bits 14 and 15
	uint16_t wake_time_p1=35; // bits 0 to 11

	//22.4 55
	uint16_t wake_time_unit_p2=2; // bits 14 and 15
	uint16_t wake_time_p2=35; // bits 0 to 11

	//22.5 56
	uint16_t wake_time_unit_p3=2; // bits 14 and 15
	uint16_t wake_time_p3=35; // bits 0 to 11

	//22.6 57
	uint16_t wake_time_unit_p4=2; // bits 14 and 15
	uint16_t wake_time_p4=35; // bits 0 to 11

	//22.7 58
	uint16_t wake_time_unit_p5=2; // bits 14 and 15
	uint16_t wake_time_p5=35; // bits 0 to 11
	
	//22.8 59
	uint16_t wake_time_unit_p6=2; // bits 14 and 15
	uint16_t wake_time_p6=35; // bits 0 to 11
	
	//22.9 60
	uint16_t wake_time_unit_p7=2; // bits 14 and 15
	uint16_t wake_time_p7=35; // bits 0 to 11

	//22.10 61
	uint16_t wol_en=0xff; //bits 8 to 15
	uint16_t wol_timer=0; // bit 0 and 1

	//22.11 62
	uint16_t aggr_idx_sel=0; // bits 3 and 4
	uint16_t aggr_mode=0; // bits 0 to 2

	//22.12 63
	uint16_t aggr_group0=0; // bits 0 to 7
	
	//22.13 64
	uint16_t aggr_group1=0; // bits 0 to 7

	//22.14 65
	uint16_t aggr_mask0=0xFF; // bits 0 to 7;
	
	//22.15 66
	uint16_t aggr_mask1=0xFF; // bits 0 to 7

	//22.16 67
	uint16_t aggr_mask2=0xFF; // bits 0 to 7

	//22.17 68
	uint16_t aggr_mask3=0xFF; // bits 0 to 7

	//22.18 69
	uint16_t aggr_mask4=0xFF; // bits 0 to 7

	//22.19 70
	uint16_t aggr_mask5=0xFF; // bits 0 to 7

	//22.20 71
	uint16_t aggr_mask6=0xFF; // bits 0 to 7

	//22.21 72
	uint16_t aggr_mask7=0xFF; // bits 0 to 7

	//23.0 73
	bool val_table_clr=0; //bit 15
	bool unvid_mode=0; // bit 13

	//23.1 74
	uint16_t vlan_cls=0; // 8 to 15
	uint16_t tag_vlan_en=0; // bit 0 to 7

	//23.2 75
	bool vlan_drop_cfi=0; // bit 13
	uint16_t rsvd_vid=1; // bits 10 to 12
	uint16_t acceptable_frm_type=0;// bit 8 and 9
	uint16_t vlan_ingress_filter=0xFF; // 0 to 7

  //23.3 76
	//23.4 77

	//23.5 78
	uint16_t vlan_info_0=1; // bits 0 to 15

	//23.6 79
	uint16_t vlan_info_1=1;
  
	//23.7 80
	uint16_t vlan_info_2=1;
	//23.8 81
	uint16_t vlan_info_3=1;
	//23.9 82
	uint16_t vlan_info_4=1;
	//23.10 83
	uint16_t vlan_info_5=1;
	//23.11 84
	uint16_t vlan_info_6=1;
	//23.12 85
	uint16_t vlan_info_7=1;

	//23.13 86
	uint16_t add_tag=0; // bits 0 to 7

	//23.14 87
	uint16_t remove_tag=0; // bits 0 to 7

	//23.15 88
	uint16_t pbv_member_p0=0xFF; // bits 0 to 7
	uint16_t pbv_member_p1=0xFF; // bits 8 to 15

	//23.16 89
	uint16_t pbv_member_p2=0xFF; // bits 0 to 7
	uint16_t pbv_member_p3=0xFF; // bits 8 to 15

  //23.17 90
	uint16_t pbv_member_p4=0xFF; // bits 0 to 7
	uint16_t pbv_member_p5=0xFF; // bits 8 to 15

  //23.18 91
	uint16_t pbv_member_p6=0xFF; // bits 0 to 7
	uint16_t pbv_member_p7=0xFF; // bits 8 to 15

  //23.19 92
	uint16_t leaky_vlan=0; // bits 0 to 2

	//24.0 93
	uint16_t vlan_valid=0; // bit 0 to 15

	//24.1 94
	uint16_t vid_0 = 0x1; // bit 0 to 11
	//24.2 95
	uint16_t vid_1 = 0x2; // bit 0 to 11
	//24.3 96
	uint16_t vid_2 = 0x3; // bit 0 to 11
	//24.4 97
	uint16_t vid_3 = 0x4; // bit 0 to 11
	//24.5 98
	uint16_t vid_4 = 0x5; // bit 0 to 11
	//24.6 99
	uint16_t vid_5 = 0x6; // bit 0 to 11
	//24.7 100
	uint16_t vid_6 = 0x7; // bit 0 to 11
	//24.8 101
	uint16_t vid_7 = 0x8; // bit 0 to 11
	//24.9 102
	uint16_t vid_8 = 0x9; // bit 0 to 11
	//24.10 103
	uint16_t vid_9 = 0xA; // bit 0 to 11
	//24.11 104
	uint16_t vid_a = 0xB; // bit 0 to 11
	//24.12 105
	uint16_t vid_b = 0xC; // bit 0 to 11
	//24.13 106
	uint16_t vid_c = 0xD; // bit 0 to 11
	//24.14 107
	uint16_t vid_d = 0xE; // bit 0 to 11
	//24.15 108
	uint16_t vid_e = 0xF; // bit 0 to 11
	//24.16 109
	uint16_t vid_f = 0x10; // bit 0 to 11

	//24.17  110
	uint16_t vlan_member_0 = 0xFF; // 0 to 7
	uint16_t vlan_member_1 = 0xFF; // 8 to 15

	//24.18 111
	uint16_t vlan_member_2 = 0xFF; // 0 to 7
	uint16_t vlan_member_3 = 0xFF; // 8 to 15
	//24.19 112
	uint16_t vlan_member_4 = 0xFF; // 0 to 7
	uint16_t vlan_member_5 = 0xFF; // 8 to 15
	//24.20 113
	uint16_t vlan_member_6 = 0xFF; // 0 to 7
	uint16_t vlan_member_7 = 0xFF; // 8 to 15
	//24.21 114
	uint16_t vlan_member_8 = 0xFF; // 0 to 7
	uint16_t vlan_member_9 = 0xFF; // 8 to 15
	//24.22 115
	uint16_t vlan_member_a = 0xFF; // 0 to 7
	uint16_t vlan_member_b = 0xFF; // 8 to 15
	//24.23 116
	uint16_t vlan_member_c = 0xFF; // 0 to 7
	uint16_t vlan_member_d = 0xFF; // 8 to 15
	//24.24 117
	uint16_t vlan_member_e = 0xFF; // 0 to 7
	uint16_t vlan_member_f = 0xFF; // 8 to 15

};
