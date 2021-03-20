#include <iostream>
#include <ncurses.h>

int main(int argc, char const* argv[]) {
    int32_t row, col;
    int32_t MAX_ROW, MAX_COL;
    int32_t begin_row, begin_col;

    // Initialize
    initscr();

    getyx(stdscr, row, col);
    getbegyx(stdscr, begin_row, begin_col);
    // Get terminal width and height
    getmaxyx(stdscr, MAX_ROW, MAX_COL);

    printw("%d, %d", MAX_ROW, MAX_COL);

    getch();

    endwin();

    return 0;
}