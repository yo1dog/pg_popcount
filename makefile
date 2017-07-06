EXTENSION = popcount
DATA = popcount--0.0.1.sql
MODULES = popcount
REGRESS = popcount_test

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
