#include <ncurses.h>

#define GREEN_COLOR 1
#define RED_COLOR 2
#define BLUE_COLOR 3
#define MAGENTA_COLOR 4
#define WHITE_COLOR 5

typedef struct {
  WINDOW *win;
  int height, width, x, y;
} WIN;

WINDOW *InitScreen() {
  WINDOW *stdwin;
  stdwin = initscr();

  start_color();
  init_pair(GREEN_COLOR, COLOR_WHITE, COLOR_GREEN);
  init_pair(RED_COLOR, COLOR_WHITE, COLOR_RED);
  init_pair(WHITE_COLOR, COLOR_BLACK, COLOR_WHITE);
  init_pair(BLUE_COLOR, COLOR_WHITE, COLOR_BLUE);
  init_pair(MAGENTA_COLOR, COLOR_WHITE, COLOR_MAGENTA);

  cbreak();
  curs_set(0);
  noecho();
  return stdwin;
}

WIN *InitWindow(WINDOW *parent, int width, int height, int y, int x,
                char *title) {
  WIN *tempWin = new WIN;
  tempWin->height = height;
  tempWin->width = width;
  tempWin->x = x;
  tempWin->y = y;
  tempWin->win = subwin(parent, height, width, y, x);
  box(tempWin->win, 0, 0); // drawing border for our window
  nodelay(tempWin->win, true);
  mvwprintw(tempWin->win, 0, 1, "%s", title);
  return tempWin;
}
