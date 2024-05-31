#include <iostream>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

class Zhan
{ 
public:
     
    int four(int name);
    void six(float ss);
};
int Zhan::four(int name) {
    int name_t = name % 4;
    if (0 < name_t) {
        name = name - name_t;
    }
    else {
        name = name - 4;
    }
    return name;
}
void Zhan::six(float ss) {
    for (int i = 0; i < 6; i++) {
        int num = 49;
        for (int j = 0; j < 3; j++) {
            // 期望:0.5， 标准差:ss
            // construct a random generator engine from a time-based seed
            unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine gen(seed);
            std::normal_distribution<double> dis(0.5, ss);
            double pdis = dis(gen);
            int left = num * pdis;
            int right = num - left - 1;
            int num1 = four(left);
            int num2= four(right);
            num = num1 + num2;
        }
        cout << num / 4;
    }
}

int main() {
    Zhan Z;
    for (int i = 0; i < 10; i++) {
        Z.six(0.35);
        cout << endl;
    }
    cout << "0.35****************" << endl;
    for (int i = 0; i < 10; i++) {
        Z.six(0.001);
        cout << endl;
    }
    cout << "0.01****************" << endl;
    for (int i = 0; i < 10; i++) {
        Z.six(1000);
        cout << endl;
    }
    cout << "1000****************" << endl;
    return 0;
}