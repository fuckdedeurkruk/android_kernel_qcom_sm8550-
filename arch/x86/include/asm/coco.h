/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_X86_COCO_H
#define _ASM_X86_COCO_H

#include <asm/asm.h>
#include <asm/types.h>

enum cc_vendor {
	CC_VENDOR_NONE,
	CC_VENDOR_AMD,
	CC_VENDOR_INTEL,
};

extern u64 cc_mask;
#ifdef CONFIG_ARCH_HAS_CC_PLATFORM
extern enum cc_vendor cc_vendor;
static inline void cc_set_mask(u64 mask)
{
	RIP_REL_REF(cc_mask) = mask;
}

u64 cc_mkenc(u64 val);
u64 cc_mkdec(u64 val);
#else
#define cc_vendor (CC_VENDOR_NONE)

static inline u64 cc_mkenc(u64 val)
{
	return val;
}

static inline u64 cc_mkdec(u64 val)
{
	return val;
}
#endif

#endif /* _ASM_X86_COCO_H */