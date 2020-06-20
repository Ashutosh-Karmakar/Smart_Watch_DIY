#include <avr/pgmspace.h>

const unsigned char callings [] PROGMEM= { 
  0x00, 0x00, 0x00, 0xe0, 0xd0, 0xb8, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0x0f, 0x1f, 0x3f, 0x7e, 0xf9, 0xf0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1b, 0x0f, 0x06, 0x04, 0x00, 0x00, 0x00
};

const unsigned char whatsapps [] PROGMEM=  { 
  0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf0, 0x78, 0x78, 0x7c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xf0, 0xc0, 0x80, 0x09, 0x1f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0xbf, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x37, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3e, 0x3e, 0x3e, 0x1e, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00
};

const unsigned char missedcalls [] PROGMEM= { 
  0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x0f, 0x3f, 0xff, 0xff, 0xf3, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3d, 0x3d, 0x3d, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x3e, 0x7c, 0x7c, 0xfc, 0xfe, 0xff, 0xff, 0xfe, 0x7e, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00
};
const unsigned char messages [] PROGMEM= { 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7e, 0x7e, 0x46, 0xc6, 0xc6, 0xfe, 0xfe, 0xfe, 0xfe, 0xc6, 0xc6, 0xc6, 0x7e, 0x3e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const unsigned char gmails [] PROGMEM={ 
  0x00, 0x00, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0xff, 0x00, 0x01, 0x03, 0x03, 0x06, 0x0c, 0x1c, 0x18, 0x18, 0x1c, 0x0c, 0x06, 0x03, 0x03, 0x01, 0x00, 0xff, 0xff, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00
};
const unsigned char notifications [] PROGMEM = 
 { 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xe0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x3f, 0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x87, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00
};//done
  

const unsigned char stopwatchs [] PROGMEM= { 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0xbf, 0x3f, 0xbf, 0x3f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0x7c, 0x1e, 0x0e, 0x0e, 0x07, 0x07, 0x07, 0xf3, 0xf7, 0x07, 0x07, 0x07, 0x0e, 0x1e, 0x1e, 0x3c, 0xf9, 0xf3, 0xc7, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x3f, 0x3f, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1e, 0x3c, 0x78, 0x70, 0x70, 0x70, 0x60, 0xe0, 0xe0, 0xe0, 0xf0, 0x70, 0x70, 0x38, 0x3c, 0x1e, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
};//done
  


const unsigned char alarms [] PROGMEM= { 
  0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfc, 0x7c, 0x3c, 0x9c, 0xdc, 0xcc, 0xe0, 0xe0, 0x70, 0x60, 0x70, 0x70, 0x60, 0x60, 0xe0, 0xe0, 0xec, 0xdc, 0x9c, 0x3e, 0x7c, 0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 
  0xc0, 0x40, 0x03, 0x07, 0xf1, 0xfc, 0x7e, 0x0f, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xec, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x0f, 0xfe, 0xfc, 0xe1, 0x07, 0x03, 0xe0, 0x80, 
  0xfd, 0x77, 0x00, 0x00, 0x0f, 0x3f, 0xfe, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x07, 0x0e, 0x0e, 0x1c, 0x38, 0x98, 0xc0, 0xf0, 0xfe, 0x3f, 0x0f, 0x00, 0x20, 0x77, 0xdd, 
  0x01, 0x03, 0x00, 0x00, 0x1c, 0x3f, 0x7f, 0x3f, 0x3f, 0x1f, 0x0f, 0x06, 0x0e, 0x0e, 0x0e, 0x0c, 0x0c, 0x0c, 0x0e, 0x0e, 0x0e, 0x0f, 0x1f, 0x3f, 0x3f, 0x7f, 0x3f, 0x18, 0x00, 0x00, 0x03, 0x01
};//done

const unsigned char backlite [] PROGMEM= { 
  0x00, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x0c, 0x88, 0xc0, 0x40, 0x40, 0xc0, 0xe0, 0xe5, 0xe6, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x88, 0x0c, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x00, 
  0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x78, 0xfe, 0xff, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x3f, 0x77, 0x7f, 0x7f, 0xfb, 0xef, 0xed, 0x7f, 0x7d, 0x3f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};//done

const unsigned char face [] PROGMEM= { 
  0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x7c, 0xfc, 0x7e, 0x1e, 0x0e, 0x1e, 0x3f, 0x3e, 0x1e, 0x0e, 0x1e, 0x7e, 0xfc, 0x7c, 0x7c, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 
  0x40, 0xf8, 0xfe, 0xff, 0xdf, 0x8f, 0x0f, 0x04, 0x00, 0x00, 0x00, 0x18, 0x18, 0x70, 0xe0, 0x40, 0x40, 0xc0, 0x70, 0x30, 0x1c, 0x0c, 0x00, 0x00, 0x06, 0x0f, 0xcf, 0xdf, 0xff, 0xff, 0xf8, 0x80, 
  0x00, 0x3f, 0x7f, 0xff, 0xfb, 0xf1, 0xf0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xf0, 0xf1, 0xfb, 0xff, 0xff, 0x1f, 0x01, 
  0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1e, 0x3f, 0x7f, 0x7e, 0x78, 0x70, 0x78, 0x7c, 0xfc, 0x78, 0x70, 0x70, 0x7e, 0x3f, 0x3f, 0x3e, 0x1e, 0x0f, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00
};//done

const unsigned char res [] PROGMEM= { 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x7c, 0x1c, 0x0e, 0x0e, 0x07, 0xc7, 0xe7, 0xe7, 0x7b, 0x3f, 0x1f, 0x0e, 0x06, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xfc, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x3c, 0x70, 0x70, 0x70, 0x38, 0x3c, 0x0e, 0x0f, 0x83, 0xff, 0xff, 0x7f, 
  0xc0, 0xe0, 0xf0, 0x78, 0x3c, 0x0e, 0x8f, 0x83, 0x81, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xf0, 0x70, 0x70, 0x70, 0x70, 0x30, 0x38, 0x38, 0x38, 0x1c, 0x0e, 0x0f, 0x03, 0x01, 0x00, 
  0x0f, 0x1f, 0x3f, 0x70, 0xe0, 0xe1, 0xc3, 0xe7, 0xe3, 0xf0, 0x70, 0x3c, 0x1c, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};//done