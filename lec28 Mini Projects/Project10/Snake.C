// Snake Game
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// // Game board dimensions
// #define HEIGHT 15
// #define WIDTH 20

// // Function prototypes
// void setupGame(char board[HEIGHT][WIDTH], int *snakeX, int *snakeY, int *foodX, int *foodY, int *score, int *gameOver);
// void drawBoard(const char board[HEIGHT][WIDTH], int score);
// void inputMovement(char *direction);
// void updateLogic(char board[HEIGHT][WIDTH], int *snakeX, int *snakeY, int *foodX, int *foodY, char direction, int *score, int *gameOver);

// int main() 
// {
//     char board[HEIGHT][WIDTH];
    
//     // Snake position tracking variables
//     int snakeX, snakeY;
//     int foodX, foodY;
    
//     int score;
//     int gameOver;
//     char direction;

//     // Seed the random number generator for placing food
//     srand(time(NULL));

//     // Initialize all values
//     setupGame(board, &snakeX, &snakeY, &foodX, &foodY, &score, &gameOver);
//     direction = 'D'; // Start by moving Right

//     // Main Game Loop
//     while (!gameOver) 
//     {
//         drawBoard(board, score);
//         inputMovement(&direction);
//         updateLogic(board, &snakeX, &snakeY, &foodX, &foodY, direction, &score, &gameOver);
//     }

//     printf("\n=============================\n");
//     printf("         GAME OVER!          \n");
//     printf("=============================\n");
//     printf("Final Score: %d points\n\n", score);

//     return 0;
// }

// // 1. Setup Function: Initializes the grid map boundaries and scores
// void setupGame(char board[HEIGHT][WIDTH], int *snakeX, int *snakeY, int *foodX, int *foodY, int *score, int *gameOver)
// {
//     *score = 0;
//     *gameOver = 0;
    
//     // Put snake in the middle of the board
//     *snakeX = HEIGHT / 2;
//     *snakeY = WIDTH / 2;

//     // Spawn the first piece of food randomly
//     *foodX = (rand() % (HEIGHT - 2)) + 1;
//     *foodY = (rand() % (WIDTH - 2)) + 1;

//     // Build the grid walls
//     for (int i = 0; i < HEIGHT; i++) 
//     {
//         for (int j = 0; j < WIDTH; j++) 
//         {
//             if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) 
//             {
//                 board[i][j] = '#'; // Border wall
//             } 
//             else if (i == *snakeX && j == *snakeY) 
//             {
//                 board[i][j] = 'O'; // Snake Head
//             } 
//             else if (i == *foodX && j == *foodY) 
//             {
//                 board[i][j] = '*'; // Food item
//             } 
//             else 
//             {
//                 board[i][j] = ' '; // Empty space
//             }
//         }
//     }
// }

// // 2. Display Function: Refreshes the board layout on screen
// void drawBoard(const char board[HEIGHT][WIDTH], int score)
// {
//     // Clear the terminal screen based on system type
//     #ifdef _WIN32
//         system("cls");
//     #else
//         system("clear");
//     #endif

//     printf("=== CLASSIC SNAKE GAME ===\n");
//     for (int i = 0; i < HEIGHT; i++) 
//     {
//         for (int j = 0; j < WIDTH; j++) 
//         {
//             printf("%c", board[i][j]);
//         }
//         printf("\n");
//     }
//     printf("Score: %d\n", score);
//     printf("Controls: W (Up) | S (Down) | A (Left) | D (Right)\n");
// }

// // 3. Input Function: Takes direction updates using pointers
// void inputMovement(char *direction)
// {
//     char userInput;
//     printf("Enter Move: ");
//     scanf(" %c", &userInput);
    
//     // Capitalize letter input
//     if (userInput >= 'a' && userInput <= 'z') 
//     {
//         userInput -= 32;
//     }

//     // Keep direction if user selects a valid option
//     if (userInput == 'W' || userInput == 'A' || userInput == 'S' || userInput == 'D') 
//     {
//         *direction = userInput;
//     }
// }

// // 4. Logic Function: Process rules, wall bounds, and scores
// void updateLogic(char board[HEIGHT][WIDTH], int *snakeX, int *snakeY, int *foodX, int *foodY, char direction, int *score, int *gameOver)
// {
//     // Clear old snake position from grid array 
//     board[*snakeX][*snakeY] = ' ';

//     // Calculate next movement step
//     switch (direction) 
//     {
//         case 'W': (*snakeX)--; break; // Up
//         case 'S': (*snakeX)++; break; // Down
//         case 'A': (*snakeY)--; break; // Left
//         case 'D': (*snakeY)++; break; // Right
//     }

//     // Collision Check: Did the snake hit a border wall?
//     if (*snakeX == 0 || *snakeX == HEIGHT - 1 || *snakeY == 0 || *snakeY == WIDTH - 1) 
//     {
//         *gameOver = 1;
//         return;
//     }

//     // Food Collision Check: Did the snake eat the food?
//     if (*snakeX == *foodX && *snakeY == *foodY) 
//     {
//         (*score) += 10;
        
//         // Spawn a new piece of food inside open spaces
//         *foodX = (rand() % (HEIGHT - 2)) + 1;
//         *foodY = (rand() % (WIDTH - 2)) + 1;
//         board[*foodX][*foodY] = '*';
//     }

//     // Render snake head in its new position on the board
//     board[*snakeX][*snakeY] = 'O';
// }
