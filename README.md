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
	- **WIP**: colors_textures (parser/textures_colors.c)
	- **WIP**: create_map

# TODO

1. Implement `.d` for the compilation
2. Add `ft_calloc` to the std_libtf
3. Add `ft_isprint` ("is printable") to std_libft
4. Add `ft_isdigit` to std_libft
5. Write additional tests for the function `check_input`
6. Write tests for the function `retrieve_input` which goal is to put the file content into the `data.filetab` tab
7. Write tests for the function `extract_parts`.