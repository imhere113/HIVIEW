#ifndef __svp_h__
#define __svp_h__

#ifdef __cplusplus
extern "C" {
#endif

#include "inc/gsf.h"

//for json cfg;
#include "mod/svp/inc/sjb_svp.h"


#define GSF_IPC_SVP      "ipc:///tmp/svp_rep"
#define GSF_PUB_SVP      "ipc:///tmp/svp_pub"

enum {
    GSF_ID_SVP_CFG    = 1,  // gsf_svp_t;
    GSF_ID_SVP_MD     = 2,  // ch, gsf_svp_md_t
    GSF_ID_SVP_LPR    = 3,  // ch, gsf_svp_lpr_t
    GSF_ID_SVP_END
};

enum {
    GSF_SVP_ERR = -1,
};

enum {
  GSF_EV_SVP_MD  = 1, // gsf_svp_mds_t;
  GSF_EV_SVP_LPR = 2, // gsf_svp_lprs_t;
};


typedef struct {
  int vpssgrp;  // grp
  int vpssch;   // ch
  int level;
  int rect[4];
}gsf_svp_md_t;


typedef struct {
  int vpssgrp;  // grp
  int vpssch;   // ch
  int level;
  int rect[4];
}gsf_svp_lpr_t;


typedef struct {
  int thr;        //thr 
  int rect[4];    //����λ��
}gsf_md_result_t;


typedef struct {
  int pts;   // u64PTS/1000
  int cnt;
  int w, h;
  gsf_md_result_t result[20];
}gsf_svp_mds_t;


typedef struct {
	char 	  number[16];         //���ƺ���
	char 	  color[8];  		      //������ɫ
	float   number_realty;      //�������Ŷ�
	int     rect[4];            //��������
	int     type ;              //��������
	float   letter_realty[16];  //�ַ����Ŷ�
	float   vertangle;          //��ֱ�Ƕ�
	float   horzangle;          //ˮƽ�Ƕ�
}gsf_lpr_result_t;


typedef struct {
  int pts;   // u64PTS/1000
  int cnt;
  int w, h;
  gsf_lpr_result_t result[20];
}gsf_svp_lprs_t;


#ifdef __cplusplus
}
#endif

#endif