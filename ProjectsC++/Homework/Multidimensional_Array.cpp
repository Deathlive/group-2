#include <iostream>
#include <cstdlib>
#include <ctime>

int SIZE;

int prn(int sum) {
	std::cout << " = " << sum << "\n";
}

int main() {
    srand(time(NULL));
    
    int last = 0;
    int sum[7] = {0};
    
    std::cout << "Write the Length of the Array: ";
    std::cin >> SIZE;
    
    if(SIZE < 5) {
        std::cout << "Array is small\n";
    } else if(SIZE > 15) {
        std::cout << "Array is big\n";
    } else {
        int arr[SIZE][SIZE] = {};
        
         //Fill the array with random elements
        std::cout << "\n";
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                arr[i][j] = (rand() % 9) + 1;
            }
        }
        
        //Output of all elements from an array
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                std::cout << " " << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        
        //From the upper left corner to, the bottom right corner
        //From the upper right corner to, the bottom left corner
        int i = 0;
        int j = SIZE - 1;
        while(i < SIZE) {
            sum[0] += arr[i][i];
            sum[1] += arr[i][j];
            i++;
            j--;
        }
        std::cout << "\\: ";
        prn(sum[0]);
        std::cout << "/: ";
        prn(sum[1]);
        
        //Sum of all sides, array
        std::cout << "All sides: ";
        int y = SIZE - 1;
        for(int x = 0; x < SIZE - 1; x++) {
            sum[2] += arr[0][x] + arr[x][y] + arr[y][x+1] + arr[x+1][0];
        }
        prn(sum[2]);
        
        //Triangle from the upper half
        std::cout << "Top Triangle: ";
        last = 1;
        for(int i = 0; i < SIZE / 2; i++) {
            for(int j = last; j < SIZE - last; j++) {
                sum[3] += arr[i][j];
                std::cout << arr[i][j] << " ";
            }
            if (i != SIZE/2 - 1) std::cout << "+ ";
            last++;
        }
        prn(sum[3]);
        
        //Triangle from the bottom half
        std::cout << "Bottom Triangle: ";
        last = 1;
        for(int i = SIZE - 1; i > SIZE / 2; i--) {
            for(int j = last; j < SIZE - last; j++) {
                sum[4] += arr[i][j];
                std::cout << arr[i][j] << " ";
            }
            if (i != SIZE / 2 + 1) std::cout << "+ ";
            last++;
        }
        prn(sum[4]);
        
        //Triangle from the Left half
        std::cout << "Left Triangle: ";
        last = SIZE - 1;
        for(int i = 1; i < SIZE / 2; i++) {
            for(int j = 0; j < SIZE - last; j++) {
                sum[5] += arr[i][j];
                std::cout << arr[i][j] << " ";
            }
            std::cout << "+ ";
            last--;
        }
        
        last = SIZE - 1;
        for(int i = SIZE - 2; i > 1; i--) {
            for(int j = 0; j < SIZE - last; j++) {
                sum[5] += arr[i][j];
                std::cout << arr[i][j] << " ";
            }
            last--;
            if(i == SIZE / 2) {
                break;
            }
            std::cout << "+ ";
        }
        prn(sum[5]);
        
        //Triangle from the right half
        std::cout << "Right Triangle: ";
        last = 1;
        for(int i = 1; i < SIZE / 2; i++) {
            for(int j = SIZE - 1; j > SIZE - 1 - last; j--) {
                sum[6] += arr[i][j];
                std::cout << arr[i][j] << " ";
            }
            std::cout << "+ ";
            last++;
        }
        
        last = 1;
        for(int i = SIZE - 2; i > 1; i--) {
            for(int j = SIZE - 1; j > SIZE - 1 - last; j--) {
                sum[6] += arr[i][j];
                std::cout << arr[i][j] << " ";
            }
            last++;
            if(i == SIZE / 2) {
                break;
            }
            std::cout << "+ ";
        }
        prn(sum[6]);
    }
    return 0;
}