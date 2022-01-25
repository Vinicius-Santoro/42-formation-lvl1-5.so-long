<h1>42-formation-lvl1-5.so-long</h1>

### _Project 5: So Long - Fifth project for the formation of software engineers at school 42 São Paulo_

- This project is a very small 2D game. It is built to make we work with
textures, sprites and some very basic gameplay elements.


## _This game was like this:_

Aqui será um gif.


## _How to Play_

The game is able to play any map you want as long as it follow some specific rules:
- The map has to be a ``.ber`` file.
- It can only contain some of the following characters:

    | Character | Object |
    | - | - |
    | E | Exit. |
    | 1 | Wall. |
    | V | Enemy |
    | C | Collectable. |
    | 0 | Empty space. |
    | P | Player starting position. |


- The map must be a rectangle surrounded by walls ‘1’.
- It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

See some examples in the ``./assets/maps`` folder of this project.

### _Controls_
Use ``WASD`` to move. You move one tile at a time. Enemies move after you do, also one tile at a time, and will kill you when you move into their tile or they move into yours. After picking up all weeds, the exits open and you may leave to see how many moves you’ve used to solve the map.

You can close the game with `ESC` or `Q`.


## _How i did (mandatory)_

-   [Makefile](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/01.makefile.md)
-   [so_long.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/02.so_long.md)
-   [verify_error.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/03.verify_error.md)
-   [read_map.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/04.read_map.md)
-   [render_game.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/05.render_game.md)
-   [move.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/06.move.md)
-   [exit_free.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/07.exit_free.md)


## _How i did (bonus)_
-   [Makefile](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/01.makefile.md)
-   [so_long.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/08.so_long.md)
-   [verify_error.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/03.verify_error.md)
-   [read_map.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/10.read_map.md)
-   [render_game.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/11.render_game.md)
-   [move.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/12.move.md)
-   [exit_free.c](https://github.com/Vinicius-Santoro/42-formation-lvl1-5.so-long/blob/main/READMES/13.exit_free.md)
