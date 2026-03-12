# 📘 Tareas de Programación Orientada a Objetos en C++

Este repositorio contiene diferentes ejercicios desarrollados en **C++** aplicando conceptos de **Programación Orientada a Objetos (POO)** como:

- Clases
- Constructores
- Encapsulamiento
- Métodos
- Interacción entre objetos

---

# 📂 Contenido

1. Clase Autobus
2. Juego Piedra, Papel o Tijera
3. Sistema de Cuentas Bancarias

---

# 🚌 1. Clase Autobus

Este programa implementa una clase `Autobus` que simula el funcionamiento básico de un autobús.

## Conceptos aplicados

- Atributos privados y públicos
- Constructores
- Sobrecarga de constructores
- Métodos
- Getters y Setters

## Funcionalidades

- Crear autobuses con diferentes configuraciones
- Recoger pasajeros
- Calcular asientos disponibles
- Calcular pago según combustible
- Mostrar información del autobús

## Código

```cpp
#include <iostream>
using namespace std;

class Autobus
{
private:
	float combustible;
	int pasajeros;

public:
	int nroAsientos;
	float tarifa;
	int cantidad;
	int capaTanque;

	Autobus()
	{
		combustible = 100;
		pasajeros = 0;
		nroAsientos = 25;
		tarifa = 2;
	}

	Autobus(float con, int nroPas, int nroAs, float tar)
	{
		combustible = con;
		pasajeros = nroPas;
		nroAsientos = nroAs;
		tarifa = tar;
	}

	Autobus(int _NroAsientos,float tarif){
		combustible = 250;
		pasajeros = 0;
		nroAsientos = _NroAsientos;
		tarifa = tarif;
	}

	void Recoger_Pasajeros(int pasajeros,int nroAsientos){
		if(pasajeros>0){
			if(pasajeros+cantidad > nroAsientos){
				pasajeros = nroAsientos;
			}else{
				pasajeros = pasajeros + cantidad;
			}
		}else {
			cout<<"Cantidad invalida"<<endl;
		}
	}

	int calcular_cant(){
		return nroAsientos- pasajeros;
	}

	int Calcular_pago(){
		return (capaTanque-combustible)*tarifa;
	}

	void Imprimir(){
		cout<< "Total Asientos "<< nroAsientos<<endl;
		cout<< "Tarifa "<< tarifa<<endl;
		cout<< "Total Combustible "<<combustible<<endl;
		cout<< "Nro de Pasajeros "<< pasajeros<<endl;
	}

	float getCombustible(){ return combustible; }
	int getPasajeros () { return pasajeros; }

	void setCombustible(float newCombustible) { combustible = newCombustible;}
	void setPasajeros(int newPasajeros) { pasajeros = newPasajeros; }
};
```

---

# 🪨📄✂️ 2. Juego Piedra, Papel o Tijera

Este programa simula una competencia entre jugadores usando el clásico juego **Piedra, Papel o Tijera**.

## Conceptos aplicados

- Clases
- Métodos privados
- Comparación entre objetos
- Referencias entre objetos
- Control de rondas

## Jugadores

- SubZero
- Scorpion
- Reptile

## Código

```cpp
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
```

---

# 🏦 3. Sistema de Cuentas Bancarias

Este programa simula un sistema básico de gestión de **cuentas bancarias**.

## Conceptos aplicados

- Encapsulamiento
- Validación de datos
- Transferencias entre objetos
- Métodos de depósito y retiro

## Funcionalidades

- Depositar dinero
- Retirar dinero
- Transferir dinero entre cuentas
- Mostrar saldo de las cuentas

## Código

```cpp
#include <iostream>
#include <string>
using namespace std;

class Cuenta {
private:
	int codigo;
	string numero;
	double dinero;

public:
	string titular;

	Cuenta(int c, string n, string t){
		codigo = c;
		numero = n;
		titular = t;
		dinero = 0.0;
	}

	void ingresar(double monto){
		if(monto > 0){
			dinero += monto;
			cout << "Ingreso realizado en la cuenta de " << titular << endl;
		}else{
			cout << "Monto invalido." << endl;
		}
	}

	bool extraer(double monto){
		if(monto <= 0){
			cout << "El monto debe ser mayor que cero." << endl;
			return false;
		}

		if(monto > dinero){
			cout << "Saldo insuficiente." << endl;
			return false;
		}

		dinero -= monto;
		cout << "Retiro exitoso de la cuenta de " << titular << endl;
		return true;
	}

	void enviar(Cuenta &destino, double monto){
		if(&destino == this){
			cout << "No se puede transferir a la misma cuenta." << endl;
			return;
		}

		if(extraer(monto)){
			destino.ingresar(monto);
			cout << "Transferencia completada correctamente." << endl;
		}else{
			cout << "No se pudo realizar la transferencia." << endl;
		}
	}

	void mostrar(){
		cout << "Cuenta: " << numero
			 << " | Titular: " << titular
			 << " | Saldo: $" << dinero << endl;
	}
};
```

---

# 🧠 Conclusión

Estos ejercicios permiten practicar conceptos fundamentales de **Programación Orientada a Objetos en C++**, incluyendo:

- Creación de clases
- Encapsulamiento
- Interacción entre objetos
- Uso de métodos y constructores

---

📚 **Materia:** Programación  
💻 **Lenguaje:** C++  
🎓 **Tema:** Programación Orientada a Objetos
