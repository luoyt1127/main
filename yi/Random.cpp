#include "Random.h"
#include <ctime>//time 原先 <time.h> 头文件的 C++ 版本
#include <iostream>
#include <random>
#include <chrono>

void Random::SetSeed(const char* mode)  const {
	if (strcmp(mode, "unconst") == 0) {
		srand((unsigned)time(nullptr) + (unsigned)rand());
	}
	else {
		cout << "随机数选择：" << mode << "为非法字符，SetSeed选择“unconst”或者整数" << endl;
		system("Pause");
		exit(0);
	}
	return;
}
void Random::SetSeed(int num) const {
	srand(num);
	return;
}

double Random::Uniform(double minValue, double maxValue) const {
	/* rand()返回[0, RAND_MAX] 之间的随机数，包括0和RAND_MAX
		若要取[0, 1]，ratio = ((double)rand())/(RAND_MAX)
					[0, 1)，ratio = ((double)rand())/(RAND_MAX+1.0)
					(0, 1]，ratio = ((double)rand()+1.0)/(RAND_MAX+1.0)
					(0, 1)，ratio = ((double)rand()+1.0)/(RAND_MAX+2.0)
	*/
	double ratio = ((double)rand() + 1.0) / (RAND_MAX + 2.0);
	return  ratio * (maxValue - minValue) + minValue;
}

double Random::Gauss(double mean, double sigma) const {
	/* 使用Bon-Muller法生成高斯随机数	*/
	static double U, V;
	static int phase = 0;
	double z;
	if (phase == 0) {
		U = Uniform(0, 1);
		V = Uniform(0, 1);
		z = sqrt(-2.0 * log(U)) * sin(2 * PI * V);
	}
	else {
		z = sqrt(-2.0 * log(U)) * cos(2 * PI * V);
	}
	phase = 1 - phase;

	return  mean + sigma * z;
}


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
    Random R;
    for (int i = 0; i < 6; i++) {
        int num = 49;
        for (int j = 0; j < 3; j++) {
            // 期望:0.5， 标准差:ss
            // construct a random generator engine from a time-based seed
            //unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
            //std::default_random_engine gen(seed);
            //std::normal_distribution<double> dis(0.5, ss);
            
            //double pdis = dis(gen);
            float temp = R.Gauss(0.5, ss);
            int left = num * temp;
            int right = num - left - 1;
            int num1 = four(left);
            int num2 = four(right);
            num = num1 + num2;
        }
        cout << num / 4;
    }
}


int main() {
    Zhan Z;
    Random R;
    for (int i = 0; i < 10; i++) {
        Z.six(0.35);
        cout << endl;
    }
    cout << "0.05****************" << endl;
    for (int i = 0; i < 10; i++) {
        Z.six(0.001);
        cout << endl;
    }
    cout << "0.001****************" << endl;
    for (int i = 0; i < 10; i++) {
        Z.six(0.5);
        cout<< R.Gauss(0.5,0.5);
        cout << endl;
    }
    cout << "0.5****************" << endl;
    return 0;
}
