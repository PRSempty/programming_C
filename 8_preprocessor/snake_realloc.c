#include <stdio.h>

#define ROWS 6
#define COLS 15 

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include <poll.h>
#include <termios.h>


void gor_gran() {
    putchar('+');
    for (int i = 0; i < COLS; i++) {
        putchar('-');
    }
    putchar('+');
    putchar('\n');

}

void pole(char *arr) {
    for (int y = 0; y < ROWS; y++) {
        putchar('|');
        for (int x = 0; x < COLS; x++){
            putchar(arr[y * COLS + x]);
        }
        putchar('|');
        putchar('\n');
    }

}

void clear_arr(char *arr) {
    for (int i = 0; i < ROWS * COLS; i++) {
            arr[i] = ' ';
        }

}


struct termios orig;

void restore_terminal(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig);
}


void setup_terminal(void) {
    tcgetattr(STDIN_FILENO, &orig);
    atexit(restore_terminal);
    struct termios raw = orig;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}


char read_key(void) {
    char c;
    struct pollfd pfd;
    pfd.fd = STDIN_FILENO;
    pfd.events = POLLIN;
    if (poll(&pfd, 1, 0) > 0) {
        read(STDIN_FILENO, &c, 1);
        return c;
    } else {
        return 0;
    }

}


void food(int *fx, int *fy, int *body, int len) {
    *fx = rand() % (COLS-1);
    *fy = rand() % (ROWS-1);
    for (int i = 0; i < len; i++) {
        if (*fx == body[i] % COLS && *fy == body[i] / COLS) {
            food(fx, fy, body, len);
            break;
        }
    }
    
    
    
}


int main(void)
{
    srand(time(NULL));
    setup_terminal();

    char arr[ROWS * COLS];
    int len = 1;

    int *body = malloc(len * sizeof(int));
    if (!body) return 1;

    int dead = 0;
    int score = 0;

    int headx = 0;
    int heady = 2;

    int r_foodx = 10;
    int r_foody = 2;

    int dx = 1;
    int dy = 0;

    body[0] = heady * COLS + headx;
    

    for (int i = 0; i < ROWS * COLS; i++) {
            arr[i] = ' ';
        }

    while (dead != 1 && score != 300) {
        char m = read_key();
        switch (m) {
            case 'w':
                if (dy != 1 || len == 1) {
                    dx = 0; dy = -1; 
                }
                break;
            case 'a':
                if (dx != 1 || len == 1) {
                    dx = -1; dy = 0;
                }
                break;
            case 's':
                if (dy != -1 || len == 1) {
                    dx = 0; dy = 1;
                }
                break;
            case 'd':
                if (dx != -1 || len == 1) {
                    dx = 1; dy = 0;
                }
                break;
            case 'q':
                printf("\033[H\033[J");
                printf("Exited!\nScore: %d\n", score);
                free(body);
                return 0;
        }
        headx += dx;
        heady += dy;

        if (headx < 0 || headx >= COLS || heady < 0 || heady >= ROWS) {
            dead += 1;
            break;
        }

        for (int i = 0; i < len; i++) {
            if (headx == body[i] % COLS && heady == body[i] / COLS) {
                dead += 1;
                break;
            }
        }
        if (dead == 1) {
            break;
        }
        

        int ate = (headx == r_foodx &&  heady == r_foody);
        if (ate) {
            len += 1;
            score += 10;
            body = realloc(body, len * sizeof(int));
            for (int i = len - 1; i > 0; i--) {
                body[i] = body[i - 1];
            }
            body[0] = heady * COLS + headx;
            food(&r_foodx, &r_foody, body, len);

        } else {
            for (int i = len - 1; i > 0; i--) {
                body[i] = body[i - 1];
            }
            body[0] = heady * COLS + headx;
        }


        clear_arr(arr);
        arr[r_foody * COLS + r_foodx] = '*';

        for (int i = 1; i < len; i++) {
            arr[body[i]] = 'o';
            arr[body[0]] = '#';
        }

        arr[heady * COLS + headx] = '#';
        
        
        printf("\033[H\033[J");
        
        gor_gran();
        pole(arr);
        gor_gran();
        printf("Score: %d\n", score);
        fflush(stdout);
        
        
        if (len < 5) {
            usleep(350000);
        } else if (len < 10) {
            usleep(300000);
        } else if (len < 15) {
            usleep(250000);
        } else if (len < 20){
            usleep(225000);
        } else {
            usleep(200000);
        }
        

        
    }
    if (dead == 1) {
        usleep(50000);
        printf("\033[H\033[J");
        printf("Game Over!\nFinal Score: %d\n", score);
    } else if (score == 300) {
        usleep(50000);
        printf("\033[H\033[J");
        printf("YOU WON!\nFinale Score: %d\n", score);
    }
    free(body);
    return 0;
}
