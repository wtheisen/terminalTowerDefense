#include <loadScreen.h>
#include <logging.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int loadScreen(struct Options * Opt)
{
    // initialize the ncurses system

    if (!Opt->disableNCurses) {
        noecho();
        curs_set(FALSE);
    }

    if (Opt->skipSplashScreen) return 1;

    // show the load screen

    char msg0[] = "  ______                    _             __   ______";
    char msg1[] = " /_  __/__  _________ ___  (_)___  ____ _/ /  /_  __/___ _      _____  _____";
    char msg2[] = "  / / / _ \\/ ___/ __ `__ \\/ / __ \\/ __ `/ /    / / / __ \\ | /| / / _ \\/ ___/";
    char msg3[] = " / / /  __/ /  / / / / / / / / / / /_/ / /    / / / /_/ / |/ |/ /  __/ /";
    char msg4[] = "/_/  \\___/_/  /_/ /_/ /_/_/_/ /_/\\__,_/_/    /_/  \\____/|__/|__/\\___/_/";
    char msg5[] = "";
    char msg6[] = "    ____       ____";
    char msg7[] = "   / __ \\___  / __/__  ____  ________";
    char msg8[] = "  / / / / _ \\/ /_/ _ \\/ __ \\/ ___/ _ \\";
    char msg9[] = " / /_/ /  __/ __/  __/ / / (__  )  __/";
    char msg10[]= "/_____/\\___/_/  \\___/_/ /_/____/\\___/";

    char msg_intro[] = "Developed by Alex Brizius, Bill Theisen, Michael Burke and Jose Badilla";
    char msg_instruction[] = "(Press enter to play)";

    int row, col;
    getmaxyx(stdscr, row, col);

    attron(A_BOLD);

    mvprintw(row/2-7, (col-strlen(msg_intro))/2, "%s", msg0);
    mvprintw(row/2-6, (col-strlen(msg_intro))/2, "%s", msg1);
    mvprintw(row/2-5, (col-strlen(msg_intro))/2, "%s", msg2);
    mvprintw(row/2-4, (col-strlen(msg_intro))/2, "%s", msg3);
    mvprintw(row/2-3, (col-strlen(msg_intro))/2, "%s", msg4);
    mvprintw(row/2-2, (col-strlen(msg_intro))/2, "%s", msg5);
    mvprintw(row/2-1, (col-strlen(msg_intro))/2+15, "%s", msg6);
    mvprintw(row/2, (col-strlen(msg_intro))/2+15, "%s", msg7);
    mvprintw(row/2+1, (col-strlen(msg_intro))/2+15, "%s", msg8);
    mvprintw(row/2+2, (col-strlen(msg_intro))/2+15, "%s", msg9);
    mvprintw(row/2+3, (col-strlen(msg_intro))/2+15, "%s", msg10);

    mvprintw(row/2+7, (col-strlen(msg_intro))/2, "%s", msg_intro);
    mvprintw(row/2+8, (col-strlen(msg_instruction))/2, "%s", msg_instruction);

    attroff(A_BOLD);

    int ch = 0;
    ch = getch();

    while (ch != 10)
    {
       ch = getch();
    }

    int ret = system("clear");
    (void) ret;
    return 1;   
}

void cleanup(struct Options * Opt)
{
    writeLog("Cleaning up");
    if (!Opt->disableNCurses) {
        endwin();
    }
}
