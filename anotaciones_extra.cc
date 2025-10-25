/*
    TODO---------------------Sábiduria básica---------------------TODO
    ?------------------(1) Git (comandos útiles)------------------
    * git clone <url-del-repositorio>
    * git config --global user.name "Tu Nombre"
    * git config --global user.email "tuemail@example.com"
    * git config --global --list a
    * git config --global --unset user.name
    * git config --global --unset user.email
    * Listar ramas locales
    git branch
    * Crear una nueva rama local
    git branch nombre-de-la-rama
    * Cambiar a otra rama
    git checkout nombre-de-la-rama
    * Eliminar una rama
    git branch -d nombre-de-la-rama
    * git add .
    * git commit -m "Mensaje del commit"
    * git push
    ?--------------------(2) Git Flow----------------------------
    * git flow init
    * git flow feature start nombre-rama
    No usar espacios o camelCase. feature/nueva-funcionalidad
    * git add .
    * git commit -m "Añadir funcionalidad de cuadrícula"
    * git flow feature publish nombre-rama
    * git flow feature finish nombre-rama
    * git push origin develop
    * git flow release start v1.0.0
    * git flow release finish v1.0.0
    * git push origin main
    * git push origin develop
    ?---------------------(3) Buenos commits---------------------
    * 1. Especifica el tipo de commit:
    feat: La nueva característica que agregas a una aplicación en particular
    fix: Un parche para un error
    style: Características o actualizaciones relacionadas con estilos
    refactor: Refactorizar una sección específica de la base de código
    test: Todo lo relacionado con pruebas
    docs: Todo lo relacionado con documentación
    chore: Mantenimiento de código regular.
    Ejempo: git commit -m "fix: Corregir error de cálculo en la función de descuento"
    * 2. Quita signos de puntuación innecesarios.
    No uses punto final ni puntos suspensivos en tus mensajes
    * 3. Usa mayúsculas al inicio del título y por cada párrafo del cuerpo del mensaje.
    * 4. Usa el cuerpo del mensaje para explicar los cambios:
    Además del titulo, un commit tiene un cuerpo del mensaje, en el cuál, puedes explicar
    a los colaboradores del repositorio tus cambios.

    git commit -m "fix: Corregir error en la validación del formulario de registro"
    -m "Se corrigió un error que impedía que los usuarios con una contraseña válida pudieran registrarse correctamente.
    El problema se debía a una falta de validación en el campo de contraseña que permitía caracteres especiales no permitidos."

    * 5. Usa el verbo en infinitivo
    Añadir, Corregir, Eliminar, Cambiar, Arreglar, Remover
    * 6. Usa como máximo 50 carácteres para tu mensaje de commits
    ?------------------(4) Google C++ Style Guide-----------------
    * Identación
    Se utiliza una identación de 2 espacios por nivel. Además, se deben dejar espacios
    alrededor de operadores y después de comas para mejorar la legibilidad.

    int CalcularTotal(int a, int b) {
    return a + b * 2;
    } // Correcto (espacios alrededor de operadores y después de comas)

    * Longitud de las líneas de código
    Las líneas de código deben limitarse a 80 caracteres como máximo.
    Si una línea supera este límite, se debe aplicar un ajuste de línea (line-wrapping)
    en puntos lógicos del código, como después de operadores, comas o concatenaciones.

    std::string GetMessage() {
    return "Esta es una cadena de texto muy larga que se ha dividido en dos líneas para "
        "cumplir con el límite de 80 caracteres por línea.";
    }

    * Uso de llaves
    Las llaves se colocan en la misma línea que la declaración del bloque (estilo K&R o llaves egipcias).
    Incluso para bloques de una sola línea, se recomienda usar llaves para mayor claridad y evitar errores.

    void CheckValue(int value) {
        if (value > 0) {
            std::cout << "El valor es positivo.\n";
        } else {
            std::cout << "El valor es cero o negativo.\n";
        }
    }

    * Declaración y diseño de funciones
    Responsabilidad única: una función debe hacer una sola cosa bien.
    Nombres claros: PascalCase

    * Declaración de variables
    Nombres claros: snake_case
    Ejemplo: nombre_variable

    * Const-correctness: marca parámetros y métodos const cuando no modifiquen estado.
    * Pasa por referencia: los pequeños tipos triviales por valor (int, double,char,string,bool).
    * Validación: valida precondiciones al inicio para evitar errorres durante el proceso de la ejecución.

    * Variables y estilo
    Inicializa siempre (brace-initialization).
    auto con criterio: úsalo cuando el tipo es obvio del lado derecho o es verboso (iteradores);
    evita ocultar tipos no triviales.
    Ámbito mínimo: declara lo más cerca del uso. Evita declarar variables que no se usaran durante el proceso de ejecución.
    Nombres descriptivos: evita abreviaturas crípticas; unidades en el nombre si aplica

    * Nombre de archivos.cc nombre_archivo.cc
    * Nombre de structs: PascalCase
    ?-----------------(5) Ejemplos de comentarios-------------------
    * Documentación: Cada archivo .hpp o .cc debe empezar con un bloque de cabecera que incluya
    Nombre del archivo
    Descripción breve de su propósito
    Autor(es)
    Fecha de creación / modificación
    -----------------------
    * @file examen.cc
    * @brief Solución del examen parcial 2 de programación de estructuras dinámicas.
    *
    * Contiene las funciones que satisfacen las indicaciones dadas por la instructura que resuelven el ejercicio.
    *
    * @author Adriana
    * @date 2025-10-25
    -----------------------

    * Documentación de funciones:
    -----------------------
    * @brief Calcula el área de un cuadrado.
    * @param lado Longitud del lado (mayor que 0).
    * @return Área del cuadrado.
    -----------------------
    ?-------------(6) A tomar en cuenta al codificar---------------
    * No usar asignación con {} en structs sin constructor.
    ❌ Ejemplo: cine.salas_cine[i] = {nombre, capacidad, formato};
    ✅ Mejor:
    cine.salas_cine[i].nombre = nombre;
    cine.salas_cine[i].capacidad = capacidad;
    cine.salas_cine[i].formato = formato;

    *Inicializá siempre las variables antes de usarlas.

    ❌ int total; cout << total;
    ✅ int total = 0;
    💡 Evita valores basura y comportamientos inesperados.

    *Error típico:
    char str1[] = "hola";
    char str2[] = "hola";
    if (str1 == str2) { ... } // compara direcciones, no contenido


    *Corrección:
    if (strcmp(str1, str2) == 0) { ... } // compara contenido

    ?Teoria
    O(1) — Constante
    Descripción: El tiempo de ejecución no depende del tamaño de la entrada.
    Ejemplo: Acceder a un elemento de un arreglo por índice.

    O(log n) — Logarítmica
    Descripció: El tiempo crece logarítmicamente con el tamaño de la entrada.
    Ejemplo: Búsqueda binaria en una lista ordenada.

    O(n) — Lineal
    Descripción: El tiempo de ejecución crece proporcionalmente al tamaño de la entrada.
    Ejemplo: Recorrer todos los elementos de una lista.

    O(n log n) — Log-lineal
    Descripción: Crece más rápido que O(n) pero más lento que O(n²).
    Ejemplo: Algoritmos de ordenación eficientes como Merge Sort o Quick Sort.

    O(n²) — Cuadrática
    Descripción: El tiempo de ejecución crece proporcionalmente al cuadrado del tamaño de la entrada.
    Ejemplo: Algoritmos de ordenación como Bubble Sort.
*/

