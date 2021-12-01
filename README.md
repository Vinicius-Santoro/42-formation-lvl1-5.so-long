<h1>42-formation-lvl1-5.so-long</h1>

### _Project 5: So Long - Fifth project for the formation of software engineers at school 42 São Paulo_

- This project is a very small 2D game. It is built to make we work with
textures, sprites and some very basic gameplay elements.

<h1></h1>

### _1: solong.c_

```c

#include "../../includes/mandatory/so_long.h"

static void	check_file_ext(const char *filename);
static void	init_params(t_data *my_data);

int	main(int argc, char **argv)
{
	const char	*filename;
	t_data		my_data;

	if (argc < 2)
		print_error(5);
	else if (argc > 2)
		print_error(6);
	else
		filename = argv[1];
	validate_map(filename, &my_data);
	my_data.game.mlx = mlx_init();
	my_data.game.mlx_win = mlx_new_window(my_data.game.mlx, my_data.map.width,
			my_data.map.height, "So long");
	mlx_hook(my_data.game.mlx_win, 33, 1L << 17, close_window, &my_data);
	mlx_key_hook(my_data.game.mlx_win, &key_press, &my_data);
	render_map(&my_data);
	mlx_expose_hook(my_data.game.mlx_win, &render_map, &my_data);
	mlx_loop(my_data.game.mlx);
	free(&my_data);
}
```
<h1></h1>

```c
main(int argc, char **argv)
```
_Usamos esses parâmetros na main para receber valores inputados no terminal._

- `argc`: quantidade de parâmetros a serem recebidos.
- `argv`: nome dos parâmetros a serem recebidos.

<h1></h1>

```c
const char	*filename;
```
_Definição da variável para o mapa do jogo._

<h1></h1>

```c
t_data		my_data;
```
_Definição da variável do tipo `t_data` para armazenar todos os dados do jogo._

<h1></h1>

```c
if (argc < 2)
	print_error(5);
else if (argc > 2)
	print_error(6);
else
	filename = argv[1];
```
_Estrutura condicional para verificação de erros no input do terminal._

- Se, a quantidade de argumentos for < 2, então o usuário receberá a mensagem de erro 5, que é: `map file missing.`
- Se não se, quantidade de argumentos > 2, então o usuário receberá a mensagem de erro 6, que é: `too many arguments.`
- Se não, filename recebe o nome do mapa.
- Observação: O índice 0 é o `solong.a` e o índice 1 é o `map.ber`. argv[0] = `solong.a` e argv[1] = `map1.ber`

<h1></h1>

```c
validate_map(filename, &my_data);
```
_Esta função valida se o mapa (arquivo.ber) é valido ou não. O funcionamento dessa função é:_

```c
void	validate_map(const char *filename, t_data *my_data)
{
	int		opened_map;

	check_file_ext(filename);
	opened_map = open(filename, O_RDONLY);
	if (opened_map < 0)
		print_error(7);
	else
	{
		init_params(my_data);
		generate_map(opened_map, my_data);
		close(opened_map);
	}
}
```



