#include <stdint.h>
#include "ip178g_registers.h"
#include <fstream>
#include <stdio.h>

using namespace std;

void make_ip178g_flash_bin(ip178g_registers *r,uint16_t *flash_bin) {

 // register 0
 flash_bin[0] = r->software_reset_register;

 // register 1
 flash_bin[1]=0;
 if(r->priority_rate           ) flash_bin[1] |= (0x1 << 15);
 if(r->reduce_ipg              ) flash_bin[1] |= (0x1 << 12);
 if(r->drop16                  ) flash_bin[1] |= (0x1 << 11);
 if(r->modify_carrier_algorithm) flash_bin[1] |= (0x1 << 9);
 if(r->bk_en                   ) flash_bin[1] |= (0x1 << 8);
 if(r->bp_kind                 ) flash_bin[1] |= (0x1 << 7);
 if(r->bf_stm_en               ) flash_bin[1] |= (0x1 << 5);
 flash_bin[1] |= (r->aging  << 2);
 if(r->modbck                  ) flash_bin[1] |= (0x1 << 1);
 if(r->learn_dis_pause         ) flash_bin[1] |= (0x1 << 0);

 // register 2
 flash_bin[2] = 0;
 flash_bin[2] |= (0x3F & (r->tmode_sel << 10));
 if(r->input_filter) flash_bin[2] |= (0x1 << 7);
 flash_bin[2] |= (0x3 & r->hash_mode) << 5;

 // register 3
 flash_bin[3] = 0;
 if(r->port_mirror_en) flash_bin[3] |= (0x1 << 15);
 flash_bin[3] |= ((0x3  & r->port_mirror_mode  ) << 13);
 flash_bin[3] |= ((0xFF & r->sel_rx_port_mirror) << 0);

 // register 4
 flash_bin[4] = 0;
 flash_bin[4] |= ((0x3 & r->sel_mirror_port)    << 13);
 flash_bin[4] |= ((0xF & r->sel_tx_port_mirror) << 0);

 // register 5
 flash_bin[5] = 0;
 flash_bin[5] |= ((0xFF & r->crc_counter) << 0);

 // register 6
 flash_bin[6] = 0;
 flash_bin[6] |= ((0xFF & r->pause_trigger) << 8);
 flash_bin[6] |= ((0xFF & r->pause_flag   ) << 0);

 // register 7
 flash_bin[7] = 0;
 if(r->thr_setting ) flash_bin[7] |= (0x1 << 15);
 if(r->read_thr    ) flash_bin[7] |= (0x1 << 14);
 if(r->wait_backoff) flash_bin[7] |= (0x1 << 13);
 flash_bin[7] |= (0xFF & r->unit_default_threshold);

 // register 8
 flash_bin[8] = 0;
 flash_bin[8] |= ((0xFF & r->share_high_threshold) << 8);
 flash_bin[8] |= ((0xFF & r->share_low_threshold ) << 0);

 // register 9
 flash_bin[9] = 0;
 flash_bin[9] |= ((0xFF & r->pkt_high_threshold) << 8);
 flash_bin[9] |= ((0xFF & r->pkt_low_threshold ) << 0);

 // register 10
 flash_bin[10] = 0;
 flash_bin[10] |= ((0xFF & r->unit_high_threshold) << 8);
 flash_bin[10] |= ((0xFF & r->unit_low_threshold) << 8);

 // register 11
 flash_bin[11] = 0;
 if(r->mon_en) flash_bin[11] |= (0x1 << 15);
 flash_bin[11] |= (0xFF & r->unit_low_num);

 // register 12
 flash_bin[12] = 0;
 flash_bin[12] |= (0xFF & r->share_high_num);

 // register 13
 flash_bin[13] = 0;
 flash_bin[13] |= ((0x3 & r->fiber_duplex) << 14);
 if(r->buf_aging_en) flash_bin[13] |= (0x1 << 13);
 if(r->src_blk_protect) flash_bin[13] |= (0x1 << 12);
 flash_bin[13] |= (0xFF & r->port_backpressure_en);

 // register 14
 flash_bin[14] = 0;
 flash_bin[14] |= ((0xFF & r->lpp_aging_en    ) << 8);
 flash_bin[14] |= ((0x3  & r->userdef_range_en) << 4);
 flash_bin[14] |= ((0xF  & r->predef_port_en  ) << 0);

 // register 15
 flash_bin[15] = r->userdef_range0_high;

 // register 16
 flash_bin[16] = r->userdef_range0_low;

 // register 17
 flash_bin[17] = r->userdef_range1_high;

 // register 18
 flash_bin[18] = r->userdef_range1_low;

 // register 19
 flash_bin[19] = 0;
 if(r->fast_mode ) flash_bin[19] |= (0x1 << 15);
 if(r->test_latin) flash_bin[19] |= (0x1 << 2);
 if(r->test_sel  ) flash_bin[19] |= (0x1 << 0);

 // register 20
 flash_bin[20] = 0;
 if(r->port0_cos_en       ) flash_bin[20] |= (0x1 << 10);
 if(r->port0_high_priority) flash_bin[20] |= (0x1 <<  9);
 
 // register 21
 flash_bin[21] = 0;
 if(r->port1_cos_en       ) flash_bin[21] |= (0x1 << 10);
 if(r->port1_high_priority) flash_bin[21] |= (0x1 <<  9);
 
 // register 22
 flash_bin[22] = 0;
 if(r->port2_cos_en       ) flash_bin[22] |= (0x1 << 10);
 if(r->port2_high_priority) flash_bin[22] |= (0x1 <<  9);

 // register 23
 flash_bin[23] = 0;
 if(r->port3_cos_en       ) flash_bin[23] |= (0x1 << 10);
 if(r->port3_high_priority) flash_bin[23] |= (0x1 <<  9);

 // register 24
 flash_bin[24] = 0;
 if(r->port4_cos_en       ) flash_bin[24] |= (0x1 << 10);
 if(r->port4_high_priority) flash_bin[24] |= (0x1 <<  9);

 // register 25
 flash_bin[25] = 0;
 if(r->port5_cos_en       ) flash_bin[25] |= (0x1 << 10);
 if(r->port5_high_priority) flash_bin[25] |= (0x1 <<  9);

 // register 26
 flash_bin[26] = 0;
 if(r->port6_cos_en       ) flash_bin[26] |= (0x1 << 10);
 if(r->port6_high_priority) flash_bin[26] |= (0x1 <<  9);

 // register 27
 flash_bin[27] = 0;
 if(r->port7_cos_en       ) flash_bin[27] |= (0x1 << 10);
 if(r->port7_high_priority) flash_bin[27] |= (0x1 <<  9);

 // register 28
 flash_bin[28] = 0;

 // register 29
 flash_bin[29] = 0;
 flash_bin[29] |= ((0x3 & r->bf_stm_thr_sel      ) << 14);
 flash_bin[29] |= ((0x3 & r->share_full_thr_sel  ) << 12);
 flash_bin[29] |= ((0x3 & r->unit_default_thr_sel) << 10);
 flash_bin[29] |= ((0x3 & r->unit_low_thr_sel    ) <<  8);
 flash_bin[29] |= ((0x3 & r->unit_high_thr_sel   ) <<  6);
 if(r->predrop_en) flash_bin[29] |= (0x1 << 4);
 flash_bin[29] |= ((0x3 & r->pkt_low_thr_sel    )  << 2);
 flash_bin[29] |= ((0x3 & r->pkt_high_thr_sel   )  << 0);

 // register 30
 flash_bin[30] = 0;
 flash_bin[30] |= ((0x7 & r->driver) << 12);
 if(r->bf_stm_en_qm  ) flash_bin[30] |= (0x1 << 11);
 if(r->hp_dis_flow_en) flash_bin[30] |= (0x1 << 10);
 if(r->two_part      ) flash_bin[30] |= (0x1 << 9);
 if(r->allpass       ) flash_bin[30] |= (0x1 << 8);
 flash_bin[30] |= ((0x3 & r->analog_off_time) << 6);

 // register 31
 flash_bin[31] = 0;
 if(r->pause_filter       ) flash_bin[31] |= (0x1 << 15);
 if(r->rsvd_gmac_filter_4 ) flash_bin[31] |= (0x1 << 14);
 if(r->rsvd_gmac_filter_3 ) flash_bin[31] |= (0x1 << 13);
 if(r->rsvd_gmac_filter_2a) flash_bin[31] |= (0x1 << 12);
 if(r->rsvd_gmac_filter_2b) flash_bin[31] |= (0x1 << 11);
 if(r->rsvd_gmac_filter_2c) flash_bin[31] |= (0x1 << 10);
 if(r->rsvd_gmac_filter_1a) flash_bin[31] |= (0x1 << 9);
 if(r->rsvd_gmac_filter_1b) flash_bin[31] |= (0x1 << 8);
 if(r->rsvd_gmac_filter_0a) flash_bin[31] |= (0x1 << 7);
 if(r->rsvd_gmac_filter_0b) flash_bin[31] |= (0x1 << 6);
 if(r->rsvd_gmac_filter_0c) flash_bin[31] |= (0x1 << 5);
 if(r->rsvd_gmac_filter_0d) flash_bin[31] |= (0x1 << 4);
 if(r->rsvd_gmac_filter_0e) flash_bin[31] |= (0x1 << 3);
 if(r->rsvd_gmac_filter_0f) flash_bin[31] |= (0x1 << 2);
 if(r->rsvd_gmac_filter_0g) flash_bin[31] |= (0x1 << 1);
 if(r->rsvd_gmac_filter_0h) flash_bin[31] |= (0x1 << 0);

 // register 32
 flash_bin[32]=0;
 flash_bin[32] = (0x3FF & r->rsvd_future_0_filter) << 2;
 if(r->rsvd_mac_ctrl_filter) flash_bin[32] |= (0x1 << 1);
 if(r->mpcp_filter         ) flash_bin[32] |= (0x1 << 0);

 // register 33
 flash_bin[33] = 0;
 flash_bin[33] |= (0x1FFF & r->rsvd_future_1_filter);

 // register 34
 flash_bin[34] |= r->ieee802_1ag_filter;

 // register 35..49
 for(size_t n=35;n<=49;n++) flash_bin[n]=0;

 // register 50
 flash_bin[50]=0;
 if(r->diffserv_en ) flash_bin[50] |= (0x1 << 13);
 if(r->bf_ffff_only) flash_bin[50] |= (0x1 << 12);
 flash_bin[50] |= ((0xF & r->special_add_forward) << 8);
 if(r->fwd_mac_ctl) flash_bin[50] |= (0x1 << 7);
 flash_bin[50] |= ((0x3 & r->drop_extra_long_packet) << 0);

 // register 51
 flash_bin[51] = 0;
 flash_bin[51] |= ((0xFF & r->eee_en) << 0);

 // register 52
 flash_bin[52] = 0;
 flash_bin[52] |= ((0x3 & r->sleep_time_unit) << 14);
 flash_bin[52] |= ((0x7F & r->sleep_time    ) << 11);

 // register 53
 flash_bin[53] = 0;
 flash_bin[53] |= ((0x3  & r->wake_time_unit_p0) << 14);
 flash_bin[53] |= ((0x7F & r->wake_time_p0     ) <<  0);

 // register 54
 flash_bin[54] = 0;
 flash_bin[54] |= ((0x3  & r->wake_time_unit_p1) << 14);
 flash_bin[54] |= ((0x7F & r->wake_time_p1     ) <<  0);

 // register 55
 flash_bin[55] = 0;
 flash_bin[55] |= ((0x3  & r->wake_time_unit_p2) << 14);
 flash_bin[55] |= ((0x7F & r->wake_time_p2     ) <<  0);

 // register 56
 flash_bin[56] = 0;
 flash_bin[56] |= ((0x3  & r->wake_time_unit_p3) << 14);
 flash_bin[56] |= ((0x7F & r->wake_time_p3     ) <<  0);

 // register 57
 flash_bin[57] = 0;
 flash_bin[57] |= ((0x3  & r->wake_time_unit_p4) << 14);
 flash_bin[57] |= ((0x7F & r->wake_time_p4     ) <<  0);

 // register 58
 flash_bin[58] = 0;
 flash_bin[58] |= ((0x3  & r->wake_time_unit_p5) << 14);
 flash_bin[58] |= ((0x7F & r->wake_time_p5     ) <<  0);

 // register 59
 flash_bin[59] = 0;
 flash_bin[59] |= ((0x3  & r->wake_time_unit_p6) << 14);
 flash_bin[59] |= ((0x7F & r->wake_time_p6     ) <<  0);

 // register 60
 flash_bin[60] = 0;
 flash_bin[60] |= ((0x3  & r->wake_time_unit_p7) << 14);
 flash_bin[60] |= ((0x7F & r->wake_time_p7     ) <<  0);

 // register 61
 flash_bin[61] = 0;
 flash_bin[61] |= ((0xFF & r->wol_en   ) << 8);
 flash_bin[61] |= ((0x3  & r->wol_timer) << 0);

 // register 62
 flash_bin[62] = 0;
 flash_bin[62] |= ((0x3 & r->aggr_idx_sel) << 3);
 flash_bin[62] |= ((0x3 & r->aggr_mode   ) << 0);

 // register 63
 flash_bin[63] = 0;
 flash_bin[63] |= ((0xFF & r->aggr_group0) << 0);

 // register 64
 flash_bin[64] = 0;
 flash_bin[64] |= ((0xFF & r->aggr_group1) << 0);

 // register 65
 flash_bin[65] = 0;
 flash_bin[65] |= ((0xFF & r->aggr_mask0) << 0);

 // register 66
 flash_bin[66] = 0;
 flash_bin[66] |= ((0xFF & r->aggr_mask1) << 0);

 // register 67
 flash_bin[67] = 0;
 flash_bin[67] |= ((0xFF & r->aggr_mask2) << 0);

 // register 68
 flash_bin[68] = 0;
 flash_bin[68] |= ((0xFF & r->aggr_mask3) << 0);

 // register 69
 flash_bin[69] = 0;
 flash_bin[69] |= ((0xFF & r->aggr_mask4) << 0);

 // register 70
 flash_bin[70] = 0;
 flash_bin[70] |= ((0xFF & r->aggr_mask5) << 0);

 // register 71
 flash_bin[71] = 0;
 flash_bin[71] |= ((0xFF & r->aggr_mask6) << 0);

 // register 72
 flash_bin[72] = 0;
 flash_bin[72] |= ((0xFF & r->aggr_mask7) << 0);

 // register 73
 flash_bin[73] = 0;
 if(r->val_table_clr) flash_bin[73] |= (0x1 << 15);
 if(r->unvid_mode   ) flash_bin[73] |= (0x1 << 13);

 // register 74
 flash_bin[74] = 0;
 flash_bin[74] |= ((0xFF & r->vlan_cls   ) << 8);
 flash_bin[74] |= ((0xFF & r->tag_vlan_en) << 0);

 // register 75
 flash_bin[75] = 0;
 if(r->vlan_drop_cfi) flash_bin[74] |= (0x1 << 13);
 flash_bin[75] |= ((0x7  & r->rsvd_vid) << 10);
 flash_bin[75] |= ((0x3  & r->acceptable_frm_type) << 8);
 flash_bin[75] |= ((0xFF & r->vlan_ingress_filter) << 0);

 // register 76
 flash_bin[76] = 0;

 // register 77
 flash_bin[77] = 0;

 // register 78
 flash_bin[78] = r->vlan_info_0;

 // register 79
 flash_bin[79] = r->vlan_info_1;

 // register 80
 flash_bin[80] = r->vlan_info_2;

 // register 81
 flash_bin[81] = r->vlan_info_3;

 // register 82
 flash_bin[82] = r->vlan_info_4;

 // register 83
 flash_bin[83] = r->vlan_info_5;

 // register 84
 flash_bin[84] = r->vlan_info_6;

 // register 85
 flash_bin[85] = r->vlan_info_7;

 // register 86
 flash_bin[86] = 0;
 flash_bin[86] |= ((0xFF & r->add_tag) << 0);

 // register 87
 flash_bin[87] = 0;
 flash_bin[87] |= ((0xFF & r->remove_tag) << 0);

 // register 88
 flash_bin[88] = 0;
 flash_bin[88] |= (r->pbv_member_p0 << 0);
 flash_bin[88] |= (r->pbv_member_p1 << 8);

 // register 89
 flash_bin[89] = 0;
 flash_bin[89] |= (r->pbv_member_p2 << 0);
 flash_bin[89] |= (r->pbv_member_p3 << 8);

 // register 90
 flash_bin[90] = 0;
 flash_bin[90] |= (r->pbv_member_p4 << 0);
 flash_bin[90] |= (r->pbv_member_p5 << 8);

 // register 91
 flash_bin[91] = 0;
 flash_bin[91] |= (r->pbv_member_p6 << 0);
 flash_bin[91] |= (r->pbv_member_p7 << 8);

 // register 92
 flash_bin[92] = 0;
 flash_bin[92] |= ((0x3 & r->leaky_vlan) << 0);

 // register 93
 flash_bin[93] = r->vlan_valid;

 // register 94
 flash_bin[94] = 0;
 flash_bin[94] |= ((0x7FF & r->vid_0) << 0);

 // register 95
 flash_bin[95] = 0;
 flash_bin[95] |= ((0x7FF & r->vid_1) << 0);

 // register 96
 flash_bin[96] = 0;
 flash_bin[96] |= ((0x7FF & r->vid_2) << 0);

 // register 97
 flash_bin[97] = 0;
 flash_bin[97] |= ((0x7FF & r->vid_3) << 0);

 // register 98
 flash_bin[98] = 0;
 flash_bin[98] |= ((0x7FF & r->vid_4) << 0);

 // register 99
 flash_bin[99] = 0;
 flash_bin[99] |= ((0x7FF & r->vid_5) << 0);

 // register 100
 flash_bin[100] = 0;
 flash_bin[100] |= ((0x7FF & r->vid_6) << 0);

 // register 101
 flash_bin[101] = 0;
 flash_bin[101] |= ((0x7FF & r->vid_7) << 0);

 // register 102
 flash_bin[102] = 0;
 flash_bin[102] |= ((0x7FF & r->vid_8) << 0);

 // register 103
 flash_bin[103] = 0;
 flash_bin[103] |= ((0x7FF & r->vid_9) << 0);

 // register 104
 flash_bin[104] = 0;
 flash_bin[104] |= ((0x7FF & r->vid_a) << 0);

 // register 105
 flash_bin[105] = 0;
 flash_bin[105] |= ((0x7FF & r->vid_b) << 0);

 // register 106
 flash_bin[106] = 0;
 flash_bin[106] |= ((0x7FF & r->vid_c) << 0);

 // register 107
 flash_bin[107] = 0;
 flash_bin[107] |= ((0x7FF & r->vid_d) << 0);

 // register 108
 flash_bin[108] = 0;
 flash_bin[108] |= ((0x7FF & r->vid_e) << 0);

 // register 109
 flash_bin[109] = 0;
 flash_bin[109] |= ((0x7FF & r->vid_f) << 0);

 // register 110
 flash_bin[110] = 0;
 flash_bin[110] = ((0xFF & r->vlan_member_0) << 0);
 flash_bin[110] = ((0xFF & r->vlan_member_1) << 8);
 
 // register 111
 flash_bin[111] = 0;
 flash_bin[111] = ((0xFF & r->vlan_member_2) << 0);
 flash_bin[111] = ((0xFF & r->vlan_member_3) << 8);

 // register 112
 flash_bin[112] = 0;
 flash_bin[112] = ((0xFF & r->vlan_member_4) << 0);
 flash_bin[112] = ((0xFF & r->vlan_member_5) << 8);

 // register 113
 flash_bin[113] = 0;
 flash_bin[113] = ((0xFF & r->vlan_member_6) << 0);
 flash_bin[113] = ((0xFF & r->vlan_member_7) << 8);

 // register 114
 flash_bin[114] = 0;
 flash_bin[114] = ((0xFF & r->vlan_member_8) << 0);
 flash_bin[114] = ((0xFF & r->vlan_member_9) << 8);

 // register 115
 flash_bin[115] = 0;
 flash_bin[115] = ((0xFF & r->vlan_member_a) << 0);
 flash_bin[115] = ((0xFF & r->vlan_member_b) << 8);

 // register 116
 flash_bin[116] = 0;
 flash_bin[116] = ((0xFF & r->vlan_member_c) << 0);
 flash_bin[116] = ((0xFF & r->vlan_member_d) << 8);

 // register 117
 flash_bin[117] = 0;
 flash_bin[117] = ((0xFF & r->vlan_member_e) << 0);
 flash_bin[117] = ((0xFF & r->vlan_member_f) << 8);
}

void write_bin(const char *fname,uint16_t *flash_bin) {

  ofstream out(fname,ios::out | ios::binary);
  out.write((char *) flash_bin,118);
	out.close();
}

void write_hex(const char *fname,uint16_t *flash_bin) {

 FILE *out;
 
 out = fopen(fname,"wb");

 for(size_t n=0;n<118;n++) {
   fprintf(out,"%02x",0xFF & (flash_bin[n] >> 8));
   fprintf(out,"%02x",0xFF & flash_bin [n]      );
 }

 fclose(out);

}

int main() {

  ip178g_registers r;

  uint16_t flash_bin[256];
	make_ip178g_flash_bin(&r,flash_bin);

	write_bin("ip178g.bin",flash_bin);
	write_hex("ip178g.hex",flash_bin);

}
