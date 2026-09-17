#include <SFML/Graphics.h>

int main(void)
{
	int xSize = 800;
	int ySize = 600;

	char backboard[xSize][ySize];

	backboard[50][50] = 255;

	sfRenderWindow *window;

	sfVideoMode video_mode = {xSize, ySize, 32};
	sfEvent event;

	window = sfRenderWindow_create(video_mode, "test", sfClose, NULL);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed) {
				sfRenderWindow_close(window);
			}
		}
		sfRenderWindow_display(window);
	}
}