Algoritmo Porciones_Pizza
	//1. Definicion de variables
	Definir radio, area_total, area_comensal, porciones_comensal como Real
	Definir comensales, porciones_totales Como Entero
	Definir porciones_extra, calorias_extras, minutos_correr Como Real
	//2. Constantes
	Definir PI_num como Real
	PI_num= 3.14
	calorias_por_porcion=250
	calorias_quemadas=11
	//3. Entrada de datos
	Escribir "Introduce el radio de la pizza en cm: "
	Leer radio
	Escribir "Introduce el numero de comensales: "
	Leer comensales
	Escribir "Introduce el numero de porciones en que se dividira la pizza: "
	Leer porciones_totales
	//4. Procesamiento (Calculos)
	area_total<-PI_num* (radio*radio)
	area_comensal<-area_total/comensales
	porciones_comensal<-porciones_totales/comensales 
	//5. Mostrar Resultados por pantalla
	Escribir "Resultados: "
	Escribir "A cada comensal le corresponde"
	Escribir "- ", porciones_comensal, " porciones"
	Escribir "-", area_comensal, " cm^2 "
	//6. Entrada Ejercicio 2
	Escribir "Introduce el numero de porciones que comio el gloton. "
	Leer porciones_gloton
	//7. Calculos
	porciones_extra<-porciones_gloton-porciones_comensal
	Si porciones_extra>0 Entonces
		calorias_extra<-porciones_extra*calorias_por_porcion
		minutos_correr<-calorias_extra/calorias_quemadas
		//8. Mostrar Resultados
		Escribir "Resultados El vengador pizzero"
		Escribir "Comiste ", porciones_extra, " porciones mas de lo normal"
		Escribir " - ", minutos_correr, " minutos "
	Sino 
		Escribir " No comiste mas de lo normal. No tienes que correr "
	FinSi
FinAlgoritmo
