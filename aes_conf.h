typedef unsigned char   u1byte; /* an 8 bit unsigned character type */
typedef unsigned short  u2byte; /* a 16 bit unsigned integer type   */
typedef unsigned long   u4byte; /* a 32 bit unsigned integer type   */

typedef signed char     s1byte; /* an 8 bit signed character type   */
typedef signed short    s2byte; /* a 16 bit signed integer type     */
typedef signed long     s4byte; /* a 32 bit signed integer type     */

extern u4byte  tab_gen;
extern u4byte  k_len;
extern u4byte  e_key[60];
extern u4byte  d_key[60];

/* 2. Standard interface for AES cryptographic routines             */

/* These are all based on 32 bit unsigned values and may require    */
/* endian conversion for big-endian architectures                   */

#define LITTLE_ENDIAN

#ifdef  __cplusplus
    extern "C"
    {
#endif

    char *cipher_name(void);
    void set_key(const u1byte in_key[], const u4byte key_len);
    void encrypt(const u1byte in_blk[16], u1byte out_blk[16]);
    void decrypt(const u1byte in_blk[16], u1byte out_blk[16]);

#ifdef  __cplusplus
    };
#endif

/* 3. Basic macros for speeding up generic operations               */

/* Circular rotate of 32 bit values                                 */

#ifdef _MSC_VER

#  include <stdlib.h>
#  pragma intrinsic(_lrotr,_lrotl)
#  define rotr(x,n) _lrotr(x,n)
#  define rotl(x,n) _lrotl(x,n)

#else

#define rotr(x,n)   (((x) >> ((int)(n))) | ((x) << (32 - (int)(n))))
#define rotl(x,n)   (((x) << ((int)(n))) | ((x) >> (32 - (int)(n))))

#endif

/* Invert byte order in a 32 bit variable                           */

#define bswap(x)    (rotl(x, 8) & 0x00ff00ff | rotr(x, 8) & 0xff00ff00)

/* Extract byte from a 32 bit quantity (little endian notation)     */

#define byte(x,n)   ((u1byte)((x) >> (8 * n)))

/* Input or output a 32 bit word in machine order                                       */

#ifdef  LITTLE_ENDIAN

#define u4byte_in(x)            (*(u4byte*)(x))
#define u4byte_out(x, v)        (*(u4byte*)(x) = (v))

#else

#define u4byte_in(x)            bswap(*(u4byte)(x))
#define u4byte_out(x, v)        (*(u4byte*)(x) = bswap(v))

#endif