// TODO------Examen parcial (1)------TODO
/**
 * @file AdrianaMejia.cc
 * @brief Resolución del parcial Clave B
 *
 * Se busca desarrollar un programa para gestionar información sobre cine y sus salas de proyección.
 *
 *
 * @author Adriana Mejia
 * @date 2025-09-20
 */

#include <iostream>
#include <vector>
#include <string>

// Declarar estructuras
struct Sala
{
    std::string nombre_sala = "";
    int capacidad_personas_sala = 0;
    bool formato_3D_sala = false;
};

struct Cine
{
    std::string nombre_cine = "";
    std::string ubicacion_cine = "";
    struct Sala salas_cine[3];
};

// Declarar funciones
struct Cine SolicitarInformacion();
void ImprimirDatos(struct Cine cine);
int CalcularCapacidadPersonasCine(struct Cine cine);
void BuscarFormatoPelicula(struct Cine cine);

int main()
{
    // Declarar variables
    bool continuar = true;
    int opcion = 0, id_cine = 0, total = 0;
    std::vector<Cine> cines;
    Cine cine;

    // Saludar al usuario
    std::cout << "---Bienvenido al programa de gestion de cines---" << std::endl;

    // Solicitar la información
    do
    {
        cines.push_back(SolicitarInformacion());
        for (auto cine : cines)
        {
            ImprimirDatos(cine);
        }
        std::cout << "\n------\n¿Desea agregar otro cine? (1 = Si, 0 = No): ";
        std::cin >> opcion;

        if (opcion == 0)
        {
            continuar = false;
        }

    } while (continuar);

    // Calcular capacidad de personas
    for (auto i : cines)
    {
        total += CalcularCapacidadPersonasCine(i);
        std::cout << "Capacidad total del cine: " << total;
    }

    // Buscar formato de peliculas
    std::cout << "Ingrese el numero de cine a buscar salas: ";
    std::cin >> id_cine;
    BuscarFormatoPelicula(cines[id_cine - 1]);

    return 0;
}

