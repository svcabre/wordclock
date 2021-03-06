#ifndef TIME_H
#define TIME_H

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "Chronodot.h"  // Real time clock library    - https://github.com/Stephanie-Maks/Arduino-Chronodot

// The real time clock chip (DS3231)
extern Chronodot RTC;

#define TIME_MODE_NORMAL         0
#define TIME_MODE_SETTING_HOUR   1
#define TIME_MODE_SETTING_MINUTE 2


// Clock variables
extern byte h, m;

#define TIME_INTERVAL 1000 // Update time every second, this way the colon will blink and the numbers will change at minute changes

void timeManager(unsigned long now, boolean modeChanged);

// Initializes the RTC
void initRTC();

// Fill h and m variables with the current time from the RTC
void getRTCtime();

// Update time in the RTC using h and m variables
void updateRTCtime();

// Show the time with the currently selected clock mode
void showTime();

// Show the current time on the display using digits
void showTimeDigits();

// Show the current time on the display using words
void showTimeWords();

// Words
// Format: { line index, start position index, length }
const byte           w_es[3] PROGMEM = { 0,  0, 2 };
const byte          w_son[3] PROGMEM = { 0,  2, 3 };    
const byte        w_falta[3] PROGMEM = { 0,  5, 5 };
const byte       w_falten[3] PROGMEM = { 0, 10, 6 };
      
const byte    w_f_set_min[3] PROGMEM = { 1,  0, 3 };
const byte    w_f_sis_min[3] PROGMEM = { 1,  3, 3 };
const byte   w_f_cinc_min[3] PROGMEM = { 1,  6, 4 };
const byte w_f_quatre_min[3] PROGMEM = { 1, 10, 6 };
const byte   w_f_tres_min[3] PROGMEM = { 2,  0, 4 };
const byte    w_f_dos_min[3] PROGMEM = { 2,  4, 3 };
const byte     w_f_un_min[3] PROGMEM = { 2,  7, 2 };
const byte      w_f_minut[3] PROGMEM = { 2, 10, 5 };
const byte     w_f_minuts[3] PROGMEM = { 2, 10, 6 };

const byte          w_per[3] PROGMEM = { 4,  0, 3 };
const byte            w_a[3] PROGMEM = { 4,  4, 1 };
const byte           w_la[3] PROGMEM = { 4,  6, 2 };
const byte          w_les[3] PROGMEM = { 4,  9, 3 };
const byte        w_mig_q[3] PROGMEM = { 4, 13, 3 };

const byte         w_un_q[3] PROGMEM = { 5,  0, 2 };
const byte        w_dos_q[3] PROGMEM = { 5,  2, 3 }; 
const byte       w_tres_q[3] PROGMEM = { 5,  5, 4 };
const byte        w_quart[3] PROGMEM = { 5, 10, 5 };
const byte       w_quarts[3] PROGMEM = { 5, 10, 6 };

const byte           w_im[3] PROGMEM = { 6,  0, 1 };
const byte          w_mig[3] PROGMEM = { 6,  2, 3 };

const byte  w_h_d_apost_u[3] PROGMEM = { 6,  6, 1 };
const byte        w_h_una[3] PROGMEM = { 6,  7, 3 };
const byte         w_h_de[3] PROGMEM = { 6, 11, 2 };
const byte       w_h_dues[3] PROGMEM = { 7,  0, 4 };
const byte       w_h_tres[3] PROGMEM = { 7,  5, 4 };
const byte     w_h_quatre[3] PROGMEM = { 7, 10, 6 };
const byte       w_h_cinc[3] PROGMEM = { 8,  0, 4 };
const byte        w_h_sis[3] PROGMEM = { 8,  5, 3 };
const byte        w_h_set[3] PROGMEM = { 8,  8, 3 };
const byte       w_h_vuit[3] PROGMEM = { 8, 12, 4 };
const byte        w_h_nou[3] PROGMEM = { 9,  0, 3 };
const byte        w_h_deu[3] PROGMEM = { 9,  3, 3 };
const byte  w_h_d_apost_o[3] PROGMEM = { 9,  6, 1 };
const byte       w_h_onze[3] PROGMEM = { 9,  7, 4 };
const byte      w_h_dotze[3] PROGMEM = { 9, 11, 5 };

const byte         w_h_en[3] PROGMEM = { 10, 0, 2 };
const byte       w_h_punt[3] PROGMEM = { 10, 3, 4 };

const byte      w_i_p_min[3] PROGMEM = { 10, 8, 1 };
const byte     w_p_un_min[3] PROGMEM = { 10,10, 2 };
const byte    w_p_dos_min[3] PROGMEM = { 10,13, 3 };
const byte   w_p_tres_min[3] PROGMEM = { 11, 0, 4 };
const byte w_p_quatre_min[3] PROGMEM = { 11, 5, 6 };
const byte   w_p_cinc_min[3] PROGMEM = { 11,12, 4 };
const byte    w_p_sis_min[3] PROGMEM = { 12, 0, 3 };
const byte      w_p_minut[3] PROGMEM = { 12, 4, 5 };
const byte     w_p_minuts[3] PROGMEM = { 12, 4, 6 };

const byte          w_del[3] PROGMEM = { 13, 1, 3 };

const byte         w_mati[3] PROGMEM = { 14, 0, 4 };
const byte       w_migdia[3] PROGMEM = { 15, 0, 6 };
const byte        w_tarda[3] PROGMEM = { 15, 7, 5 };
const byte          w_nit[3] PROGMEM = { 15,13, 3 };
      
const byte w_minuts_falten[7][3] PROGMEM = {
  { 1,  0, 3 }, // set
  { 1,  3, 3 }, // sis
  { 1,  6, 4 }, // cinc
  { 1, 10, 6 }, // quatre
  { 2,  0, 4 }, // tres
  { 2,  4, 3 }, // dos
  { 2,  7, 2 }  // un
};

const byte w_minuts_passen[6][3] PROGMEM = {
  { 10,10, 2 }, // un
  { 10,13, 3 }, // dos
  { 11, 0, 4 }, // tres
  { 11, 5, 6 }, // quatre
  { 11,12, 4 }, // cinc
  { 12, 0, 3 } // sis
};

const byte w_hores[12][3] PROGMEM = {
  { 6,  7, 3 }, // una
  { 7,  0, 4 }, // dues
  { 7,  5, 4 }, // tres
  { 7, 10, 6 }, // quatre
  { 8,  0, 4 }, // cinc
  { 8,  5, 3 }, // sis
  { 8,  8, 3 }, // set
  { 8, 12, 4 }, // vuit
  { 9,  0, 3 }, // nou
  { 9,  3, 3 }, // deu
  { 9,  7, 4 }, // onze
  { 9, 11, 5 }  // dotze  
};

void afegirDpelsQuarts(byte h2);

void afegirLaLesHores(byte hora);

void afegirEsSon(byte hora, byte minut);

#endif


