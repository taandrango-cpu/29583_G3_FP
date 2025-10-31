Algoritmo Porciones_Pizza
	//1. Definicion de variables
	Definir radio, area_total, area_comensal, porciones_comensal como Real
	Definir comensales, porciones_totales Como Entero
	Definir PI_num como Real
	PI_num= 3.14
	//2. Entrada de datos
	Escribir "Introduce el radio de la pizza en cm: "
	Leer radio
	Escribir "Introduce el numero de comensales: "
	Leer comensales
	Escribir "Introduce el numero de porciones en que se dividira la pizza: "
	Leer porciones_totales
	//3. Procesamiento (Calculos)
	area_total<-PI_num* (radio*radio)
	area_comensal<-area_total/comensales
	porciones_comensal<-porciones_totales/comensales 
	//4. Mostrar Resultados por pantalla
	Escribir "Resultados: "
	Escribir "A cada comensal le corresponde"
	Escribir "- ", porciones_comensal, " porciones"
	Escribir "-", area_comensal, " cm^2 "
	
FinAlgoritmo
