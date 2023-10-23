#include "magic.h"

void escritura (string& nombre, string& texto)
{
ofstream escribir;
string nombree= "C:/Users/cuent/Desktop/p3 lizeth/build-prac3-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/" + nombre;
escribir.open(nombree,ios::out);

if (escribir.fail())
{
    cout << "No se pudo abrir el archivo.\n";
    exit(1);
}
escribir<< texto;
}

string caracter_binario (string& texto)
{
    int longitud_texto = texto.length();

    string binario ="";
    char letra;
    for (int i =0; i<longitud_texto;i++)
    {
        string copia= "";
        letra = texto [i];
        int num = letra,
            vector[8] = {128,64,32,16,8,4,2,1};

        for (int j=0; j <8;j++)
        {
            if (num >= vector [j])
            {
                copia = copia + '1';
                num -=vector[j];
            }
            else
                copia = copia + '0';
        }
        binario = binario + copia;
    }
    return binario;
}

string binario_caracter (string& texto)
{
    string auxiliar="",texto_caracter= "";
    int semilla = 8,
        repeticiones =  texto.length()/ semilla,
        aguja = semilla,
        vector []= {128,64,32,16,8,4,2,1};
    auxiliar = texto.substr(0,semilla);
    for (int i = 0; i < repeticiones; i++){ //for principal
        int resultado=0;
        for (int j=0; j<8; j++) // 0100 0001 65   64+1 = 65
        {
            if (auxiliar[j]== '1')
                resultado = resultado+vector [j];
        }
        auxiliar = "";
        auxiliar= texto.substr(aguja, semilla);
        aguja = aguja+semilla;
        char caracter = resultado;
        texto_caracter= texto_caracter + caracter ;
    } // for repeticiones

    return texto_caracter;
}

string decodificacion (string& texto, int metodo, int semilla)
{
    string decodificado = "";

    if (metodo == 1){   cout << "***** Metodo de decodificacion 1. *****\n\n";
        string auxiliar = "";
        int repeticiones =  texto.length()/ semilla;
        int aguja = semilla,cantidad_ceros=0, cantidad_unos= 0;
        auxiliar = texto.substr(0,semilla);  cout << "auxiliar"<<auxiliar<<endl;
        for (int i = 0; i < repeticiones; i++)  { //SE HACE LO MISMO PERO RESPECTO A LA CODIFICACIÓN
            if (cantidad_unos == cantidad_ceros || i == 0)
            {
                for (int j = 0; j<semilla ; j++ )
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } // if cantida_unos == cantidad_ceros
            else  if  (cantidad_ceros >cantidad_unos )
            {
                for (int j = 1; j<semilla ; j=j+2)
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';

                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } // if cantidad_ceros >cantidad_unos
            else if (cantidad_unos > cantidad_ceros) // else
            {
                for (int j = 2; j<semilla; j=j+3 )
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            } //if cantidad_unos>cantidad_ceros
            cantidad_ceros=0, cantidad_unos= 0;
            // ciclo que cuenta los 1 y 0 en cadena auxiliar
            for (int k=0; k<semilla ; k++)
            {
                if (auxiliar [k]== '1')
                    cantidad_unos++;
                if (auxiliar [k] == '0')
                    cantidad_ceros++;
            }
            decodificado = decodificado + auxiliar;
            auxiliar = "";
            auxiliar= texto.substr(aguja, semilla);
            aguja = aguja+semilla;
        } // for repeticiones
    } // if metodo == 1

    if (metodo == 2)
    { //se toma el ultimo bit del bloque, todos se mueven hacia la izquierda y el bit tomado se
        //pone al final
        string auxiliar = "",       //bloque para decodificar
            copia="";
        int repeticiones =  texto.length()/ semilla;
        int aguja = semilla;
        auxiliar = texto.substr(0,semilla);
        copia = auxiliar;
        for (int i = 0; i < repeticiones; i++)  {
            copia = auxiliar;
            for (int j = 0; j<semilla;j++){
                if (j != semilla-1)
                    auxiliar[j] = copia [j+1];  //mover hacia la izquierda 1 posicion
                if (j == semilla-1)
                    auxiliar[j] = copia[0]; //el primer bit del bloque se guarda en la ultima
            }                               //posicion
            decodificado = decodificado + auxiliar;
            auxiliar = "";
            auxiliar= texto.substr(aguja, semilla);
            aguja = aguja+semilla;
        }//for principal metodo 2
    }

    return decodificado;
}
int  inicio_sesion(string& texto)
{
    int veri = 0;
    string usuario,contrasena,verificacion = "";
    cout << "Ingrese nombre de usuario:\n";
    cin >> usuario;
    cout << "Ingrese contrasena:\n";
    cin >> contrasena;
    verificacion = usuario +','+ contrasena + '\n'; //unir usuario y contraseña para darle la forma
    veri = texto.find(verificacion);  //en como estan en el archivo, y verificar si este usuario
    return veri;                //y contraseña se encuentra en el archivo, se retorna la posicion en donde se encontró
}                               //retorna -1 si no lo encuentra

