#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric> //per iota
#include <algorithm> //per generate
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

int main(int argc, char* argv[])
{
    cout<< "Number of vector that are being used to test the efficency of MergeSort and BubbleSort methods: " << argc-1 << endl;
    cout<<endl;

    //creo due numeri per sommare tutti i tempi impiegati dai due metodi
    double timeMerge = 0.0;
    double timeBubble = 0.0;

    //ciclo sul numero di vettori indicati in output
    for(int i = 1; i<argc; i++){

        int n = stoi(argv[i]);
        vector<double> v(n);

        cout << "Vector numer: " << i << endl << "Dimension: " << n;

        //ciclo sulla lunghezza del vettore per generarlo in maniera randomica
        srand(time(NULL));
        for(unsigned int j=0; j<v.size(); j++){
            v[j] = rand() % 100;
            //cout << v[j] << " ";
        }
        cout << endl;
        vector<double> v2 = v;

        //conto i tempi impiegati
        std::chrono::steady_clock::time_point t_beginM = std::chrono::steady_clock::now();
        MergeSort(v);
        std::chrono::steady_clock::time_point t_endM = std::chrono::steady_clock::now();
        double durationM = std::chrono::duration_cast<std::chrono::microseconds>(t_endM - t_beginM).count();
        cout << "Microseconds needed by MergeSort to finish: " << durationM << endl;
        timeMerge += durationM;

        std::chrono::steady_clock::time_point t_beginB = std::chrono::steady_clock::now();
        BubbleSort(v2);
        std::chrono::steady_clock::time_point t_endB = std::chrono::steady_clock::now();
        double durationB = std::chrono::duration_cast<std::chrono::microseconds>(t_endB - t_beginB).count();
        cout << "Microseconds needed by BubbleSort to finish: " << durationB << endl;
        timeBubble += durationB;

        cout<<endl;
    }

    //calcolo la media dei tempi
    double meanMerge = timeMerge/(argc-1);
    cout << "Avarage time of MergeSort: " << meanMerge << " microseconds" << endl;

    double meanBubble = timeBubble/(argc-1);
    cout << "Avarage time of BubbleSort: " << meanBubble << " microseconds" << endl;;


    return 0;
}

