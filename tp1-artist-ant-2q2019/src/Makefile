
all: tp0_if tp0_tables tp0_tables_pf tp0_if_pf

prof: tp0_if_pf tp0_tables_pf

col_major:tp0_if_col_major tp0_tables_col_major

global_dims: tp0_tables_global_dims

tp0_if: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c ant_engine_jumps.c artist_ant.c 
	gcc -g $^ -o $@

tp0_tables: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c ant_engine_tables.c artist_ant.c 
	gcc -g -DUSE_TABLES $^ -o $@

tp0_if_pf: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c ant_engine_jumps.c artist_ant.c 
	gcc -no-pie -pg -g -DSANITY_CHECK $^ -o $@

tp0_tables_pf: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c ant_engine_tables.c artist_ant.c
	gcc -no-pie -pg -g -DUSE_TABLES $^ -o $@

tp0_if_col_major: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c ant_engine_jumps.c artist_ant.c 
	gcc -no-pie -pg -g -DUSE_COL_MAJOR $^ -o $@

tp0_tables_col_major: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c ant_engine_tables.c artist_ant.c 
	gcc -no-pie -pg -g -DUSE_TABLES -DUSE_COL_MAJOR $^ -o $@

tp0_tables_global_dims: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c ant_engine_tables.c artist_ant.c 
	gcc -g -DUSE_TABLES -DUSE_GLOBAL_GRID_DIMS $^ -o $@

gen_asm:
	gcc -g  ant_engine_tables.c -c  -o ant_engine_tables.o -mno-mips16 -mgp32 -mfp32 -gpubnames  -mlong32 -mips1 -mabicalls -mlong-calls -mframe-header-opt -march=r2k
clean:
	rm tp0_*
