#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>

double euclidean_distance(int a, int b, int c, int d) {
    return std::pow(pow((a - b),2)+pow((c - d), 2),0.5);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> random_numbers;

    for (int i = 0; i < 100; i++) {
        int num = rand() % 101;
        random_numbers.push_back(std::rand() % 101);
    }

    int number_30 = random_numbers[29];
    int number_70 = random_numbers[69];

    std::vector<int> A;
    std::vector<int> B;

    for (int i = 0; i < 100; i++) {
        double distance_to_30 = euclidean_distance(random_numbers[i], number_30 ,i,30);
        double distance_to_70 = euclidean_distance(random_numbers[i], number_70 ,i, 70);

        if (distance_to_30 <= 10) {
            A.push_back(distance_to_30);
        }

        if (distance_to_70 <= 10) {
            B.push_back(distance_to_70);
        }
    }

    std::cout << "배열 : "; //확인용
    for (int num : random_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "배열 A: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "배열 B: ";
    for (int num : B) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}