#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // For getch()

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

// Structure to represent a snake segment
typedef struct {
    int x;
    int y;
} Segment;

// Function prototypes
void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void printBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void placeFood(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void moveSnake(char board[BOARD_HEIGHT][BOARD_WIDTH], Segment *snake, int *snakeLength, int direction, int *gameRunning);

int main() {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    Segment snake[BOARD_WIDTH * BOARD_HEIGHT]; // Allocate enough space for the snake
    int snakeLength = 1;
    int gameRunning = 1;
    int direction = 0; // 0: Right, 1: Up, 2: Left, 3: Down

    // Initialize the board and place the snake
    initializeBoard(board);
    snake[0].x = BOARD_WIDTH / 2;
    snake[0].y = BOARD_HEIGHT / 2;
    board[snake[0].y][snake[0].x] = '*'; // Place the snake on the board
    placeFood(board);

    // Game loop
    while (gameRunning) {
        printBoard(board);

        // Get user input
        if (kbhit()) {
            char input = getch();
            switch (input) {
                case 'w': direction = 1; break;
                case 's': direction = 3; break;
                case 'a': direction = 2; break;
                case 'd': direction = 0; break;
            }
        }

        // Move the snake
        moveSnake(board, snake, &snakeLength, direction, &gameRunning);

        // Add a delay (adjust for difficulty)
        Sleep(100);
    }

    printf("Game Over!\n");
    return 0;
}

void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' '; // Initialize with empty space
        }
    }
}

void printBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    system("cls"); // Clear the console (Windows)
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void placeFood(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    int x, y;
    do {
        x = rand() % BOARD_WIDTH;
        y = rand() % BOARD_HEIGHT;
    } while (board[y][x] != ' '); // Ensure food is placed on an empty cell

    board[y][x] = 'O';
}

void moveSnake(char board[BOARD_HEIGHT][BOARD_WIDTH], Segment *snake, int *snakeLength, int direction, int *gameRunning) {
    // Calculate new head position
    int newX = snake[0].x;
    int newY = snake[0].y;

    switch (direction) {
        case 0: newX++; break; // Right
        case 1: newY--; break; // Up
        case 2: newX--; break; // Left
        case 3: newY++; break; // Down
    }

    // Check for collisions with walls or self
    if (newX < 0 || newX >= BOARD_WIDTH || newY < 0 || newY >= BOARD_HEIGHT || board[newY][newX] == '*') {
        *gameRunning = 0; // End the game
        return;
    }

    // Check if food is eaten
    int foodEaten = (board[newY][newX] == 'O');

    // Move the snake (shift segments)
    for (int i = *snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0].x = newX;
    snake[0].y = newY;

    // Update the board
    board[newY][newX] = '*'; // New head position
    if (!foodEaten) {
        // Clear the tail segment
        board[snake[*snakeLength - 1].y][snake[*snakeLength - 1].x] = ' ';
    } else {
        (*snakeLength)++; // Grow the snake
        placeFood(board); // Place new food
    }
}
