#include <iostream>
#include <iomanip>

int main() {
    int n, m, j = 0, k = 0;
    enum {down, right, up, left} d = down;
    
    std::cout << "Enter the row size: ";
    std::cin >> m;
    std::cout << "Enter the column size: ";
    std::cin >> n;
    std::cout << "\n";
    
    if (n < 0 || n > 30)
        n = 5;
    if (m < 0 || m > 30)
        m = 5;

    int arr[30][30];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = 0;

    for(int i = 1; i <= n*m; i++) {
        arr[j][k] = i;

        if (d == down)
          if (j < n-1 && arr[j+1][k] == 0)
            j++;
          else
            d = right;

        if (d == right)
          if (k < m-1 && arr[j][k+1] == 0)
            k++;
          else
            d = up;

        if (d == up)
          if (j > 0 && arr[j-1][k] == 0)
            j--;
          else
            d = left;

        if(d == left)
          if (k > 0 && arr[j][k-1] == 0)
            k--;
          else {
            d = down;
            j++;
      }
  }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            std::cout << std::setw(4) << arr[i][j];
        std::cout << "\n";
    }
  
  return 0;
}
