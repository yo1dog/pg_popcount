\echo Use "CREATE EXTENSION popcount;" to load this file. \quit

CREATE FUNCTION popcount_smallint(smallint) RETURNS int
AS '$libdir/popcount', 'popcount_smallint'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION popcount_int(int) RETURNS int
AS '$libdir/popcount', 'popcount_int'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION popcount_bigint(bigint) RETURNS int
AS '$libdir/popcount', 'popcount_bigint'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION popcount_varbit(varbit) RETURNS int
AS '$libdir/popcount', 'popcount_varbit'
LANGUAGE C IMMUTABLE STRICT;