// Funcion struct para solicitar la informacion
struct Cine SolicitarInformacion()
{
    Cine cine;
    Sala salas;

    std::string nombre_sala = "";
    int capacidad_sala = 0, opcion = 0;
    bool formato_3D = false;

    std::cout << "Por favor, ingrese la siguiente informacion: " << std::endl;

    std::cout << "\n1) Nombre del cine: ";
    std::getline(std::cin, cine.nombre_cine);

    std::cout << "2) Ubicacion del cine: ";
    std::getline(std::cin, cine.ubicacion_cine);

    std::cout << "3) Informacion de las salas(3): " << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nNombre de la sala (" << i + 1 << "): ";
        std::getline(std::cin, nombre_sala);

        std::cout << "Capacidad de personas: ";
        std::cin >> capacidad_sala;

        std::cout << "Permite formato 3D? \n (1): Si \n (2): No \n Mi respuesta: ";
        std::cin >> opcion;

        if (opcion == 1)
        {
            formato_3D = true;
        }
        else
        {
            formato_3D = false;
        }

        cine.salas_cine[i] = {nombre_sala, capacidad_sala, formato_3D};
        std::cin.ignore();
    }

    return cine;
}

// Funcion void para imprimir los datos
void ImprimirDatos(struct Cine cine)
{

    std::cout << "\n-------\nInformacion ingresada: \n-------" << std::endl;
    std::cout << "Nombre del cine: " << cine.nombre_cine << std::endl;
    std::cout << "Ubicacion del cine: " << cine.ubicacion_cine << std::endl;
    std::cout << "-----\nInformacion de las salas (3): ";

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\n----\nNombre de la sala (" << i + 1 << "):" << cine.salas_cine[i].nombre_sala;
        std::cout << "\nCapacidad de la sala: " << cine.salas_cine[i].capacidad_personas_sala;

        std::cout << "\nPermite formato 3D: ";
        if (cine.salas_cine[i].formato_3D_sala)
        {
            std::cout << "Si";
        }
        else
        {
            std::cout << "No";
        }
    }
}

// Funcion int que calcula la capcidad de personas del cine
int CalcularCapacidadPersonasCine(struct Cine cine)
{
    int capacidad_total = 0;
    for (int i = 0; i < 3; i++)
    {
        capacidad_total += cine.salas_cine[i].capacidad_personas_sala;
    }
    return capacidad_total;
}

// Funcion void que busca el formato de pelicula
void BuscarFormatoPelicula(struct Cine cine)
{
    int opcion;
    std::cout << "\n---\nQue desea buscar?: \n(1)Formato 3D \n(2)Formato 2D \n Mi respuesta: ";

    std::cin >> opcion;

    if (opcion == 1)
    {
        std::cout << "Salas con formato 3D: \n";

        for (auto sala : cine.salas_cine)
        {
            if (sala.formato_3D_sala)
            {
                std::cout << "\nNombre de la sala: " << sala.nombre_sala;
                std::cout << "\nCapacidad de la sala: " << sala.capacidad_personas_sala;
            }
            else
            {
                std::cout << "\nNo hay salas con formato 3D";
            }
        }
    }
    else if (opcion == 2)
    {
        std::cout << "Salas con formato 2D: \n";

        for (auto sala : cine.salas_cine)
        {
            if (!sala.formato_3D_sala)
            {
                std::cout << "Nombre de la sala: " << sala.nombre_sala;
                std::cout << "\nCapacidad de la sala: " << sala.capacidad_personas_sala;
            }
            else
            {
                std::cout << "\nNo hay salas con formato 2D";
            }
        }
    }
    else
    {
        std::cout << "Error: Debe escoger alguna de las 2 opciones, vuelva a empezar :p" << std::endl;
    }
}

// TODO------Bubble Sort------TODO
#include <iostream>

void OrdenarPorBurbuja(int arreglo[], int n);
void Imprimirarreglo(int arreglo[], int n);

int main()
{
    // Definimos un arregloeglo de ejemplo
    int arreglo[] = {5, 3, 8, 4, 2};
    // Tamaño del arregloeglo
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    std::cout << "arreglo sin ordenar: ";
    Imprimirarreglo(arreglo, n);

    // Ordenamos el arregloeglo usando el método burbuja
    OrdenarPorBurbuja(arreglo, n);

    std::cout << "arreglo ordenado: ";
    Imprimirarreglo(arreglo, n);

    return 0;
}

