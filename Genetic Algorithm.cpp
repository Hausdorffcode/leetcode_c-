#include<bits/stdc++.h>
using namespace std;

const int maxn = 30;
const double eps = 1e-6;

/// Genetic Algorithm for Functional Maximum Problem

/// f(x) = x+10*sin(5*x)+7*cos(4*x), x∈[0,9]
double f(double x) {
    return x + 10*sin(5*x) + 7*cos(4*x);
    //return -1*x*x + 10*x + 100;
    //return sin(x);
}
int upper_bound_num = 9;        // 自变量的区间上限
int lower_bound_num = 0;        // 自变量的区间下限

const int population_size = 10; //输入种群大小
const int chromosome_size = 17;  //输入染色体长度
int generation_size = 160; //输入迭代次数
double cross_rate = 0.6;  //输入交叉概率
double mutate_rate = 0.01; //输入变异概率
bool elitism = false; //输入是否精英选择

int population[population_size][chromosome_size];  //种群
double fitness_value[population_size];   // 当前代适应度矩阵
int population_new[population_size][chromosome_size];  //新种群
int G = 0;              // 当前迭代次数

double best_fitness = 0;    // 历代最佳适应值
int best_individual[chromosome_size]; // 历代最佳个体
int best_generation = 0; // 最佳个体出现代

///[Test] print current population
void printPopulation() {
    printf("Current population:\n");
    for (int i = 0; i < population_size; i++) {
        for (int j = 0; j < chromosome_size; j++) {
            printf("%d", population[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//
double BToD(int *s) {
    int delnum = 0;
    for (int j = 0; j < chromosome_size; j++) {
        if (s[j]) {
            delnum += pow(2, j);
        }
    }
    double x = lower_bound_num + (double)delnum/(pow(2, chromosome_size) - 1) * (upper_bound_num-lower_bound_num);
    return x;
}

///初始化:随机生成染色体
void init() {
    for (int i = 0; i < population_size; i++) {
        for (int j = 0; j < chromosome_size; j++) {
            population[i][j] = rand() > RAND_MAX/2 ? 1 : 0;
        }
    }
}

///计算适应度矩阵
void fitness() {
    for (int i = 0; i < population_size; i++) {
        double x = BToD(population[i]);
        //printf("x = %lf\n", x);
        fitness_value[i] = f(x);
    }
}

///[Test] print current fitness
void printFitness() {
    printf("Print Fitness:\n");
    for(int i = 0; i < population_size; i++) {
        printf("%lf  ", fitness_value[i]);
    }
    printf("\n");
}

///对个体按适应度大小进行排序，并且保存最佳个体，population(i)的适应度随i递增而递增
void rankness() {
    for (int i = 0; i < population_size; i++) {
        int min_index = i;
        for (int j = i+1; j < population_size; j++) {
            if (fitness_value[j] < fitness_value[min_index]) min_index = j;
        }
        if (i != min_index) {
            double temp = fitness_value[i];
            fitness_value[i] = fitness_value[min_index];
            fitness_value[min_index] = temp;

            for (int k = 0; k < chromosome_size; k++) {
                int temp_pop = population[i][k];
                population[i][k] = population[min_index][k];
                population[min_index][k] = temp_pop;
            }
        }
    }
    if (fitness_value[population_size-1] > best_fitness) {
        best_fitness = fitness_value[population_size-1];
        best_generation = G;
        for (int k = 0; k < chromosome_size; k++) {
            best_individual[k] = population[population_size-1][k];
        }
    }
}

///轮盘赌选择操作
void selection() {
    int sum_fitness = 0;
    for (int i = 0; i < population_size; i++) {
        sum_fitness += (fitness_value[i]) + abs(fitness_value[0]);
        //printf("%d ", sum_fitness);
    }
    //printf("\n");
    for (int i = 0; i < population_size; i++) {
        double r = (double)rand() / RAND_MAX * sum_fitness;
        //printf("%lf\n", r);
        int idx = -1;
        double sum = 0;
        for (int k = 0; k < population_size; k++) {
            sum += fitness_value[k] + abs(fitness_value[0]);
            if (sum > r) {idx = k; break;}
        }
        //printf("%d\n", idx);
        for (int j = 0; j < chromosome_size; j++) {
            population_new[i][j] = population[idx][j];
        }
    }
    if (elitism) {};

    for (int i = 0; i < population_size; i++) {
        for (int j = 0; j < chromosome_size; j++) {
            population[i][j] = population_new[i][j];
        }
    }
}

///单点交叉操作
void crossover() {
    for (int i = 0; i < population_size; i = i+2) {
        if ((double)rand()/RAND_MAX < cross_rate) {
            int cross_pos = rand()/RAND_MAX * chromosome_size;
            if (cross_pos == 0 || cross_pos == chromosome_size) continue;
            for (int k = cross_pos; k < chromosome_size; k++) {
                int temp = population[i][k];
                population[i][k] = population[i+1][k];
                population[i+1][k] = temp;
            }
        }
    }
}

///单点变异操作
void mutation() {
    for (int i = 0; i < population_size; i++) {
        if ((double)rand()/RAND_MAX < mutate_rate) {
            int mutate_pos = rand()/RAND_MAX * chromosome_size;
            population[i][mutate_pos] = 1-population[i][mutate_pos];
        }
    }
}


int main () {
    srand(443);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    init();

    for (G = 1; G <= generation_size; G++) {
        //printPopulation();
        fitness();
        //printFitness();
        rankness();
        //printFitness();
        selection();
        //printPopulation();
        crossover();
        mutation();
    }

    double best_x = BToD(best_individual);
    printf("best_fitness = %lf\n", best_fitness);
    printf("best_generation = %d\n", best_generation);
    printf("best_x = %lf\n", best_x);
    return 0;
}