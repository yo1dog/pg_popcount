# pg_popcount

popcount (population count/sideways sum/bit summation) for PostgreSQL writen in C for performance.

Supports `smallint`, `int`, `bigint`, and `bit`/`varbit`.

Can be used to calculate the [hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) between two integers or bit strings.

## Usage

```sql
CREATE EXTENSION popcount;
SELECT popcount_smallint(11693::smallint);     -- returns 9  (0010110110101101)
SELECT popcount_int     (-1381126739);         -- returns 20 (10101101101011011010110110101101)
SELECT popcount_bigint  (3291477864132488621); -- returns 39 (0010110110101101101011011010110110101101101011011010110110101101)
SELECT popcount_varbit  (B'11011');            -- returns 4

-- calculate hamming distance
SELECT popcount_int   (123 # 456);
SELECT popcount_varbit(B'11011' # B'01111');
```

## Build & Install

Requires PGXS. This is included with developer installations of PostgreSQL server. Ex: `yum install postgresql-devel`/`apt-get install postgresql-server-dev-all`/etc. ).

```
make
make install
```

## Test

```
make installcheck
```

## TODO:
- Combine functions into a single polymorphic `popcount` function.