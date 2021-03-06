/*
  MOSTLora.h - Library for MOST Link Lora
  MOST-Link protocol

  Created by Macbear Chen, Auguest 12, 2016.
  Released into the public domain.
*/

#ifndef __MLpacket_h
#define __MLpacket_h

// downlink packet header for MOST Link (14 bytes)
struct MLDownlink {

    unsigned char preamble[2];      // 0xFB FC
    unsigned char version;
    unsigned char length;
    // --------
    unsigned char flag;             // 0
    unsigned char receiver_id[8];
    unsigned char headerCrc;
    
    MLDownlink(unsigned char ver, unsigned char len, unsigned char flg, unsigned char *r_id);
};

// uplink packet header for MOST Link (22 bytes)
struct MLUplink {
    unsigned char preamble[2];      // 0xFB FC
    unsigned char version;
    unsigned char length;
    // --------
    unsigned char flag;             // 0
    unsigned char receiver_id[8];
    unsigned char sender_id[8];
    unsigned char headerCrc;

    MLUplink(unsigned char ver, unsigned char len, unsigned char flg, unsigned char *s_id, unsigned char *r_id);
};

#endif // __MLpacket_h