// Función para realizar el ordenamiento por burbuja
void OrdenarPorBurbuja(int arreglo[], int n)
{
    // Contador para el número de pasos realizados
    int pasos = 0;
    // Contador de intercambios
    int intercambios = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Incrementamos el contador de pasos en cada comparación
            pasos++;
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (arreglo[j] > arreglo[j + 1])
            {
                // Intercambio de elementos
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
                // Incrementamos el contador de intercambios
                intercambios++;
            }
        }
    }
    std::cout << "Numero total de pasos: " << pasos << std::endl;
    std::cout << "Numero total de intercambios: " << intercambios << std::endl;
}

// Función para imprimir el arregloeglo
void Imprimirarreglo(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}
// TODO------Insertion Sort------TODO
#include <iostream>

void OrdenarPorInsercion(int arreglo[], int n);
void imprimirArreglo(int arreglo[], int n);

int main()
{
    // Declarar e inicializar el arreglo
    int arreglo[] = {4, 1, 65, 12, 10};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    // Imprimir arreglo sin ordenar
    std::cout << "Arreglo sin ordenar: ";
    imprimirArreglo(arreglo, n);

    // Ordenar el arreglo usando el método de inserción
    OrdenarPorInsercion(arreglo, n);

    // Imprimir arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    imprimirArreglo(arreglo, n);

    return 0;
}

// Definición de la función de inserción
void OrdenarPorInsercion(int arreglo[], int n)
{
    // Comienza desde el segundo elemento
    for (int i = 1; i < n; i++)
    {
        // Valor a insertar
        int aux = arreglo[i];
        int j = i - 1;

        // Mover los elementos mayores que 'aux' hacia la derecha
        while (j >= 0 && arreglo[j] > aux)
        {
            // Desplazar hacia la derecha
            arreglo[j + 1] = arreglo[j];
            j--;
        }

        // Insertar el valor en su posición correcta
        arreglo[j + 1] = aux;
    }
}

// Definición de la función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}
// TODO------Selection Sort------TODO
#include <iostream>

// Declaración de las funciones
void imprimir(int arreglo[], int n);
void ordenarPorSeleccion(int arreglo[], int n);

int main()
{
    // Declarar e inicializar el arreglo
    int arreglo[] = {4, 8, 9, 55, 6, 1, 3};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    // Imprimir el arreglo sin ordenar
    std::cout << "Arreglo sin ordenar: ";
    imprimir(arreglo, n);

    // Ordenar el arreglo usando el método de selección
    ordenarPorSeleccion(arreglo, n);

    // Imprimir el arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    imprimir(arreglo, n);

    return 0;
}

// Definición de la función para ordenar el arreglo usando el método de selección
void OrdenarPorSeleccion(int arreglo[], int n)
{
    // Solo necesitamos recorrer hasta el penúltimo elemento
    for (int i = 0; i < n - 1; i++)
    {
        // Inicializamos la posición del menor elemento en el índice i
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            // Si encontramos un valor menor, actualizamos la posición del menor
            if (arreglo[j] < arreglo[minPos])
            {
                minPos = j;
            }
        }

        // Intercambiamos los valores
        std::swap(arreglo[i], arreglo[minPos]);
    }
}

// Definición de la función para imprimir el arreglo
void Imprimir(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}
// TODO------Busqueda Lineal------TODO
#include <iostream>

int BusquedaLineal(int[], int, int);

int main(int argc, char *argv[])
{
    int arreglo[] = {1, 40, 100, 80, 25};
    int valor_buscado = 40;
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    std::cout << BusquedaLineal(arreglo, tamano, valor_buscado);
    return 0;
}

// Recorre el arreglo y compara cada elemento con el número buscado
int BusquedaLineal(int arreglo[], int tamano, int valor)
{
    for (int i = 0; i < tamano; i++)
    {
        if (arreglo[i] == valor)
        {
            return i;
        }
    }
    return -1;
}
// TODO------Busqueda Binaria------TODO
#include <iostream>

int BusquedaBinaria(int arreglo[], int pos_menor, int pos_mayor, int valor_buscado);

int main(int argc, char *argv[])
{
    int arreglo[] = {1, 40, 100, 80, 25};
    int valor_buscado = 40;
    int long_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);
    int resultado = BusquedaBinaria(arreglo, 0, long_arreglo - 1, valor_buscado);

    // Si la búsqueda fue exitosa, resultado tendrá el índice del valor buscado
    if (resultado != -1)
    {
        std::cout << "Valor encontrado en el indice: " << resultado << std::endl;
    }
    else
    {
        std::cout << "Valor no encontrado." << std::endl;
    }

    return 0;
}

