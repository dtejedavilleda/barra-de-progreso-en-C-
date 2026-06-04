#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void spinner(int duracion_ms) {
    char animacion[] = {'|', '/', '-', '\\'};
    int i = 0;

    auto fin = chrono::steady_clock::now() + chrono::milliseconds(duracion_ms);

    while (chrono::steady_clock::now() < fin) {
        cout << "\rProcesando... " << animacion[i % 4];
        cout.flush();

        i++;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "\rProcesando... listo ✅" << endl;
}

int main() {
    spinner(3000); // gira por 3 segundos
    return 0;
}
