/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_PTP_CLOCK_H
#define Z_INCLUDE_SYSCALLS_PTP_CLOCK_H


#include <zephyr/tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <stdarg.h>

#include <syscall_list.h>
#include <zephyr/syscall.h>

#include <zephyr/linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_ptp_clock_get(const struct device * dev, struct net_ptp_time * tm);

__pinned_func
static inline int ptp_clock_get(const struct device * dev, struct net_ptp_time * tm)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; struct net_ptp_time * val; } parm1 = { .val = tm };
		return (int) arch_syscall_invoke2(parm0.x, parm1.x, K_SYSCALL_PTP_CLOCK_GET);
	}
#endif
	compiler_barrier();
	return z_impl_ptp_clock_get(dev, tm);
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define ptp_clock_get(dev, tm) ({ 	int syscall__retval; 	sys_port_trace_syscall_enter(K_SYSCALL_PTP_CLOCK_GET, ptp_clock_get, dev, tm); 	syscall__retval = ptp_clock_get(dev, tm); 	sys_port_trace_syscall_exit(K_SYSCALL_PTP_CLOCK_GET, ptp_clock_get, dev, tm, syscall__retval); 	syscall__retval; })
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */
