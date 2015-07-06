/***************************************************************
 * This confidential and  proprietary  software may be used only
 * as authorised  by  a licensing  agreement  from  ARM  Limited
 *
 *             (C) COPYRIGHT 2013-2014 ARM Limited
 *                      ALL RIGHTS RESERVED
 *
 *  The entire notice above must be reproduced on all authorised
 *  copies and copies  may only be made to the  extent permitted
 *  by a licensing agreement from ARM Limited.
 *
 ***************************************************************/

#ifndef __UNVIC_H__
#define __UNVIC_H__

#define UNVIC_MIN_PRIORITY (uint32_t) 1

typedef struct {
    TIsrVector hdlr;
    uint8_t    id;
} TIsrUVector;

extern TIsrUVector g_unvic_vector[IRQ_VECTORS];

extern void     unvic_isr_set(uint32_t irqn, uint32_t vector, uint32_t flag);
extern uint32_t unvic_isr_get(uint32_t irqn);

extern void     unvic_irq_enable(uint32_t irqn);
extern void     unvic_irq_disable(uint32_t irqn);
extern void     unvic_irq_pending_clr(uint32_t irqn);
extern void     unvic_irq_pending_set(uint32_t irqn);
extern uint32_t unvic_irq_pending_get(uint32_t irqn);
extern void     unvic_irq_priority_set(uint32_t irqn, uint32_t priority);
extern uint32_t unvic_irq_priority_get(uint32_t irqn);

extern void unvic_init(void);

void unvic_isr_mux(void);

#endif/*__UNVIC_H__*/