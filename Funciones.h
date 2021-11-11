
// Hilo relaciones
void* relacion(void* arg);
// Hilo funciones
void* funcion(void* arg);

// Conjutos A y B
typedef struct{
	int a,b,aux;
	long int relaciones;
	int funciones;
}Conj;

class Funciones{
	private:
		Conj elem; // Declaracion de conjuntos A y B
	public:
		void set_ab();
		void ini_hilos();		
};

// se ingresan los numeros de elementos
void Funciones::set_ab(){
	cout<<"\n\tIngresa el numero de elementos de A: ";
	cin>>elem.a;
	cout<<"\n\tIngresa el numero de elementos de B: ";
	cin>>elem.b;
	elem.funciones=0;
	elem.relaciones=0;
}

// metodo que inicializa los hilos
void Funciones::ini_hilos(){
	pthread_t h_rela;
	pthread_t h_fun;
	
	pthread_create(&h_rela,NULL,relacion,&elem);
	pthread_create(&h_fun,NULL,funcion,&elem);
	
	pthread_join(h_rela,NULL);
}

// hilo que calcula el numero de relaciones
void* relacion(void *arg){
	Conj num = *((Conj*)arg);
	
	num.aux=num.a*num.b;
	num.relaciones=pow(2,num.aux);
	cout<<"\n\tRelaciones de A-->B : "<<num.relaciones;
	cout<<"\n\tRelaciones de B-->A : "<<num.relaciones<<endl;
}

// hilo que calcula el numero de funciones y funciones inyectivas
void* funcion(void *arg){
	Conj num = *((Conj*)arg);
	
	num.funciones=pow(num.b,num.a); // A->B
	cout<<"\n\tNumero de funciones A-->B: "<<num.funciones;
	num.funciones=pow(num.a,num.b); // B->A
	cout<<"\n\tNumero de funciones B-->A: "<<num.funciones;
	
	num.aux=num.b*num.a;
	// inyectivas A->B
	if(num.b>=num.a){
		cout<<"\n\tFunciones inyectivas A-->B : "<<num.aux<<endl;
	}else{
		cout<<"\n\tNo hay funciones inyectivas A-->B"<<endl;
	}
	
	// inyectivas B->A
	if(num.a>=num.b){
		cout<<"\n\tFunciones inyectivas B-->A : "<<num.aux<<endl;
	}else{
		cout<<"\n\tNo hay funciones inyectivas B-->A"<<endl;
	}
}


// Nota: Podria incrustarse un objeto en lugar de una estructura dentro de un hilo tal vez