// Recorre el arreglo en busca de un valor, partiendo del medio del rango (menor a mayor).
int BusquedaBinaria(int arreglo[], int pos_menor, int pos_mayor, int valor_buscado)
{
    // Mientras el índice 'menor' no sea mayor que 'mayor', seguimos buscando
    while (pos_menor <= pos_mayor)
    {
        // Calculamos el índice del medio del rango
        int pos_medio = pos_menor + (pos_mayor - pos_menor) / 2;

        // Si encontramos el valor en la posición del medio, retornamos su índice
        if (arreglo[pos_medio] == valor_buscado)
        {
            return pos_medio;
        }
        // Si el valor buscado es mayor que el del medio, ignoramos la mitad izquierda
        if (arreglo[pos_medio] < valor_buscado)
        {
            // Movemos el índice 'menor' para la mitad derecha
            pos_menor = pos_mayor + 1;
        }
        // Si el valor buscado es menor que el del medio, ignoramos la mitad derecha
        else
        {
            // Movemos el índice 'mayor' para la mitad izquierda
            pos_mayor = pos_menor - 1;
        }
    }
    // Si no encontramos el valor, retornamos -1
    return -1;
}
// TODO------Implementación de librerias------TODO
#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort y std::swap

using namespace std;

void bubbleSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
}

void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
            if (v[j] < v[minIndex])
                minIndex = j;
        swap(v[i], v[minIndex]);
    }
}

void insertionSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main()
{
    vector<int> v = {5, 3, 1, 4, 2};

    cout << "Original: ";
    for (int n : v)
        cout << n << " ";
    cout << endl;

    // Puedes probar cada uno descomentando:
    // bubbleSort(v);
    // selectionSort(v);
    // insertionSort(v);

    sort(v.begin(), v.end()); // versión con la librería estándar

    cout << "Ordenado: ";
    for (int n : v)
        cout << n << " ";
    cout << endl;

    return 0;
}
// TODO------Cola ejemplo-------TODO
#include <iostream>

// La informacion que el usuario ingresara
struct Persona
{
    std::string nombre;
    int f_nac;
};

struct Nodo
{
    struct Persona inf;
    struct Nodo *siguiente;
};

// Variable global
struct Nodo *frente_cola = nullptr;
struct Nodo *final_cola = nullptr;

// Declaracion de funciones / creacion de prototipo
bool Vacia();
void Insertar(struct Persona p);
void Eliminar();
void Imprimir();
void ImprimirFrente();
void ImprimirFinal();

int main(int argc, char *argv[])
{
    struct Persona p;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Ingresa un nombre ";
        std::cin >> p.nombre;
        std::cout << "Ingresa la fecha de Nac";
        std::cin >> p.f_nac;
        Insertar(p);
    }
    std::cout << " --------------- " << std::endl;
    Imprimir();

    return 0;
}

// Operación vacia
bool Vacia()
{
    if (frente_cola == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(struct Persona p)
{
    // Reserva de memoria
    struct Nodo *nuevo_nodo = new Nodo;
    // Asignacion del valor que ingresa el usuario
    nuevo_nodo->inf = p;
    nuevo_nodo->siguiente = nullptr;

    if (frente_cola == nullptr)
    {
        frente_cola = nuevo_nodo;
    }
    else
    {
        final_cola->siguiente = nuevo_nodo;
    }
    // Se establece el final de la cola con el nuevo nodo agregado
    final_cola = nuevo_nodo;
}

// Desencolar -- inicio de la lista
void Eliminar()
{
    if (!Vacia())
    {
        struct Nodo *temporal = frente_cola;
        if (frente_cola == final_cola)
        {
            frente_cola = nullptr;
            final_cola = nullptr;
        }
        else
        {
            frente_cola = temporal->siguiente;
        }
        delete temporal;
        temporal = nullptr;
    }
}

// Imprimir elementos de la cola
void Imprimir()
{
    struct Nodo *temporal = frente_cola;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la cola " << temporal->inf.nombre
                  << " - " << temporal->inf.f_nac << " dir propia "
                  << temporal << " dir nod sig " << temporal->siguiente << std::endl;
        temporal = temporal->siguiente;
    }
}

void ImprimirFrente()
{
    struct Nodo *temporal = frente_cola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento frente en la cola " << temporal->inf.nombre << std::endl;
    }
}

void ImprimirFinal()
{

    struct Nodo *temporal = final_cola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento final en la cola " << temporal->inf.nombre << std::endl;
    }
}
