// normal_distribution
#include <iostream>
#include <string>
#include <random>
#include <cmath>

double calc_E(double time, double dist) {
    double a =268065.0;
    double cf = 0.00000025;
    double d = 0.11;
    double d_12 = 1.0;
    double e = a * cf * time * pow(0.5, 0)/ (dist*dist);
    return e;

}
int main()
{
    const int nrolls=1000;  // number of experiments

    std::default_random_engine generator;
    std::normal_distribution<double> distribution_dist(1.75,0.38);
    std::normal_distribution<double> distribution_time(35,17.5);
    double p_time[nrolls];
    double p_dist[nrolls];
    double p_e[nrolls];
    int i = 0;
    double sum = 0;

    // calculate 1000 samples of time
    while(i<nrolls) {
        double number = distribution_time(generator);
        if ((number>=10)&&(number<60)) {
            p_time[i] = number;
            i++;
        }
    }
    // calculate 1000 samples of distance

    i = 0;
    while(i<nrolls) {
        double number = distribution_dist(generator);
        if ((number>=1)&&(number<2.5)) {
            p_dist[i] = number;
            i++;
        }

    }
    // calculate 1000 samples of E(effective dose)
    for (i=0; i < nrolls; i++) {
        p_e[i]  = calc_E(p_time[i]/3600, p_dist[i]);
        sum += p_e[i];
    }
    //the average
    double avg = 0.0;  //or double for higher precision
    avg = sum/nrolls; //or cast sum to double before division

    double var = 0;
    int n = 0;
    for( n = 0; n < nrolls; n++ )
    {
        var += (p_e[n] - avg) * (p_e[n] - avg);
    }
    var /= nrolls;
    double sd = sqrt(var);
    std::cout << avg << '\n';
    std::cout << sd;
	system("pause");
    return 0;
}