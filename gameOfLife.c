#include <stdio.h>

/*
The Game of Life is a cellular automaton created by mathematician John Conway. 
It is played on an infinite two-dimensional grid of square cells, 
each of which can be either alive or dead.

->The rules for the game of life are:

1) Any live cell with fewer than two live neighbors dies, as if by underpopulation.
2) Any live cell with two or three live neighbors lives on to the next generation.
3) Any live cell with more than three live neighbors dies, as if by overpopulation.
4) Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

These rules are applied to every cell simultaneously, 
and the next generation of the grid is created. 
The process is repeated infinitely or until a specific condition is met. 
The game of life is known for its complex, 
self-organizing patterns that emerge from simple initial configurations.


https://playgameoflife.com/

*/

void main(){
    int empty = 0;
    int populated = 1;

    int rows, columns;
    int row, column;

    int step, steps;
    
    printf("The Game of Life Simulation\n");

    printf("Enter the number of rows and columns for a matrix\n");
    printf("Rows: ");
    scanf("%d", &rows);
    printf("Columns: ");
    scanf("%d", &columns);

    int matrix[rows][columns], new_matrix[rows][columns];

    printf("Enter a matrix:\n");
    for(row=0; row < rows; row++){
        for(column=0; column < columns; column++){
            scanf("%d", &matrix[row][column]);
        }
    }

    printf("Enter the number of steps: ");
    scanf("%d", &steps);

    for(row=0; row < rows; row++){
        for(column=0; column < columns; column++){
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
    

    /* 
    3x3 matrix visualization:
    
    ======================================================
    | top left (0,0)   | top (0,1)   | top right (0,2)   |
    ======================================================
    | left (1,0)       | main (1,1)  | right (1,2)       |
    ======================================================
    | bottom left (2,0)| bottom (2,1)| bottom right (2,2)|
    ======================================================
    */
    
    for (step=1; step <= steps; step++){
        printf("After %d steps: \n",step);
        for(row=0; row < rows; row++){
            for(column=0; column < columns; column++){
                int count = 0;
                if (row-1>=0 && matrix[row-1][column]==populated) count++;  // top cell         
                if (row+1<rows && matrix[row+1][column]==populated) count++; // bottom cell
                if (column-1>=0 && matrix[row][column-1]==populated) count++; // left cell
                if (column+1<columns && matrix[row][column+1]==populated) count++; // right cell
                if (row-1>=0 && column-1>=0 && matrix[row-1][column-1]==populated) count++;         // top left cell
                if (row+1<rows && column-1>=0 && matrix[row+1][column-1]==populated) count++;  // bottom left cell
                if (row-1>=0 && column+1<columns && matrix[row-1][column+1]==populated) count++; // top right cell
                if (row+1<rows && column+1<columns && matrix[row+1][column+1]==populated) count++; // bottom right cell

                if (matrix[row][column]==empty && count==3) new_matrix[row][column]=populated;
                else if (matrix[row][column]==populated && (count<2 || count>3)) new_matrix[row][column]=empty;
                else new_matrix[row][column]=matrix[row][column];
            }
        }

        for(row=0; row < rows; row++){
            for (column=0; column < columns; column++){
                printf("%d ", new_matrix[row][column]);
                matrix[row][column]=new_matrix[row][column];
            }
            printf("\n");
        }
    }
}
