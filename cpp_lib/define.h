#ifndef SIMPLE_LOGIC_DEFINE_H_
#define SIMPLE_LOGIC_DEFINE_H_

typedef unsigned char	BYTE;
//typedef short			int2;
//typedef int			int4;
typedef unsigned short	uint2;
typedef unsigned int	uint4;
//typedef long			long4;
typedef long long		long8;
typedef unsigned int	ulong4;
typedef unsigned long long ulong8;


inline
ulong8 MAKE_COMUSRID(ulong8 brandid, ulong8 userid)
{
    return ((brandid << 32) | userid);
}

inline
ulong4 GET_BRANDID(ulong8 comusrid)
{
    return (comusrid >> 32);
}

inline
ulong4 GET_USERID(ulong8 comusrid)
{
    return (ulong4)comusrid;
}

#define INVALID_TABLEID  -1 
#define INVALID_SEAT  -1    

#endif