string lectura (string& nombre)
{
    string contenido;
    string nombree= "C:/Users/cuent/Desktop/p3 lizeth/build-prac3-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/" + nombre;

    try {
        ifstream archivo(nombree);

        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                contenido += linea + '\n';
            }
            archivo.close();
        } else {
            throw runtime_error("No se pudo abrir el archivo");
        }
    } catch (const runtime_error& e) {
        contenido = e.what();
    }

    return contenido;
}

string codificacion (string& texto, int metodo ,int semilla)
{
    string codificado = "";
    if (metodo == 1){   cout << "Metodo de codificacion 1.\n";
        string auxiliar = "";
        int repeticiones =  texto.length()/ semilla;   //calcular bloques
        int aguja = semilla,cantidad_ceros=0, cantidad_unos= 0;
        auxiliar = texto.substr(0,semilla); //extrae el primer bloque (hasta semilla -1 por indexación)
        for (int k=0; k<semilla ; k++)// ciclo que cuenta los 1 y 0 en cadena auxiliar del primer bloque
        {
            if (auxiliar [k]== '1')
                cantidad_unos++;
            if (auxiliar [k] == '0')
                cantidad_ceros++;
        }
        for (int i = 0; i < repeticiones; i++){ //for principal
            if (i>1)  //se hace esta para que empiece a codificar el segundo bloque respecto a la cantidad de unos y ceros del primer bloque
            {
                cantidad_ceros=0, cantidad_unos= 0;
                // ciclo que cuenta los 1 y 0 en cadena auxiliar
                string cantidad = texto.substr((semilla*(i-1)),semilla);
                for (int k=0; k<semilla ; k++)
                {
                    if (cantidad [k]== '1')
                        cantidad_unos++;
                    if (cantidad [k] == '0')
                        cantidad_ceros++;
                }
            }
            if (cantidad_unos == cantidad_ceros || i == 0) //comprobar si si se necesita la otra condicion i==0
            {
                for (int j = 0; j<semilla ; j++ )      //ciclo para codificar cuando las cantidades de ceros y unos son iguales
                {
                    if (auxiliar [j] == '1')
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            }
            else  if  (cantidad_ceros >cantidad_unos )
            {
                for (int j = 1; j<semilla ; j=j+2)  //ciclo para codificar cuando ceros>unos,
                {                                   //j empieza en 1 porque dice que se van a invertir
                    if (j % 2 != 0)                 //cada 1 bit
                    {   //comprobar que se va a invertir cada 1 bit (serían las posiciones impares)
                        if (auxiliar [j] == '1')
                            auxiliar [j]= '0';
                        else if(auxiliar [j] == '0')
                            auxiliar [j] = '1';
                    }
                }
            }
            else if (cantidad_unos > cantidad_ceros) // else
            {
                for (int j = 2; j<semilla; j=j+3 ) //ciclo para codificar cuando unos>ceros
                {                                  //j empieza en 2 porque se va a invertir cada 2 bits
                    if (auxiliar [j] == '1')       //se va sumando j=j+3 para que vaya saltando cada 2 bits
                        auxiliar [j]= '0';
                    else if(auxiliar [j] == '0')
                        auxiliar [j] = '1';
                }
            }
            codificado = codificado + auxiliar; //se va construyendon codificado
            auxiliar = "";
            auxiliar= texto.substr(aguja, semilla); //se actualiza auxiliar para los demás bloques
            aguja = aguja+semilla;          //se actualiza aguja para los demás bloques
        }
    } // metodo 1

    if (metodo == 2){cout << "***** Metodo de codificacion 2. *****\n";
        int repeticiones = texto.length()/ semilla, //repeticiones=cantidad de bloques
            aguja = semilla;               //posicion de inicio del bloque para seleccionarlo
        string auxiliar = "";              //bloque de bits que va a ser codificado
        auxiliar = texto.substr(0,semilla);
        string copia;                      //bloque sin codificar para hacer la codificacion
        for (int i = 0; i< repeticiones;i++){
            copia = auxiliar;
            char inicio = copia[semilla-1]; //ultimo bit del bloque que se guarda
            for (int j = 0; j<= semilla-1;j++){ //ciclo para mover todos los bits de copia
                auxiliar [j+1]=copia[j];    //1 espacio hacia la derecha y guarda esto en auxiliar
                if (j==0){
                    auxiliar [0]= inicio; //el ultimo bit del bloque se guarda en la primera pos
                }
            }
            codificado = codificado + auxiliar; //se va construyendon codificado
            auxiliar = "";
            auxiliar = texto.substr(aguja, semilla); //se actualiza auxiliar para los demás bloques
            aguja = aguja+semilla; //se actualiza aguja para los demás bloques
            inicio = copia [semilla-1]; //
        }
    } //metodo 2

    return codificado;
}

void menu_codificacion ()
{
    int metodo=0,semilla=0; string nombre="",texto="";string verificacion = "";
    system("cls");
    cout << "***** CODIFICACION *****\n"<<"Problema 1"<<endl;
    cout << "Ingrese nombre de texto a codificar:"<<endl;
    cin>>nombre;
    cout << "Ingrese numero de particiones:"<<endl;
    cin >> semilla;
    texto = lectura(nombre);
    texto = caracter_binario(texto);
    cout<<"seleccione una opcion \n"<<endl;
    cout<<"1) Codificacion metodo 1."<<endl;
    cout<<"2) Codificacion metodo 2."<<endl;
    cin >> metodo;
    texto = codificacion ( texto, metodo , semilla);
    escritura(nombre,texto);
}

void menu_decodificacion ()
{
    int metodo=0,semilla=0; string nombre="",texto="";string verificacion = "";
    system("cls");
    cout << "***** DECODIFICACION *****\n"<<"Problema 1"<<endl;
    cout << "Ingrese nombre de texto.txt a decodificar:"<<endl;
    cin>>nombre;
    cout << "Ingrese numero de particiones:"<<endl;
    cin >> semilla;
    cout << "Ingrese metodo de decodificacion:"<<endl;
    cin >> metodo;
    texto = lectura(nombre);
    texto = decodificacion ( texto, metodo,  semilla);
    texto = binario_caracter(texto);
    escritura(nombre,texto);
}

void menu_app()
{
    string sudo="sudo.txt",
        nombre_archivo_usuario="usuario.txt";

    int opcion=1;
    while (opcion!=0)
    {
        int veri = 0;
        string archivo_sudo="", archivo_usuario="";
        cout << "***** APLICACION *****\n\n"<<endl;
        cout<<"seleccione una opcion \n"<<endl;
        cout<<"1) Inicio Administrador."<<endl;
        cout<<"2) Inicio Usuario."<<endl;
        cout<< "0) Salir.\n";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "ADMINISTRADOR\n";
            archivo_sudo = lectura(sudo);   //informacion de los usuarios encriptada
            archivo_sudo = decodificacion(archivo_sudo,2,4); //decodificar para obtener la información de usuarios
            archivo_sudo = binario_caracter(archivo_sudo); //pasar a texto
            veri = inicio_sesion(archivo_sudo);            //iniciar sesion

            if (veri == -1)
                cout << "usuario y contrasena errada.\n";

            if (veri != -1)
            {
                int opcion1 = 1;
                while (opcion1 !=0 )
                {
                    cout << "********* BIENVENIDO ADMINISTRADOR*********\n";
                    cout << "1) Ingresar nuevo usuario.\n";
                    cout << "0) Salir.\n";
                    string dato = "",
                        nuevo = "";
                    cin >> opcion1;

                    switch (opcion1)
                    {
                    case 1:
                        cout << "Ingresar Cedula:\n";
                        cin>>dato;  dato = dato +',';     //darle el formato del archivo
                        int verificacion = 0;
                        archivo_usuario = lectura(nombre_archivo_usuario);  //informacion de los usuarios
                        archivo_usuario = decodificacion(archivo_usuario,2,4);  //decodificar para obtener la información de usuarios
                        archivo_usuario = binario_caracter(archivo_usuario); //pasar a texto

                        verificacion = archivo_usuario.find(dato);  //buscar si la cedula esta registrada
                        if (verificacion == -1)     //si no está registrada
                        {
                            nuevo = dato;
                            cout << "ingrese clave y saldo separados por (,).\n";
                            cin>> dato;
                            nuevo = nuevo + dato +'.'+'\n';

                            archivo_usuario = archivo_usuario + nuevo;      //agregar el nuevo usuario
                            archivo_usuario = caracter_binario(archivo_usuario); //codificar informacion y escribir el archivo
                            archivo_usuario = codificacion(archivo_usuario,2,4);
                            escritura(nombre_archivo_usuario,archivo_usuario);

                        }//(verificacion != -1)

                        else if (verificacion != -1)
                            cout << "usuario ya se encuentra registrado.\n";
                        break;


                    }

                }

            }
            break;

        case 2:
            /*se lee archivo usuarios.txt y se guarda en variable archivo_usuario, luego se decodifica el archivo_usuario con
             * metodo 2 y 4 particiones, archivo_usuario decodificado se pasa a caracteres, en este se busca verificacion
             * (usuario y contrasena ingresados) pertenescan a un usuario registrado,  veri me dice si el dato verificacion esta en el archivo_usuario
             * si esta se inicia sesion.
             */
            cout << "********* USUARIO ********* \n";
            archivo_usuario = lectura(nombre_archivo_usuario);
            archivo_usuario = decodificacion(archivo_usuario,2,4);
            archivo_usuario = binario_caracter(archivo_usuario);

            int veri = 0;
            string usuario="",contrasena="",verificacion = "";
            cout << "Ingrese nombre de usuario:\n";
            cin >> usuario;
            cout << "Ingrese contrasena:\n";
            cin >> contrasena;
            verificacion = usuario +','+ contrasena + ',';

            veri = archivo_usuario.find(verificacion);
            if (veri == -1)
                cout << "usuario y contrasena errada.\n";
            if (veri != -1)
            {
                int eso = archivo_usuario.length()-verificacion.length();
                string datos_usuario,
                        datos_antes_de_usuario="",
                        datos_despues_de_usuario="",
                        saldo_char;
                datos_usuario = archivo_usuario.substr(veri, eso) ;
                eso =  datos_usuario.find('.');
                datos_usuario = archivo_usuario.substr(veri,eso);
                datos_antes_de_usuario = archivo_usuario.substr(0,veri);
                datos_despues_de_usuario = archivo_usuario.substr(veri+eso,archivo_usuario.length()-(veri+eso));
                int saldo_int;
                saldo_int = datos_usuario.find(contrasena);
                saldo_int = saldo_int + contrasena.length();
                saldo_char = datos_usuario.substr(saldo_int+1);
                saldo_int = stoi (saldo_char);
                saldo_int = saldo_int -1000;

                int opcion1=1;
                while (opcion1 !=0){
                    cout << "\n********* BIENVENIDO  "<<usuario <<" *********\n";
                    cout << " 1. Consultar saldo.\n 2. Retirar dinero.\n 0. salir.\n";
                    cin>> opcion1;
                    switch (opcion1)
                    {
                    case 1:
                        cout << " 1. Consultar saldo.\n\n";
                        cout << "su saldo es:"<< saldo_int;

                        saldo_char = to_string (saldo_int);
                        datos_usuario = usuario + ','+contrasena+','+saldo_char;
                        archivo_usuario = datos_antes_de_usuario + datos_usuario + datos_despues_de_usuario;
                        archivo_usuario = caracter_binario(archivo_usuario);
                        archivo_usuario = codificacion(archivo_usuario,2,4);
                        escritura(nombre_archivo_usuario,archivo_usuario);

                        break;

                    case 2:
                        cout << "2. Retirar dinero.";
                        int retiro;
                        cout << "ingrese cantidad de dinero que desea retirar:\n";
                        cin >> retiro;
                        if (retiro>saldo_int)
                            cout << "No se puede realizar retiro \n Saldo insuficiente\n";

                        else if (retiro < saldo_int){
                            saldo_int = saldo_int - retiro;
                            cout << "Saldo:" << saldo_int<<endl;


                            saldo_char = to_string (saldo_int);
                            datos_usuario = usuario + ','+contrasena+','+saldo_char;
                            archivo_usuario = datos_antes_de_usuario + datos_usuario + datos_despues_de_usuario;
                            archivo_usuario = caracter_binario(archivo_usuario);
                            archivo_usuario = codificacion(archivo_usuario,2,4);
                            escritura(nombre_archivo_usuario,archivo_usuario);
                        }
                        break;

                    default:
                        cout <<"La opcion ingresada no es valida\n";
                        break;

                    }

                }

            }
            break;
        }
    }
}
