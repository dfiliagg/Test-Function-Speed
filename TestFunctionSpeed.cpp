#include "TestFunctionSpeed.hpp"

template <typename F, typename... Args>
double speed_calc(F f, Args... args) {
  // Inizia il timer.
  auto start = std::chrono::high_resolution_clock::now();

  // Esegue la funzione.
  f(args...);

  // Termina il timer.
  auto end = std::chrono::high_resolution_clock::now();

  // Ritorna la differenza tra i due tempi, in millisecondi.
  return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0;
}

template <typename F, typename... Args>
double speed_calc_n_time(F f, int n, Args... args) {
  // Esegue la funzione n volte.
  std::vector<double> tempi;
  for (int i = 0; i < n; i++) {
    tempi.push_back(speed_calc(f, args...));
  }

  // Ritorna la media dei tempi di esecuzione.
  return std::accumulate(tempi.begin(), tempi.end(), 0.0) / tempi.size();
}
