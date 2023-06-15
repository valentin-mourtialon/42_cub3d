# Dev cub3d
This is the `dev` branch Readme.

See `main` branch for the project's Readme.

# Program details

1. check_input (parser/input_check.c)
2. init_data (init/init_data.c)
3. retrieve_input (parser/input_retrieve.c)
4. parse (parser/input_parse.c) 
	- extract_parts (parser/input_parse.c)
	- cardinals_textures (parser/textures_cardinals.c)
	- colors_textures (parser/textures_colors.c)
	- create_map (parser/map_create.c)
5. check_map (parser/map_check.c && parser/map_borders_check.c)
6. **WIP** check_textures (parser/textures_check.c)

# TODO

1. Implement `.d` for the compilation
2. Write additional tests for the function `check_input`
3. Write tests for the function `retrieve_input` which goal is to put the file content into the `data.filetab` tab
4. Write tests for the function `extract_parts` and `parse`
5. Write all the tests for the `check_map` function.

# Do not forget !

1. Compilation add `.d`
2. Compilation: do not display useless message when files have already been compiled ! People would think the Makefile is 'relinking'...
3. Issue to solve: INVALID_TEXTURE. The initial player position is taken into account (and we don't want that at this stage): File `input_parse`.
4. Border left side of the map has to be checked !
