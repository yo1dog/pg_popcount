#include "postgres.h"
#include "fmgr.h"
#include "utils/varbit.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(popcount_smallint);
Datum popcount_smallint(PG_FUNCTION_ARGS) {
  int16 sv = PG_GETARG_INT16(0);
  u_int16_t v = 0 | sv;
  
  // http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; v; c++) {
    v &= v - 1; // clear the least significant bit set
  }
  
  PG_RETURN_INT32(c);
}

PG_FUNCTION_INFO_V1(popcount_int);
Datum popcount_int(PG_FUNCTION_ARGS) {
  int32 sv = PG_GETARG_INT32(0);
  u_int32_t v = 0 | sv;
  
  // http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; v; c++) {
    v &= v - 1; // clear the least significant bit set
  }
  
  PG_RETURN_INT32(c);
}

PG_FUNCTION_INFO_V1(popcount_bigint);
Datum popcount_bigint(PG_FUNCTION_ARGS) {
  int64 sv = PG_GETARG_INT64(0);
  u_int64_t v = 0 | sv;
  
  // http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; v; c++) {
    v &= v - 1; // clear the least significant bit set
  }
  
  PG_RETURN_INT32(c);
}


unsigned int __popcount_byte(unsigned char v);

PG_FUNCTION_INFO_V1(popcount_varbit);
Datum popcount_varbit(PG_FUNCTION_ARGS) {
  VarBit* v = PG_GETARG_VARBIT_P(0);
  
  unsigned int num_bytes = VARBITBYTES(v);
  unsigned char* byte = VARBITS(v);
  unsigned int n = 0;
  
  for (int i = 0; i < num_bytes; ++i) {
    n += __popcount_byte(*byte);
    ++byte;
  }
  
  PG_RETURN_INT32(n);
}

unsigned int __popcount_byte(unsigned char v) {
  // http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; v; c++) {
    v &= v - 1; // clear the least significant bit set
  }
  
  return c;
}