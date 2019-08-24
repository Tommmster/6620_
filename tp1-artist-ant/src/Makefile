
tp0_if: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c artist_ant.c 
	gcc -g $^ -o $@

tp0_if_col_major: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c artist_ant.c 
	gcc -g $^ -DUSE_COL_MAJOR -o $@

tp0_tables: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c artist_ant.c 
	gcc -g $^ -DUSE_TABLES -o $@

tp0_tables_col_major: square_grid.c builders.c palette.c rules.c square_grid.c ant_engine.c artist_ant.c 
	gcc -g $^ -DUSE_TABLES -DUSE_COL_MAJOR  -o $@
clean:
	rm *.o tp0_*
