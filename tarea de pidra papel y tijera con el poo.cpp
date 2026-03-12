#include <iostream>
#include <string>

using namespace std;

class Player{
private:
	short jugada;
	int puntos;
	
	int comparar(Player rival){
		if(jugada == rival.jugada)
			return 0;
		
		if((jugada == 1 && rival.jugada == 3) ||
			(jugada == 2 && rival.jugada == 1) ||
			(jugada == 3 && rival.jugada == 2))
			return 1;
		
		return -1;
	}
		
public:
			string nombreJugador;
			
			Player(){
				puntos = 0;
			}
				
				void elegir(){
					cout << nombreJugador << " seleccione opcion (1:Piedra 2:Papel 3:Tijera): ";
					cin >> jugada;
				}
					
					string mostrarJugada(){
						if(jugada == 1)
							return "()";
						else if(jugada == 2)
							return "[]";
						else
							return "8<";
					}
						
						void competir(Player &rival){
							int res = comparar(rival);
							
							cout << endl;
							cout << nombreJugador << " " << mostrarJugada()
								<< " VS "
								<< rival.nombreJugador << " " << rival.mostrarJugada()
								<< endl;
							
							if(res == 1){
								puntos++;
								cout << ">>> Gana la ronda: " << nombreJugador << endl;
							}
							else if(res == -1){
								rival.puntos++;
								cout << ">>> Gana la ronda: " << rival.nombreJugador << endl;
							}
							else{
								cout << ">>> Resultado: Empate" << endl;
							}
							
							cout << endl;
						}
							
							float eficiencia(int partidas){
								return (puntos / (float)partidas) * 100;
							}
};

int main(){
	
	Player j1, j2, j3;
	
	j1.nombreJugador = "SubZero";
	j2.nombreJugador = "Scorpion";
	j3.nombreJugador = "Reptile";
	
	cout << "===========================================" << endl;
	cout << "          BATALLA DE JUGADORES (POO)" << endl;
	cout << "===========================================" << endl << endl;
	
	for(int i = 1; i <= 3; i++){
		
		cout << "[Ronda " << i << ": " << j1.nombreJugador << " vs " << j2.nombreJugador << "]" << endl;
		
		j1.elegir();
		j2.elegir();
		
		j1.competir(j2);
		
		cout << "[Ronda " << i << ": " << j2.nombreJugador << " vs " << j3.nombreJugador << "]" << endl;
		
		j2.elegir();
		j3.elegir();
		
		j2.competir(j3);
	}
	
	cout << "-------------------------------------------" << endl;
	cout << "EFICIENCIA FINAL (3 Partidas)" << endl;
	cout << "-------------------------------------------" << endl;
	
	cout << "1. " << j1.nombreJugador << " : " << j1.eficiencia(3) << "%" << endl;
	cout << "2. " << j2.nombreJugador << " : " << j2.eficiencia(3) << "%" << endl;
	cout << "3. " << j3.nombreJugador << " : " << j3.eficiencia(3) << "%" << endl;
	
	cout << "===========================================" << endl;
	
	return 0;
}
	
