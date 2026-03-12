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

int main(){
	
	Cuenta c1(1,"001","Juan Perez");
	Cuenta c2(2,"002","Maria Lopez");
	
	cout << "=== ESTADO INICIAL ===" << endl;
	c1.mostrar();
	c2.mostrar();
	
	cout << endl << "=== DEPOSITO ===" << endl;
	c1.ingresar(1000);
	
	cout << endl << "=== INTENTO DE RETIRO GRANDE ===" << endl;
	c1.extraer(2000);
	
	cout << endl << "=== TRANSFERENCIA ===" << endl;
	cout << "Monto: 450" << endl << endl;
	
	c1.enviar(c2,450);
	
	cout << endl << "=== ESTADO FINAL ===" << endl;
	c1.mostrar();
	c2.mostrar();
	
	return 0;
}
