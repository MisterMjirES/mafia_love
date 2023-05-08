#include "timer.h"
#include "tm4c123gh6pm.h"

/* n, pri, prin, prio, enable, irq % 32 */
#define X_LIST \
	X(0, 4, 0x1FFFFFFF, 0x60000000, 0, 19) \
	X(1, 5, 0xFFFF1FFF, 0x00006000, 0, 21)
#define X(n, pri, prin, prio, en, irq) \
	void timer##n##_init(void) \
	{ \
		SYSCTL_RCGCTIMER_R |= (1 << n); \
		__asm ("NOP"); \
		__asm ("NOP"); \
		TIMER##n##_CTL_R = 0x0; \
		TIMER##n##_CFG_R = 0x0; /* 32 bit mode */ \
		TIMER##n##_TAMR_R = 0x2; /* Period mode */ \
		TIMER##n##_TAILR_R = 0x1; /* Reload time */ \
		TIMER##n##_TAPR_R = 0; /* Clock resolution */ \
		TIMER##n##_ICR_R = 0x3; /* Clear timeout flag */ \
		TIMER##n##_IMR_R = 0x3; /* Arm the timer */ \
		NVIC_PRI##pri##_R = (NVIC_PRI##pri##_R & prin) | prio; /* Priority (all are 3) */ \
		NVIC_EN##en##_R |= (1 << irq); \
		TIMER##n##_CTL_R = 0x0; /* Enable here to default on */ \
	}
X_LIST
#undef X
#define X(n, pri, prin, prio, en, irq) \
	void timer##n##_start(uint32_t reload) \
	{ \
		TIMER##n##_TAILR_R = reload; \
		TIMER##n##_CTL_R = 0x1; \
	}
X_LIST
#undef X
#define X(n, pri, prin, prio, en, irq) \
	void timer##n##_stop(void) \
	{ \
		TIMER##n##_CTL_R = 0x0; \
	}
X_LIST
#undef X
#undef X_LIST