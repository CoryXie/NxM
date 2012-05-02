#ifndef __STDARG
#define __STDARG

typedef char *va_list;

#define va_start(list, start) list =\
	(sizeof(start) < 4?\
		(char*)((int*)&(start)+1):\
		(char*)(&(start)+1))
#define va_end(list)
#define va_arg(list, mode)\
	((sizeof(mode) == 1)?\
		((list += 4), (mode*)list)[-4]:\
	(sizeof(mode) == 2)?\
		((list += 4), (mode*)list)[-2]:\
	sizeof(mode)>4?\
		((mode*)(list = (char*)((long)(list+7) & ~7) + sizeof(mode)))[-1]:\
		((list += sizeof(mode)), (mode*)list)[-1])

#endif /* __STDARG */
