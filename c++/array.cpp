#include <stdlib.h>
#include <iostream>

int main() {
    int M = 0, N = 0, amt = 0;
    std::cin >> M >> N >> amt;
    char rc
    int stroke = 0;
    char art[M][N] = {'B'}; //ignore that i filled this with 1 value - tested after finding problem
    
    int goldCount = 0;

/*
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            //printf("art[%d][%d] = 'B'\n", i, j);
            art[i][j] = 'B';
            std::cout << "array being filled\n";
        }
    }
*/

    //testing output
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!art[i][j]) {
              std::cout << ".";
            }
            std::cout << art[i][j] << " ";
//            printf("art[%d][%d] = %c\n", 
        }
        std::cout << "\n";
    }
}
