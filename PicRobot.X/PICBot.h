#ifndef PICBOTH
   #define PICBOTH

#include "irdetect.h" 

#define BOT_FORWARD		DIRECTV_UP
#define BOT_BACKWARD	DIRECTV_DOWN
#define BOT_RIGHT		DIRECTV_RIGHT
#define BOT_LEFT		DIRECTV_LEFT
#define BOT_STOP		DIRECTV_SELECT

#ifdef PICBOTC
	#define _SCOPE_ /**/
#else
 	#define _SCOPE_ extern
#endif
_SCOPE_ void PICBOT_Stop(void);
_SCOPE_ void PICBOT_fwd(void);
_SCOPE_ void PICBOT_rvs(void); //reverse;
_SCOPE_ void PICBOT_lft(void);
_SCOPE_ void PICBOT_rgt(void);

_SCOPE_ void PICBOT_Task(void);

#endif /* safety check for duplicate .h file */